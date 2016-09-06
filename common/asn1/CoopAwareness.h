/*
 * Generated by asn1c-0.9.24 (http://lionet.info/asn1c)
 * From ASN.1 module "CAM-PDU-Descriptions"
 * 	found in "ITS_CAM_v1.3.2.asn"
 * 	`asn1c -fnative-types -gen-PER`
 */

#ifndef	_CoopAwareness_H_
#define	_CoopAwareness_H_


#include <asn_application.h>

/* Including external dependencies */
#include "GenerationDeltaTime.h"
#include "CamParameters.h"
#include <constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* CoopAwareness */
typedef struct CoopAwareness {
	GenerationDeltaTime_t	 generationDeltaTime;
	CamParameters_t	 camParameters;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} CoopAwareness_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_CoopAwareness;

#ifdef __cplusplus
}
#endif

#endif	/* _CoopAwareness_H_ */
#include <asn_internal.h>
