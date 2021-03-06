#!/bin/sh
# This script assumes that instructions in OpenC2X/README.txt have been followed

SESSION=OpenC2X
CURR_DIR=$(pwd)
OPENC2X=$CURR_DIR/..
BUILD_DIR=$OPENC2X/build/


tmux -2 new-session -d -s $SESSION


tmux set-option -g mouse

tmux new-window -t $SESSION:1 -n 'App'

tmux split-window -h
tmux select-pane -t 0

tmux send-keys "mkdir -p $OPENC2X/pingApp/output/delay" C-m
tmux send-keys "mkdir -p $OPENC2X/autoware/output/delay" C-m
tmux send-keys "mkdir -p $OPENC2X/cam/output/delay" C-m

#tmux send-keys "cam" C-m
tmux send-keys "cd $BUILD_DIR/cam/src" C-m
if [ ${1} = "s" ]; then
    tmux send-keys "./cam_sender" C-m
else
    tmux send-keys "./cam_receiver" C-m
fi
tmux split-window -v

tmux split-window -v


#tmux send-keys "rm ../db/ldm-*.db" C-m
# tmux send-keys "ldm" C-m
tmux send-keys "cd $BUILD_DIR/ldm/src" C-m
tmux send-keys "./ldm" C-m
tmux split-window -v


tmux kill-pane
tmux select-pane -t 3



tmux send-keys "denm" C-m
tmux split-window -v

tmux send-keys "dcc" C-m
tmux split-window -v


tmux send-keys "cd $BUILD_DIR/autoware/src" C-m
if [ ${1} = "s" ]; then
    tmux send-keys "./autoware_sender ${2}" C-m
else
    tmux send-keys "./autoware_receiver ${2}" C-m
fi
# tmux split-window -v


# tmux send-keys "gpsService" C-m

tmux -2 attach-session -t $SESSION

