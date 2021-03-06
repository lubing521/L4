/*
 * $Id: 7a714e7f55f58c5022186d244d9c154be67dfc46 $
 * 
 * $Copyright: Copyright 2012 Broadcom Corporation.
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
 * THE AMOUNT ACTUALLY PAID FOR THE SOFTWARE ITSELF OR USD 1.00,
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
    bcmPolicerModeSrTcm = 0,            /* RFC 2697 */
    bcmPolicerModeCommitted = 1, 
    bcmPolicerModePeak = 2, 
    bcmPolicerModeTrTcm = 3,            /* RFC 2698 */
    bcmPolicerModeTrTcmDs = 4,          /* RFC 4115 */
    bcmPolicerModeGreen = 5, 
    bcmPolicerModePassThrough = 6, 
    bcmPolicerModeSrTcmModified = 7, 
    bcmPolicerModeCoupledTrTcmDs = 8, 
    bcmPolicerModeCascade = 9, 
    bcmPolicerModeCoupledCascade = 10, 
    bcmPolicerModeCount = 11 
} bcm_policer_mode_t;

/* Modes for creating a group of policers */
typedef enum bcm_policer_group_mode_e {
    bcmPolicerGroupModeSingle = 0,      /* A single policer used for all traffic
                                           types */
    bcmPolicerGroupModeTrafficType = 1, /* A dedicated policer per traffic type
                                           unicast, multicast, broadcast */
    bcmPolicerGroupModeDlfAll = 2,      /* A pair of policers where the base
                                           policer is used for dlf and the other
                                           policer is used for all traffic types */
    bcmPolicerGroupModeDlfIntPri = 3,   /* N+1 policers where the base policer
                                           is used for dlf and next N are used
                                           per Cos */
    bcmPolicerGroupModeTyped = 4,       /* A dedicated policer for unknown
                                           unicast, known unicast, multicast,
                                           broadcast */
    bcmPolicerGroupModeTypedAll = 5,    /* A dedicated policer for unknown
                                           unicast, known unicast, multicast,
                                           broadcast and one for all traffic
                                           (not already policed) */
    bcmPolicerGroupModeTypedIntPri = 6, /* A dedicated policer for unknown
                                           unicast, known unicast, multicast,
                                           broadcast and N internal priority
                                           policers for traffic (not already
                                           policed) */
    bcmPolicerGroupModeSingleWithControl = 7, /* A single policer used for all traffic
                                           types with an additional policer for
                                           control traffic */
    bcmPolicerGroupModeTrafficTypeWithControl = 8, /* A dedicated policer per traffic type
                                           unicast, multicast, broadcast with an
                                           additional policer for control
                                           traffic */
    bcmPolicerGroupModeDlfAllWithControl = 9, /* A pair of policers where the base
                                           policer is used for control, the next
                                           one for dlf and the other policer is
                                           used for all traffic types */
    bcmPolicerGroupModeDlfIntPriWithControl = 10, /* N+2 policers where the base policer
                                           is used for control, the next one for
                                           dlf and next N are used per Cos */
    bcmPolicerGroupModeTypedWithControl = 11, /* A dedicated policer for control,
                                           unknown unicast, known unicast,
                                           multicast, broadcast */
    bcmPolicerGroupModeTypedAllWithControl = 12, /* A dedicated policer for control,
                                           unknown unicast, known unicast,
                                           multicast, broadcast and one for all
                                           traffic (not already policed) */
    bcmPolicerGroupModeTypedIntPriWithControl = 13, /* A dedicated policer for control,
                                           unknown unicast, known unicast,
                                           multicast, broadcast and N internal
                                           priority policers for traffic (not
                                           already policed) */
    bcmPolicerGroupModeDot1P = 14,      /* A Set of 8 policers based on outer
                                           Vlan priority */
    bcmPolicerGroupModeIntPri = 15,     /* A Set of 16 policers based on
                                           internal priority */
    bcmPolicerGroupModeIntPriCng = 16,  /* A Set of 64 policers based on
                                           internal priority and cng */
    bcmPolicerGroupModeSvpType = 17,    /* A Set of 2 policers based on SVP type */
    bcmPolicerGroupModeDscp = 18,       /* A Set of 64 policers based on IP DSCP
                                           bits */
    bcmPolicerGroupModeCascade = 19,    /*  User specified set of policers(max
                                           8), wherein excess bandwidth can
                                           overflow from high priority bucket to
                                           low priority bucket */
    bcmPolicerGroupModeCascadeWithCoupling = 20, /*  User specified set of policers(max
                                           4), wherein excess bandwidth can
                                           overflow from high priority bucket to
                                           low priority bucket and from low
                                           priority green bucket to high
                                           priority yellow bucket */
    bcmPolicerGroupModeInnerDot1P = 21, /* A Set of 8 policers based on inner
                                           Vlan priority */
    bcmPolicerGroupModeEgressSingle = 22, /* A dedicated policer for all egress
                                           traffic */
    bcmPolicerGroupModeEgressIntPri = 23, /* A dedicated policer for egress
                                           traffic for each cos level */
    bcmPolicerGroupModeShortIntPri = 24, /* A Set of 8 policers based on internal
                                           priority */
    bcmPolicerGroupModeIntPriCascade = 25, /*  Set of policers(max 8), wherein
                                           excess bandwidth can overflow from
                                           high priority bucket to low priority
                                           bucket, qualified on internal
                                           priority */
    bcmPolicerGroupModeIntPriCascadeWithCoupling = 26 /*  Set of policers(max 4), wherein
                                           excess bandwidth can overflow from
                                           high priority bucket to low priority
                                           bucket and from low priority green
                                           bucket to high priority yellow */
} bcm_policer_group_mode_t;

