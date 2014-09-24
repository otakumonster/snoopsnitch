/*
 * Generated by asn1c-0.9.24 (http://lionet.info/asn1c)
 * From ASN.1 module "InformationElements"
 * 	found in "../asn/InformationElements.asn"
 * 	`asn1c -fcompound-names -fnative-types`
 */

#include "UE-Positioning-GPS-NavModelAddDataReq.h"

static int
memb_gps_Week_constraint_1(asn_TYPE_descriptor_t *td, const void *sptr,
			asn_app_constraint_failed_f *ctfailcb, void *app_key) {
	long value;
	
	if(!sptr) {
		_ASN_CTFAIL(app_key, td, sptr,
			"%s: value not given (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}
	
	value = *(const long *)sptr;
	
	if((value >= 0 && value <= 1023)) {
		/* Constraint check succeeded */
		return 0;
	} else {
		_ASN_CTFAIL(app_key, td, sptr,
			"%s: constraint failed (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}
}

static int
memb_gps_Toe_constraint_1(asn_TYPE_descriptor_t *td, const void *sptr,
			asn_app_constraint_failed_f *ctfailcb, void *app_key) {
	long value;
	
	if(!sptr) {
		_ASN_CTFAIL(app_key, td, sptr,
			"%s: value not given (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}
	
	value = *(const long *)sptr;
	
	if((value >= 0 && value <= 255)) {
		/* Constraint check succeeded */
		return 0;
	} else {
		_ASN_CTFAIL(app_key, td, sptr,
			"%s: constraint failed (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}
}

static int
memb_tToeLimit_constraint_1(asn_TYPE_descriptor_t *td, const void *sptr,
			asn_app_constraint_failed_f *ctfailcb, void *app_key) {
	long value;
	
	if(!sptr) {
		_ASN_CTFAIL(app_key, td, sptr,
			"%s: value not given (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}
	
	value = *(const long *)sptr;
	
	if((value >= 0 && value <= 15)) {
		/* Constraint check succeeded */
		return 0;
	} else {
		_ASN_CTFAIL(app_key, td, sptr,
			"%s: constraint failed (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}
}

static asn_per_constraints_t asn_PER_memb_gps_Week_constr_2 = {
	{ APC_CONSTRAINED,	 10,  10,  0,  1023 }	/* (0..1023) */,
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	0, 0	/* No PER value map */
};
static asn_per_constraints_t asn_PER_memb_gps_Toe_constr_3 = {
	{ APC_CONSTRAINED,	 8,  8,  0,  255 }	/* (0..255) */,
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	0, 0	/* No PER value map */
};
static asn_per_constraints_t asn_PER_memb_tToeLimit_constr_4 = {
	{ APC_CONSTRAINED,	 4,  4,  0,  15 }	/* (0..15) */,
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	0, 0	/* No PER value map */
};
static asn_TYPE_member_t asn_MBR_UE_Positioning_GPS_NavModelAddDataReq_1[] = {
	{ ATF_NOFLAGS, 0, offsetof(struct UE_Positioning_GPS_NavModelAddDataReq, gps_Week),
		(ASN_TAG_CLASS_CONTEXT | (0 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_NativeInteger,
		memb_gps_Week_constraint_1,
		&asn_PER_memb_gps_Week_constr_2,
		0,
		"gps-Week"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct UE_Positioning_GPS_NavModelAddDataReq, gps_Toe),
		(ASN_TAG_CLASS_CONTEXT | (1 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_NativeInteger,
		memb_gps_Toe_constraint_1,
		&asn_PER_memb_gps_Toe_constr_3,
		0,
		"gps-Toe"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct UE_Positioning_GPS_NavModelAddDataReq, tToeLimit),
		(ASN_TAG_CLASS_CONTEXT | (2 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_NativeInteger,
		memb_tToeLimit_constraint_1,
		&asn_PER_memb_tToeLimit_constr_4,
		0,
		"tToeLimit"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct UE_Positioning_GPS_NavModelAddDataReq, satDataList),
		(ASN_TAG_CLASS_CONTEXT | (3 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_SatDataList,
		0,	/* Defer constraints checking to the member type */
		0,	/* No PER visible constraints */
		0,
		"satDataList"
		},
};
static ber_tlv_tag_t asn_DEF_UE_Positioning_GPS_NavModelAddDataReq_tags_1[] = {
	(ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static asn_TYPE_tag2member_t asn_MAP_UE_Positioning_GPS_NavModelAddDataReq_tag2el_1[] = {
    { (ASN_TAG_CLASS_CONTEXT | (0 << 2)), 0, 0, 0 }, /* gps-Week at 19254 */
    { (ASN_TAG_CLASS_CONTEXT | (1 << 2)), 1, 0, 0 }, /* gps-Toe at 19257 */
    { (ASN_TAG_CLASS_CONTEXT | (2 << 2)), 2, 0, 0 }, /* tToeLimit at 19260 */
    { (ASN_TAG_CLASS_CONTEXT | (3 << 2)), 3, 0, 0 } /* satDataList at 19262 */
};
static asn_SEQUENCE_specifics_t asn_SPC_UE_Positioning_GPS_NavModelAddDataReq_specs_1 = {
	sizeof(struct UE_Positioning_GPS_NavModelAddDataReq),
	offsetof(struct UE_Positioning_GPS_NavModelAddDataReq, _asn_ctx),
	asn_MAP_UE_Positioning_GPS_NavModelAddDataReq_tag2el_1,
	4,	/* Count of tags in the map */
	0, 0, 0,	/* Optional elements (not needed) */
	-1,	/* Start extensions */
	-1	/* Stop extensions */
};
asn_TYPE_descriptor_t asn_DEF_UE_Positioning_GPS_NavModelAddDataReq = {
	"UE-Positioning-GPS-NavModelAddDataReq",
	"UE-Positioning-GPS-NavModelAddDataReq",
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
	asn_DEF_UE_Positioning_GPS_NavModelAddDataReq_tags_1,
	sizeof(asn_DEF_UE_Positioning_GPS_NavModelAddDataReq_tags_1)
		/sizeof(asn_DEF_UE_Positioning_GPS_NavModelAddDataReq_tags_1[0]), /* 1 */
	asn_DEF_UE_Positioning_GPS_NavModelAddDataReq_tags_1,	/* Same as above */
	sizeof(asn_DEF_UE_Positioning_GPS_NavModelAddDataReq_tags_1)
		/sizeof(asn_DEF_UE_Positioning_GPS_NavModelAddDataReq_tags_1[0]), /* 1 */
	0,	/* No PER visible constraints */
	asn_MBR_UE_Positioning_GPS_NavModelAddDataReq_1,
	4,	/* Elements count */
	&asn_SPC_UE_Positioning_GPS_NavModelAddDataReq_specs_1	/* Additional specs */
};
