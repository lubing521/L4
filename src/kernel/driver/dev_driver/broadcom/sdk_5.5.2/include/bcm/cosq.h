/*
 * $Id: cosq.h,v 1.27.2.6 Broadcom SDK $
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

#ifndef __BCM_COSQ_H__
#define __BCM_COSQ_H__

#include <bcm/types.h>
#include <bcm/fabric.h>

/* Initialize the COSQ subsystem. */
extern int bcm_cosq_init(
    int unit);

/* De-initialize the COSQ subsystem. */
extern int bcm_cosq_detach(
    int unit);

/* Configure the number of Class of Service Queues (COSQs). */
extern int bcm_cosq_config_set(
    int unit, 
    int numq);

/* Configure the number of Class of Service Queues (COSQs). */
extern int bcm_cosq_config_get(
    int unit, 
    int *numq);

/* Set the mapping from internal priority to COS queue. */
extern int bcm_cosq_mapping_set(
    int unit, 
    bcm_cos_t priority, 
    bcm_cos_queue_t cosq);

/* Get the mapping from internal priority to COS queue. */
extern int bcm_cosq_mapping_get(
    int unit, 
    bcm_cos_t priority, 
    bcm_cos_queue_t *cosq);

/* Set the mapping from internal priority to COS queue. */
extern int bcm_cosq_port_mapping_set(
    int unit, 
    bcm_port_t port, 
    bcm_cos_t priority, 
    bcm_cos_queue_t cosq);

/* Get the mapping from internal priority to COS queue. */
extern int bcm_cosq_port_mapping_get(
    int unit, 
    bcm_port_t port, 
    bcm_cos_t priority, 
    bcm_cos_queue_t *cosq);

/* Class of Service policies. */
#define BCM_COSQ_STRICT                 0x01       /* Weights are ignored. */
#define BCM_COSQ_ROUND_ROBIN            0x02       /* Weights are ignored. */
#define BCM_COSQ_WEIGHTED_ROUND_ROBIN   0x03       
#define BCM_COSQ_WEIGHTED_FAIR_QUEUING  0x04       
#define BCM_COSQ_DEFICIT_ROUND_ROBIN    0x05       /* XGS3 only. */
#define BCM_COSQ_BOUNDED_DELAY          0x06       /* Strata only. */
#define BCM_COSQ_SP                     BCM_COSQ_STRICT /* Strict priority. */
#define BCM_COSQ_EF                     0x07       /* Expedited forwarding. */
#define BCM_COSQ_AF                     0x08       /* Assured forwarding. */
#define BCM_COSQ_SP_GLOBAL              0x09       
#define BCM_COSQ_BE                     0x0A       /* Best effort. */
#define BCM_COSQ_MAX                    0x0A       

#define BCM_COSQ_WEIGHT_UNLIMITED   -1         
#define BCM_COSQ_WEIGHT_STRICT      0          
#define BCM_COSQ_WEIGHT_MIN         1          

#define BCM_COSQ_PRIO_VALID(prio)  ((prio) >= 0 && (prio < 8)) 

#define BCM_COSQ_QUEUE_VALID(unit, numq)  \
    ((numq) >= 0 && (numq) < NUM_COS(unit)) 

/* Set Class of Service policy, weights and delay. */
extern int bcm_cosq_sched_set(
    int unit, 
    int mode, 
    const int weights[BCM_COS_COUNT], 
    int delay);

/* Set Class of Service policy, weights and delay. */
extern int bcm_cosq_port_sched_set(
    int unit, 
    bcm_pbmp_t pbm, 
    int mode, 
    const int weights[BCM_COS_COUNT], 
    int delay);

/* Set Class of Service policy, weights and delay. */
extern int bcm_cosq_sched_get(
    int unit, 
    int *mode, 
    int weights[BCM_COS_COUNT], 
    int *delay);

/* Get Class of Service policy, weights and delay. */
extern int bcm_cosq_port_sched_get(
    int unit, 
    bcm_pbmp_t pbm, 
    int *mode, 
    int weights[BCM_COS_COUNT], 
    int *delay);

/* Retrieve maximum weights for given COS policy. */
extern int bcm_cosq_sched_weight_max_get(
    int unit, 
    int mode, 
    int *weight_max);

