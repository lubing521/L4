/*
 * $Id: types.h,v 1.61.2.9 Broadcom SDK $
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

#ifndef __BCM_TYPES_H__
#define __BCM_TYPES_H__

#include <sal/types.h>
#include <shared/bitop.h>
#include <shared/pbmp.h>
#include <shared/types.h>
#include <shared/util.h>
#include <shared/gport.h>
#include <shared/cosq.h>

#if !defined(BCM_LOCAL_UNITS_MAX)
#define BCM_LOCAL_UNITS_MAX     16         
#endif

#define BCM_MAX_NUM_UNITS       BCM_LOCAL_UNITS_MAX 
#define BCM_UNITS_MAX           128        

#define BCM_PBMP_PORT_MAX       _SHR_PBMP_PORT_MAX 

#define BCM_PBMP_CLEAR(pbm)     _SHR_PBMP_CLEAR(pbm) 
#define BCM_PBMP_MEMBER(bmp, port)  _SHR_PBMP_MEMBER((bmp), (port)) 
#define BCM_PBMP_ITER(bmp, port)  _SHR_PBMP_ITER((bmp), (port)) 
#define BCM_PBMP_COUNT(pbm, count)  _SHR_PBMP_COUNT(pbm, count) 

#define BCM_PBMP_IS_NULL(pbm)   _SHR_PBMP_IS_NULL(pbm) 
#define BCM_PBMP_NOT_NULL(pbm)  _SHR_PBMP_NOT_NULL(pbm) 
#define BCM_PBMP_EQ(pbm_a, pbm_b)  _SHR_PBMP_EQ(pbm_a, pbm_b) 
#define BCM_PBMP_NEQ(pbm_a, pbm_b)  _SHR_PBMP_NEQ(pbm_a, pbm_b) 

/* Assignment operators */
#define BCM_PBMP_ASSIGN(dst, src)  _SHR_PBMP_ASSIGN(dst, src) 
#define BCM_PBMP_AND(pbm_a, pbm_b)  _SHR_PBMP_AND(pbm_a, pbm_b) 
#define BCM_PBMP_OR(pbm_a, pbm_b)  _SHR_PBMP_OR(pbm_a, pbm_b) 
#define BCM_PBMP_XOR(pbm_a, pbm_b)  _SHR_PBMP_XOR(pbm_a, pbm_b) 
#define BCM_PBMP_REMOVE(pbm_a, pbm_b)  _SHR_PBMP_REMOVE(pbm_a, pbm_b) 
#define BCM_PBMP_NEGATE(pbm_a, pbm_b)  _SHR_PBMP_NEGATE(pbm_a, pbm_b) 

/* Port PBMP operators */
#define BCM_PBMP_PORT_SET(pbm, port)  _SHR_PBMP_PORT_SET(pbm, port) 
#define BCM_PBMP_PORT_ADD(pbm, port)  _SHR_PBMP_PORT_ADD(pbm, port) 
#define BCM_PBMP_PORT_REMOVE(pbm, port)  _SHR_PBMP_PORT_REMOVE(pbm, port) 
#define BCM_PBMP_PORT_FLIP(pbm, port)  _SHR_PBMP_PORT_FLIP(pbm, port) 

/* Set the default tag protocol ID (TPID) for the specified port. */
typedef int bcm_port_t;

/* bcm_pbmp_t */
typedef _shr_pbmp_t bcm_pbmp_t;

/* bcm_mac_t */
typedef uint8 bcm_mac_t[6];

#define BCM_MAC_IS_MCAST(_mac_)  \
    (_mac_[0] & 0x1) 

#define BCM_MAC_IS_ZERO(_mac_)  \
    (((_mac_)[0] | (_mac_)[1] | (_mac_)[2] | \
      (_mac_)[3] | (_mac_)[4] | (_mac_)[5]) == 0) 

/* bcm_ip_t */
typedef uint32 bcm_ip_t;

/* bcm_ip6_t */
typedef uint8 bcm_ip6_t[16];

/* bcm_if_t */
typedef int bcm_if_t;

/* bcm_l4_port_t */
typedef int bcm_l4_port_t;

/* bcm_if_group_t */
typedef int bcm_if_group_t;