/* Supported policer stats */
typedef enum bcm_policer_stat_e {
    bcmPolicerStatGreenToGreenPackets = 0, /* Packet count for G-To-G transitions */
    bcmPolicerStatGreenToGreenBytes = 1, /* Byte count for G-To-G transitions */
    bcmPolicerStatGreenToYellowPackets = 2, /* Packet count for G-To-Y transitions */
    bcmPolicerStatGreenToYellowBytes = 3, /* Byte count for G-To-Y transitions */
    bcmPolicerStatGreenToRedPackets = 4, /* Packet count for G-To-R transitions */
    bcmPolicerStatGreenToRedBytes = 5,  /* Byte count for G-To-R transitions */
    bcmPolicerStatGreenToDropPackets = 6, /* Packet count for G-To-D transitions */
    bcmPolicerStatGreenToDropBytes = 7, /* Byte count for G-To-D transitions */
    bcmPolicerStatYellowToGreenPackets = 8, /* Packet count for Y-To-G transitions */
    bcmPolicerStatYellowToGreenBytes = 9, /* Byte count for Y-To-G transitions */
    bcmPolicerStatYellowToYellowPackets = 10, /* Packet count for Y-To-Y transitions */
    bcmPolicerStatYellowToYellowBytes = 11, /* Byte count for Y-To-Y transitions */
    bcmPolicerStatYellowToRedPackets = 12, /* Packet count for Y-To-R transitions */
    bcmPolicerStatYellowToRedBytes = 13, /* Byte count for Y-To-R transitions */
    bcmPolicerStatYellowToDropPackets = 14, /* Packet count for Y-To-D transitions */
    bcmPolicerStatYellowToDropBytes = 15, /* Byte count for Y-To-D transitions */
    bcmPolicerStatRedToGreenPackets = 16, /* Packet count for R-To-G transitions */
    bcmPolicerStatRedToGreenBytes = 17, /* Byte count for R-To-G transitions */
    bcmPolicerStatRedToYellowPackets = 18, /* Packet count for R-To-Y transitions */
    bcmPolicerStatRedToYellowBytes = 19, /* Byte count for R-To-Y transitions */
    bcmPolicerStatRedToRedPackets = 20, /* Packet count for R-To-R transitions */
    bcmPolicerStatRedToRedBytes = 21,   /* Byte count for R-To-R transitions */
    bcmPolicerStatRedToDropPackets = 22, /* Packet count for R-To-D transitions */
    bcmPolicerStatRedToDropBytes = 23,  /* Byte count for R-To-D transitions */
    bcmPolicerStatPackets = 24,         /* Packet count for all types of traffic
                                           policed */
    bcmPolicerStatBytes = 25,           /* Byte count for all types of traffic
                                           policed */
    bcmPolicerStatUnknownUnicastPackets = 26, /* Packet count for policed unknown
                                           unicast traffic */
    bcmPolicerStatUnknownUnicastBytes = 27, /* Byte count for policed unknown
                                           unicast traffic */
    bcmPolicerStatUnicastPackets = 28,  /* Packet count for policed unicast
                                           traffic */
    bcmPolicerStatUnicastBytes = 29,    /* Byte count for policed unicast
                                           traffic */
    bcmPolicerStatMulticastPackets = 30, /* Packet count for policed multicast
                                           traffic */
    bcmPolicerStatMulticastBytes = 31,  /* Byte count for policed multicast
                                           traffic */
    bcmPolicerStatBroadcastPackets = 32, /* Packet count for policed broadcast
                                           traffic */
    bcmPolicerStatBroadcastBytes = 33,  /* Byte count for policed broadcast
                                           traffic */
    bcmPolicerStatDropPackets = 34,     /* Packet count for all types of traffic
                                           dropped */
    bcmPolicerStatDropBytes = 35,       /* Byte count for all types of traffic
                                           dropped */
    bcmPolicerStatDropUnknownUnicastPackets = 36, /* Packet count for dropped unknown
                                           unicast traffic */
    bcmPolicerStatDropUnknownUnicastBytes = 37, /* Byte count for dropped unknown
                                           unicast traffic */
    bcmPolicerStatDropUnicastPackets = 38, /* Packet count for dropped unicast
                                           traffic */
    bcmPolicerStatDropUnicastBytes = 39, /* Byte count for dropped unicast
                                           traffic */
    bcmPolicerStatDropMulticastPackets = 40, /* Packet count for dropped multicast
                                           traffic */
    bcmPolicerStatDropMulticastBytes = 41, /* Byte count for dropped multicast
                                           traffic */
    bcmPolicerStatDropBroadcastPackets = 42, /* Packet count for dropped broadcast
                                           traffic */
    bcmPolicerStatDropBroadcastBytes = 43, /* Byte count for dropped broadcast
                                           traffic */
    bcmPolicerStatGreenPackets = 44,    /* Packet count for traffic marked green */
    bcmPolicerStatGreenBytes = 45,      /* Byte count for traffic marked green */
    bcmPolicerStatYellowPackets = 46,   /* Packet count for traffic marked
                                           yellow */
    bcmPolicerStatYellowBytes = 47,     /* Byte count for traffic marked yellow */
    bcmPolicerStatRedPackets = 48,      /* Packet count for traffic marked red */
    bcmPolicerStatRedBytes = 49,        /* Byte count for traffic marked red */
    bcmPolicerStatCount = 50            /* Always last */
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
#define BCM_POLICER_EGRESS                  0x00000800 /* Allocate policer for
                                                          egress usage */
#define BCM_POLICER_REGEX                   0x00001000 /* Allocate policer for
                                                          regex usage */
#define BCM_POLICER_REPLACE_SHARED          0x00002000 /* Replace the profile
                                                          rather than the
                                                          configuration */
#define BCM_POLICER_MIXED_MICRO_MACRO       0x00004000 /* Micro policer not
                                                          under the macro
                                                          envelope */
#define BCM_POLICER_BW_SHARING_GROUP_START  0x00008000 /* Indicates that this
                                                          policer corresponds to
                                                          the start of the
                                                          bandwidth sharing
                                                          group(cascade chain) */
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
    uint32 flags;               /* BCM_POLICER_* Flags. */
    bcm_policer_mode_t mode;    /* Policer mode. */
    uint32 ckbits_sec;          /* Committed rate. */
    uint32 max_ckbits_sec;      /* Maximum Committed rate, Applicable only for
                                   cascade mode. */
    uint32 ckbits_burst;        /* Committed burst size. */
    uint32 pkbits_sec;          /* Peak rate. */
    uint32 max_pkbits_sec;      /* Maximum Peak rate. Applicable only for
                                   cascade mode. */
    uint32 pkbits_burst;        /* Peak burst size. */
    uint32 kbits_current;       /* Current size. */
    uint32 action_id;           /* Index of the global meter action entry */
    uint32 sharing_mode;        /* Meter sharing mode in case of Macro meter of
                                   Envelop */
    uint32 entropy_id;          /* If set, indicate the configuration group the
                                   policer belongs to */
} bcm_policer_config_t;