/* 
 * "Prioritize selected queue(s) for bandwidth before non-selected
 * queue(s).",
 */
#define BCM_COSQ_BW_EXCESS_PREF     0x00000001 
#define BCM_COSQ_BW_MINIMUM_PREF    0x00000002 

/* Configure a port bandwidth distribution among COS queues. */
extern int bcm_cosq_port_bandwidth_set(
    int unit, 
    bcm_port_t port, 
    bcm_cos_queue_t cosq, 
    uint32 kbits_sec_min, 
    uint32 kbits_sec_max, 
    uint32 flags);

/* Configure a port bandwidth distribution among COS queues. */
extern int bcm_cosq_port_bandwidth_get(
    int unit, 
    bcm_port_t port, 
    bcm_cos_queue_t cosq, 
    uint32 *kbits_sec_min, 
    uint32 *kbits_sec_max, 
    uint32 *flags);

/* Discard (WRED) related flags. */
#define BCM_COSQ_DISCARD_ENABLE         0x0001     
#define BCM_COSQ_DISCARD_CAP_AVERAGE    0x0002     
#define BCM_COSQ_DISCARD_COLOR_GREEN    0x0100     
#define BCM_COSQ_DISCARD_COLOR_YELLOW   0x0200     
#define BCM_COSQ_DISCARD_COLOR_RED      0x0400     
#define BCM_COSQ_DISCARD_COLOR_ALL      0x0700     
#define BCM_COSQ_DISCARD_DROP_FIRST     BCM_COSQ_DISCARD_COLOR_RED 
#define BCM_COSQ_DISCARD_BYTES          0x0800     
#define BCM_COSQ_DISCARD_PACKETS        0x1000     

/* Configure Weighted Random Early Discard (WRED). */
extern int bcm_cosq_discard_set(
    int unit, 
    uint32 flags);

/* Configure Weighted Random Early Discard (WRED). */
extern int bcm_cosq_discard_get(
    int unit, 
    uint32 *flags);

/* Configure a port's Weighted Random Early Discard (WRED) parameters. */
extern int bcm_cosq_discard_port_set(
    int unit, 
    bcm_port_t port, 
    bcm_cos_queue_t cosq, 
    uint32 color, 
    int drop_start, 
    int drop_slope, 
    int average_time);

/* Configure a port's Weighted Random Early Discard (WRED) parameters. */
extern int bcm_cosq_discard_port_get(
    int unit, 
    bcm_port_t port, 
    bcm_cos_queue_t cosq, 
    uint32 color, 
    int *drop_start, 
    int *drop_slope, 
    int *average_time);

/* Features that can be controlled on a gport/cosq  basis. */
typedef enum bcm_cosq_control_e {
    bcmCosqControlFabricConnectMinUtilization, /* percentage of minimum utilization
                                           before connection is established. */
    bcmCosqControlFabricConnectMaxTime  /* timeout configuration for minimum
                                           utilization connection setting. */
} bcm_cosq_control_t;

/* set various features at the gport/cosq level. */
extern int bcm_cosq_control_set(
    int unit, 
    bcm_gport_t port, 
    bcm_cos_queue_t cosq, 
    bcm_cosq_control_t type, 
    int arg);

/* Get various features at the gport/cosq level. */
extern int bcm_cosq_control_get(
    int unit, 
    bcm_gport_t port, 
    bcm_cos_queue_t cosq, 
    bcm_cosq_control_t type, 
    int *arg);

/* For Virtual output queues (system ports) */
typedef struct bcm_cosq_gport_discard_s {
    uint32 flags; 
    int min_thresh;         /* Queue depth to begin dropping. */
    int max_thresh;         /* Queue depth to drop all packets. */
    int drop_probability;   /* Drop probability at max threshold. */
    int gain;               /* Determines the smoothing that should be applied. */
    int ecn_thresh;         /* Queue depth to stop marking and start dropping. */
} bcm_cosq_gport_discard_t;

