/*******************************************************************************
*              (c), Copyright 2001, Marvell International Ltd.                 *
* THIS CODE CONTAINS CONFIDENTIAL INFORMATION OF MARVELL SEMICONDUCTOR, INC.   *
* NO RIGHTS ARE GRANTED HEREIN UNDER ANY PATENT, MASK WORK RIGHT OR COPYRIGHT  *
* OF MARVELL OR ANY THIRD PARTY. MARVELL RESERVES THE RIGHT AT ITS SOLE        *
* DISCRETION TO REQUEST THAT THIS CODE BE IMMEDIATELY RETURNED TO MARVELL.     *
* THIS CODE IS PROVIDED "AS IS". MARVELL MAKES NO WARRANTIES, EXPRESSED,       *
* IMPLIED OR OTHERWISE, REGARDING ITS ACCURACY, COMPLETENESS OR PERFORMANCE.   *
********************************************************************************
* cpssDxChPortStat.h
*
* DESCRIPTION:
*       CPSS implementation for core port statistics and
*       egress counters facility.
*
* FILE REVISION NUMBER:
*       $Revision: 7 $
*******************************************************************************/

#ifndef __cpssDxChPortStath
#define __cpssDxChPortStath

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#include <cpss/generic/cpssTypes.h>
#include <cpss/generic/port/cpssPortStat.h>
#include <cpss/generic/cos/cpssCosTypes.h>


/******* info about Ethernet CPU port ******************************************
    support only next counters:

    1. CPSS_GOOD_PKTS_SENT_E:      32 bits counter
    2. CPSS_MAC_TRANSMIT_ERR_E:    16 bits counter
    3. CPSS_GOOD_OCTETS_SENT_E:    32 bits counter
    4. CPSS_DROP_EVENTS_E:         16 bits counter
    5. CPSS_GOOD_PKTS_RCV_E:       16 bits counter
    6. CPSS_BAD_PKTS_RCV_E:        16 bits counter
    7. CPSS_GOOD_OCTETS_RCV_E:     32 bits counter
    8. CPSS_BAD_OCTETS_RCV_E:      16 bits counter

*******************************************************************************/


/*******************************************************************************
* cpssDxChPortStatInit
*
* DESCRIPTION:
*       Init port statistics counter set CPSS facility.
*
* APPLICABLE DEVICES:  All DxCh Devices
*
* INPUTS:
*       devNum   - physical device number
*
* OUTPUTS:
*       None.
*
* RETURNS:
*       GT_OK                    - on success
*       GT_FAIL                  - on error
*       GT_BAD_PARAM             - on wrong port number or device
*       GT_HW_ERROR              - on hardware error
*       GT_NOT_APPLICABLE_DEVICE - on not applicable device
*
* COMMENTS:
*
*******************************************************************************/
GT_STATUS cpssDxChPortStatInit
(
    IN  GT_U8       devNum
);

/*******************************************************************************
* cpssDxChMacCounterGet
*
* DESCRIPTION:
*       Gets Ethernet MAC counter for a specified port on specified device.
*
* APPLICABLE DEVICES:  All DxCh Devices
*
* INPUTS:
*       devNum   - physical device number
*       portNum  - physical port number
*                  CPU port counters are valid only when using "Ethernet CPU
*                  port" (not using the SDMA interface).
*                  when using the SDMA interface refer to the API
*                  cpssDxChNetIfSdmaRxCountersGet(...)
*       cntrName - specific counter name
*
* OUTPUTS:
*       cntrValuePtr - (pointer to) current counter value.
*
* RETURNS:
*       GT_OK        - on success
*       GT_FAIL      - on error
*       GT_BAD_PARAM - on wrong port number, device or counter name
*       GT_HW_ERROR  - on hardware error
*       GT_NOT_APPLICABLE_DEVICE - on not applicable device
*
* COMMENTS:
*     The 10G MAC MIB counters are 64-bit wide.
*     Not supported counters: CPSS_BAD_PKTS_RCV_E, CPSS_UNRECOG_MAC_CNTR_RCV_E,
*     CPSS_BadFC_RCV_E, CPSS_GOOD_PKTS_RCV_E, CPSS_GOOD_PKTS_SENT_E.
*
*******************************************************************************/
GT_STATUS cpssDxChMacCounterGet
(
    IN  GT_U8                       devNum,
    IN  GT_U8                       portNum,
    IN  CPSS_PORT_MAC_COUNTERS_ENT  cntrName,
    OUT GT_U64                      *cntrValuePtr
);

