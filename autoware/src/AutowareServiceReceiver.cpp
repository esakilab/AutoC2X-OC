// This file is part of OpenC2X.
//
// OpenC2X is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// OpenC2X is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
//
// You should have received a copy of the GNU Lesser General Public License
// along with OpenC2X.  If not, see <http://www.gnu.org/licenses/>.
//
// Authors:
// Sven Laux <slaux@mail.uni-paderborn.de>
// Gurjashan Singh Pannu <gurjashan.pannu@ccs-labs.org>
// Stefan Schneider <stefan.schneider@ccs-labs.org>
// Jan Tiemann <janhentie@web.de>


#define ELPP_THREAD_SAFE
#define ELPP_NO_DEFAULT_LOG_FILE

#include "AutowareServiceReceiver.h"
#include <unistd.h>
#include <iostream>
#include <cstdlib>
#include <chrono>
#include <cmath>
#include <common/utility/Utils.h>
#include <math.h>

using namespace std;

INITIALIZE_EASYLOGGINGPP


AutowareService::AutowareService(AutowareConfig &config, int argc, char* argv[]) {
	flag = -1;
	try {
		mGlobalConfig.loadConfig(AUTOWARE_CONFIG_NAME);
	}
	catch (std::exception &e) {
		cerr << "Error while loading /etc/config/openc2x_common: " << e.what() << endl;
	}
	mConfig = config;
	ptree pt = load_config_tree();
	mLogger = new LoggingUtility(AUTOWARE_CONFIG_NAME, AUTOWARE_MODULE_NAME, mGlobalConfig.mLogBasePath, mGlobalConfig.mExpName, mGlobalConfig.mExpNo, pt);

	mSender = new CommunicationSender("25000", *mLogger);
	// mLogger = new LoggingUtility("AutowareService", mGlobalConfig.mExpNo, loggingConf, statisticConf);
	mLogger->logStats("speed (m/sec)");

	mReceiverFromCa = new CommunicationReceiver("23456", "CAM", *mLogger);
	mClientCam = new CommunicationClient("6789", *mLogger);
	
	mThreadReceive = new boost::thread(&AutowareService::receiveFromCa, this);
	mThreadReceiveFromAutoware = new boost::thread(&AutowareService::receiveFromAutoware, this);
	

	char cur_dir[1024];
	getcwd(cur_dir, 1024);
	time_t t = time(nullptr);
	const tm* lt = localtime(&t);
	std::stringstream s;
	s<<"20";
	s<<lt->tm_year-100; //100を引くことで20xxのxxの部分になる
	s<<"-";
	s<<lt->tm_mon+1; //月を0からカウントしているため
	s<<"-";
	s<<lt->tm_mday; //そのまま
	s<<"_";
	s<<lt->tm_hour;
	s<<":";
	s<<lt->tm_min;
	s<<":";
	s<<lt->tm_sec;
	std::string timestamp = s.str();

	std::string filename = std::string(cur_dir) + "/../../../autoware/output/delay/receiver_delay_" + timestamp + ".csv";
	delay_output_file.open(filename, std::ios::out);

	filename = std::string(cur_dir) + "/../../../autoware/output/timestamp_record/receiver_timestamp_" + timestamp + ".csv";
        timestamp_record_file.open(filename, std::ios::out);

	loadOpt(argc, argv);
	std::cout << "socket open" << std::endl;
	struct sockaddr_in addr;
	if( (sockfd = socket( AF_INET, SOCK_STREAM, 0) ) < 0 ) perror( "socket" ); 
	addr.sin_family = AF_INET;
	addr.sin_port = htons( 23459 );
	addr.sin_addr.s_addr = inet_addr( host_addr.c_str() );
	connect( sockfd, (struct sockaddr *)&addr, sizeof( struct sockaddr_in ) );
	while(1){
		//testSender();
		sendToAutoware(100000);
		usleep(100000);
	}

}

AutowareService::~AutowareService() {
	delete mSender;
	delete mLogger;

	mTimer->cancel();
	delete mTimer;
}

void AutowareService::loadOpt(int argc, char* argv[]){	
	int i, opt;
	opterr = 0; //getopt()のエラーメッセージを無効にする。
    //オプション以外の引数を出力する
    for (i = optind; i < argc; i++) {
		host_addr = std::string(argv[i]);
		std::cout << host_addr << std::endl;
		break;
    }
	if(host_addr.length() < 4){
		printf("Usage: %s  [host_addr] ...\n", argv[0]);
	}
}


//simulates Autoware data, logs and sends it
void AutowareService::simulateData() {
	std::cout << "simulating....." << std::endl;
	autowarePackage::AUTOWARE autoware;

	//write current speed to protocol buffer
	autoware.set_speed(speed); // standard expects speed in 0.01 m/s
	// autoware.set_time(Utils::currentTime());
	autoware.set_time(generationUnixTime);
	autoware.set_longitude(longitude);
	autoware.set_latitude(latitude);
	std::cout << std::setprecision(20) << "speed:" << autoware.speed() << " time:" << autoware.time() << " longitude:" << autoware.longitude() << " latitude:" << autoware.latitude() << std::endl;
	// sendToServices(autoware);

}

//logs and sends Autoware
void AutowareService::receiveFromCa() {
	string serializedCam;
	camPackage::CAM cam;

	while(1){
		pair<string, string> received = mReceiverFromCa->receive();
		std::cout << "receive from ca" << std::endl;

		serializedCam = received.second;
		cam.ParseFromString(serializedCam);
		std::cout << "stationid:" << cam.header().stationid() << " latitude:" << cam.coop().camparameters().basiccontainer().latitude() << " longitude:" << cam.coop().camparameters().basiccontainer().longitude() << " speed:" <<  cam.coop().camparameters().highfreqcontainer().basicvehiclehighfreqcontainer().speed() << std::endl;

		s_message.latitude.push_back( cam.coop().camparameters().basiccontainer().latitude() );
		s_message.longitude.push_back( cam.coop().camparameters().basiccontainer().longitude() );
		s_message.time.push_back( cam.coop().gendeltatime() );
		s_message.speed.push_back( cam.coop().camparameters().highfreqcontainer().basicvehiclehighfreqcontainer().speed() );
	}
}


