/*
 * Generated by asn1c-0.9.24 (http://lionet.info/asn1c)
 * From ASN.1 module "InformationElements"
 * 	found in "../asn/InformationElements.asn"
 * 	`asn1c -fcompound-names -fnative-types`
 */

#include "LoggedConnectionEstablishmentFailureLocationInfo.h"

static asn_per_constraints_t asn_PER_type_location_constr_2 = {
	{ APC_CONSTRAINED,	 3,  3,  0,  4 }	/* (0..4) */,
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	0, 0	/* No PER value map */
};
static asn_TYPE_member_t asn_MBR_location_2[] = {
	{ ATF_NOFLAGS, 0, offsetof(struct LoggedConnectionEstablishmentFailureLocationInfo__location, choice.ellipsoidPoint),
		(ASN_TAG_CLASS_CONTEXT | (0 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_EllipsoidPoint,
		0,	/* Defer constraints checking to the member type */
		0,	/* No PER visible constraints */
		0,
		"ellipsoidPoint"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct LoggedConnectionEstablishmentFailureLocationInfo__location, choice.ellipsoidPointUncertCircle),
		(ASN_TAG_CLASS_CONTEXT | (1 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_EllipsoidPointUncertCircle,
		0,	/* Defer constraints checking to the member type */
		0,	/* No PER visible constraints */
		0,
		"ellipsoidPointUncertCircle"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct LoggedConnectionEstablishmentFailureLocationInfo__location, choice.ellipsoidPointUncertEllipse),
		(ASN_TAG_CLASS_CONTEXT | (2 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_EllipsoidPointUncertEllipse,
		0,	/* Defer constraints checking to the member type */
		0,	/* No PER visible constraints */
		0,
		"ellipsoidPointUncertEllipse"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct LoggedConnectionEstablishmentFailureLocationInfo__location, choice.ellipsoidPointAltitude),
		(ASN_TAG_CLASS_CONTEXT | (3 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_EllipsoidPointAltitude,
		0,	/* Defer constraints checking to the member type */
		0,	/* No PER visible constraints */
		0,
		"ellipsoidPointAltitude"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct LoggedConnectionEstablishmentFailureLocationInfo__location, choice.ellipsoidPointAltitudeEllipse),
		(ASN_TAG_CLASS_CONTEXT | (4 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_EllipsoidPointAltitudeEllipsoide,
		0,	/* Defer constraints checking to the member type */
		0,	/* No PER visible constraints */
		0,
		"ellipsoidPointAltitudeEllipse"
		},
};
static asn_TYPE_tag2member_t asn_MAP_location_tag2el_2[] = {
    { (ASN_TAG_CLASS_CONTEXT | (0 << 2)), 0, 0, 0 }, /* ellipsoidPoint at 16299 */
    { (ASN_TAG_CLASS_CONTEXT | (1 << 2)), 1, 0, 0 }, /* ellipsoidPointUncertCircle at 16300 */
    { (ASN_TAG_CLASS_CONTEXT | (2 << 2)), 2, 0, 0 }, /* ellipsoidPointUncertEllipse at 16301 */
    { (ASN_TAG_CLASS_CONTEXT | (3 << 2)), 3, 0, 0 }, /* ellipsoidPointAltitude at 16302 */
    { (ASN_TAG_CLASS_CONTEXT | (4 << 2)), 4, 0, 0 } /* ellipsoidPointAltitudeEllipse at 16304 */
};
static asn_CHOICE_specifics_t asn_SPC_location_specs_2 = {
	sizeof(struct LoggedConnectionEstablishmentFailureLocationInfo__location),
	offsetof(struct LoggedConnectionEstablishmentFailureLocationInfo__location, _asn_ctx),
	offsetof(struct LoggedConnectionEstablishmentFailureLocationInfo__location, present),
	sizeof(((struct LoggedConnectionEstablishmentFailureLocationInfo__location *)0)->present),
	asn_MAP_location_tag2el_2,
	5,	/* Count of tags in the map */
	0,
	-1	/* Extensions start */
};
static /* Use -fall-defs-global to expose */
asn_TYPE_descriptor_t asn_DEF_location_2 = {
	"location",
	"location",
	CHOICE_free,
	CHOICE_print,
	CHOICE_constraint,
	CHOICE_decode_ber,
	CHOICE_encode_der,
	CHOICE_decode_xer,
	CHOICE_encode_xer,
	CHOICE_decode_uper,
	CHOICE_encode_uper,
	CHOICE_outmost_tag,
	0,	/* No effective tags (pointer) */
	0,	/* No effective tags (count) */
	0,	/* No tags (pointer) */
	0,	/* No tags (count) */
	&asn_PER_type_location_constr_2,
	asn_MBR_location_2,
	5,	/* Elements count */
	&asn_SPC_location_specs_2	/* Additional specs */
};

static asn_TYPE_member_t asn_MBR_LoggedConnectionEstablishmentFailureLocationInfo_1[] = {
	{ ATF_NOFLAGS, 0, offsetof(struct LoggedConnectionEstablishmentFailureLocationInfo, location),
		(ASN_TAG_CLASS_CONTEXT | (0 << 2)),
		+1,	/* EXPLICIT tag at current level */
		&asn_DEF_location_2,
		0,	/* Defer constraints checking to the member type */
		0,	/* No PER visible constraints */
		0,
		"location"
		},
	{ ATF_POINTER, 1, offsetof(struct LoggedConnectionEstablishmentFailureLocationInfo, horizontalVelocity),
		(ASN_TAG_CLASS_CONTEXT | (1 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_HorizontalVelocity,
		0,	/* Defer constraints checking to the member type */
		0,	/* No PER visible constraints */
		0,
		"horizontalVelocity"
		},
};
static int asn_MAP_LoggedConnectionEstablishmentFailureLocationInfo_oms_1[] = { 1 };
static ber_tlv_tag_t asn_DEF_LoggedConnectionEstablishmentFailureLocationInfo_tags_1[] = {
	(ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static asn_TYPE_tag2member_t asn_MAP_LoggedConnectionEstablishmentFailureLocationInfo_tag2el_1[] = {
    { (ASN_TAG_CLASS_CONTEXT | (0 << 2)), 0, 0, 0 }, /* location at 16299 */
    { (ASN_TAG_CLASS_CONTEXT | (1 << 2)), 1, 0, 0 } /* horizontalVelocity at 16305 */
};
static asn_SEQUENCE_specifics_t asn_SPC_LoggedConnectionEstablishmentFailureLocationInfo_specs_1 = {
	sizeof(struct LoggedConnectionEstablishmentFailureLocationInfo),
	offsetof(struct LoggedConnectionEstablishmentFailureLocationInfo, _asn_ctx),
	asn_MAP_LoggedConnectionEstablishmentFailureLocationInfo_tag2el_1,
	2,	/* Count of tags in the map */
	asn_MAP_LoggedConnectionEstablishmentFailureLocationInfo_oms_1,	/* Optional members */
	1, 0,	/* Root/Additions */
	-1,	/* Start extensions */
	-1	/* Stop extensions */
};
asn_TYPE_descriptor_t asn_DEF_LoggedConnectionEstablishmentFailureLocationInfo = {
	"LoggedConnectionEstablishmentFailureLocationInfo",
	"LoggedConnectionEstablishmentFailureLocationInfo",
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
	asn_DEF_LoggedConnectionEstablishmentFailureLocationInfo_tags_1,
	sizeof(asn_DEF_LoggedConnectionEstablishmentFailureLocationInfo_tags_1)
		/sizeof(asn_DEF_LoggedConnectionEstablishmentFailureLocationInfo_tags_1[0]), /* 1 */
	asn_DEF_LoggedConnectionEstablishmentFailureLocationInfo_tags_1,	/* Same as above */
	sizeof(asn_DEF_LoggedConnectionEstablishmentFailureLocationInfo_tags_1)
		/sizeof(asn_DEF_LoggedConnectionEstablishmentFailureLocationInfo_tags_1[0]), /* 1 */
	0,	/* No PER visible constraints */
	asn_MBR_LoggedConnectionEstablishmentFailureLocationInfo_1,
	2,	/* Elements count */
	&asn_SPC_LoggedConnectionEstablishmentFailureLocationInfo_specs_1	/* Additional specs */
};