/*******************************************************************************
* cpssDxChPortMacCountersOnPortGet
*
* DESCRIPTION:
*       Gets Ethernet MAC counter for a particular Port.
*
* APPLICABLE DEVICES:  All DxCh Devices
*
* INPUTS:
*       devNum   - physical device number
*       portNum  - physical port number
*                  CPU port counters are valid only when using "Ethernet CPU
*                  port" (not using the SDMA interface).
*                  when using the SDMA interface refer to the API
*                  cpssDxChNetIfSdmaRxCountersGet(...)
*
* OUTPUTS:
*       portMacCounterSetArrayPtr - (pointer to) array of current counter values.
*
* RETURNS:
*       GT_OK                    - on success
*       GT_FAIL                  - on error
*       GT_BAD_PARAM             - on wrong port number or device
*       GT_HW_ERROR              - on hardware error
*       GT_NOT_APPLICABLE_DEVICE - on not applicable device
*
* COMMENTS:
*     Not supported counters: CPSS_BAD_PKTS_RCV_E, CPSS_UNRECOG_MAC_CNTR_RCV_E,
*     CPSS_BadFC_RCV_E, CPSS_GOOD_PKTS_RCV_E, CPSS_GOOD_PKTS_SENT_E.
*
*******************************************************************************/
GT_STATUS   cpssDxChPortMacCountersOnPortGet
(
    IN  GT_U8                           devNum,
    IN  GT_U8                           portNum,
    OUT CPSS_PORT_MAC_COUNTER_SET_STC   *portMacCounterSetArrayPtr
);

/*******************************************************************************
* cpssDxChPortMacCounterCaptureGet
*
* DESCRIPTION:
*       Gets the captured Ethernet MAC counter for a specified port
*       on specified device.
*
* APPLICABLE DEVICES:  All DxCh Devices
*
* INPUTS:
*       devNum   - physical device number
*       portNum  - physical port number
*       cntrName - specific counter name
*
* OUTPUTS:
*       cntrValuePtr - (pointer to) current counter value.
*
* RETURNS:
*       GT_OK            - on success
*       GT_FAIL          - on error
*       GT_BAD_PARAM - on wrong port number, device or counter name
*       GT_HW_ERROR      - on hardware error
*       GT_BAD_PTR       - one of the parameters is NULL pointer
*       GT_NOT_APPLICABLE_DEVICE - on not applicable device
*
* COMMENTS:
*     The 10G MAC MIB counters are 64-bit wide.
*       Overiding of previous capture by another port in a group is occurs,
*       when the capture triggered port
*       (see cpssDxChPortMacCountersCaptureTriggerSet) and previous
*       capture triggered port are in the same group.
*       (This comment dosn't connected to HyperG.Stack ports.)
*       Not supported counters: CPSS_BAD_PKTS_RCV_E, CPSS_UNRECOG_MAC_CNTR_RCV_E,
*       CPSS_BadFC_RCV_E, CPSS_GOOD_PKTS_RCV_E, CPSS_GOOD_PKTS_SENT_E.
*
*******************************************************************************/
GT_STATUS cpssDxChPortMacCounterCaptureGet
(
    IN  GT_U8                       devNum,
    IN  GT_U8                       portNum,
    IN  CPSS_PORT_MAC_COUNTERS_ENT  cntrName,
    OUT GT_U64                      *cntrValuePtr
);