/* bcm_vrf_t */
typedef int bcm_vrf_t;

/* bcm_mpls_label_t */
typedef uint32 bcm_mpls_label_t;

#define BCM_MPLS_LABEL_INVALID  0xffffffff 

#define BCM_VLAN_NONE           ((bcm_vlan_t)0x0000) 
#define BCM_VLAN_ALL            ((bcm_vlan_t)0xffff) 
#define BCM_VLAN_DEFAULT        ((bcm_vlan_t)0x0001) 
#define BCM_VLAN_INVALID        ((bcm_vlan_t)0x0fff) 

#define BCM_VLAN_VALID(id)      \
    ((id) >= BCM_VLAN_DEFAULT && \
     (id) < BCM_VLAN_INVALID) 

#define BCM_VLAN_CTRL(prio, cfi, id)  \
    (((prio) & 0x007) << 13 | \
     ((cfi ) & 0x001) << 12 | \
     ((id  ) & 0xfff) << 0) 

#define BCM_VLAN_CTRL_PRIO(c)   ((c) >> 13 & 0x007) 
#define BCM_VLAN_CTRL_CFI(c)    ((c) >> 12 & 0x001) 
#define BCM_VLAN_CTRL_ID(c)     ((c) >>  0 & 0xfff) 

/* bcm_vlan_t */
typedef uint16 bcm_vlan_t;

/* bcm_ethertype_t */
typedef uint16 bcm_ethertype_t;

/* bcm_vpn_t */
typedef bcm_vlan_t bcm_vpn_t;

/* bcm_mim_vpn_t */
typedef bcm_vlan_t bcm_mim_vpn_t;

/* bcm_policer_t */
typedef int bcm_policer_t;

/* bcm_vlan_tag_t */
typedef uint32 bcm_vlan_tag_t;

#define BCM_VLAN_MIN            0          
#define BCM_VLAN_MAX            4095       
#define BCM_VLAN_COUNT          (BCM_VLAN_MAX - BCM_VLAN_MIN + 1) 

#define _BCM_MAX_VLANS          BCM_VLAN_COUNT /* For backward compatibility */

/* bcm_vlan_vector_t */
typedef uint32 bcm_vlan_vector_t[_SHR_BITDCLSIZE(BCM_VLAN_COUNT)];

#define BCM_VLAN_VEC_GET(vec, n)  SHR_BITGET(vec, n) 
#define BCM_VLAN_VEC_SET(vec, n)  SHR_BITSET(vec, n) 
#define BCM_VLAN_VEC_CLR(vec, n)  SHR_BITCLR(vec, n) 
#define BCM_VLAN_VEC_ZERO(vec)  \
    sal_memset(vec, 0, \
                    SHR_BITALLOCSIZE(BCM_VLAN_COUNT)) 

/* bcm_cos_t */
typedef int bcm_cos_t;

/* bcm_cos_queue_t */
typedef int bcm_cos_queue_t;

#define BCM_COS_MIN             0          
#define BCM_COS_MAX             7          
#define BCM_COS_COUNT           8          
#define BCM_COS_DEFAULT         4          
#define BCM_COS_INVALID         -1         

#define BCM_PRIO_MIN            0          
#define BCM_PRIO_MAX            7          
#define BCM_PRIO_RED            0x100      
#define BCM_PRIO_YELLOW         0x200      
#define BCM_PRIO_DROP_FIRST     BCM_PRIO_RED 
#define BCM_PRIO_MASK           0xff       

/* bcm_module_t */
typedef int bcm_module_t;

#define BCM_TRUNK_INVALID       ((bcm_trunk_t) -1) 

/* bcm_trunk_t */
typedef int bcm_trunk_t;

/* 
 * GPORT (generic port) definitions.
 * See shared/gport.h for more details.
 */
typedef int bcm_gport_t;

