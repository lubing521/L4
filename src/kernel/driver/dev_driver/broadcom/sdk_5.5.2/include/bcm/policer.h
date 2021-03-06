/*
 * $Id: policer.h,v 1.4.6.6 Broadcom SDK $
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

#ifndef __BCM_POLICER_H__
#define __BCM_POLICER_H__

#include <bcm/types.h>

/* Policer Modes. */
typedef enum bcm_policer_mode_e {
    bcmPolicerModeSrTcm,        /* RFC 2697 */
    bcmPolicerModeCommitted, 
    bcmPolicerModePeak, 
    bcmPolicerModeTrTcm,        /* RFC 2698 */
    bcmPolicerModeTrTcmDs,      /* RFC 4115 */
    bcmPolicerModeGreen, 
    bcmPolicerModePassThrough, 
    bcmPolicerModeCount 
} bcm_policer_mode_t;

/* Modes for creating a group of policers */
typedef enum bcm_policer_group_mode_e {
    bcmPolicerGroupModeSingle,      /* A single policer used for all traffic
                                       types */
    bcmPolicerGroupModeTrafficType, /* A dedicated policer per traffic type
                                       unicast, multicast, flood etc. */
    bcmPolicerGroupModeDlfAll,      /* A pair of policers where the base policer
                                       is used for dlf and the other policer is
                                       used for all traffic types */
    bcmPolicerGroupModeDlfIntPri    /* N+1 policers where the base policer is
                                       used for dlf and next N are used per Cos */
} bcm_policer_group_mode_t;

/* Supported policer stats */
typedef enum bcm_policer_stat_e {
    bcmPolicerStatGreenToGreenPackets,  /* Packet count for G-To-G transitions */
    bcmPolicerStatGreenToGreenBytes,    /* Byte count for G-To-G transitions */
    bcmPolicerStatGreenToYellowPackets, /* Packet count for G-To-Y transitions */
    bcmPolicerStatGreenToYellowBytes,   /* Byte count for G-To-Y transitions */
    bcmPolicerStatGreenToRedPackets,    /* Packet count for G-To-R transitions */
    bcmPolicerStatGreenToRedBytes,      /* Byte count for G-To-R transitions */
    bcmPolicerStatGreenToDropPackets,   /* Packet count for G-To-D transitions */
    bcmPolicerStatGreenToDropBytes,     /* Byte count for G-To-D transitions */
    bcmPolicerStatYellowToGreenPackets, /* Packet count for Y-To-G transitions */
    bcmPolicerStatYellowToGreenBytes,   /* Byte count for Y-To-G transitions */
    bcmPolicerStatYellowToYellowPackets, /* Packet count for Y-To-Y transitions */
    bcmPolicerStatYellowToYellowBytes,  /* Byte count for Y-To-Y transitions */
    bcmPolicerStatYellowToRedPackets,   /* Packet count for Y-To-R transitions */
    bcmPolicerStatYellowToRedBytes,     /* Byte count for Y-To-R transitions */
    bcmPolicerStatYellowToDropPackets,  /* Packet count for Y-To-D transitions */
    bcmPolicerStatYellowToDropBytes,    /* Byte count for Y-To-D transitions */
    bcmPolicerStatRedToGreenPackets,    /* Packet count for R-To-G transitions */
    bcmPolicerStatRedToGreenBytes,      /* Byte count for R-To-G transitions */
    bcmPolicerStatRedToYellowPackets,   /* Packet count for R-To-Y transitions */
    bcmPolicerStatRedToYellowBytes,     /* Byte count for R-To-Y transitions */
    bcmPolicerStatRedToRedPackets,      /* Packet count for R-To-R transitions */
    bcmPolicerStatRedToRedBytes,        /* Byte count for R-To-R transitions */
    bcmPolicerStatRedToDropPackets,     /* Packet count for R-To-D transitions */
    bcmPolicerStatRedToDropBytes,       /* Byte count for R-To-D transitions */
    bcmPolicerStatCount                 /* Always last */
} bcm_policer_stat_t;

#define BCM_POLICER_WITH_ID                 0x00000001
#define BCM_POLICER_REPLACE                 0x00000002
#define BCM_POLICER_COLOR_BLIND             0x00000004
#define BCM_POLICER_DROP_RED                0x00000008
#define BCM_POLICER_COLOR_MERGE_MASK        0x00000030
#define BCM_POLICER_COLOR_MERGE_AND         0x00000000
#define BCM_POLICER_COLOR_MERGE_OR          0x00000010
#define BCM_POLICER_COLOR_MERGE_DUAL        0x00000020
#define BCM_POLICER_MODE_BYTES              0x00000040
#define BCM_POLICER_MODE_PACKETS            0x00000080
#define BCM_POLICER_MAX_CKBITS_SEC_VALID    0x00000100
#define BCM_POLICER_MAX_PKBITS_SEC_VALID    0x00000200
#define BCM_POLICER_MACRO                   0x00000400
#define BCM_POLICER_EGRESS                  0x00000800 /* Allocate policer for egress usage */
#define BCM_POLICER_REGEX                   0x00001000 /* Allocate policer for regex usage */
#define BCM_POLICER_REPLACE_SHARED          0x00002000 /* Replace the profile rather than the configuration */
#define BCM_POLICER_MIXED_MICRO_MACRO       0x00004000 /* Micro policer not under the macro envelope */
#define BCM_POLICER_BW_SHARING_GROUP_START  0x00008000 /* Indicates that this policer corresponds to
                                                          the start of the bandwidth sharing group(cascade chain) */