/*******************************************************************************
* cpssDxChPortMacCountersCaptureOnPortGet
*
* DESCRIPTION:
*       Gets captured Ethernet MAC counter for a particular Port.
*
* APPLICABLE DEVICES:  All DxCh Devices
*
* INPUTS:
*       devNum   - physical device number
*       portNum  - physical port number
*
* OUTPUTS:
*       portMacCounterSetArrayPtr - (pointer to) array of current counter values.
*
* RETURNS:
*       GT_OK        - on success
*       GT_FAIL      - on error
*       GT_BAD_PARAM - on wrong port number or device
*       GT_HW_ERROR  - on hardware error
*       GT_BAD_PTR   - one of the parameters is NULL pointer
*       GT_NOT_APPLICABLE_DEVICE - on not applicable device
*
* COMMENTS:
*       Overiding of previous capture by another port in a group is occurs,
*       when the capture triggered port
*       (see cpssDxChPortMacCountersCaptureTriggerSet) and previous
*       capture triggered port are in the same group.
*       (This comment dosn't connected to HyperG.Stack ports.)
*        Not supported counters: CPSS_BAD_PKTS_RCV_E, CPSS_UNRECOG_MAC_CNTR_RCV_E,
*        CPSS_BadFC_RCV_E, CPSS_GOOD_PKTS_RCV_E, CPSS_GOOD_PKTS_SENT_E.
*
*******************************************************************************/
GT_STATUS   cpssDxChPortMacCountersCaptureOnPortGet
(
    IN  GT_U8                           devNum,
    IN  GT_U8                           portNum,
    OUT CPSS_PORT_MAC_COUNTER_SET_STC   *portMacCounterSetArrayPtr
);

/*******************************************************************************
* cpssDxChPortMacCountersCaptureTriggerSet
*
* DESCRIPTION:
*     The function triggers a capture of MIB counters for specific port.
*
* APPLICABLE DEVICES:  All DxCh Devices
*
* INPUTS:
*       devNum    - physical device number
*       portNum   - physical port number, whose counters are to be captured.
*
* OUTPUTS:
*       None.
*
* RETURNS:
*       GT_OK        - on success
*       GT_FAIL      - on error
*       GT_BAD_PARAM - on wrong port number or device
*       GT_HW_ERROR  - on hardware error
*       GT_BAD_STATE - previous capture operation isn't finished.
*       GT_NOT_APPLICABLE_DEVICE - on not applicable device
*
*
* COMMENTS:
*        To get the counters, see cpssDxChPortMacCountersCaptureOnPortGet,
*                                 cpssDxChPortMacCounterCaptureGet.
*        For HyperG.Stack ports the feature operates per port, for other ports
*        it operates per group.
*        Ports 0-5 belong to group 0.
*        Ports 6-11 belong to group 1.
*        Ports 12-17 belong to group 2.
*        Ports 18-23 belong to group 3.
*
*******************************************************************************/
GT_STATUS cpssDxChPortMacCountersCaptureTriggerSet
(
    IN  GT_U8  devNum,
    IN  GT_U8  portNum
);

/*******************************************************************************
* cpssDxChPortMacCountersCaptureTriggerGet
*
* DESCRIPTION:
*    The function gets status of a capture of MIB counters for specific port.
*
* APPLICABLE DEVICES:  All DxCh Devices
*
* INPUTS:
*       devNum    - physical device number
*       portNum   - physical port number.
*
* OUTPUTS:
*       captureIsDonePtr     - pointer to status of Capture counter Trigger
*                              - GT_TRUE  - capture is done.
*                              - GT_FALSE - capture action is in proccess.
*
* RETURNS:
*       GT_OK        - on success
*       GT_FAIL      - on error
*       GT_BAD_PARAM - on wrong device number
*       GT_HW_ERROR  - on hardware error
*       GT_BAD_PTR   - one of the parameters is NULL pointer
*       GT_NOT_APPLICABLE_DEVICE - on not applicable device
*
* COMMENTS:
*        To get the counters, see cpssDxChPortMacCountersCaptureOnPortGet,
*                                 cpssDxChPortMacCounterCaptureGet.
*        For HyperG.Stack ports the feature operates per port, for other ports
*        it operates per group.
*        Ports 0-5 belong to group 0.
*        Ports 6-11 belong to group 1.
*        Ports 12-17 belong to group 2.
*        Ports 18-23 belong to group 3.
*
*******************************************************************************/
GT_STATUS cpssDxChPortMacCountersCaptureTriggerGet
(
    IN  GT_U8    devNum,
    IN  GT_U8    portNum,
    OUT GT_BOOL  *captureIsDonePtr
);