/* Initialize a policer config structure. */
extern void bcm_policer_config_t_init(
    bcm_policer_config_t *pol_cfg);

#ifndef BCM_HIDE_DISPATCHABLE

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

#endif /* BCM_HIDE_DISPATCHABLE */

typedef int (*bcm_policer_traverse_cb)(
    int unit, 
    bcm_policer_t policer_id, 
    bcm_policer_config_t *info, 
    void *user_data);

#ifndef BCM_HIDE_DISPATCHABLE

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
 * Allocate a policer for envelop meter. Depending on the flag a micro or
 * a macro meter is allocated. Note that bcm_policer_set must be called
 * to setup the individual policers.
 */
extern int bcm_policer_envelop_create(
    int unit, 
    uint32 flag, 
    bcm_policer_t macro_flow_policer_id, 
    bcm_policer_t *policer_id);

/* 
 * Allocate a group of policers for envelop meter. Depending on the flag
 * a micro or a macro meter is allocated. Note that bcm_policer_set must
 * be called to setup the individual policers. In case of macro meter
 * only PolicerGroupModeSingle is allowed
 */
extern int bcm_policer_envelop_group_create(
    int unit, 
    uint32 flag, 
    bcm_policer_group_mode_t mode, 
    bcm_policer_t macro_flow_policer_id, 
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
    bcm_cos_t int_pri, 
    bcm_policer_stat_t stat, 
    uint64 *value);