/* For Virtual output queues (system ports) */
typedef enum bcm_cosq_gport_stats_e {
    bcmCosqGportGreenAcceptedPkts,      /* Green/DP0, accepted packet count. */
    bcmCosqGportGreenAcceptedBytes,     /* Green/DP0, accepted byte count. */
    bcmCosqGportGreenMarkedPkts,        /* Green/DP0, marked packets. */
    bcmCosqGportGreenMarkedBytes,       /* Green/DP0, marked bytes. */
    bcmCosqGportGreenDiscardPkts,       /* Green/DP0, WRED dropped at packets. */
    bcmCosqGportGreenDiscardBytes,      /* Green/DP0, WRED dropped bytes. */
    bcmCosqGportYellowAcceptedPkts,     /* Yellow/DP1, accepted packet count. */
    bcmCosqGportYellowAcceptedBytes,    /* Yellow/DP1, accepted byte count. */
    bcmCosqGportYellowMarkedPkts,       /* Yellow/DP1, marked packets. */
    bcmCosqGportYellowMarkedBytes,      /* Yellow/DP1, marked bytes. */
    bcmCosqGportYellowDiscardPkts,      /* Yellow/DP1, WRED dropped at packets. */
    bcmCosqGportYellowDiscardBytes,     /* Yellow/DP1, WRED dropped bytes. */
    bcmCosqGportRedAcceptedPkts,        /* Red/DP2, accepted packet count. */
    bcmCosqGportRedAcceptedBytes,       /* Red/DP2, accepted byte count. */
    bcmCosqGportRedMarkedPkts,          /* Red/DP2, marked packets. */
    bcmCosqGportRedMarkedBytes,         /* Red/DP2, marked bytes. */
    bcmCosqGportRedDiscardPkts,         /* Red/DP2, WRED dropped at packets. */
    bcmCosqGportRedDiscardBytes,        /* Red/DP2, WRED dropped bytes. */
    bcmCosqGportNonWredDroppedPkts,     /* NON-WRED dropped packet count. */
    bcmCosqGportNonWredDroppedBytes,    /* NON-WRED dropped byte count. */
    bcmCosqGportDequeuedPkts,           /* dequeued packets. */
    bcmCosqGportDequeuedBytes           /* dequeued bytes. */
} bcm_cosq_gport_stats_t;

/* Initialize a COSQ GPORT discard structure. */
extern void bcm_cosq_gport_discard_t_init(
    bcm_cosq_gport_discard_t *discard);

extern int bcm_cosq_gport_get(
    int unit, 
    bcm_gport_t gport, 
    bcm_gport_t *physical_port, 
    int *num_cos_levels, 
    uint32 *flags);

typedef int (*bcm_cosq_gport_traverse_cb)(
    int unit, 
    bcm_gport_t port, 
    int numq, 
    uint32 flags, 
    bcm_gport_t gport, 
    void *user_data);

extern int bcm_cosq_gport_traverse(
    int unit, 
    bcm_cosq_gport_traverse_cb cb, 
    void *user_data);

extern int bcm_cosq_fabric_distribution_add(
    int unit, 
    bcm_fabric_distribution_t ds_id, 
    int num_cos_levels, 
    uint32 flags, 
    bcm_gport_t *req_gport);

extern int bcm_cosq_fabric_distribution_get(
    int unit, 
    bcm_fabric_distribution_t ds_id, 
    int *num_cos_levels, 
    bcm_gport_t *req_gport, 
    uint32 *flags);

extern int bcm_cosq_gport_mapping_set(
    int unit, 
    bcm_gport_t gport, 
    bcm_cos_t priority, 
    bcm_cos_queue_t cosq);

extern int bcm_cosq_gport_mapping_get(
    int unit, 
    bcm_gport_t gport, 
    bcm_cos_t priority, 
    bcm_cos_queue_t *cosq);

extern int bcm_cosq_gport_size_set(
    int unit, 
    bcm_gport_t gport, 
    bcm_cos_queue_t cosq, 
    uint32 bytes_min, 
    uint32 bytes_max);

extern int bcm_cosq_gport_size_get(
    int unit, 
    bcm_gport_t gport, 
    bcm_cos_queue_t cosq, 
    uint32 *bytes_min, 
    uint32 *bytes_max);

#define BCM_COSQ_ALL            0x0001     

extern int bcm_cosq_gport_enable_set(
    int unit, 
    bcm_gport_t gport, 
    bcm_cos_queue_t cosq, 
    int enable);