/*******************************************************************************
* cpssDxChPortEgressCntrModeSet
*
* DESCRIPTION:
*       Configure a set of egress counters that work in specified bridge egress
*       counters mode on specified device.
*
* APPLICABLE DEVICES:  All DxCh Devices
*
* INPUTS:
*       devNum     - physical device number
*       cntrSetNum - counter set number.
*       setModeBmp - counter mode bitmap. For example:
*                   GT_EGRESS_CNT_PORT | GT_EGRESS_CNT_VLAN | GT_EGRESS_CNT_DP.
*       portNum   - physical port number, if corresponding bit in setModeBmp is 1.
*       vlanId    - VLAN Id, if corresponding bit in setModeBmp is 1.
*       tc        - traffic class queue, if corresponding bit in setModeBmp is 1.
*       dpLevel   - drop precedence level, if corresponding bit in setModeBmp is 1.
*
* OUTPUTS:
*       None.
*
* RETURNS:
*       GT_OK                    - on success
*       GT_FAIL                  - on error
*       GT_BAD_PARAM             - on wrong port number or device
*       GT_HW_ERROR              - on hardware error
*       GT_NOT_APPLICABLE_DEVICE - on not applicable device
*
* COMMENTS:
*       Supported DP levels:  CPSS_DP_GREEN_E, CPSS_DP_RED_E.
*
*******************************************************************************/
GT_STATUS cpssDxChPortEgressCntrModeSet
(
    IN  GT_U8                           devNum,
    IN  GT_U8                           cntrSetNum,
    IN  CPSS_PORT_EGRESS_CNT_MODE_ENT   setModeBmp,
    IN  GT_U8                           portNum,
    IN  GT_U16                          vlanId,
    IN  GT_U8                           tc,
    IN  CPSS_DP_LEVEL_ENT               dpLevel
);

/*******************************************************************************
* cpssDxChPortEgressCntrModeGet
*
* DESCRIPTION:
*       Get configuration of a bridge egress counters set.
*
* APPLICABLE DEVICES:  All DxCh Devices
*
* INPUTS:
*       devNum     - physical device number
*       cntrSetNum - counter set number.
*
* OUTPUTS:
*       setModeBmpPtr - Pointer to counter mode bitmap. For example:
*                       GT_EGRESS_CNT_PORT | GT_EGRESS_CNT_VLAN | GT_EGRESS_CNT_DP.
*       portNumPtr    - Pointer to the egress port of the packets counted by
*                       the set of counters
*       vlanIdPtr     - Pointer to the vlan id of the packets counted by the
*                       set of counters.
*       tcPtr         - Pointer to the tc of the packets counted by the set
*                       of counters.
*       dpLevelPtr    - Pointer to the dp of the packets counted by the set
*                       of counters.
*
* RETURNS:
*       GT_OK                    - on success
*       GT_FAIL                  - on error
*       GT_BAD_PARAM             - on wrong port number or device
*       GT_BAD_PTR               - one of the parameters is NULL pointer
*       GT_HW_ERROR              - on hardware error
*       GT_NOT_APPLICABLE_DEVICE - on not applicable device
*
* COMMENTS:
*       Supported DP levels:  CPSS_DP_GREEN_E, CPSS_DP_RED_E.
*
*******************************************************************************/
GT_STATUS cpssDxChPortEgressCntrModeGet
(
    IN   GT_U8                           devNum,
    IN   GT_U8                           cntrSetNum,
    OUT  CPSS_PORT_EGRESS_CNT_MODE_ENT   *setModeBmpPtr,
    OUT  GT_U8                           *portNumPtr,
    OUT  GT_U16                          *vlanIdPtr,
    OUT  GT_U8                           *tcPtr,
    OUT  CPSS_DP_LEVEL_ENT               *dpLevelPtr
);

