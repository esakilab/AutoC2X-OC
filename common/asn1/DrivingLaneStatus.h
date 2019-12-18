/*
 * Generated by asn1c-0.9.28 (http://lionet.info/asn1c)
 * From ASN.1 module "ITS-Container"
 * 	found in "its_facilities_pdu_all.asn"
 * 	`asn1c -fnative-types -gen-PER -pdu=auto`
 */

#ifndef	_DrivingLaneStatus_H_
#define	_DrivingLaneStatus_H_


#include <asn_application.h>

/* Including external dependencies */
#include <BIT_STRING.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum DrivingLaneStatus {
	DrivingLaneStatus_outermostLaneClosed	= 1,
	DrivingLaneStatus_secondLaneFromOutsideClosed	= 2
} e_DrivingLaneStatus;

/* DrivingLaneStatus */
typedef BIT_STRING_t	 DrivingLaneStatus_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_DrivingLaneStatus;
asn_struct_free_f DrivingLaneStatus_free;
asn_struct_print_f DrivingLaneStatus_print;
asn_constr_check_f DrivingLaneStatus_constraint;
ber_type_decoder_f DrivingLaneStatus_decode_ber;
der_type_encoder_f DrivingLaneStatus_encode_der;
xer_type_decoder_f DrivingLaneStatus_decode_xer;
xer_type_encoder_f DrivingLaneStatus_encode_xer;
per_type_decoder_f DrivingLaneStatus_decode_uper;
per_type_encoder_f DrivingLaneStatus_encode_uper;

#ifdef __cplusplus
}
#endif

#endif	/* _DrivingLaneStatus_H_ */
#include <asn_internal.h>
