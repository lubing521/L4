/*
 * $Id: meter.h,v 1.9.6.1 Broadcom SDK $
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

#ifndef __BCM_METER_H__
#define __BCM_METER_H__

#include <bcm/types.h>

/* Initialize meter software subsystem. */
extern int bcm_meter_init(
    int unit);

/* Create a meter and FFP packet counter. */
extern int bcm_meter_create(
    int unit, 
    int port, 
    int *mid);

/* Set ingress packet interval */
extern int
bcm_meter_control_set(
	int	unit,
	uint32 value);

/* Delete a meter and FFP packet counter. */
extern int bcm_meter_delete(
    int unit, 
    int port, 
    int mid);

/* Delete all meters and FFP packet counters. */
extern int bcm_meter_delete_all(
    int unit);

/* Get the metering parameter. */
extern int bcm_meter_get(
    int unit, 
    int port, 
    int mid, 
    uint32 *kbits_sec, 
    uint32 *kbits_burst);

/* Set the metering parameter. */
extern int bcm_meter_set(
    int unit, 
    int port, 
    int mid, 
    uint32 kbits_sec, 
    uint32 kbits_burst);

/* 
 * Set both the hardware and software accumulated FFP packet counter to
 * the value.
 */
extern int bcm_ffppacketcounter_set(
    int unit, 
    int port, 
    int mid, 
    uint64 val);

/* Get the 64-bit software-accumulated packet counter value. */
extern int bcm_ffppacketcounter_get(
    int unit, 
    int port, 
    int mid, 
    uint64 *val);

/* Initialize FFP counter software subsystem. */
extern int bcm_ffpcounter_init(
    int unit);

/* Create a FFP counter. */
extern int bcm_ffpcounter_create(
    int unit, 
    int port, 
    int *ffpcounterid);

/* Delete a FFP counter. */
extern int bcm_ffpcounter_delete(
    int unit, 
    int port, 
    int ffpcounterid);

/* Delete all FFP counters. */
extern int bcm_ffpcounter_delete_all(
    int unit);

/* 
 * Set both the hardware and software accumulated FFP counter to the
 * value.
 */
extern int bcm_ffpcounter_set(
    int unit, 
    int port, 
    int ffpcounterid, 
    uint64 val);

/* Get the 64-bit software-accumulated counter value. */
extern int bcm_ffpcounter_get(
    int unit, 
    int port, 
    int ffpcounterid, 
    uint64 *val);

#endif /* __BCM_METER_H__ */