/* System-wide port types */
#define BCM_GPORT_TYPE_NONE                 _SHR_GPORT_NONE 
#define BCM_GPORT_INVALID                   _SHR_GPORT_INVALID 
#define BCM_GPORT_TYPE_LOCAL                _SHR_GPORT_TYPE_LOCAL 
#define BCM_GPORT_TYPE_MODPORT              _SHR_GPORT_TYPE_MODPORT 
#define BCM_GPORT_TYPE_TRUNK                _SHR_GPORT_TYPE_TRUNK 
#define BCM_GPORT_TYPE_BLACK_HOLE           _SHR_GPORT_TYPE_BLACK_HOLE 
#define BCM_GPORT_TYPE_LOCAL_CPU            _SHR_GPORT_TYPE_LOCAL_CPU 
#define BCM_GPORT_MPLS_PORT                 _SHR_GPORT_TYPE_MPLS_PORT 
#define BCM_GPORT_SUBPORT_GROUP             _SHR_GPORT_TYPE_SUBPORT_GROUP 
#define BCM_GPORT_SUBPORT_PORT              _SHR_GPORT_TYPE_SUBPORT_PORT 
#define BCM_GPORT_TYPE_UCAST_QUEUE_GROUP    _SHR_GPORT_TYPE_UCAST_QUEUE_GROUP 
#define BCM_GPORT_TYPE_MCAST                _SHR_GPORT_TYPE_MCAST 
#define BCM_GPORT_TYPE_MCAST_QUEUE_GROUP    _SHR_GPORT_TYPE_MCAST_QUEUE_GROUP 
#define BCM_GPORT_TYPE_SCHEDULER            _SHR_GPORT_TYPE_SCHEDULER 
#define BCM_GPORT_TYPE_SPECIAL              _SHR_GPORT_TYPE_SPECIAL 
#define BCM_GPORT_TYPE_MIRROR               _SHR_GPORT_TYPE_MIRROR 
#define BCM_GPORT_VLAN_PORT                 _SHR_GPORT_TYPE_VLAN_PORT 

#define BCM_GPORT_IS_SET(_gport)        _SHR_GPORT_IS_SET(_gport) 
#define BCM_GPORT_IS_LOCAL(_gport)      _SHR_GPORT_IS_LOCAL(_gport) 
#define BCM_GPORT_IS_MODPORT(_gport)    _SHR_GPORT_IS_MODPORT(_gport) 
#define BCM_GPORT_IS_TRUNK(_gport)      _SHR_GPORT_IS_TRUNK(_gport) 
#define BCM_GPORT_IS_UCAST_QUEUE_GROUP(_gport)  _SHR_GPORT_IS_UCAST_QUEUE_GROUP(_gport) 
#define BCM_GPORT_IS_MCAST(_gport)      _SHR_GPORT_IS_MCAST(_gport) 
#define BCM_GPORT_IS_MCAST_QUEUE_GROUP(_gport)  _SHR_GPORT_IS_MCAST_QUEUE_GROUP(_gport) 
#define BCM_GPORT_IS_BLACK_HOLE(_gport)  _SHR_GPORT_IS_BLACK_HOLE(_gport) 
#define BCM_GPORT_IS_LOCAL_CPU(_gport)  _SHR_GPORT_IS_LOCAL_CPU(_gport) 
#define BCM_GPORT_IS_MPLS_PORT(_gport)  _SHR_GPORT_IS_MPLS_PORT(_gport) 
#define BCM_GPORT_IS_SUBPORT_GROUP(_gport)  _SHR_GPORT_IS_SUBPORT_GROUP(_gport) 
#define BCM_GPORT_IS_SUBPORT_PORT(_gport)  _SHR_GPORT_IS_SUBPORT_PORT(_gport) 
#define BCM_GPORT_IS_SCHEDULER(_gport)  _SHR_GPORT_IS_SCHEDULER(_gport) 
#define BCM_GPORT_IS_DEVPORT(_gport)    _SHR_GPORT_IS_DEVPORT(_gport) 
#define BCM_GPORT_IS_SPECIAL(_gport)    _SHR_GPORT_IS_SPECIAL(_gport) 
#define BCM_GPORT_IS_MIRROR(_gport)     _SHR_GPORT_IS_MIRROR(_gport) 
#define BCM_GPORT_IS_VLAN_PORT(_gport)  _SHR_GPORT_IS_VLAN_PORT(_gport) 

#define BCM_GPORT_LOCAL_SET(_gport, _port)  \
    _SHR_GPORT_LOCAL_SET(_gport, _port) 

