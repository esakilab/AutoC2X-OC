/*
 * Generated by asn1c-0.9.24 (http://lionet.info/asn1c)
 * From ASN.1 module "CAM-PDU-Descriptions"
 * 	found in "ITS_CAM_v1.3.2.asn"
 * 	`asn1c -fnative-types -gen-PER`
 */

#include "CoopAwareness.h"

static asn_TYPE_member_t asn_MBR_CoopAwareness_1[] = {
	{ ATF_NOFLAGS, 0, offsetof(struct CoopAwareness, generationDeltaTime),
		(ASN_TAG_CLASS_CONTEXT | (0 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_GenerationDeltaTime,
		0,	/* Defer constraints checking to the member type */
		0,	/* No PER visible constraints */
		0,
		"generationDeltaTime"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct CoopAwareness, camParameters),
		(ASN_TAG_CLASS_CONTEXT | (1 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_CamParameters,
		0,	/* Defer constraints checking to the member type */
		0,	/* No PER visible constraints */
		0,
		"camParameters"
		},
};
static ber_tlv_tag_t asn_DEF_CoopAwareness_tags_1[] = {
	(ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static asn_TYPE_tag2member_t asn_MAP_CoopAwareness_tag2el_1[] = {
    { (ASN_TAG_CLASS_CONTEXT | (0 << 2)), 0, 0, 0 }, /* generationDeltaTime at 29 */
    { (ASN_TAG_CLASS_CONTEXT | (1 << 2)), 1, 0, 0 } /* camParameters at 31 */
};
static asn_SEQUENCE_specifics_t asn_SPC_CoopAwareness_specs_1 = {
	sizeof(struct CoopAwareness),
	offsetof(struct CoopAwareness, _asn_ctx),
	asn_MAP_CoopAwareness_tag2el_1,
	2,	/* Count of tags in the map */
	0, 0, 0,	/* Optional elements (not needed) */
	-1,	/* Start extensions */
	-1	/* Stop extensions */
};
asn_TYPE_descriptor_t asn_DEF_CoopAwareness = {
	"CoopAwareness",
	"CoopAwareness",
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
	asn_DEF_CoopAwareness_tags_1,
	sizeof(asn_DEF_CoopAwareness_tags_1)
		/sizeof(asn_DEF_CoopAwareness_tags_1[0]), /* 1 */
	asn_DEF_CoopAwareness_tags_1,	/* Same as above */
	sizeof(asn_DEF_CoopAwareness_tags_1)
		/sizeof(asn_DEF_CoopAwareness_tags_1[0]), /* 1 */
	0,	/* No PER visible constraints */
	asn_MBR_CoopAwareness_1,
	2,	/* Elements count */
	&asn_SPC_CoopAwareness_specs_1	/* Additional specs */
};