/*******************************************************************************
* cpssDxChPortEgressCntrsGet
*
* DESCRIPTION:
*       Gets a egress counters from specific counter-set.
*
* APPLICABLE DEVICES:  All DxCh Devices
*
* INPUTS:
*       devNum        - physical device number
*       cntrSetNum - counter set number : 0, 1
*
* OUTPUTS:
*       egrCntrPtr - (pointer to) structure of egress counters current values.
*
* RETURNS:
*       GT_OK                    - on success
*       GT_FAIL                  - on error
*       GT_BAD_PARAM             - on wrong port number or device
*       GT_HW_ERROR              - on hardware error
*       GT_BAD_PTR               - one of the parameters is NULL pointer
*       GT_NOT_APPLICABLE_DEVICE - on not applicable device
*
* COMMENTS:
*       None.
*
*******************************************************************************/
GT_STATUS cpssDxChPortEgressCntrsGet
(
    IN  GT_U8                       devNum,
    IN  GT_U8                       cntrSetNum,
    OUT CPSS_PORT_EGRESS_CNTR_STC   *egrCntrPtr
);

/*******************************************************************************
* cpssDxChPortMacCountersEnable
*
* DESCRIPTION:
*       Enable or disable MAC Counters update for this port.
*
* APPLICABLE DEVICES:  All DxCh Devices
*
* INPUTS:
*       devNum   - device number.
*       portNum  - physical port number (or CPU port)
*       enable   -  enable update of MAC counters
*                   GT_FALSE = MAC counters update for this port is disabled.
*                   GT_TRUE = MAC counters update for this port is enabled.
*
* OUTPUTS:
*       None.
*
* RETURNS:
*       GT_OK                    - on success.
*       GT_FAIL                  - on error.
*       GT_HW_ERROR              - on hardware error
*       GT_BAD_PARAM - on wrong device number or wrong physical port number
*       GT_NOT_APPLICABLE_DEVICE - on not applicable device
*
* COMMENTS:
*       None;
*
*******************************************************************************/
GT_STATUS cpssDxChPortMacCountersEnable(
    IN GT_U8 devNum,
    IN GT_U8 portNum,
    IN GT_BOOL enable
);


/*******************************************************************************
* cpssDxChPortMacCountersClearOnReadSet
*
* DESCRIPTION:
*       Enable or disable MAC Counters Clear on read per group of ports
*       for Tri-Speed Ports or per port for HyperG.Stack ports.
*       For Tri-Speed Ports groups are:
*       - Ports 0 through 5
*       - Ports 6 through 11
*       - Ports 12 through 17
*       - Ports 18 through 23
*
* APPLICABLE DEVICES:  All DxCh Devices
*
* INPUTS:
*       devNum      - device number.
*       portNum     - physical port number (or CPU port)
*       enable      - enable clear on read for MAC counters
*                   GT_FALSE - Counters are not cleared.
*                   GT_TRUE - Counters are cleared.

*
* OUTPUTS:
*       None.
*
* RETURNS:
*       GT_OK                    - on success.
*       GT_FAIL                  - on error.
*       GT_HW_ERROR              - on hardware error
*       GT_BAD_PARAM - on wrong device number or wrong physical port number
*       GT_NOT_APPLICABLE_DEVICE - on not applicable device
*
* COMMENTS:
*       None
*******************************************************************************/
GT_STATUS cpssDxChPortMacCountersClearOnReadSet(
    IN GT_U8    devNum,
    IN GT_U8    portNum,
    IN GT_BOOL  enable
);

