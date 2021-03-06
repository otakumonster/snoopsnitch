/*
 * Generated by asn1c-0.9.24 (http://lionet.info/asn1c)
 * From ASN.1 module "InformationElements"
 * 	found in "../asn/InformationElements.asn"
 * 	`asn1c -fcompound-names -fnative-types`
 */

#ifndef	_MAC_ehs_QueueIdDCHandHSDSCH_H_
#define	_MAC_ehs_QueueIdDCHandHSDSCH_H_


#include <asn_application.h>

/* Including external dependencies */
#include "TransportChannelIdentity.h"
#include "MAC-ehs-QueueId.h"
#include <constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* MAC-ehs-QueueIdDCHandHSDSCH */
typedef struct MAC_ehs_QueueIdDCHandHSDSCH {
	TransportChannelIdentity_t	 dch_transport_ch_id;
	MAC_ehs_QueueId_t	 hsdsch_mac_ehs_QueueId;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} MAC_ehs_QueueIdDCHandHSDSCH_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_MAC_ehs_QueueIdDCHandHSDSCH;

#ifdef __cplusplus
}
#endif

#endif	/* _MAC_ehs_QueueIdDCHandHSDSCH_H_ */
#include <asn_internal.h>