#define BCM_POLICER_BW_SHARING_GROUP_END    0x00010000 /* Indicates that this
                                                          policer corresponds to
                                                          the end of the
                                                          bandwidth sharing
                                                          group(cascade chain) */

#define BCM_POLICER_GLOBAL_METER_SHARING_MODE_MIN 0x00000000
#define BCM_POLICER_GLOBAL_METER_SHARING_MODE_MAX 0x00000001
#define BCM_POLICER_GLOBAL_METER_SHARING_MODE_MIN_MAX 0x00000002

#define BCM_POLICER_GLOBAL_METER_ENVELOP_MICRO_FLOW 0x1
#define BCM_POLICER_GLOBAL_METER_ENVELOP_MACRO_FLOW 0x2

typedef struct bcm_policer_config_s {
    uint32 flags;               /* Service VLAN TPID value. */
    bcm_policer_mode_t mode;    /* Policer mode. */
    uint32 ckbits_sec;          /* Committed rate. */
    uint32 ckbits_burst;        /* Committed burst size. */
    uint32 pkbits_sec;          /* Peak rate. */
    uint32 pkbits_burst;        /* Peak burst size. */
    uint32 kbits_current;       /* Current size. */
} bcm_policer_config_t;

/* Initialize a policer config structure. */
extern void bcm_policer_config_t_init(
    bcm_policer_config_t *pol_cfg);

/* Initialize policer module. */
extern int bcm_policer_init(
    int unit);

/* Create a policer entry. */
extern int bcm_policer_create(
    int unit,
    bcm_policer_config_t *pol_cfg,
    bcm_policer_t *policer_id);

/* Destroy a policer entry. */
extern int bcm_policer_destroy(
    int unit, 
    bcm_policer_t policer_id);

/* Destroy all policer entries. */
extern int bcm_policer_destroy_all(
    int unit);

/* Set the config settings for a policer entry. */
extern int bcm_policer_set(
    int unit, 
    bcm_policer_t policer_id, 
    bcm_policer_config_t *pol_cfg);

/* Get the config settings for a policer entry. */
extern int bcm_policer_get(
    int unit, 
    bcm_policer_t policer_id, 
    bcm_policer_config_t *pol_cfg);

typedef int (*bcm_policer_traverse_cb)(
    int unit, 
    bcm_policer_t policer_id, 
    bcm_policer_config_t *info, 
    void *user_data);

/* 
 * Traverse all existing policer entries and call supplied callback
 * function.
 */
extern int bcm_policer_traverse(
    int unit, 
    bcm_policer_traverse_cb cb, 
    void *user_data);

/* 
 * Allocate a block of policer entries. Note that bcm_policer_set must be
 * called to setup the individual policers.
 */
extern int bcm_policer_group_create(
    int unit, 
    bcm_policer_group_mode_t mode, 
    bcm_policer_t *policer_id, 
    int *npolicers);

/* 
 * Checks if statistics collection is enabled on the specified policer
 * id.
 */
extern int bcm_policer_stat_enable_get(
    int unit, 
    bcm_policer_t policer_id, 
    int *enable);

/* Enables statistics collection on the specified policer id. */
extern int bcm_policer_stat_enable_set(
    int unit, 
    bcm_policer_t policer_id, 
    int enable);

/* Gets the specified stat */
extern int bcm_policer_stat_get(
    int unit, 
    bcm_policer_t policer_id, 
    bcm_policer_stat_t stat, 
    uint64 *value);

/* 32bit version of stat get API */
extern int bcm_policer_stat_get32(
    int unit, 
    bcm_policer_t policer_id, 
    bcm_policer_stat_t stat, 
    uint32 *value);

/* Sets the specified stat */
extern int bcm_policer_stat_set(
    int unit, 
    bcm_policer_t policer_id, 
    bcm_policer_stat_t stat, 
    uint64 value);

/* 32bit version of stat set API */
extern int bcm_policer_stat_set32(
    int unit, 
    bcm_policer_t policer_id, 
    bcm_policer_stat_t stat, 
    uint32 value);

#endif /* __BCM_POLICER_H__ */
