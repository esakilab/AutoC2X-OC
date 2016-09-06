/*
 * Generated by asn1c-0.9.24 (http://lionet.info/asn1c)
 * From ASN.1 module "ITS-Container"
 * 	found in "ITS_CAM_v1.3.2.asn"
 * 	`asn1c -fnative-types -gen-PER`
 */

#ifndef	_ClosedLanes_H_
#define	_ClosedLanes_H_


#include <asn_application.h>

/* Including external dependencies */
#include "HardShoulderStatus.h"
#include "DrivingLaneStatus.h"
#include <constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* ClosedLanes */
typedef struct ClosedLanes {
	HardShoulderStatus_t	*hardShoulderStatus	/* OPTIONAL */;
	DrivingLaneStatus_t	 drivingLaneStatus;
	/*
	 * This type is extensible,
	 * possible extensions are below.
	 */
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} ClosedLanes_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_ClosedLanes;

#ifdef __cplusplus
}
#endif

#endif	/* _ClosedLanes_H_ */
#include <asn_internal.h>
