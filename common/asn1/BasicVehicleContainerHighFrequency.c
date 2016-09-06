/*
 * Generated by asn1c-0.9.24 (http://lionet.info/asn1c)
 * From ASN.1 module "CAM-PDU-Descriptions"
 * 	found in "ITS_CAM_v1.3.2.asn"
 * 	`asn1c -fnative-types -gen-PER`
 */

#include "BasicVehicleContainerHighFrequency.h"

static asn_TYPE_member_t asn_MBR_BasicVehicleContainerHighFrequency_1[] = {
	{ ATF_NOFLAGS, 0, offsetof(struct BasicVehicleContainerHighFrequency, heading),
		(ASN_TAG_CLASS_CONTEXT | (0 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_Heading,
		0,	/* Defer constraints checking to the member type */
		0,	/* No PER visible constraints */
		0,
		"heading"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct BasicVehicleContainerHighFrequency, speed),
		(ASN_TAG_CLASS_CONTEXT | (1 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_Speed,
		0,	/* Defer constraints checking to the member type */
		0,	/* No PER visible constraints */
		0,
		"speed"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct BasicVehicleContainerHighFrequency, driveDirection),
		(ASN_TAG_CLASS_CONTEXT | (2 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_DriveDirection,
		0,	/* Defer constraints checking to the member type */
		0,	/* No PER visible constraints */
		0,
		"driveDirection"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct BasicVehicleContainerHighFrequency, vehicleLength),
		(ASN_TAG_CLASS_CONTEXT | (3 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_VehicleLength,
		0,	/* Defer constraints checking to the member type */
		0,	/* No PER visible constraints */
		0,
		"vehicleLength"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct BasicVehicleContainerHighFrequency, vehicleWidth),
		(ASN_TAG_CLASS_CONTEXT | (4 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_VehicleWidth,
		0,	/* Defer constraints checking to the member type */
		0,	/* No PER visible constraints */
		0,
		"vehicleWidth"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct BasicVehicleContainerHighFrequency, longitudinalAcceleration),
		(ASN_TAG_CLASS_CONTEXT | (5 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_LongitudinalAcceleration,
		0,	/* Defer constraints checking to the member type */
		0,	/* No PER visible constraints */
		0,
		"longitudinalAcceleration"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct BasicVehicleContainerHighFrequency, curvature),
		(ASN_TAG_CLASS_CONTEXT | (6 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_Curvature,
		0,	/* Defer constraints checking to the member type */
		0,	/* No PER visible constraints */
		0,
		"curvature"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct BasicVehicleContainerHighFrequency, curvatureCalculationMode),
		(ASN_TAG_CLASS_CONTEXT | (7 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_CurvatureCalculationMode,
		0,	/* Defer constraints checking to the member type */
		0,	/* No PER visible constraints */
		0,
		"curvatureCalculationMode"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct BasicVehicleContainerHighFrequency, yawRate),
		(ASN_TAG_CLASS_CONTEXT | (8 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_YawRate,
		0,	/* Defer constraints checking to the member type */
		0,	/* No PER visible constraints */
		0,
		"yawRate"
		},
	{ ATF_POINTER, 7, offsetof(struct BasicVehicleContainerHighFrequency, accelerationControl),
		(ASN_TAG_CLASS_CONTEXT | (9 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_AccelerationControl,
		0,	/* Defer constraints checking to the member type */
		0,	/* No PER visible constraints */
		0,
		"accelerationControl"
		},
	{ ATF_POINTER, 6, offsetof(struct BasicVehicleContainerHighFrequency, lanePosition),
		(ASN_TAG_CLASS_CONTEXT | (10 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_LanePosition,
		0,	/* Defer constraints checking to the member type */
		0,	/* No PER visible constraints */
		0,
		"lanePosition"
		},
	{ ATF_POINTER, 5, offsetof(struct BasicVehicleContainerHighFrequency, steeringWheelAngle),
		(ASN_TAG_CLASS_CONTEXT | (11 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_SteeringWheelAngle,
		0,	/* Defer constraints checking to the member type */
		0,	/* No PER visible constraints */
		0,
		"steeringWheelAngle"
		},
	{ ATF_POINTER, 4, offsetof(struct BasicVehicleContainerHighFrequency, lateralAcceleration),
		(ASN_TAG_CLASS_CONTEXT | (12 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_LateralAcceleration,
		0,	/* Defer constraints checking to the member type */
		0,	/* No PER visible constraints */
		0,
		"lateralAcceleration"
		},
	{ ATF_POINTER, 3, offsetof(struct BasicVehicleContainerHighFrequency, verticalAcceleration),
		(ASN_TAG_CLASS_CONTEXT | (13 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_VerticalAcceleration,
		0,	/* Defer constraints checking to the member type */
		0,	/* No PER visible constraints */
		0,
		"verticalAcceleration"
		},
	{ ATF_POINTER, 2, offsetof(struct BasicVehicleContainerHighFrequency, performanceClass),
		(ASN_TAG_CLASS_CONTEXT | (14 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_PerformanceClass,
		0,	/* Defer constraints checking to the member type */
		0,	/* No PER visible constraints */
		0,
		"performanceClass"
		},
	{ ATF_POINTER, 1, offsetof(struct BasicVehicleContainerHighFrequency, cenDsrcTollingZone),
		(ASN_TAG_CLASS_CONTEXT | (15 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_CenDsrcTollingZone,
		0,	/* Defer constraints checking to the member type */
		0,	/* No PER visible constraints */
		0,
		"cenDsrcTollingZone"
		},
};
static int asn_MAP_BasicVehicleContainerHighFrequency_oms_1[] = { 9, 10, 11, 12, 13, 14, 15 };
static ber_tlv_tag_t asn_DEF_BasicVehicleContainerHighFrequency_tags_1[] = {
	(ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static asn_TYPE_tag2member_t asn_MAP_BasicVehicleContainerHighFrequency_tag2el_1[] = {
    { (ASN_TAG_CLASS_CONTEXT | (0 << 2)), 0, 0, 0 }, /* heading at 70 */
    { (ASN_TAG_CLASS_CONTEXT | (1 << 2)), 1, 0, 0 }, /* speed at 71 */
    { (ASN_TAG_CLASS_CONTEXT | (2 << 2)), 2, 0, 0 }, /* driveDirection at 72 */
    { (ASN_TAG_CLASS_CONTEXT | (3 << 2)), 3, 0, 0 }, /* vehicleLength at 73 */
    { (ASN_TAG_CLASS_CONTEXT | (4 << 2)), 4, 0, 0 }, /* vehicleWidth at 74 */
    { (ASN_TAG_CLASS_CONTEXT | (5 << 2)), 5, 0, 0 }, /* longitudinalAcceleration at 75 */
    { (ASN_TAG_CLASS_CONTEXT | (6 << 2)), 6, 0, 0 }, /* curvature at 76 */
    { (ASN_TAG_CLASS_CONTEXT | (7 << 2)), 7, 0, 0 }, /* curvatureCalculationMode at 77 */
    { (ASN_TAG_CLASS_CONTEXT | (8 << 2)), 8, 0, 0 }, /* yawRate at 78 */
    { (ASN_TAG_CLASS_CONTEXT | (9 << 2)), 9, 0, 0 }, /* accelerationControl at 79 */
    { (ASN_TAG_CLASS_CONTEXT | (10 << 2)), 10, 0, 0 }, /* lanePosition at 80 */
    { (ASN_TAG_CLASS_CONTEXT | (11 << 2)), 11, 0, 0 }, /* steeringWheelAngle at 81 */
    { (ASN_TAG_CLASS_CONTEXT | (12 << 2)), 12, 0, 0 }, /* lateralAcceleration at 82 */
    { (ASN_TAG_CLASS_CONTEXT | (13 << 2)), 13, 0, 0 }, /* verticalAcceleration at 83 */
    { (ASN_TAG_CLASS_CONTEXT | (14 << 2)), 14, 0, 0 }, /* performanceClass at 84 */
    { (ASN_TAG_CLASS_CONTEXT | (15 << 2)), 15, 0, 0 } /* cenDsrcTollingZone at 85 */
};
static asn_SEQUENCE_specifics_t asn_SPC_BasicVehicleContainerHighFrequency_specs_1 = {
	sizeof(struct BasicVehicleContainerHighFrequency),
	offsetof(struct BasicVehicleContainerHighFrequency, _asn_ctx),
	asn_MAP_BasicVehicleContainerHighFrequency_tag2el_1,
	16,	/* Count of tags in the map */
	asn_MAP_BasicVehicleContainerHighFrequency_oms_1,	/* Optional members */
	7, 0,	/* Root/Additions */
	-1,	/* Start extensions */
	-1	/* Stop extensions */
};
asn_TYPE_descriptor_t asn_DEF_BasicVehicleContainerHighFrequency = {
	"BasicVehicleContainerHighFrequency",
	"BasicVehicleContainerHighFrequency",
	SEQUENCE_free,
	SEQUENCE_print,
	SEQUENCE_constraint,
	SEQUENCE_decode_ber,
	SEQUENCE_encode_der,
	SEQUENCE_decode_xer,
	SEQUENCE_encode_xer,
	SEQUENCE_decode_uper,
	SEQUENCE_encode_uper,
	0,	/* Use generic outmost tag fetcher */
	asn_DEF_BasicVehicleContainerHighFrequency_tags_1,
	sizeof(asn_DEF_BasicVehicleContainerHighFrequency_tags_1)
		/sizeof(asn_DEF_BasicVehicleContainerHighFrequency_tags_1[0]), /* 1 */
	asn_DEF_BasicVehicleContainerHighFrequency_tags_1,	/* Same as above */
	sizeof(asn_DEF_BasicVehicleContainerHighFrequency_tags_1)
		/sizeof(asn_DEF_BasicVehicleContainerHighFrequency_tags_1[0]), /* 1 */
	0,	/* No PER visible constraints */
	asn_MBR_BasicVehicleContainerHighFrequency_1,
	16,	/* Elements count */
	&asn_SPC_BasicVehicleContainerHighFrequency_specs_1	/* Additional specs */
};