/*******************************************************************************
* cpssDxChPortMacCountersClearOnReadGet
*
* DESCRIPTION:
*       Get "Clear on read" status of MAC Counters per group of ports
*       for Tri-Speed Ports or per port for HyperG.Stack ports.
*       For Tri-Speed Ports groups are:
*       - Ports 0 through 5
*       - Ports 6 through 11
*       - Ports 12 through 17
*       - Ports 18 through 23
*
* APPLICABLE DEVICES:  All DxCh Devices
*
* INPUTS:
*       devNum      - device number.
*       portNum     - physical port number (or CPU port)
*
* OUTPUTS:
*       enablePtr   - (pointer to) "Clear on read" status for MAC counters
*                     GT_FALSE - Counters are not cleared.
*                     GT_TRUE - Counters are cleared.
*
* RETURNS:
*       GT_OK                       - on success.
*       GT_FAIL                     - on error.
*       GT_HW_ERROR                 - on hardware error
*       GT_BAD_PARAM - on wrong device number or wrong physical port number
*       GT_BAD_PTR                  - one of the parameters is NULL pointer
*       GT_NOT_APPLICABLE_DEVICE    - on not applicable device
*
* COMMENTS:
*       None
*******************************************************************************/
GT_STATUS cpssDxChPortMacCountersClearOnReadGet(
    IN GT_U8    devNum,
    IN GT_U8    portNum,
    OUT GT_BOOL  *enablePtr
);

/*******************************************************************************
* cpssDxChPortMacCountersRxHistogramEnable
*
* DESCRIPTION:
*       Enable/disable updating of the RMON Etherstat histogram
*       counters for received packets per group of ports
*       for Tri-Speed Ports or per port for HyperG.Stack ports.
*       For Tri-Speed Ports groups are:
*           - Ports 0 through 5
*           - Ports 6 through 11
*           - Ports 12 through 17
*           - Ports 18 through 23
*
* APPLICABLE DEVICES:  All DxCh Devices
*
* INPUTS:
*       devNum      - device number.
*       portNum     - physical port number
*       enable      - enable updating of the counters for received packets
*                   GT_FALSE - Counters are updated.
*                   GT_TRUE - Counters are not updated.
*
*
* OUTPUTS:
*       None.
*
* RETURNS:
*       GT_OK                    - on success.
*       GT_FAIL                  - on error.
*       GT_HW_ERROR              - on hardware error
*       GT_BAD_PARAM - on wrong device number or wrong physical port number
*       GT_NOT_APPLICABLE_DEVICE - on not applicable device
*
* COMMENTS:
*       None
*******************************************************************************/
GT_STATUS cpssDxChPortMacCountersRxHistogramEnable(
    IN GT_U8    devNum,
    IN GT_U8    portNum,
    IN GT_BOOL  enable
);

/*******************************************************************************
* cpssDxChPortMacCountersTxHistogramEnable
*
* DESCRIPTION:
*       Enable/disable updating of the RMON Etherstat histogram
*       counters for transmitted packets per group of ports
*       for Tri-Speed Ports or per port for HyperG.Stack ports.
*       For Tri-Speed Ports groups are:
*           - Ports 0 through 5
*           - Ports 6 through 11
*           - Ports 12 through 17
*           - Ports 18 through 23
*
* APPLICABLE DEVICES:  All DxCh Devices
*
* INPUTS:
*       devNum      - device number.
*       portNum     - physical port number
*       enable      - enable updating of the counters for transmitted packets
*                   GT_FALSE - Counters are updated.
*                   GT_TRUE - Counters are not updated.
*
*
* OUTPUTS:
*       None.
*
* RETURNS:
*       GT_OK                    - on success.
*       GT_FAIL                  - on error.
*       GT_HW_ERROR              - on hardware error
*       GT_BAD_PARAM - on wrong device number or wrong physical port number
*       GT_NOT_APPLICABLE_DEVICE - on not applicable device
*
* COMMENTS:
*       None
*******************************************************************************/
GT_STATUS cpssDxChPortMacCountersTxHistogramEnable(
    IN GT_U8    devNum,
    IN GT_U8    portNum,
    IN GT_BOOL  enable
);


#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* __cpssDxChPortStath */

