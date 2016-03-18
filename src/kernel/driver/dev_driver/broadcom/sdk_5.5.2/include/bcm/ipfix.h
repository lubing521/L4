/*
 * $Id: ipfix.h,v 1.9.6.1 Broadcom SDK $
 * 
 * $Copyright: Copyright 2008 Broadcom Corporation.
 * This program is the proprietary software of Broadcom Corporation
 * and/or its licensors, and may only be used, duplicated, modified
 * or distributed pursuant to the terms and conditions of a separate,
 * written license agreement executed between you and Broadcom
 * (an "Authorized License").  Except as set forth in an Authorized
 * License, Broadcom grants no license (express or implied), right
 * to use, or waiver of any kind with respect to the Software, and
 * Broadcom expressly reserves all rights in and to the Software
 * and all intellectual property rights therein.  IF YOU HAVE
 * NO AUTHORIZED LICENSE, THEN YOU HAVE NO RIGHT TO USE THIS SOFTWARE
 * IN ANY WAY, AND SHOULD IMMEDIATELY NOTIFY BROADCOM AND DISCONTINUE
 * ALL USE OF THE SOFTWARE.  
 *  
 * Except as expressly set forth in the Authorized License,
 *  
 * 1.     This program, including its structure, sequence and organization,
 * constitutes the valuable trade secrets of Broadcom, and you shall use
 * all reasonable efforts to protect the confidentiality thereof,
 * and to use this information only in connection with your use of
 * Broadcom integrated circuit products.
 *  
 * 2.     TO THE MAXIMUM EXTENT PERMITTED BY LAW, THE SOFTWARE IS
 * PROVIDED "AS IS" AND WITH ALL FAULTS AND BROADCOM MAKES NO PROMISES,
 * REPRESENTATIONS OR WARRANTIES, EITHER EXPRESS, IMPLIED, STATUTORY,
 * OR OTHERWISE, WITH RESPECT TO THE SOFTWARE.  BROADCOM SPECIFICALLY
 * DISCLAIMS ANY AND ALL IMPLIED WARRANTIES OF TITLE, MERCHANTABILITY,
 * NONINFRINGEMENT, FITNESS FOR A PARTICULAR PURPOSE, LACK OF VIRUSES,
 * ACCURACY OR COMPLETENESS, QUIET ENJOYMENT, QUIET POSSESSION OR
 * CORRESPONDENCE TO DESCRIPTION. YOU ASSUME THE ENTIRE RISK ARISING
 * OUT OF USE OR PERFORMANCE OF THE SOFTWARE.
 * 
 * 3.     TO THE MAXIMUM EXTENT PERMITTED BY LAW, IN NO EVENT SHALL
 * BROADCOM OR ITS LICENSORS BE LIABLE FOR (i) CONSEQUENTIAL,
 * INCIDENTAL, SPECIAL, INDIRECT, OR EXEMPLARY DAMAGES WHATSOEVER
 * ARISING OUT OF OR IN ANY WAY RELATING TO YOUR USE OF OR INABILITY
 * TO USE THE SOFTWARE EVEN IF BROADCOM HAS BEEN ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGES; OR (ii) ANY AMOUNT IN EXCESS OF
 * THE AMOUNT ACTUALLY PAID FOR THE SOFTWARE ITSELF OR U.S. $1,
 * WHICHEVER IS GREATER. THESE LIMITATIONS SHALL APPLY NOTWITHSTANDING
 * ANY FAILURE OF ESSENTIAL PURPOSE OF ANY LIMITED REMEDY.$
 * 
 * DO NOT EDIT THIS FILE!
 * This file is auto-generated.
 * Edits to this file will be lost when it is regenerated.
 */

#ifndef __BCM_IPFIX_H__
#define __BCM_IPFIX_H__

#include <bcm/types.h>

#define BCM_IPFIX_DSCP_MASK_COUNT   64         

typedef enum bcm_ipfix_stage_e {
    BCM_IPFIX_STAGE_INGRESS, 
    BCM_IPFIX_STAGE_EGRESS 
} bcm_ipfix_stage_t;

