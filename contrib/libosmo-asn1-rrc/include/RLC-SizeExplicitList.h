/*
 * Generated by asn1c-0.9.24 (http://lionet.info/asn1c)
 * From ASN.1 module "InformationElements"
 * 	found in "../asn/InformationElements.asn"
 * 	`asn1c -fcompound-names -fnative-types`
 */

#ifndef	_RLC_SizeExplicitList_H_
#define	_RLC_SizeExplicitList_H_


#include <asn_application.h>

/* Including external dependencies */
#include <asn_SEQUENCE_OF.h>
#include <constr_SEQUENCE_OF.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Forward declarations */
struct RLC_SizeInfo;

/* RLC-SizeExplicitList */
typedef struct RLC_SizeExplicitList {
	A_SEQUENCE_OF(struct RLC_SizeInfo) list;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} RLC_SizeExplicitList_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_RLC_SizeExplicitList;

#ifdef __cplusplus
}
#endif

/* Referred external types */
#include "RLC-SizeInfo.h"

#endif	/* _RLC_SizeExplicitList_H_ */
#include <asn_internal.h>
