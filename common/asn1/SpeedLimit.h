/*
 * Generated by asn1c-0.9.24 (http://lionet.info/asn1c)
 * From ASN.1 module "ITS-Container"
 * 	found in "ITS_CAM_v1.3.2.asn"
 * 	`asn1c -fnative-types -gen-PER`
 */

#ifndef	_SpeedLimit_H_
#define	_SpeedLimit_H_


#include <asn_application.h>

/* Including external dependencies */
#include <NativeInteger.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum SpeedLimit {
	SpeedLimit_oneKmPerHour	= 1
} e_SpeedLimit;

/* SpeedLimit */
typedef long	 SpeedLimit_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_SpeedLimit;
asn_struct_free_f SpeedLimit_free;
asn_struct_print_f SpeedLimit_print;
asn_constr_check_f SpeedLimit_constraint;
ber_type_decoder_f SpeedLimit_decode_ber;
der_type_encoder_f SpeedLimit_encode_der;
xer_type_decoder_f SpeedLimit_decode_xer;
xer_type_encoder_f SpeedLimit_encode_xer;
per_type_decoder_f SpeedLimit_decode_uper;
per_type_encoder_f SpeedLimit_encode_uper;

#ifdef __cplusplus
}
#endif

#endif	/* _SpeedLimit_H_ */
#include <asn_internal.h>
