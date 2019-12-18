/*
 * Generated by asn1c-0.9.28 (http://lionet.info/asn1c)
 * From ASN.1 module "ITS-Container"
 * 	found in "its_facilities_pdu_all.asn"
 * 	`asn1c -fnative-types -gen-PER -pdu=auto`
 */

#ifndef	_AccelerationControl_H_
#define	_AccelerationControl_H_


#include <asn_application.h>

/* Including external dependencies */
#include <BIT_STRING.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum AccelerationControl {
	AccelerationControl_brakePedalEngaged	= 0,
	AccelerationControl_gasPedalEngaged	= 1,
	AccelerationControl_emergencyBrakeEngaged	= 2,
	AccelerationControl_collisionWarningEngaged	= 3,
	AccelerationControl_accEngaged	= 4,
	AccelerationControl_cruiseControlEngaged	= 5,
	AccelerationControl_speedLimiterEngaged	= 6
} e_AccelerationControl;

/* AccelerationControl */
typedef BIT_STRING_t	 AccelerationControl_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_AccelerationControl;
asn_struct_free_f AccelerationControl_free;
asn_struct_print_f AccelerationControl_print;
asn_constr_check_f AccelerationControl_constraint;
ber_type_decoder_f AccelerationControl_decode_ber;
der_type_encoder_f AccelerationControl_encode_der;
xer_type_decoder_f AccelerationControl_decode_xer;
xer_type_encoder_f AccelerationControl_encode_xer;
per_type_decoder_f AccelerationControl_decode_uper;
per_type_encoder_f AccelerationControl_encode_uper;

#ifdef __cplusplus
}
#endif

#endif	/* _AccelerationControl_H_ */
#include <asn_internal.h>
