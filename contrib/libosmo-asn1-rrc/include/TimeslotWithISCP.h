/*
 * Generated by asn1c-0.9.24 (http://lionet.info/asn1c)
 * From ASN.1 module "InformationElements"
 * 	found in "../asn/InformationElements.asn"
 * 	`asn1c -fcompound-names -fnative-types`
 */

#ifndef	_TimeslotWithISCP_H_
#define	_TimeslotWithISCP_H_


#include <asn_application.h>

/* Including external dependencies */
#include "TimeslotNumber.h"
#include "TimeslotISCP.h"
#include <constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* TimeslotWithISCP */
typedef struct TimeslotWithISCP {
	TimeslotNumber_t	 timeslot;
	TimeslotISCP_t	 timeslotISCP;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} TimeslotWithISCP_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_TimeslotWithISCP;

#ifdef __cplusplus
}
#endif

#endif	/* _TimeslotWithISCP_H_ */
#include <asn_internal.h>
