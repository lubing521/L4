/*******************************************************************************
*              (c), Copyright 2001, Marvell International Ltd.                 *
* THIS CODE CONTAINS CONFIDENTIAL INFORMATION OF MARVELL SEMICONDUCTOR, INC.   *
* NO RIGHTS ARE GRANTED HEREIN UNDER ANY PATENT, MASK WORK RIGHT OR COPYRIGHT  *
* OF MARVELL OR ANY THIRD PARTY. MARVELL RESERVES THE RIGHT AT ITS SOLE        *
* DISCRETION TO REQUEST THAT THIS CODE BE IMMEDIATELY RETURNED TO MARVELL.     *
* THIS CODE IS PROVIDED "AS IS". MARVELL MAKES NO WARRANTIES, EXPRESSED,       *
* IMPLIED OR OTHERWISE, REGARDING ITS ACCURACY, COMPLETENESS OR PERFORMANCE.   *
********************************************************************************
* prvCpssDxChIp.h
*
* DESCRIPTION:
*       Private CPSS DXCH Ip HW structures
*
* FILE REVISION NUMBER:
*       $Revision: 7 $
*******************************************************************************/
#ifndef __prvCpssDxChIph
#define __prvCpssDxChIph

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#include <cpss/dxCh/dxChxGen/ip/cpssDxChIpTypes.h>

/*******************************************************************************
 * External usage variables
 ******************************************************************************/

/*******************************************************************************
* prvCpssDxChIpConvertUcEntry2HwFormat
*
* DESCRIPTION:
*       This function converts a given ip uc entry to the HW format.
*
* APPLICABLE DEVICES: DxCh2 and above.
*
* INPUTS:
*       ipUcRouteEntryPtr - The entry to be converted.
*
* OUTPUTS:
*       hwDataPtr  - The entry in the HW format representation.
*
* RETURNS:
*       GT_OK
*
* COMMENTS:
*       None.
*
*******************************************************************************/
extern GT_STATUS prvCpssDxChIpConvertUcEntry2HwFormat
(
    IN  CPSS_DXCH_IP_UC_ROUTE_ENTRY_STC *ipUcRouteEntryPtr,
    OUT GT_U32                          *hwDataPtr
 );

/*******************************************************************************
* prvCpssDxChIpConvertHwFormat2UcEntry
*
* DESCRIPTION:
*       This function converts a given ip uc entry to the HW format.
*
* APPLICABLE DEVICES: DxCh2 and above.
*
* INPUTS:
*       hwDataPtr          - The entry in the HW format representation.
*       ipUcRouteEntryPtr  - Set the route entry type to determine how hw data will be
*                         interpreted
*
* OUTPUTS:
*       ipUcRouteEntryPtr - The entry to be converted.
*
* RETURNS:
*       GT_OK
*
* COMMENTS:
*       None.
*
*******************************************************************************/
extern GT_STATUS prvCpssDxChIpConvertHwFormat2UcEntry
(
    IN  GT_U32 *hwDataPtr,
    INOUT CPSS_DXCH_IP_UC_ROUTE_ENTRY_STC *ipUcRouteEntryPtr
);

/*******************************************************************************
* prvCpssDxChIpUcRouteEntriesCheck
*
* DESCRIPTION:
*       Check validity of the route entry parametrers, in all entries
*       of routeEntriesArray.
*
* APPLICABLE DEVICES: DxCh2 and above.
*
* INPUTS:
*       devNum               - the device number
*       routeEntriesArray    - the uc route entries array
*       numOfRouteEntries    - the number route entries in the array.
*
* OUTPUTS:
*       None.
*
* RETURNS:
*       GT_OK           - on all valid parameters.
*       GT_BAD_PARAM    - on invalid parameter.
*       GT_OUT_OF_RANGE - on out of range parameter.
*       GT_BAD_PTR      - on NULL pointer.
*
* COMMENTS:
*       None.
*
*******************************************************************************/
extern GT_STATUS prvCpssDxChIpUcRouteEntriesCheck
(
    IN GT_U8                           devNum,
    IN CPSS_DXCH_IP_UC_ROUTE_ENTRY_STC *routeEntriesArray,
    IN GT_U32                          numOfRouteEntries
);


/*******************************************************************************
* prvCpssDxChIpConvertMcEntry2HwFormat
*
* DESCRIPTION:
*       This function converts a given ip mc entry to the HW format.
*
* APPLICABLE DEVICES: DxCh2 and above.
*
* INPUTS:
*       ipMcRouteEntryPtr - The entry to be converted.
*
* OUTPUTS:
*       hwDataPtr  - The entry in the HW format representation.
*
* RETURNS:
*       GT_OK
*
* COMMENTS:
*       None.
*
*******************************************************************************/
extern GT_STATUS prvCpssDxChIpConvertMcEntry2HwFormat
(
    IN  CPSS_DXCH_IP_MC_ROUTE_ENTRY_STC *ipMcRouteEntryPtr,
    OUT GT_U32                          *hwDataPtr
);

/*******************************************************************************
* prvCpssDxChIpMcRouteEntryCheck
*
* DESCRIPTION:
*       Check validity of the route entry parametrers, in all entries
*       of routeEntriesArray.
*
* APPLICABLE DEVICES: DxCh2 and above.
*
* INPUTS:
*       routeEntryPtr    - the Mc route entry
*
* OUTPUTS:
*       None.
*
* RETURNS:
*       GT_OK           - on all valid parameters.
*       GT_BAD_PARAM    - on invalid parameter.
*       GT_OUT_OF_RANGE - on out of range parameter.
*
* COMMENTS:
*       None.
*
*******************************************************************************/
extern GT_STATUS prvCpssDxChIpMcRouteEntryCheck
(
    IN CPSS_DXCH_IP_MC_ROUTE_ENTRY_STC *routeEntryPtr
);


/*******************************************************************************
* prvCpssDxChIpConvertHwFormat2McEntry
*
* DESCRIPTION:
*       This function converts a given ip mc entry to the HW format.
*
* APPLICABLE DEVICES: DxCh2 and above.
*
* INPUTS:
*       hwDataPtr    - The mc entry in the HW format to be converted..
*
* OUTPUTS:
*       ipMcRouteEntryPtr - The mc entry data.
*
* RETURNS:
*       GT_OK
*
* COMMENTS:
*       None.
*
*******************************************************************************/
extern GT_STATUS prvCpssDxChIpConvertHwFormat2McEntry
(
    OUT  CPSS_DXCH_IP_MC_ROUTE_ENTRY_STC *ipMcRouteEntryPtr,
    IN   GT_U32                          *hwDataPtr
);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* __prvCpssDxChIph */