/* Flags for for bcm_ipfix_data_t. */
#define BCM_IPFIX_DATA_VLAN_TAGGED          0x0001     
#define BCM_IPFIX_DATA_TYPE_L2              0x0002     
#define BCM_IPFIX_DATA_TYPE_IP4             0x0004     
#define BCM_IPFIX_DATA_TYPE_IP6             0x0008     
#define BCM_IPFIX_DATA_REASON_FLOW_TIMEOUT  0x0010     
#define BCM_IPFIX_DATA_REASON_FLOW_END      0x0020     
#define BCM_IPFIX_DATA_REASON_FLOW          0x0040     
#define BCM_IPFIX_DATA_REASON_COUNT         0x0080     
#define BCM_IPFIX_DATA_REASON_TIMESTAMP     0x0100     
#define BCM_IPFIX_DATA_TYPE_MASK            0x000e     
#define BCM_IPFIX_DATA_REASON_MASK          0x01f0     

/* bcm_ipfix_data_s */
typedef struct bcm_ipfix_data_s {
    bcm_ipfix_stage_t stage;    /* Ingress or egress. */
    uint32 flags;               /* Type and reason. */
    bcm_port_t port;            /* L2: port. */
    bcm_vlan_t vlan;            /* L2: VLAN identifier. */
    uint16 vlan_prio;           /* L2: VLAN priority. */
    uint16 ether_type;          /* L2: type in ethernet II frame or 802.1Q tag. */
    bcm_mac_t src_mac_addr;     /* L2: source MAC address. */
    bcm_mac_t dst_mac_addr;     /* L2: destination MAC address. */
    bcm_ip_t src_ip4_addr;      /* IPv4: source IP address. */
    bcm_ip_t dst_ip4_addr;      /* IPv4: destination IP address. */
    bcm_ip6_t src_ip6_addr;     /* IPv6: source IP address. */
    bcm_ip6_t dst_ip6_addr;     /* IPv6: destination IP address. */
    uint16 ip_protocol;         /* IPv4: protocol; IPv6: next header. */
    uint16 tos;                 /* IPv4: type of service; IPv6: traffic class. */
    uint32 ip6_flow_label;      /* IPv6: flow label. */
    uint16 l4_src_port;         /* First 16 bits of L4 header such as TCP source
                                   port or ICMP type and code. */
    uint16 l4_dst_port;         /* Second 16 bits of L4 header such as TCP
                                   destination port. */
    int tunnel_idx;             /* IP: L3 tunnel index. */
    uint32 start_timestamp;     /* Session information. */
    uint32 last_timestamp;      /* Session information. */
    uint32 byte_count;          /* Session information. */
    uint32 pkt_count;           /* Session information. */
} bcm_ipfix_data_t;

#define BCM_IPFIX_CONFIG_ENABLE_NON_IP      0x00000001 
#define BCM_IPFIX_CONFIG_ENABLE_IP4         0x00000002 
#define BCM_IPFIX_CONFIG_ENABLE_IP6         0x00000004 
#define BCM_IPFIX_CONFIG_TCP_END_DETECT     0x00000008 
#define BCM_IPFIX_CONFIG_RECORD_NON_DISCARD_PKT 0x00000010 
#define BCM_IPFIX_CONFIG_RECORD_DISCARD_PKT 0x00000020 
#define BCM_IPFIX_CONFIG_KEY_IP4_USE_L2     0x00000040 
#define BCM_IPFIX_CONFIG_KEY_IP6_USE_L2     0x00000080 
#define BCM_IPFIX_CONFIG_KEY_SRC_IP         0x00000100 
#define BCM_IPFIX_CONFIG_KEY_DST_IP         0x00000200 
#define BCM_IPFIX_CONFIG_KEY_IP_PROT        0x00000400 
#define BCM_IPFIX_CONFIG_KEY_IP_DSCP        0x00000800 
#define BCM_IPFIX_CONFIG_KEY_IP_ECN         0x00001000 
#define BCM_IPFIX_CONFIG_KEY_L4_SRC_PORT    0x00002000 
#define BCM_IPFIX_CONFIG_KEY_L4_DST_PORT    0x00004000 
#define BCM_IPFIX_CONFIG_KEY_IP6_FLOW       0x00008000 
#define BCM_IPFIX_CONFIG_KEY_ICMP_TYPE      0x00010000 
#define BCM_IPFIX_CONFIG_KEY_ICMP_CODE      0x00020000 
#define BCM_IPFIX_CONFIG_KEY_MACDA          0x00040000 
#define BCM_IPFIX_CONFIG_KEY_MACSA          0x00080000 
#define BCM_IPFIX_CONFIG_KEY_VLAN_ID        0x00100000 
#define BCM_IPFIX_CONFIG_KEY_VLAN_PRI       0x00200000 
#define BCM_IPFIX_CONFIG_KEY_ETHER_TYPE     0x00400000 
#define BCM_IPFIX_CONFIG_KEY_VLAN_TAGGED    0x00800000 
#define BCM_IPFIX_CONFIG_ENABLE_MASK        0x00000007 
#define BCM_IPFIX_CONFIG_KEY_MASK           0x00ffffc0 

