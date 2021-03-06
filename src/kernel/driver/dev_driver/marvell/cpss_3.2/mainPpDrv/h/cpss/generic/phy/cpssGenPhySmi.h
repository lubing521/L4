/*******************************************************************************
*              Copyright 2006, MARVELL TECHNOLOGY, LTD.
*
* THIS CODE CONTAINS CONFIDENTIAL INFORMATION OF MARVELL. NO RIGHTS ARE GRANTED
* HEREIN UNDER ANY PATENT, MASK WORK RIGHT OR COPYRIGHT OF MARVELL OR ANY THIRD
* PARTY. MARVELL RESERVES THE RIGHT AT ITS SOLE DISCRETION TO REQUEST THAT THIS
* CODE BE IMMEDIATELY RETURNED TO MARVELL. THIS CODE IS PROVIDED "AS IS".
* MARVELL MAKES NO WARRANTIES, EXPRESS, IMPLIED OR OTHERWISE, REGARDING ITS
* ACCURACY, COMPLETENESS OR PERFORMANCE. MARVELL COMPRISES MARVELL TECHNOLOGY
* GROUP LTD. (MTGL) AND ITS SUBSIDIARIES, MARVELL INTERNATIONAL LTD. (MIL),
* MARVELL TECHNOLOGY, INC. (MTI), MARVELL SEMICONDUCTOR, INC. (MSI), MARVELL
* ASIA PTE LTD. (MAPL), MARVELL JAPAN K.K. (MJKK), GALILEO TECHNOLOGY LTD. (GTL)
* AND GALILEO TECHNOLOGY, INC. (GTI).
********************************************************************************
* cpssGenPhySmi.h
*
* DESCRIPTION:
*       API implementation for port Core Serial Management Interface facility.
*
*
* FILE REVISION NUMBER:
*       $Revision: 5 $
*******************************************************************************/

#ifndef __cpssGenPhySmih
#define __cpssGenPhySmih

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/*
 * typedef: enum CPSS_PHY_SMI_INTERFACE_ENT
 *
 * Description: Generic Serial Management Interface numbering
 *
 * Enumerations:
 *      CPSS_PHY_SMI_INTERFACE_0_E  - SMI interface\controller 0
 *      CPSS_PHY_SMI_INTERFACE_1_E  - SMI interface\controller 1  
 */
typedef enum
{
    CPSS_PHY_SMI_INTERFACE_0_E,
    CPSS_PHY_SMI_INTERFACE_1_E

} CPSS_PHY_SMI_INTERFACE_ENT;

/*
 * typedef: enum CPSS_PHY_ERRATA_WA_ENT
 *
 * Description: PHY errata workarond list
 *
 * Enumerations:
 *      CPSS_PHY_ERRATA_WA_88E1240_SGMII_LOCKUP_E  - Workaround for 88E1240 
 *                  SGMII lock-up problem. Should be used only after packet 
 *                  processor PHY SMI lib init is finished and SGMII 
 *                  autonegotiation between the PHY and the packet processor
 *                  reached synchronization. The PHY SGMII autonegotiation 
 *                  should be disabled if the packet processor uses 
 *                  out-of-band PHY autonegotiation.
 *
 *      CPSS_PHY_ERRATA_WA_88E1340_BGA_INIT_E - Workaround for 88E1340 BGA 
 *                  package init. If used, should be after hard-reset 
 *                  de-asserted for PHY initialization. 
 *                  Should only be applied for BGA package.
 */
typedef enum
{
    CPSS_PHY_ERRATA_WA_88E1240_SGMII_LOCKUP_E,
    CPSS_PHY_ERRATA_WA_88E1340_BGA_INIT_E

} CPSS_PHY_ERRATA_WA_ENT;

/*******************************************************************************
* cpssPhyErrataWaExecute
*
* DESCRIPTION:
*   This function execute workaround for PHY errata from a selected list.
*
* APPLICABLE DEVICES:  All devices
*
* INPUTS:
*       devNum      - Device Number.
*       portNum     - Port Number.
*       errataWa    - the selected workaround to execute
*
* OUTPUTS:
*       None.
*
* RETURNS :
*       GT_OK                    - on success
*       GT_FAIL                  - on error
*       GT_HW_ERROR              - on hardware error
*       GT_NOT_INITIALIZED       - on not initialized function pointers for
*                                  read and write phy registers operations.
*       GT_BAD_PARAM             - on wrong device, port or requested WA
*
* COMMENTS:
*       None.
*
*******************************************************************************/
GT_STATUS cpssPhyErrataWaExecute
(
   IN GT_U8                     devNum,
   IN GT_U8                     portNum,
   IN CPSS_PHY_ERRATA_WA_ENT    errataWa
);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* __cpssGenPhySmih */