void AutowareService::init() {
	if (!mConfig.mSimulateData) {	//use real Autoware data
	}
	else {				//use simulated Autoware data
	}
}

double AutowareService::calcSpeed(){
}

void AutowareService::timeCalc(){
}

void AutowareService::sendToAutoware(long timestamp){

	// std::cout << timestamp << std::endl;
	// for(int i=0; i<s_message.speed.size(); i++){
	// 	std::cout  <<  "latitude:" << std::setprecision(20) << s_message.latitude[i] << " longitude:" << s_message.longitude[i] << std::endl;
	// }

	s_message.timestamp = Utils::currentTime();
	std::stringstream ss;
	boost::archive::text_oarchive archive(ss);
	// cereal::BinaryOutputArchive archive(ss);
	archive << s_message;
	std::cout << ss.str() << std::endl;
	timestamp_record_file << s_message.timestamp << std::endl;
	ss.seekg(0, ios::end);
	if( send( sockfd, ss.str().c_str(), ss.tellp(), 0 ) < 0 ) {
			perror( "send" );
	} else {
	}

	s_message.speed.clear();
	s_message.latitude.clear();
	s_message.longitude.clear();
	s_message.time.clear();
}

void AutowareService::testSender(){

	std::mt19937 mt(rnd());
	std::uniform_int_distribution<> rand(0, 100);
	// std::cout << std::setprecision(20) << rand(mt) / 1000000.0 << std::endl;

	s_message.speed.push_back(rand(mt)/1000.0);
	s_message.latitude.push_back(35.714464 * 10000000);
	s_message.longitude.push_back(139.760606 * 10000000);
	s_message.time.push_back(rand(mt)/1000.0);

	s_message.speed.push_back(rand(mt)/1000.0);
	s_message.latitude.push_back(35.71419722 * 10000000 + rand(mt)*0);
	s_message.longitude.push_back(139.76148888 * 10000000 + rand(mt)*0);
	s_message.time.push_back(rand(mt)/1000.0);

	s_message.speed.push_back(rand(mt)/1000.0);
	s_message.latitude.push_back(35.714497 * 10000000 + rand(mt)*0);
	s_message.longitude.push_back(139.763014 * 10000000 + rand(mt)*0);
	s_message.time.push_back(rand(mt)/1000.0);

	s_message.speed.push_back(rand(mt)/1000.0);
	s_message.latitude.push_back(35.713997 * 10000000 + rand(mt)*0);
	s_message.longitude.push_back(139.760153 * 10000000 + rand(mt)*0);
	s_message.time.push_back(rand(mt)/1000.0);

	s_message.speed.push_back(rand(mt)/1000.0);
	s_message.latitude.push_back(35.712992 * 10000000 + rand(mt)*0);
	s_message.longitude.push_back(139.759819 * 10000000 + rand(mt)*0);
	s_message.time.push_back(rand(mt)/1000.0);
	
	sendToAutoware(100000);
}

void AutowareService::receiveFromAutoware(){
	std::cout << "*****receive setup" << std::endl;
	int sock_fd;
    int client_sockfd;
    struct sockaddr_in addr;
    socklen_t len = sizeof( struct sockaddr_in );
    struct sockaddr_in from_addr;
    char buf[4096];
 
    memset( buf, 0, sizeof( buf ) );
    if( ( sock_fd = socket( AF_INET, SOCK_STREAM, 0 ) ) < 0 ) {
        perror( "socket" );
    }
    addr.sin_family = AF_INET;
    addr.sin_port = htons( 23460 );
    addr.sin_addr.s_addr = INADDR_ANY;
    if( bind( sock_fd, (struct sockaddr *)&addr, sizeof( addr ) ) < 0 ) perror( "bind" );
    if( listen( sock_fd, SOMAXCONN ) < 0 ) perror( "listen" );
    if( ( client_sockfd = accept( sock_fd, (struct sockaddr *)&from_addr, &len ) ) < 0 ) perror( "accept" );
 
    // 受信
    int rsize;
    while( 1 ) {
		std::stringstream ss;
		memset( buf, 0, sizeof( buf ) );
        rsize = recv( client_sockfd, buf, sizeof( buf ), 0 );
		std::cout << "received" << std::endl;

		ss << buf;

		boost::archive::text_iarchive archive(ss);
		// cereal::BinaryInputArchive archive(ss);
		archive >> tmp_message;
		std::cout << "received" << std::endl;

		delay_output_file << std::setprecision(20) << tmp_message.timestamp << "," << Utils::currentTime() << "," << tmp_message.lat << "," << tmp_message.lon << std::endl;

		if ( rsize == 0 ) {
            break;
        } else if ( rsize == -1 ) {
            perror( "recv" );
        }
		// simulateData();
		std::cout << tmp_message.timestamp << std::endl;
		// testSender();
    }
    close( client_sockfd );
    close( sock_fd );
}

int main(int argc,  char* argv[]) {

	AutowareConfig config;
	try {
		config.loadConfig();
	}
	catch (std::exception &e) {
		cerr << "Error while loading config.xml: " << e.what() << endl << flush;
		return EXIT_FAILURE;
	}
	AutowareService autoware(config, argc, argv);

	return 0;
}