#define BCM_GPORT_LOCAL_GET(_gport)  \
    (!_SHR_GPORT_IS_LOCAL(_gport) ? -1 : \
    _SHR_GPORT_LOCAL_GET(_gport)) 

#define BCM_GPORT_MODPORT_SET(_gport, _module, _port)  \
    _SHR_GPORT_MODPORT_SET(_gport, _module, _port) 

#define BCM_GPORT_MODPORT_MODID_GET(_gport)  \
    (!_SHR_GPORT_IS_MODPORT(_gport) ? -1 : \
    _SHR_GPORT_MODPORT_MODID_GET(_gport)) 

#define BCM_GPORT_MODPORT_PORT_GET(_gport)  \
    (!_SHR_GPORT_IS_MODPORT(_gport) ? -1 : \
    _SHR_GPORT_MODPORT_PORT_GET(_gport)) 

#define BCM_GPORT_TRUNK_SET(_gport, _trunk_id)  \
    _SHR_GPORT_TRUNK_SET(_gport, _trunk_id) 

#define BCM_GPORT_TRUNK_GET(_gport)  \
    (!_SHR_GPORT_IS_TRUNK(_gport) ? BCM_TRUNK_INVALID : \
    _SHR_GPORT_TRUNK_GET(_gport)) 

#define BCM_GPORT_UCAST_QUEUE_GROUP_SET(_gport, _qid)  \
         _SHR_GPORT_UCAST_QUEUE_GROUP_SET(_gport, _qid) 

#define BCM_GPORT_UCAST_QUEUE_GROUP_SYSQID_SET(_gport, _sysport_id, _qid)  \
         _SHR_GPORT_UCAST_QUEUE_GROUP_SYSQID_SET(_gport, _sysport_id, _qid) 

#define BCM_GPORT_UCAST_QUEUE_GROUP_SYSPORTID_GET(_gport)  \
            (!_SHR_GPORT_IS_UCAST_QUEUE_GROUP(_gport) ? -1 :  \
        _SHR_GPORT_UCAST_QUEUE_GROUP_SYSPORTID_GET(_gport))
 

#define BCM_GPORT_UCAST_QUEUE_GROUP_QID_GET(_gport)  \
            (!_SHR_GPORT_IS_UCAST_QUEUE_GROUP(_gport) ? -1 :  \
        _SHR_GPORT_UCAST_QUEUE_GROUP_QID_GET(_gport))
 

#define BCM_GPORT_MCAST_SET(_gport, _mcast_id)  \
        (_SHR_GPORT_MCAST_SET(_gport, _mcast_id))
 

#define BCM_GPORT_MCAST_GET(_gport)  \
            (!_SHR_GPORT_IS_MCAST(_gport) ? -1 :  \
        _SHR_GPORT_MCAST_GET(_gport))
 

#define BCM_GPORT_MCAST_DS_ID_SET(_gport, _ds_id)  \
     _SHR_GPORT_MCAST_DS_ID_SET(_gport,_ds_id)
 

#define BCM_GPORT_MCAST_DS_ID_GET(_gport)  \
            (!_SHR_GPORT_IS_MCAST(_gport) ? -1 :  \
        _SHR_GPORT_MCAST_DS_ID_GET(_gport))
 

#define BCM_GPORT_MCAST_QUEUE_GROUP_SET(_gport, _queue_group_id)  \
	 _SHR_GPORT_MCAST_QUEUE_GROUP_SET(_gport, _queue_group_id)
 

#define BCM_GPORT_UCAST_MCAST_QUEUE_GROUP_GET(_gport)  \
            (!_SHR_GPORT_IS_MCAST_QUEUE_GROUP(_gport) ? -1 :  \
        _SHR_GPORT_MCAST_QUEUE_GROUP_GET(_gport))
 

#define BCM_GPORT_MCAST_QUEUE_GROUP_SYSQID_SET(_gport, _sysport_id, _qid)  \
     _SHR_GPORT_MCAST_QUEUE_GROUP_SYSQID_SET(_gport, _sysport_id, _qid)
 

