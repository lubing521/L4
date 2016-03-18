/*
 * DO NOT EDIT THIS FILE!
 * This file is auto-generated from the registers file.
 * Edits to this file will be lost when it is regenerated.
 *
 * $Id: memregs.h,v 1.16.6.2 Broadcom SDK $
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
 * File:	memregs.h
 * Purpose:	Memory entry declarations, memory and register macros
 * Supports:	bcm5324_a0
 *		bcm5396_a0
 *		bcm5389_a0
 *		bcm5398_a0
 *		bcm5324_a1
 *		bcm5348_a0
 *		bcm5397_a0
 *		bcm5347_a0
 *		bcm5395_a0
 *		bcm53242_a0
 *		bcm53262_a0
 *		bcm53115_a0
 *		bcm53118_a0
 */

#ifndef _SOC_ROBO_MEMREGS_H
#define _SOC_ROBO_MEMREGS_H



#include <soc/mcm/robo/allfields.h>
#include <soc/mcm/robo/allenum.h>

/****************************************************************
 *
 * Each structure is an array big enough for the memory structures
 * in all supported chips.
 * These are accessed and manipulated by soc_mem functions
 * in soc/common.c and soc/mem.c
 *
 ****************************************************************/

#define MEM_ENTRY(tname, bytes) \
	typedef struct { \
		uint32 entry_data[BYTES2WORDS(bytes)]; \
	} tname 

MEM_ENTRY(cfp_act_pol_entry_t, 8);
MEM_ENTRY(cfp_meter_entry_t, 8);
MEM_ENTRY(cfp_stat_ib_entry_t, 4);
MEM_ENTRY(cfp_stat_ob_entry_t, 4);
MEM_ENTRY(cfp_tcam_chain_mask_entry_t, 29);
MEM_ENTRY(cfp_tcam_chain_sc_entry_t, 29);
MEM_ENTRY(cfp_tcam_ipv4_mask_entry_t, 29);
MEM_ENTRY(cfp_tcam_ipv4_sc_entry_t, 29);
MEM_ENTRY(cfp_tcam_ipv6_mask_entry_t, 29);
MEM_ENTRY(cfp_tcam_ipv6_sc_entry_t, 29);
MEM_ENTRY(cfp_tcam_mask_entry_t, 48);
MEM_ENTRY(cfp_tcam_nonip_mask_entry_t, 29);
MEM_ENTRY(cfp_tcam_nonip_sc_entry_t, 29);
MEM_ENTRY(cfp_tcam_s0_entry_t, 48);
MEM_ENTRY(cfp_tcam_s1_entry_t, 48);
MEM_ENTRY(cfp_tcam_s2_entry_t, 48);
MEM_ENTRY(cfp_tcam_s3_entry_t, 24);
MEM_ENTRY(cfp_tcam_s4_entry_t, 24);
MEM_ENTRY(cfp_tcam_s5_entry_t, 24);
MEM_ENTRY(egress_vid_remark_entry_t, 4);
MEM_ENTRY(flow2vlan_entry_t, 4);
MEM_ENTRY(gen_memory_entry_t, 10);
MEM_ENTRY(l2_arl_entry_t, 11);
MEM_ENTRY(l2_arl_sw_entry_t, 11);
MEM_ENTRY(l2_marl_sw_entry_t, 11);
MEM_ENTRY(mac2vlan_entry_t, 8);
MEM_ENTRY(marl_pbmp_entry_t, 24);
MEM_ENTRY(mspt_tab_entry_t, 24);
MEM_ENTRY(protocol2vlan_entry_t, 4);
MEM_ENTRY(stsec_counter0_entry_t, 7);
MEM_ENTRY(stsec_counter1_entry_t, 7);
MEM_ENTRY(stsec_counter2_entry_t, 7);
MEM_ENTRY(stsec_mac0_entry_t, 7);
MEM_ENTRY(stsec_mac1_entry_t, 7);
MEM_ENTRY(stsec_mac2_entry_t, 7);
MEM_ENTRY(vlan2vlan_entry_t, 4);
MEM_ENTRY(vlan_1q_entry_t, 24);
#undef MEM_ENTRY

/* Register and memory list declarations */
extern soc_reg_info_t soc_robo_reg_list[];
extern soc_mem_info_t soc_robo_mem_list[];
extern char *soc_robo_reg_name[];
extern char *soc_robo_reg_alias[];
extern char *soc_robo_reg_desc[];
extern char *soc_robo_mem_name[];
extern char *soc_robo_mem_ufname[];
extern char *soc_robo_mem_ufalias[];
extern char *soc_robo_mem_desc[];

#if !defined(SOC_NO_NAMES)
#define SOC_ROBO_REG_NAME(unit, reg)		soc_robo_reg_name[reg]
#else
#define SOC_ROBO_REG_NAME(unit, reg)		""
#endif

#if !defined(SOC_NO_ALIAS)
#define SOC_ROBO_REG_ALIAS(unit, reg)	soc_robo_reg_alias[reg]
#else
#define SOC_ROBO_REG_ALIAS(unit, reg)	""
#endif

#if !defined(SOC_NO_DESC)
#define SOC_ROBO_REG_DESC(unit, reg)		soc_robo_reg_desc[reg]
#else
#define SOC_ROBO_REG_DESC(unit, reg)		""
#endif

#if !defined(SOC_NO_NAMES)
#define SOC_ROBO_MEM_NAME(unit, mem)		soc_robo_mem_name[mem]
#define SOC_ROBO_MEM_UFNAME(unit, mem)	soc_robo_mem_ufname[mem]
#else
#define SOC_ROBO_MEM_NAME(unit, mem)		""
#define SOC_ROBO_MEM_UFNAME(unit, mem)	""
#endif

#if !defined(SOC_NO_ALIAS)
#define SOC_ROBO_MEM_UFALIAS(unit, mem)	soc_robo_mem_ufalias[mem]
#else
#define SOC_ROBO_MEM_UFALIAS(unit, mem)	""
#endif

#if !defined(SOC_NO_DESC)
#define SOC_ROBO_MEM_DESC(unit, mem)		soc_robo_mem_desc[mem]
#else
#define SOC_ROBO_MEM_DESC(unit, mem)		""
#endif

/* Chip specific include matter */


/* bcm5324_a0 */

/* bcm5396_a0 */

/* bcm5389_a0 */

/* bcm5398_a0 */

/* bcm5324_a1 */

/* bcm5348_a0 */

/* bcm5397_a0 */

/* bcm5347_a0 */

/* bcm5395_a0 */

/* bcm53242_a0 */

/* bcm53262_a0 */

/* bcm53115_a0 */

/* bcm53118_a0 */



#endif	/* !_SOC_ROBO_MEMREGS_H */
