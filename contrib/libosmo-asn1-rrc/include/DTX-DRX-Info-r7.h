/*
 * Generated by asn1c-0.9.24 (http://lionet.info/asn1c)
 * From ASN.1 module "InformationElements"
 * 	found in "../asn/InformationElements.asn"
 * 	`asn1c -fcompound-names -fnative-types`
 */

#ifndef	_DTX_DRX_Info_r7_H_
#define	_DTX_DRX_Info_r7_H_


#include <asn_application.h>

/* Including external dependencies */
#include "Uplink-DPCCH-Slot-Format-Information.h"
#include <constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Forward declarations */
struct DTX_Info;
struct DRX_Info;

/* DTX-DRX-Info-r7 */
typedef struct DTX_DRX_Info_r7 {
	struct DTX_Info	*dtx_Info	/* OPTIONAL */;
	struct DRX_Info	*drx_Info	/* OPTIONAL */;
	Uplink_DPCCH_Slot_Format_Information_t	 uplink_DPCCHSlotFormatInformation;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} DTX_DRX_Info_r7_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_DTX_DRX_Info_r7;

#ifdef __cplusplus
}
#endif

/* Referred external types */
#include "DTX-Info.h"
#include "DRX-Info.h"

#endif	/* _DTX_DRX_Info_r7_H_ */
#include <asn_internal.h>