#define BCM_GPORT_MCAST_QUEUE_GROUP_SYSPORTID_GET(_gport)  \
            (!_SHR_GPORT_IS_MCAST_QUEUE_GROUP(_gport) ? -1 :  \
        _SHR_GPORT_MCAST_QUEUE_GROUP_SYSPORTID_GET(_gport))
 

#define BCM_GPORT_MCAST_QUEUE_GROUP_QID_GET(_gport)  \
            (!_SHR_GPORT_IS_MCAST_QUEUE_GROUP(_gport) ? -1 :  \
        _SHR_GPORT_MCAST_QUEUE_GROUP_QID_GET(_gport))
 

#define BCM_GPORT_SCHEDULER_SET(_gport, _scheduler_id)  \
    _SHR_GPORT_SCHEDULER_SET(_gport, _scheduler_id) 

#define BCM_GPORT_SCHEDULER_GET(_gport)  \
    _SHR_GPORT_SCHEDULER_GET(_gport) 

#define BCM_GPORT_MPLS_PORT_ID_SET(_gport, _id)  \
    _SHR_GPORT_MPLS_PORT_ID_SET(_gport, _id) 

#define BCM_GPORT_MPLS_PORT_ID_GET(_gport)  \
    (!_SHR_GPORT_IS_MPLS_PORT(_gport) ? -1 :  \
    _SHR_GPORT_MPLS_PORT_ID_GET(_gport)) 

#define BCM_GPORT_VLAN_PORT_ID_SET(_gport, _id)  \
    _SHR_GPORT_VLAN_PORT_ID_SET(_gport, _id) 

#define BCM_GPORT_VLAN_PORT_ID_GET(_gport)  \
    (!_SHR_GPORT_IS_VLAN_PORT(_gport) ? -1 :  \
    _SHR_GPORT_VLAN_PORT_ID_GET(_gport)) 

#define BCM_GPORT_SUBPORT_GROUP_SET(_gport, _id)  \
    _SHR_GPORT_SUBPORT_GROUP_SET(_gport, _id) 

#define BCM_GPORT_SUBPORT_GROUP_GET(_gport)  \
    (!_SHR_GPORT_IS_SUBPORT_GROUP(_gport) ? -1 :  \
    _SHR_GPORT_SUBPORT_GROUP_GET(_gport)) 

#define BCM_GPORT_SUBPORT_PORT_SET(_gport, _id)  \
    _SHR_GPORT_SUBPORT_PORT_SET(_gport, _id) 

#define BCM_GPORT_SUBPORT_PORT_GET(_gport)  \
    (!_SHR_GPORT_IS_SUBPORT_PORT(_gport) ? -1 :  \
    _SHR_GPORT_SUBPORT_PORT_GET(_gport)) 

/* Multicast distribution set */
typedef int bcm_fabric_distribution_t;

/* Failover Object */
typedef int bcm_failover_t;

#define BCM_GPORT_DEVPORT_SET(_gport, _device, _port)  \
    _SHR_GPORT_DEVPORT_SET(_gport, _device, _port) 

#define BCM_GPORT_DEVPORT_DEVID_GET(_gport)  \
    (!_SHR_GPORT_IS_DEVPORT(_gport) ? -1 : \
    _SHR_GPORT_DEVPORT_DEVID_GET(_gport)) 

#define BCM_GPORT_DEVPORT_PORT_GET(_gport)  \
    (!_SHR_GPORT_IS_DEVPORT(_gport) ? -1 : \
    _SHR_GPORT_DEVPORT_PORT_GET(_gport)) 

#define BCM_GPORT_LOCAL_CPU     _SHR_GPORT_LOCAL_CPU 

#define BCM_GPORT_SPECIAL(_value)  \
    _SHR_GPORT_SPECIAL(_value) 

#define BCM_GPORT_SPECIAL_SET(_gport, _value)  \
    _SHR_GPORT_SPECIAL_SET(_gport, _value) 

#define BCM_GPORT_SPECIAL_GET(_gport)  \
    (!_SHR_GPORT_IS_SPECIAL(_gport) ? -1 : \
    _SHR_GPORT_SPECIAL_GET(_gport)) 

#define BCM_GPORT_MIRROR_SET(_gport, _value)  \
    _SHR_GPORT_MIRROR_SET(_gport, _value) 