extern int bcm_cosq_gport_enable_get(
    int unit, 
    bcm_gport_t gport, 
    bcm_cos_queue_t cosq, 
    int *enable);

extern int bcm_cosq_gport_nexus_attach(
    int unit, 
    bcm_gport_t master_port, 
    bcm_cos_queue_t master_port_cosq, 
    bcm_gport_t nexus_port, 
    bcm_cos_queue_t nexus_port_cosq);

extern int bcm_cosq_gport_nexus_detach(
    int unit, 
    bcm_gport_t master_port, 
    bcm_cos_queue_t master_port_cosq, 
    bcm_gport_t nexus_port, 
    bcm_cos_queue_t nexus_port_cosq);

extern int bcm_cosq_gport_stat_enable_set(
    int unit, 
    bcm_gport_t gport, 
    int enable);

extern int bcm_cosq_gport_stat_enable_get(
    int unit, 
    bcm_gport_t gport, 
    int *enable);

extern int bcm_cosq_gport_stat_get(
    int unit, 
    bcm_gport_t gport, 
    bcm_cos_queue_t cosq, 
    bcm_cosq_gport_stats_t stat, 
    uint64 *value);

extern int bcm_cosq_gport_stat_set(
    int unit, 
    bcm_gport_t gport, 
    bcm_cos_queue_t cosq, 
    bcm_cosq_gport_stats_t stat, 
    uint64 value);

#define BCM_COSQ_GPORT_WITH_ID              0x00000001 
#define BCM_COSQ_GPORT_SCHEDULER            0x00000002 
#define BCM_COSQ_GPORT_OVERLAY              0x00000004 
#define BCM_COSQ_GPORT_UCAST_QUEUE_GROUP    0x00000008 
#define BCM_COSQ_GPORT_MCAST_QUEUE          0x00000010 
#define BCM_COSQ_GPORT_MCAST_QUEUE_GROUP    0x00000020 
#define BCM_COSQ_GPORT_LOCAL                0x00000040 

extern int bcm_cosq_gport_add(
    int unit, 
    bcm_gport_t port, 
    int numq, 
    uint32 flags, 
    bcm_gport_t *gport);

extern int bcm_cosq_gport_delete(
    int unit, 
    bcm_gport_t gport);

extern int bcm_cosq_gport_bandwidth_set(
    int unit, 
    bcm_gport_t gport, 
    bcm_cos_queue_t cosq, 
    uint32 kbits_sec_min, 
    uint32 kbits_sec_max, 
    uint32 flags);

extern int bcm_cosq_gport_bandwidth_get(
    int unit, 
    bcm_gport_t gport, 
    bcm_cos_queue_t cosq, 
    uint32 *kbits_sec_min, 
    uint32 *kbits_sec_max, 
    uint32 *flags);

extern int bcm_cosq_gport_sched_set(
    int unit, 
    bcm_gport_t gport, 
    bcm_cos_queue_t cosq, 
    int mode, 
    int weight);

extern int bcm_cosq_gport_sched_get(
    int unit, 
    bcm_gport_t gport, 
    bcm_cos_queue_t cosq, 
    int *mode, 
    int *weight);

extern int bcm_cosq_gport_discard_set(
    int unit, 
    bcm_gport_t gport, 
    bcm_cos_queue_t cosq, 
    bcm_cosq_gport_discard_t *discard);

extern int bcm_cosq_gport_discard_get(
    int unit, 
    bcm_gport_t gport, 
    bcm_cos_queue_t cosq, 
    bcm_cosq_gport_discard_t *discard);

extern int bcm_cosq_gport_attach(
    int unit, 
    bcm_gport_t sched_port, 
    bcm_gport_t input_port, 
    bcm_cos_queue_t cosq);

extern int bcm_cosq_gport_detach(
    int unit, 
    bcm_gport_t sched_port, 
    bcm_gport_t input_port, 
    bcm_cos_queue_t cosq);

extern int bcm_cosq_gport_attach_get(
    int unit, 
    bcm_gport_t sched_port, 
    bcm_gport_t *input_port, 
    bcm_cos_queue_t *cosq);

#endif /* __BCM_COSQ_H__ */