/*
 * $Id: proxy.h,v 1.10.6.1 Broadcom SDK $
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

#ifndef __BCM_PROXY_H__
#define __BCM_PROXY_H__

#if defined(INCLUDE_L3)

#include <bcm/types.h>
#include <bcm/port.h>
#include <bcm/filter.h>
#include <bcm/field.h>

/* Proxy server operational modes. */
typedef enum bcm_proxy_mode_e {
    BCM_PROXY_MODE_NONE,        /* Invalid. */
    BCM_PROXY_MODE_LOOPBACK, 
    BCM_PROXY_MODE_HIGIG 
} bcm_proxy_mode_t;

/* bcm_proxy_proto_type_s */
typedef enum bcm_proxy_proto_type_e {
    BCM_PROXY_PROTO_INVALID, 
    BCM_PROXY_PROTO_IP4_ALL, 
    BCM_PROXY_PROTO_IP4_UCAST, 
    BCM_PROXY_PROTO_IP4_MCAST, 
    BCM_PROXY_PROTO_IP6_ALL, 
    BCM_PROXY_PROTO_IP6_UCAST, 
    BCM_PROXY_PROTO_IP6_MCAST, 
    BCM_PROXY_PROTO_MPLS_UCAST, 
    BCM_PROXY_PROTO_MPLS_MCAST, 
    BCM_PROXY_PROTO_MPLS_ALL, 
    BCM_PROXY_PROTO_IP6_IN_IP4, 
    BCM_PROXY_PROTO_IP_IN_IP,           /* IPv4-in-IPv4. */
    BCM_PROXY_PROTO_GRE_IN_IP, 
    BCM_PROXY_PROTO_UNKNOWN_IP4_UCAST,  /* IPv4 table expansion. */
    BCM_PROXY_PROTO_UNKNOWN_IP6_UCAST   /* IPv6 table expansion. */
} bcm_proxy_proto_type_t;

/* 
 * Configure a proxy client for the given unit and port. The server
 * module id and port must be valid.
 */
extern int bcm_proxy_client_set(
    int unit, 
    bcm_port_t client_port, 
    bcm_proxy_proto_type_t proto_type, 
    bcm_module_t server_modid, 
    bcm_port_t server_port, 
    int enable);

/* 
 * This API enables various kinds of lookups on XGS3 device on behalf of
 * remote legacy or XGS3 devices.
 */
extern int bcm_proxy_server_set(
    int unit, 
    bcm_port_t server_port, 
    bcm_proxy_mode_t mode, 
    int enable);

/* 
 * Get the lookup status (enabled/disabled) of XGS3 Proxy server device,
 * given the Server mode.
 */
extern int bcm_proxy_server_get(
    int unit, 
    bcm_port_t server_port, 
    bcm_proxy_mode_t mode, 
    int *enable);

#endif /* defined(INCLUDE_L3) */

#endif /* __BCM_PROXY_H__ */