#define BCM_GPORT_MIRROR_GET(_gport)  \
    (!_SHR_GPORT_IS_MIRROR(_gport) ? -1 : \
    _SHR_GPORT_MIRROR_GET(_gport)) 

#define BCM_COSQ_CONTROL_FABRIC_CONNECT_MIN_UTILIZATION_SET(whole_utilization, fractional_utilization)  \
    _SHR_COSQ_CONTROL_FABRIC_CONNECT_MIN_UTILIZATION_SET(whole_utilization, fractional_utilization) 

#define BCM_COSQ_CONTROL_FABRIC_CONNECT_MIN_UTILIZATION_WHOLE_GET(utilization)  \
    _SHR_COSQ_CONTROL_FABRIC_CONNECT_MIN_UTILIZATION_WHOLE_GET(utilization) 

#define BCM_COSQ_CONTROL_FABRIC_CONNECT_MIN_UTILIZATION_FRACTIONAL_GET(utilization)  \
    _SHR_COSQ_CONTROL_FABRIC_CONNECT_MIN_UTILIZATION_FRACTIONAL_GET(utilization) 

#define BCM_STG_DEFAULT         ((bcm_stg_t) 1) 
#define BCM_STG_INVALID         ((bcm_stg_t) -1) 

/* bcm_stg_t */
typedef int bcm_stg_t;

/* bcm_dma_chan_t */
typedef _shr_dma_chan_t bcm_dma_chan_t;

/* bcm_mod_port_t */
typedef struct bcm_mod_port_s {
    bcm_module_t mod; 
    bcm_port_t port; 
} bcm_mod_port_t;

/* bcm_color_t */
typedef enum bcm_color_e {
    bcmColorGreen, 
    bcmColorYellow, 
    bcmColorRed, 
    bcmColorDropFirst = bcmColorRed, 
    bcmColorCount 
} bcm_color_t;

#if defined(LE_HOST)
#define bcm_htonl(_l)           _shr_swap32(_l) 
#define bcm_htons(_s)           _shr_swap16(_s) 
#define bcm_ntohl(_l)           _shr_swap32(_l) 
#define bcm_ntohs(_s)           _shr_swap16(_s) 
#else
#define bcm_htonl(_l)           (_l)       
#define bcm_htons(_s)           (_s)       
#define bcm_ntohl(_l)           (_l)       
#define bcm_ntohs(_s)           (_s)       
#endif

/* bcm_unit_bmp_t */
typedef uint32 bcm_unit_bmp_t[_SHR_BITDCLSIZE(BCM_UNITS_MAX)];

#define BCM_UNIT_BMP_CLEAR(_bmp)  \
    sal_memset(_bmp, 0, \
    SHR_BITALLOCSIZE(BCM_UNITS_MAX)) 

#define BCM_UNIT_BMP_ADD(_bmp, _u)  SHR_BITSET(_bmp, _u) 
#define BCM_UNIT_BMP_REMOVE(_bmp, _u)  SHR_BITCLR(_bmp, _u) 
#define BCM_UNIT_BMP_TEST(_bmp, _u)  SHR_BITGET(_bmp, _u) 

/* bcm_unit_valid */
extern int bcm_unit_valid(
    int unit);

/* bcm_unit_local */
extern int bcm_unit_local(
    int unit);

/* bcm_unit_max */
extern int bcm_unit_max(
    void );

/* bcm_unit_remote */
extern int bcm_unit_remote(
    int unit);

/* bcm_unit_remote_unit_get */
extern int bcm_unit_remote_unit_get(
    int unit, 
    int *remunit);

/* bcm_unit_subtype_get */
extern int bcm_unit_subtype_get(
    int unit, 
    char *subtype, 
    int maxlen);

#define BCM_FOREACH_LOCAL_UNIT(_unit)  \
    for (_unit = 0; _unit < bcm_unit_max(); _unit++) \
        if (bcm_unit_local(_unit)) 

#define BCM_FOREACH_UNIT(_unit)  \
    for (_unit = 0; _unit < bcm_unit_max(); _unit++) \
        if (bcm_unit_valid(_unit)) 

#endif /* __BCM_TYPES_H__ */
