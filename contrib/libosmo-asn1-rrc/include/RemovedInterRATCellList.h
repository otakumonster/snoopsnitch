/*
 * Generated by asn1c-0.9.24 (http://lionet.info/asn1c)
 * From ASN.1 module "InformationElements"
 * 	found in "../asn/InformationElements.asn"
 * 	`asn1c -fcompound-names -fnative-types`
 */

#ifndef	_RemovedInterRATCellList_H_
#define	_RemovedInterRATCellList_H_


#include <asn_application.h>

/* Including external dependencies */
#include <NULL.h>
#include "InterRATCellID.h"
#include <asn_SEQUENCE_OF.h>
#include <constr_SEQUENCE_OF.h>
#include <constr_CHOICE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum RemovedInterRATCellList_PR {
	RemovedInterRATCellList_PR_NOTHING,	/* No components present */
	RemovedInterRATCellList_PR_removeAllInterRATCells,
	RemovedInterRATCellList_PR_removeSomeInterRATCells,
	RemovedInterRATCellList_PR_removeNoInterRATCells
} RemovedInterRATCellList_PR;

/* RemovedInterRATCellList */
typedef struct RemovedInterRATCellList {
	RemovedInterRATCellList_PR present;
	union RemovedInterRATCellList_u {
		NULL_t	 removeAllInterRATCells;
		struct RemovedInterRATCellList__removeSomeInterRATCells {
			A_SEQUENCE_OF(InterRATCellID_t) list;
			
			/* Context for parsing across buffer boundaries */
			asn_struct_ctx_t _asn_ctx;
		} removeSomeInterRATCells;
		NULL_t	 removeNoInterRATCells;
	} choice;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} RemovedInterRATCellList_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_RemovedInterRATCellList;

#ifdef __cplusplus
}
#endif

#endif	/* _RemovedInterRATCellList_H_ */
#include <asn_internal.h>