/* 32bit version of stat get API */
extern int bcm_policer_stat_get32(
    int unit, 
    bcm_policer_t policer_id, 
    bcm_cos_t int_pri, 
    bcm_policer_stat_t stat, 
    uint32 *value);

/* Sets the specified stat */
extern int bcm_policer_stat_set(
    int unit, 
    bcm_policer_t policer_id, 
    bcm_cos_t int_pri, 
    bcm_policer_stat_t stat, 
    uint64 value);

/* 32bit version of stat set API */
extern int bcm_policer_stat_set32(
    int unit, 
    bcm_policer_t policer_id, 
    bcm_cos_t int_pri, 
    bcm_policer_stat_t stat, 
    uint32 value);

/* Attach policer action to a policer id */
extern int bcm_policer_action_attach(
    int unit, 
    bcm_policer_t policer_id, 
    uint32 action_id);

/* detach policer action from a policer id */
extern int bcm_policer_action_detach(
    int unit, 
    bcm_policer_t policer_id, 
    uint32 action_id);

/* Get the action id associated with a policer id */
extern int bcm_policer_action_attach_get(
    int unit, 
    bcm_policer_t policer_id, 
    uint32 *action_id);

#endif /* BCM_HIDE_DISPATCHABLE */

/* Global meter policer actions */
typedef enum bcm_policer_action_e {
    bcmPolicerActionGpDrop = 0,         /* Green priority drop */
    bcmPolicerActionGpDscpNew = 1,      /* Green packet change DSCP value
                                           param0: New DSCP value */
    bcmPolicerActionGpEcnNew = 2,       /* Green packet change ECN value param0:
                                           New ECN value */
    bcmPolicerActionGpPrioIntNew = 3,   /* Green packet internal priority from
                                           an argument. param0: New priority */
    bcmPolicerActionGpCngNew = 4,       /* Green packet change CNG */
    bcmPolicerActionGpVlanPrioNew = 5,  /* Green packet change vlan priority.
                                           param0: New priority */
    bcmPolicerActionYpDrop = 6,         /* Yellow priority drop */
    bcmPolicerActionYpDscpNew = 7,      /* Yellow packet change DSCP value
                                           param0: New DSCP value */
    bcmPolicerActionYpEcnNew = 8,       /* Yellow packet change ECN value
                                           param0: New ECN value */
    bcmPolicerActionYpPrioIntNew = 9,   /* Yellow packet internal priority from
                                           an argument. param0: New priority */
    bcmPolicerActionYpCngNew = 10,      /* Yellow packet change CNG */
    bcmPolicerActionYpVlanPrioNew = 11, /* Yellow packet change vlan priority.
                                           param0: New priority */
    bcmPolicerActionRpDrop = 12,        /* Red priority drop */
    bcmPolicerActionRpDscpNew = 13,     /* Red packet change DSCP value param0:
                                           New DSCP value */
    bcmPolicerActionRpEcnNew = 14,      /* Red packet change ECN value param0:
                                           New ECN value */
    bcmPolicerActionRpPrioIntNew = 15,  /* Red packet internal priority from an
                                           argument. param0: New priority */
    bcmPolicerActionRpCngNew = 16,      /* Red packet change CNG */
    bcmPolicerActionRpVlanPrioNew = 17  /* Red packet change vlan priority.
                                           param0: New priority */
} bcm_policer_action_t;

#ifndef BCM_HIDE_DISPATCHABLE

/* Create a new action entry in global meter action table */
extern int bcm_policer_action_create(
    int unit, 
    uint32 *action_id);

/* Delete an entry from meter action table */
extern int bcm_policer_action_destroy(
    int unit, 
    uint32 action_id);

/* Add an action to global meter action table entry */
extern int bcm_policer_action_add(
    int unit, 
    uint32 action_id, 
    bcm_policer_action_t action, 
    uint32 param0);

/* get action parameter for a given action */
extern int bcm_policer_action_get(
    int unit, 
    uint32 action_id, 
    bcm_policer_action_t action, 
    uint32 *param0);

#endif /* BCM_HIDE_DISPATCHABLE */

#endif /* __BCM_POLICER_H__ */