/* bcm_ipfix_config_s */
typedef struct bcm_ipfix_config_s {
    uint32 flags;                       /* Fields select and other flags. */
    uint8 dscp_mask[BCM_IPFIX_DSCP_MASK_COUNT]; /* DSCP value translation mapping. */
    bcm_ip_t src_ip4_mask;              /* Mask to map IPv4 address to key
                                           value. */
    bcm_ip_t dst_ip4_mask;              /* Mask to map IPv4 address to key
                                           value. */
    bcm_ip_t tunnel_src_ip4_mask;       /* Mask to map IPv4 address to key
                                           value. */
    bcm_ip_t tunnel_dst_ip4_mask;       /* Mask to map IPv4 address to key
                                           value. */
    bcm_ip6_t src_ip6_mask;             /* Mask to map IPv6 address to key
                                           value. */
    bcm_ip6_t dst_ip6_mask;             /* Mask to map IPv6 address to key
                                           value. */
    bcm_ip6_t tunnel_src_ip6_mask;      /* Mask to map IPv6 address to key
                                           value. */
    bcm_ip6_t tunnel_dst_ip6_mask;      /* Mask to map IPv6 address to key
                                           value. */
    uint32 entry_limit;                 /* Maximum number of flow entry
                                           collected for the port. */
    uint32 min_time;                    /* The flow will not be exported unless
                                           the flow has been established for
                                           more than min_time (unit is 10 ms). */
    uint32 max_idle_time;               /* The flow will be exported and
                                           terminated if idle for more than
                                           max_idle_time (unit is 10 ms). */
    uint32 sample_rate;                 /* Collect one packet info for every
                                           sample_rate packets. */
} bcm_ipfix_config_t;

/* bcm_ipfix_callback_t */
typedef void (*bcm_ipfix_callback_t)(
    int unit, 
    bcm_ipfix_data_t *info, 
    void *userdata);

/* bcm_ipfix_config_t_init */
extern void bcm_ipfix_config_t_init(
    bcm_ipfix_config_t *config);

/* bcm_ipfix_register */
extern int bcm_ipfix_register(
    int unit, 
    bcm_ipfix_callback_t callback, 
    void *userdata);

/* bcm_ipfix_unregister */
extern int bcm_ipfix_unregister(
    int unit, 
    bcm_ipfix_callback_t callback, 
    void *userdata);

/* bcm_ipfix_config_set */
extern int bcm_ipfix_config_set(
    int unit, 
    bcm_ipfix_stage_t stage, 
    bcm_port_t port, 
    bcm_ipfix_config_t *config);

/* bcm_ipfix_config_get */
extern int bcm_ipfix_config_get(
    int unit, 
    bcm_ipfix_stage_t stage, 
    bcm_port_t port, 
    bcm_ipfix_config_t *config);

#endif /* __BCM_IPFIX_H__ */
