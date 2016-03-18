/*******************************************************************************
*              (c), Copyright 2001, Marvell International Ltd.                 *
* THIS CODE CONTAINS CONFIDENTIAL INFORMATION OF MARVELL SEMICONDUCTOR, INC.   *
* NO RIGHTS ARE GRANTED HEREIN UNDER ANY PATENT, MASK WORK RIGHT OR COPYRIGHT  *
* OF MARVELL OR ANY THIRD PARTY. MARVELL RESERVES THE RIGHT AT ITS SOLE        *
* DISCRETION TO REQUEST THAT THIS CODE BE IMMEDIATELY RETURNED TO MARVELL.     *
* THIS CODE IS PROVIDED "AS IS". MARVELL MAKES NO WARRANTIES, EXPRESSED,       *
* IMPLIED OR OTHERWISE, REGARDING ITS ACCURACY, COMPLETENESS OR PERFORMANCE.   *
********************************************************************************
* cpssDxChCos.h
*
* DESCRIPTION:
*        CPSS Cos facility API.
*
*
*
* FILE REVISION NUMBER:
*       $Revision: 10 $
*
*******************************************************************************/

#ifndef __cpssDxChCosh
#define __cpssDxChCosh

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#include <cpss/generic/cpssTypes.h>
#include <cpss/generic/cos/cpssCosTypes.h>
#include <cpss/generic/cpssCommonDefs.h>
#include <cpss/generic/bridge/cpssGenBrgVlanTypes.h>


/*
 * Typedef: CPSS_DXCH_COS_PROFILE_STC
 *
 * Description: The Prestera Class-of-Service profile parameters.
 *
 * Fields:
 *    dropPrecedence  - drop precedence (color) (0..2).
 *    userPriority    - IEEEE 802.1p User Priority (0..7).
 *    trafficClass    - egress tx traffic class queue (0..7).
 *    dscp            - ip DCSP field (0..63).
 *    exp             - MPLS label exp value (0..7) - DxCh2 and above.
 */
typedef struct
{
    CPSS_DP_LEVEL_ENT   dropPrecedence;
    GT_U32              userPriority;
    GT_U32              trafficClass;
    GT_U32              dscp;
    GT_U32              exp;
}CPSS_DXCH_COS_PROFILE_STC;


/*******************************************************************************
* cpssDxChCosProfileEntrySet
*
* DESCRIPTION:
*       Configures the Profile Table Entry and
*       Initial Drop Precedence (DP) for Policer.
*
* APPLICABLE DEVICES:  All DxCh Devices.
*
* INPUTS:
*       devNum        - device number.
*       profileIndex  - index of a profile in the profile table
*                       Ch values (0..71); Ch2 and above values (0..127).
*       cosPtr        - Pointer to new CoS values for packet
*                       (dp = CPSS_DP_YELLOW_E is not applicable).
*
* OUTPUTS:
*       None.
*
* RETURNS:
*       GT_OK                    - on success.
*       GT_BAD_PARAM             - wrong devNum or cos.
*       GT_NOT_APPLICABLE_DEVICE - on not applicable device
*
* COMMENTS:
*       For DxCh3 devices Initial DP supports 3 levels (Yellow, Red, Green),
*       but QoS profile entry supports only 2 levels by the following way:
*        - The function set value 0 for Green DP
*        - The function set value 1 for both Yellow and Red DPs.
*
*******************************************************************************/
GT_STATUS cpssDxChCosProfileEntrySet
(
     IN  GT_U8                      devNum,
     IN  GT_U32                     profileIndex,
     IN  CPSS_DXCH_COS_PROFILE_STC  *cosPtr
);

/*******************************************************************************
* cpssDxChCosProfileEntryGet
*
* DESCRIPTION:
*       Get Profile Table Entry configuration and
*       initial Drop Precedence (DP) for Policer.
*
* APPLICABLE DEVICES:  All DxCh Devices.
*
* INPUTS:
*       devNum        - device number.
*       profileIndex  - index of a profile in the profile table
*                       Ch values (0..71); Ch2 and above values (0..127).
*
* OUTPUTS:
*       cosPtr        - Pointer to new CoS values for packet.
*
* RETURNS:
*       GT_OK                    - on success.
*       GT_BAD_PARAM             - wrong devNum or cos.
*       GT_TIMEOUT      - after max number of retries checking if PP ready.
*       GT_NOT_APPLICABLE_DEVICE - on not applicable device
*
* COMMENTS:
*       For DxCh3 devices Initial DP supports 3 levels (Yellow, Red, Green),
*       but QoS profile entry supports only 2 levels.
*       Therefore DP value is taken from the Initial DP table.
*
*******************************************************************************/
GT_STATUS cpssDxChCosProfileEntryGet
(
     IN  GT_U8                      devNum,
     IN  GT_U32                     profileIndex,
     OUT CPSS_DXCH_COS_PROFILE_STC  *cosPtr
);

/*******************************************************************************
* cpssDxChCosDscpToProfileMapSet
*
* DESCRIPTION:
*       Maps the packet DSCP (or remapped DSCP) to a QoS Profile.
*
* APPLICABLE DEVICES:  All DxCh Devices.
*
* INPUTS:
*       devNum        - device number.
*       dscp          - DSCP of a IP packet [0..63].
*       profileIndex  - profile index, which is assigned to a IP packet with
*                       the DSCP on ports with enabled trust L3 or trust L2-L3.
*                       Ch values (0..71); Ch2(and above) values (0..127).
*
* OUTPUTS:
*       None.
*
* RETURNS:
*       GT_OK                    - on success.
*       GT_BAD_PARAM             - wrong devNum, dscp or profileIndex
*       GT_NOT_APPLICABLE_DEVICE - on not applicable device
*
* COMMENTS:
*       None.
*
*******************************************************************************/
GT_STATUS cpssDxChCosDscpToProfileMapSet
(
    IN GT_U8    devNum,
    IN GT_U8    dscp,
    IN GT_U32   profileIndex
);

/*******************************************************************************
* cpssDxChCosDscpToProfileMapGet
*
* DESCRIPTION:
*       Get the Mapping: packet DSCP (or remapped DSCP) to a QoS Profile.
*
* APPLICABLE DEVICES:  All DxCh Devices.
*
* INPUTS:
*       devNum        - device number.
*       dscp          - DSCP of a IP packet [0..63]
*
* OUTPUTS:
*       profileIndexPtr - (pointer to) profile index, which is assigned to
*                         an IP packet with the DSCP on ports with enabled
*                         trust L3 or trust L2-L3.
*
* RETURNS:
*       GT_OK           - on success.
*       GT_BAD_PARAM    - wrong devNum, dscp or profileIndex.
*       GT_NOT_APPLICABLE_DEVICE - on not applicable device
*
* COMMENTS:
*       None.
*
*******************************************************************************/
GT_STATUS cpssDxChCosDscpToProfileMapGet
(
    IN  GT_U8    devNum,
    IN  GT_U8    dscp,
    OUT GT_U32  *profileIndexPtr
);

/*******************************************************************************
* cpssDxChCosDscpMutationEntrySet
*
* DESCRIPTION:
*       Maps the packet DSCP to a new, mutated DSCP.
*
* APPLICABLE DEVICES:  All DxCh Devices.
*
* INPUTS:
*       devNum   - device number.
*       dscp     - DSCP of a IP packet [0..63]
*       newDscp  - new DSCP, which is assigned to a IP packet with the DSCP on
*          ports with enabled trust L3 or trust L2-L3 and enabled DSCP mutation.
*
* OUTPUTS:
*       None.
*
* RETURNS:
*       GT_OK                    - on success.
*       GT_BAD_PARAM             - wrong devNum, dscp or newDscp
*       GT_NOT_APPLICABLE_DEVICE - on not applicable device
*
* COMMENTS:
*       None.
*
*******************************************************************************/
GT_STATUS cpssDxChCosDscpMutationEntrySet
(
    IN GT_U8   devNum,
    IN GT_U8   dscp,
    IN GT_U8   newDscp
);

/*******************************************************************************
* cpssDxChCosDscpMutationEntryGet
*
* DESCRIPTION:
*       Get the Mapping: packet DSCP to a new, mutated DSCP.
*
* APPLICABLE DEVICES:  All DxCh Devices.
*
* INPUTS:
*       devNum   - device number.
*       dscp     - DSCP of a IP packet [0..63]
*
* OUTPUTS:
*       newDscpPtr  - new DSCP, which is assigned to a IP packet with the DSCP on
*          ports with enabled trust L3 or trust L2-L3 and enabled DSCP mutation.
*
* RETURNS:
*       GT_OK                    - on success.
*       GT_BAD_PARAM             - wrong devNum, dscp or newDscp
*       GT_NOT_APPLICABLE_DEVICE - on not applicable device
*
* COMMENTS:
*       None.
*
*******************************************************************************/
GT_STATUS cpssDxChCosDscpMutationEntryGet
(
    IN  GT_U8   devNum,
    IN  GT_U8   dscp,
    OUT GT_U8  *newDscpPtr
);

/*******************************************************************************
* cpssDxChCosUpToProfileMapSet
*
* DESCRIPTION:
*       Maps the packet User Priority to a QoS Profile.
*
* APPLICABLE DEVICES:  DxCh1, DxCh2
*
* INPUTS:
*       devNum          - device number.
*       up              - user priority of a VLAN or Marvell tagged
*                         packet [0..7].
*       profileIndex    - profile index, which is assigned to a VLAN or
*                         Marvell tagged packet with the up on ports with
*                         enabled trust L2 or trust L2-L3.
*                         Ch values (0..71); Ch2 values (0..127).
* OUTPUTS:
*       None.
*
* RETURNS:
*       GT_OK                    - on success.
*       GT_BAD_PARAM             - wrong devNum, up or profileIndex.
*       GT_NOT_APPLICABLE_DEVICE - on not applicable device
*
* COMMENTS:
*       None.
*
*******************************************************************************/
GT_STATUS cpssDxChCosUpToProfileMapSet
(
    IN GT_U8  devNum,
    IN GT_U8  up,
    IN GT_U32 profileIndex
);

/*******************************************************************************
* cpssDxChCosUpToProfileMapGet
*
* DESCRIPTION:
*       Returns the mapping of packet User Priority to a QoS Profile.
*
* APPLICABLE DEVICES:  DxCh1, DxCh2.
*
* INPUTS:
*       devNum          - device number.
*       up              - user priority of a VLAN or Marvell tagged
*                         packet [0..7].
*
* OUTPUTS:
*       profileIndexPtr - (pointer to)profile index, which is assigned to
*                         a VLAN or Marvell tagged packet with the up on
*                         ports with enabled trust L2 or trust L2-L3.
*
* RETURNS:
*       GT_OK                    - on success.
*       GT_BAD_PARAM             - wrong devNum, up.
*       GT_BAD_PTR               - NULL pointer.
*       GT_NOT_APPLICABLE_DEVICE - on not applicable device
*
* COMMENTS:
*       None.
*
*******************************************************************************/
GT_STATUS cpssDxChCosUpToProfileMapGet
(
    IN  GT_U8   devNum,
    IN  GT_U8   up,
    OUT GT_U32 *profileIndexPtr
);

/*******************************************************************************
* cpssDxChCosUpCfiDeiToProfileMapSet
*
* DESCRIPTION:
*       Maps the packet's User Priority and CFI/DEI bit (Canonical Format
*       Indicator/Drop Eligibility Indicator) to QoS Profile.
*       The mapping relevant for L2 and L2-L3 QoS Trust modes for 802.1Q
*       or DSA tagged packets.
*
* APPLICABLE DEVICES:   DxCh3 and above.
*
* INPUTS:
*       devNum          - device number.
*       up              - User Priority of a VLAN or DSA tagged packet [0..7].
*       cfiDeiBit       - value of CFI/DEI bit[0..1].
*       profileIndex    - QoS Profile index, which is assigned to a VLAN or DSA
*                         tagged packet with the UP on ports with enabled trust
*                         L2 or trust L2-L3. Range is [0..127].
*
* OUTPUTS:
*       None.
*
* RETURNS:
*       GT_OK           - on success.
*       GT_HW_ERROR     - on hardware error.
*       GT_BAD_PARAM    - on wrong devNum, up or cfiDeiBit.
*       GT_OUT_OF_RANGE - on profileIndex out of range.
*       GT_NOT_APPLICABLE_DEVICE - on not applicable device
*
* COMMENTS:
*       None.
*******************************************************************************/
GT_STATUS cpssDxChCosUpCfiDeiToProfileMapSet
(
    IN GT_U8    devNum,
    IN GT_U8    up,
    IN GT_U8    cfiDeiBit,
    IN GT_U32   profileIndex
);

/*******************************************************************************
* cpssDxChCosUpCfiDeiToProfileMapGet
*
* DESCRIPTION:
*       Gets the mapping of packet's User Priority and CFI/DEI bit
*       (Canonical Format Indicator/Drop Eligibility Indicator) to QoS Profile.
*       The mapping relevant for L2 and L2-L3 QoS Trust modes for 802.1Q
*       or DSA tagged packets.
*
* APPLICABLE DEVICES:   DxCh3 and above.
*
* INPUTS:
*       devNum          - device number.
*       up              - User Priority of a VLAN or DSA tagged packet [0..7].
*       cfiDeiBit       - value of CFI/DEI bit[0..1].
*
* OUTPUTS:
*       profileIndexPtr - (pointer to)QoS Profile index, which is assigned to a
*                         VLAN or DSA tagged packet with the UP on ports with
*                         enabled trust L2 or trust L2-L3. Range is [0..127].
*
* RETURNS:
*       GT_OK           - on success.
*       GT_HW_ERROR     - on hardware error.
*       GT_BAD_PARAM    - on wrong devNum, up or cfiDeiBit.
*       GT_BAD_PTR      - on NULL pointer.
*       GT_NOT_APPLICABLE_DEVICE - on not applicable device
*
* COMMENTS:
*       None.
*******************************************************************************/
GT_STATUS cpssDxChCosUpCfiDeiToProfileMapGet
(
    IN  GT_U8   devNum,
    IN  GT_U8   up,
    IN  GT_U8   cfiDeiBit,
    OUT GT_U32  *profileIndexPtr
);

/*******************************************************************************
* cpssDxChCosPortDpToCfiDeiMapEnableSet
*
* DESCRIPTION:
*       Enables or disables mapping of Drop Precedence to Drop Eligibility
*       Indicator bit.
*       When enabled on egress port the DEI(CFI) bit at the outgoing VLAN
*       tag is set according to the packet DP(after mapping).
*
* APPLICABLE DEVICES:   DxCh3 and above.
*
* INPUTS:
*       devNum          - device number.
*       port            - egress port number including CPU port.
*       enable          - enable/disable DP-to-CFI/DEI mapping on the
*                         egress port:
*                             GT_TRUE  - DP-to-CFI/DEI mapping enable on port.
*                             GT_FALSE - DP-to-CFI/DEI mapping disable on port.
*
* OUTPUTS:
*       None.
*
* RETURNS:
*       GT_OK           - on success.
*       GT_HW_ERROR     - on hardware error.
*       GT_BAD_PARAM    - on wrong devNum or port.
*       GT_NOT_APPLICABLE_DEVICE - on not applicable device
*
* COMMENTS:
*       None.
*******************************************************************************/
GT_STATUS cpssDxChCosPortDpToCfiDeiMapEnableSet
(
    IN GT_U8    devNum,
    IN GT_U8    port,
    IN GT_BOOL  enable
);

/*******************************************************************************
* cpssDxChCosPortDpToCfiDeiMapEnableGet
*
* DESCRIPTION:
*       Gets status (Enabled/Disabled) of Drop Precedence mapping to
*       Drop Eligibility Indicator bit.
*       When enabled on egress port the DEI(CFI) bit at the outgoing VLAN
*       tag is set according to the packet DP(after mapping).
*
* APPLICABLE DEVICES:   DxCh3 and above.
*
* INPUTS:
*       devNum          - device number.
*       port            - egress port number including CPU port.
*
* OUTPUTS:
*       enablePtr       - (pointer to) value of DP-to-CFI/DEI mapping on the
*                         egress port (enable/disable):
*                             GT_TRUE  - DP-to-CFI/DEI mapping enable on port.
*                             GT_FALSE - DP-to-CFI/DEI mapping disable on port.
*
* RETURNS:
*       GT_OK           - on success.
*       GT_HW_ERROR     - on hardware error.
*       GT_BAD_PARAM    - on wrong devNum or port.
*       GT_BAD_PTR      - on NULL pointer.
*       GT_NOT_APPLICABLE_DEVICE - on not applicable device
*
* COMMENTS:
*       None.
*******************************************************************************/
GT_STATUS cpssDxChCosPortDpToCfiDeiMapEnableGet
(
    IN  GT_U8   devNum,
    IN  GT_U8   port,
    OUT GT_BOOL *enablePtr
);

/*******************************************************************************
* cpssDxChCosDpToCfiDeiMapSet
*
* DESCRIPTION:
*       Maps Drop Precedence to Drop Eligibility Indicator bit.
*       Ports that support S-Tags can be enabled to map the packet's DP
*       (derived from QoS Profile assignment) to the DEI bit(appeared
*       in the outgoing S-Tag) by cpssDxChCosPortDpToCfiDeiMapEnableSet().
*
* APPLICABLE DEVICES:   DxCh3 and above.
*
* INPUTS:
*       devNum          - device number.
*       dp              - Drop Precedence [Green, Red].
*       cfiDeiBit       - value of CFI/DEI bit[0..1].
*
* OUTPUTS:
*       None.
*
* RETURNS:
*       GT_OK           - on success.
*       GT_HW_ERROR     - on hardware error.
*       GT_BAD_PARAM    - on wrong devNum or dp.
*       GT_OUT_OF_RANGE - on cfiDeiBit out of range.
*       GT_NOT_APPLICABLE_DEVICE - on not applicable device
*
* COMMENTS:
*       Three DP levels are mapped to only two values of CFI/DEI bit.
*
*******************************************************************************/
GT_STATUS cpssDxChCosDpToCfiDeiMapSet
(
    IN GT_U8                devNum,
    IN CPSS_DP_LEVEL_ENT    dp,
    IN GT_U8                cfiDeiBit
);

/*******************************************************************************
* cpssDxChCosDpToCfiDeiMapGet
*
* DESCRIPTION:
*       Gets Drop Precedence mapping to Drop Eligibility Indicator bit.
*       Ports that support S-Tags can be enabled to map the packet's DP
*       (derived from QoS Profile assignment) to the DEI bit(appeared
*       in the outgoing S-Tag) by cpssDxChCosPortDpToCfiDeiMapEnableSet().
*
* APPLICABLE DEVICES:   DxCh3 and above.
*
* INPUTS:
*       devNum          - device number.
*       dp              - Drop Precedence [Green, Red].
*
* OUTPUTS:
*       cfiDeiBitPtr    - (pointer to) value of CFI/DEI bit[0..1].
*
* RETURNS:
*       GT_OK           - on success.
*       GT_HW_ERROR     - on hardware error.
*       GT_BAD_PARAM    - on wrong devNum or dp.
*       GT_BAD_PTR      - on NULL pointer.
*       GT_NOT_APPLICABLE_DEVICE - on not applicable device
*
* COMMENTS:
*       Three DP levels are mapped to only two values of CFI/DEI bit.
*
*******************************************************************************/
GT_STATUS cpssDxChCosDpToCfiDeiMapGet
(
    IN  GT_U8               devNum,
    IN  CPSS_DP_LEVEL_ENT   dp,
    OUT GT_U8               *cfiDeiBitPtr
);

/*******************************************************************************
* cpssDxChCosExpToProfileMapSet
*
* DESCRIPTION:
*       Maps the packet MPLS exp to a QoS Profile.
*
* APPLICABLE DEVICES:  DxCh2 and above.
*
* INPUTS:
*       devNum          - device number.
*       exp             - mpls exp [0..7].
*       profileIndex    - profile index, which is assigned to a VLAN or
*                         Marvell tagged packet with the up on ports with
*                         enabled trust L2 or trust L2-L3.
*                         Ch values (0..71); Ch2(and above) values (0..127).
*
* OUTPUTS:
*       None.
*
* RETURNS:
*       GT_OK                    - on success.
*       GT_BAD_PARAM             - wrong devNum, exp or profileIndex
*       GT_NOT_APPLICABLE_DEVICE - on not applicable device
*
* COMMENTS:
*       None.
*
*******************************************************************************/
GT_STATUS cpssDxChCosExpToProfileMapSet
(
    IN  GT_U8   devNum,
    IN  GT_U32  exp,
    IN  GT_U32  profileIndex
);

/*******************************************************************************
* cpssDxChCosExpToProfileMapGet
*
* DESCRIPTION:
*       Returns the mapping of packet MPLS exp to a QoS Profile.
*
* APPLICABLE DEVICES:  DxCh2 and above.
*
* INPUTS:
*       devNum          - device number.
*       exp             - mpls exp.
*
* OUTPUTS:
*       profileIndexPtr - (pointer to)profile index, which is assigned to
*                         a VLAN or Marvell tagged packet with the up on
*                         ports with enabled trust L2 or trust L2-L3.
*
* RETURNS:
*       GT_OK                    - on success.
*       GT_BAD_PARAM             - wrong devNum, exp or profileIndex
*       GT_NOT_APPLICABLE_DEVICE - on not applicable device
*
* COMMENTS:
*       None.
*
*******************************************************************************/
GT_STATUS cpssDxChCosExpToProfileMapGet
(
    IN  GT_U8   devNum,
    IN  GT_U32  exp,
    OUT GT_U32  *profileIndexPtr
);

/*******************************************************************************
* cpssDxChCosPortQosConfigSet
*
* DESCRIPTION:
*       Configures the port's QoS attributes.
*
* APPLICABLE DEVICES:  All DxCh Devices.
*
* INPUTS:
*       devNum          - device number.
*       port            - logical port number, CPU port.
*       portQosCfgPtr   - Pointer to QoS related configuration of a port.
*                         portQosCfgPtr->qosProfileId -
*                                                   [0..71] for Ch,
*                                                   [0..127] for Ch2 and above;
*                         portQosCfgPtr->enableModifyDscp and
*                         portQosCfgPtr->enableModifyUp
*                         only [CPSS_PACKET_ATTRIBUTE_MODIFY_DISABLE_E,
*                              CPSS_PACKET_ATTRIBUTE_MODIFY_ENABLE_E]
*
* OUTPUTS:
*       None.
*
* RETURNS:
*       GT_OK                    - on success.
*       GT_BAD_PARAM             - wrong devNum, port or portQosCfgPtr
*       GT_BAD_PTR               - one of the parameters is NULL pointer
*       GT_TIMEOUT  - after max number of retries checking if PP ready
*       GT_NOT_APPLICABLE_DEVICE - on not applicable device
*
* COMMENTS:
*       None.
*
*******************************************************************************/
GT_STATUS cpssDxChCosPortQosConfigSet
(
    IN GT_U8                devNum,
    IN GT_U8                port,
    IN CPSS_QOS_ENTRY_STC  *portQosCfgPtr
);

/*******************************************************************************
* cpssDxChCosPortQosConfigGet
*
* DESCRIPTION:
*       Get the port's QoS attributes configuration.
*
* APPLICABLE DEVICES:  All DxCh Devices.
*
* INPUTS:
*       devNum          - device number.
*       port            - logical port number, CPU port.
*
* OUTPUTS:
*       portQosCfgPtr   - Pointer to QoS related configuration of a port.
*
* RETURNS:
*       GT_OK                    - on success.
*       GT_BAD_PARAM             - wrong devNum, port or portQosCfgPtr
*       GT_BAD_PTR               - one of the parameters is NULL pointer
*       GT_TIMEOUT  - after max number of retries checking if PP ready
*       GT_NOT_APPLICABLE_DEVICE - on not applicable device
*
* COMMENTS:
*       None.
*
*******************************************************************************/
GT_STATUS cpssDxChCosPortQosConfigGet
(
    IN GT_U8                devNum,
    IN GT_U8                port,
    OUT CPSS_QOS_ENTRY_STC  *portQosCfgPtr
);

/*******************************************************************************
* cpssDxChCosMacQosEntrySet
*
* DESCRIPTION:
*       Set the QoS Attribute of the MAC QoS Table Entr
*
* APPLICABLE DEVICES:  All DxCh Devices.
*
* INPUTS:
*       devNum         - device number.
*       entryIdx       - Index of a MAC QoS table's entry. Valid values 1 - 7.
*       macQosCfgPtr   - Pointer to QoS related configuration of a MAC QoS table's entry.
*                        macQosCfgPtr->qosProfileId -
*                                                   [0..71] for Ch and
*                                                   [0..127] for Ch2 and above;
*
* OUTPUTS:
*       None.
*
* RETURNS:
*       GT_OK                    - on success.
*       GT_BAD_PARAM             - wrong devNum, entryIndex or macQosCfgPtr
*       GT_BAD_PTR               - one of the parameters is NULL pointer
*       GT_NOT_APPLICABLE_DEVICE - on not applicable device
*
* COMMENTS:
*       None.
*
******************************************************************************/
GT_STATUS cpssDxChCosMacQosEntrySet
(
    IN GT_U8               devNum,
    IN GT_U32              entryIdx,
    IN CPSS_QOS_ENTRY_STC *macQosCfgPtr
);

/*******************************************************************************
* cpssDxChCosMacQosEntryGet
*
* DESCRIPTION:
*       Returns the QoS Attribute of the MAC QoS Table Entry.
*
* APPLICABLE DEVICES:  All DxCh Devices.
*
* INPUTS:
*       devNum         - device number.
*       entryIdx       - Index of a MAC QoS table's entry. Valid values 1 - 7.
*
* OUTPUTS:
*       macQosCfgPtr  - Pointer to QoS related configuration of a MAC QoS
*                        table's entry.
*
* RETURNS:
*       GT_OK           - on success.
*       GT_BAD_PARAM    - wrong devNum, entryIndex or macQosCfgPtr.
*       GT_BAD_PTR      - one of the parameters is NULL pointer.
*       GT_NOT_APPLICABLE_DEVICE - on not applicable device
*
* COMMENTS:
*       None.
*
******************************************************************************/
GT_STATUS cpssDxChCosMacQosEntryGet
(
    IN  GT_U8               devNum,
    IN  GT_U32              entryIdx,
    OUT CPSS_QOS_ENTRY_STC *macQosCfgPtr
);

/*******************************************************************************
* cpssDxChCosMacQosConflictResolutionSet
*
* DESCRIPTION:
*       Configure QoS Marking Conflict Mode.
*
* APPLICABLE DEVICES:  All DxCh Devices.
*
* INPUTS:
*       devNum              - device number.
*       macQosResolvType    - Enum holding two attributes for selecting
*                             the SA command or the DA command
*                             (0 - DA command, 1 - SA caommand).
*
* OUTPUTS:
*       None.
*
* RETURNS:
*       GT_OK                    - on success.
*       GT_BAD_PARAM             - wrong devNum or macQosResolvType
*       GT_NOT_APPLICABLE_DEVICE - on not applicable device
*
* COMMENTS:
*       None.
*
*******************************************************************************/
GT_STATUS cpssDxChCosMacQosConflictResolutionSet
(
    IN GT_U8                        devNum,
    IN CPSS_MAC_QOS_RESOLVE_ENT     macQosResolvType
);

/*******************************************************************************
* cpssDxChCosMacQosConflictResolutionGet
*
* DESCRIPTION:
*       Get Configured QoS Marking Conflict Mode.
*
* APPLICABLE DEVICES:  All DxCh Devices.
*
* INPUTS:
*       devNum              - device number.
*
* OUTPUTS:
*       macQosResolvTypePtr - Pointer Enum holding two optional attributes for
*                             selecting the SA command or the DA
*                             command (0 - DA command, 1 - SA caommand).
*
* RETURNS:
*       GT_OK                    - on success.
*       GT_BAD_PARAM             - wrong devNum or macQosResolvType
*       GT_NOT_APPLICABLE_DEVICE - on not applicable device
*
* COMMENTS:
*       None.
*
*******************************************************************************/
GT_STATUS cpssDxChCosMacQosConflictResolutionGet
(
    IN  GT_U8                        devNum,
    OUT CPSS_MAC_QOS_RESOLVE_ENT    *macQosResolvTypePtr
);

/*******************************************************************************
* cpssDxChCosRemarkTblEntrySet
*
* DESCRIPTION:
*       Sets new profile index for out profile packets.
*
* APPLICABLE DEVICES:  DxCh1, DxCh2.
*
* INPUTS:
*       devNum          - device number.
*       profileIndex    - profile index in the QoS Profile Table
*                         Ch values (0..71); Ch2(and above) values (0..127).
*       newProfileIndex - new profile index, which is assigned for out-profile
*                         packets according to Traffic Conditioner command.
*                         Ch values (0..71); Ch2(and above) values (0..127).
* OUTPUTS:
*       None.
*
* RETURNS:
*       GT_OK                    - on success.
*       GT_BAD_PARAM             - wrong devNum, profileIndex or newProfileIndex
*       GT_NOT_APPLICABLE_DEVICE - on not applicable device
*
* COMMENTS:
*       None.
*
*******************************************************************************/
GT_STATUS cpssDxChCosRemarkTblEntrySet
(
    IN GT_U8    devNum,
    IN GT_U32   profileIndex,
    IN GT_U32   newProfileIndex
);

/*******************************************************************************
* cpssDxChCosRemarkTblEntryGet
*
* DESCRIPTION:
*       Get new profile index setting for out profile packets.
*
* APPLICABLE DEVICES:  DxCh1, DxCh2.
*
* INPUTS:
*       devNum          - device number.
*       profileIndex    - profile index in the QoS Profile Table
*                         Ch values (0..71); Ch2(and above) values (0..127).
*
* OUTPUTS:
*       newProfileIndexPtr - (pointer to) new profile index, which will be
*                            assigned for out-profile packets according to
*                            Traffic Conditioner command.
*
* RETURNS:
*       GT_OK                    - on success.
*       GT_BAD_PARAM             - wrong devNum, profileIndex
*       GT_BAD_PTR               - NULL == newProfileIndexPtr
*       GT_TIMEOUT  - after max number of retries checking if PP ready
*       GT_NOT_APPLICABLE_DEVICE - on not applicable device
*
* COMMENTS:
*       None.
*
*******************************************************************************/
GT_STATUS cpssDxChCosRemarkTblEntryGet
(
    IN  GT_U8    devNum,
    IN  GT_U32   profileIndex,
    OUT GT_U32  *newProfileIndexPtr
);

/*******************************************************************************
* cpssDxChPortDefaultUPSet
*
* DESCRIPTION:
*       Set default user priority (VPT) for untagged packet to a given port.
*
* APPLICABLE DEVICES:  All DxCh Devices.
*
* INPUTS:
*       devNum       - packet processor device number.
*       port      - logical port number, CPU port.
*       defaultUserPrio  - default user priority (VPT) [0..7].
*
* OUTPUTS:
*       None.
*
* RETURNS:
*       GT_OK                    - on success
*       GT_FAIL                  - on error
*       GT_HW_ERROR              - on hardware error
*       GT_NOT_APPLICABLE_DEVICE - on not applicable device
*
* COMMENTS:
*
*******************************************************************************/
GT_STATUS cpssDxChPortDefaultUPSet
(
    IN GT_U8    devNum,
    IN GT_U8    port,
    IN GT_U8    defaultUserPrio
);

/*******************************************************************************
* cpssDxChPortDefaultUPGet
*
* DESCRIPTION:
*       Get default user priority (VPT) for untagged packet to a given port.
*
* APPLICABLE DEVICES:  All DxCh Devices.
*
* INPUTS:
*       devNum       - packet processor device number.
*       port      - logical port number, CPU port.
*
* OUTPUTS:
*       defaultUserPrioPtr  - (pointer to) default user priority (VPT).
*
* RETURNS:
*       GT_OK                    - on success
*       GT_FAIL                  - on error
*       GT_HW_ERROR              - on hardware error
*       GT_TIMEOUT  - after max number of retries checking if PP ready
*       GT_NOT_APPLICABLE_DEVICE - on not applicable device
*
* COMMENTS:
*
*******************************************************************************/
GT_STATUS cpssDxChPortDefaultUPGet
(
    IN  GT_U8    devNum,
    IN  GT_U8    port,
    OUT GT_U8   *defaultUserPrioPtr
);

/*******************************************************************************
* cpssDxChPortModifyUPSet
*
* DESCRIPTION:
*       Enable/Disable overriding a tagged packet's User Priority by
*       other assignment mechanisms.
*
* APPLICABLE DEVICES:  All DxCh Devices.
*
* INPUTS:
*       devNum         - packet processor device number.
*       port        - logical port, CPU port.
*       upOverrideEnable - GT_TRUE, enable overriding a tagged packet's
*                                   User Priority by other assignment
*                                   mechanisms.
*                          GT_FALSE for disable.
*
* OUTPUTS:
*       None.
*
* RETURNS:
*       GT_OK                    - on success
*       GT_BAD_PARAM             - wrong devNum or port.
*       GT_NOT_APPLICABLE_DEVICE - on not applicable device
*
* COMMENTS:
*       None.
*
*******************************************************************************/
GT_STATUS cpssDxChPortModifyUPSet
(
    IN GT_U8   devNum,
    IN GT_U8   port,
    IN GT_BOOL upOverrideEnable
);

/*******************************************************************************
* cpssDxChPortModifyUPGet
*
* DESCRIPTION:
*       Get Enable/Disable overriding a tagged packet's User Priority by
*       other assignment mechanisms setting.
*
* APPLICABLE DEVICES:  All DxCh Devices.
*
* INPUTS:
*       devNum         - packet processor device number.
*       port        - logical port, CPU port.
*
* OUTPUTS:
*       upOverrideEnablePtr - GT_TRUE, enable overriding a tagged packet's
*                                   User Priority by other assignment
*                                   mechanisms.
*                          GT_FALSE for disable.
*
*
* RETURNS:
*       GT_OK                    - on success
*       GT_BAD_PARAM             - wrong devNum or port.
*       GT_TIMEOUT  - after max number of retries checking if PP ready
*       GT_NOT_APPLICABLE_DEVICE - on not applicable device
*
* COMMENTS:
*       None.
*
*******************************************************************************/
GT_STATUS cpssDxChPortModifyUPGet
(
    IN  GT_U8    devNum,
    IN  GT_U8    port,
    OUT GT_BOOL *upOverrideEnablePtr
);

/*******************************************************************************
* cpssDxChCosPortQosTrustModeSet
*
* DESCRIPTION:
*       Configures port's Trust Mode.
*
* APPLICABLE DEVICES:  All DxCh Devices.
*
* INPUTS:
*       devNum              - device number.
*       port                - logical port number, CPU port.
*       portQosTrustMode    - QoS trust mode of a port.
*
*
* OUTPUTS:
*       None.
*
* RETURNS:
*       GT_OK                    - on success.
*       GT_BAD_PARAM             - wrong devNum, port or trustMode.
*       GT_NOT_APPLICABLE_DEVICE - on not applicable device
*
* COMMENTS:
*       None.
*
*******************************************************************************/
GT_STATUS cpssDxChCosPortQosTrustModeSet
(
    IN GT_U8                         devNum,
    IN GT_U8                         port,
    IN CPSS_QOS_PORT_TRUST_MODE_ENT  portQosTrustMode
);

/*******************************************************************************
* cpssDxChCosPortQosTrustModeGet
*
* DESCRIPTION:
*       Get Configured port's Trust Mode.
*
* APPLICABLE DEVICES:  All DxCh Devices.
*
* INPUTS:
*       devNum              - device number.
*       port                - logical port number, CPU port.
*
* OUTPUTS:
*       portQosTrustModePtr  - QoS trust mode of a port.
*
*
* RETURNS:
*       GT_OK                    - on success.
*       GT_BAD_PARAM             - wrong devNum, port or trustMode.
*       GT_TIMEOUT      - after max number of retries checking if PP ready.
*       GT_NOT_APPLICABLE_DEVICE - on not applicable device
*
* COMMENTS:
*       None.
*
*******************************************************************************/
GT_STATUS cpssDxChCosPortQosTrustModeGet
(
    IN  GT_U8                         devNum,
    IN  GT_U8                         port,
    OUT CPSS_QOS_PORT_TRUST_MODE_ENT  *portQosTrustModePtr
);

/*******************************************************************************
* cpssDxChCosPortReMapDSCPSet
*
* DESCRIPTION:
*       Enable/Disable DSCP-to-DSCP re-mapping.
*       Relevant for L2-L3 or L3 trust modes.
*
* APPLICABLE DEVICES:  All DxCh Devices.
*
* INPUTS:
*       devNum              - device number.
*       port                - logical port number, CPU port.
*       enableDscpMutation  - GT_TRUE: Packet's DSCP is remapped.
*                             GT_FALSE: Packet's DSCP is not remapped.
*
* OUTPUTS:
*       None.
*
* RETURNS:
*       GT_OK                    - on success.
*       GT_BAD_PARAM             - wrong devNum or port.
*       GT_NOT_APPLICABLE_DEVICE - on not applicable device
*
* COMMENTS:
*       None.
*
*******************************************************************************/
GT_STATUS cpssDxChCosPortReMapDSCPSet
(
    IN GT_U8                        devNum,
    IN GT_U8                        port,
    IN GT_BOOL                      enableDscpMutation
);

/*******************************************************************************
* cpssDxChCosPortReMapDSCPGet
*
* DESCRIPTION:
*       Get status (Enabled/Disabled) for DSCP-to-DSCP re-mapping.
*       Relevant for L2-L3 or L3 trust modes.
*
* APPLICABLE DEVICES:  All DxCh Devices.
*
* INPUTS:
*       devNum              - device number.
*       port                - logical port number, CPU port.
*
* OUTPUTS:
*       enableDscpMutationPtr   - GT_TRUE: Packet's DSCP is remapped.
*                                 GT_FALSE: Packet's DSCP is not remapped.
*
* RETURNS:
*       GT_OK                    - on success.
*       GT_BAD_PARAM             - wrong devNum or port.
*       GT_TIMEOUT      - after max number of retries checking if PP ready.
*       GT_NOT_APPLICABLE_DEVICE - on not applicable device
*
* COMMENTS:
*       None.
*
*******************************************************************************/
GT_STATUS cpssDxChCosPortReMapDSCPGet
(
    IN  GT_U8      devNum,
    IN  GT_U8      port,
    OUT GT_BOOL   *enableDscpMutationPtr
);

/*******************************************************************************
* cpssDxChCosPortVlanQoSCfgEntryGet
*
* DESCRIPTION:
*       Read an entry from HW from Ports VLAN and QoS Configuration Table.
*
* APPLICABLE DEVICES:  All DxCh Devices.
*
* INPUTS:
*        devNum  - device number
*        port    - logical port number, CPU port
*
* OUTPUTS:
*        entryPtr  - pointer to memory where will be placed next entry.
*                     size 32 Bytes.
*
* RETURNS:
*       GT_OK           - on success.
*       GT_BAD_PARAM    - wrong devNum or port.
*       GT_TIMEOUT      - after max number of retries checking if PP ready
*       GT_NOT_APPLICABLE_DEVICE - on not applicable device
*
*
* COMMENTS:
*       None.
*
*******************************************************************************/
GT_STATUS cpssDxChCosPortVlanQoSCfgEntryGet
(
    IN    GT_U8     devNum,
    IN    GT_U8     port,
    OUT   GT_U32   *entryPtr
);

/*******************************************************************************
* cpssDxChCosRemarkEntryGet
*
* DESCRIPTION:
*       Read an entry from HW Policers QoS Remarking and Initial DP Table.
*
* APPLICABLE DEVICES:  DxCh1, DxCh2.
*
* INPUTS:
*        devNum  - device number
*        index   - index of entry [0..71] for Ch and [0..127] for Ch2 and above.
*
* OUTPUTS:
*        entryPtr  - pointer to memory where will be placed next entry. size 4 Bytes
*
* RETURNS:
*       GT_OK                    - on success
*       GT_BAD_PARAM             - wrong devNum or entry index.
*       GT_TIMEOUT  - after max number of retries checking if PP ready
*       GT_NOT_APPLICABLE_DEVICE - on not applicable device
*
*
* COMMENTS:
*       None.
*
*******************************************************************************/
GT_STATUS cpssDxChCosRemarkEntryGet
(
    IN    GT_U8     devNum,
    IN    GT_U32    index,
    OUT   GT_U32   *entryPtr
);

/*******************************************************************************
* cpssDxChCosQoSProfileEntryGet
*
* DESCRIPTION:
*       Read an entry from HW QoS Profile Table on specified device.
*
* APPLICABLE DEVICES:  All DxCh Devices.
*
* INPUTS:
*        devNum  - device number
*        index   - index of entry [0..71] for Ch and [0..127] for Ch2 and above.
*
* OUTPUTS:
*        entryPtr  - pointer to memory where will be placed next entry. size 4 Bytes
*
* RETURNS:
*       GT_OK                    - on success
*       GT_BAD_PARAM             - wrong devNum or entry index.
*       GT_TIMEOUT  - after max number of retries checking if PP ready
*       GT_NOT_APPLICABLE_DEVICE - on not applicable device
*
*
* COMMENTS:
*       None.
*
*******************************************************************************/
GT_STATUS cpssDxChCosQoSProfileEntryGet
(
    IN    GT_U8     devNum,
    IN    GT_U32    index,
    OUT   GT_U32   *entryPtr
);

/*******************************************************************************
* cpssDxChCosTrustDsaTagQosModeSet
*
* DESCRIPTION:
*       Set trust DSA tag QoS mode. To enable end to end QoS in cascade system,
*       the DSA carries QoS profile assigned to the packet in previous device.
*       When the mode is set to GT_TRUE and the packet's DSA tag contains QoS
*       profile, the QoS profile assigned to the packet is assigned from the
*       DSA tag.
*       Relevant for cascading port only.
*
* APPLICABLE DEVICES:  All DxCh Devices.
*
* INPUTS:
*       devNum  - device number.
*       port    -  physical port number, CPU port.
*       enable  - trust DSA tag QoS mode.
*                 GT_FALSE - The QoS profile isn't assigned from DSA tag.
*                 GT_TRUE  - If the packets DSA tag contains a QoS profile,
*                     it is assigned to the packet.
*
* OUTPUTS:
*       None.
*
* RETURNS:
*       GT_OK                    - on success.
*       GT_BAD_PARAM             - wrong devNum or port.
*       GT_NOT_APPLICABLE_DEVICE - on not applicable device
*
* COMMENTS:
*       None.
*
*******************************************************************************/
GT_STATUS cpssDxChCosTrustDsaTagQosModeSet
(
    IN GT_U8      devNum,
    IN GT_U8      port,
    IN GT_BOOL    enable
);

/*******************************************************************************
* cpssDxChCosTrustDsaTagQosModeGet
*
* DESCRIPTION:
*       Get trust DSA tag QoS mode. To enable end to end QoS in cascade system,
*       the DSA carries QoS profile assigned to the packet in previous device.
*       When the mode is  GT_TRUE and the packet's DSA tag contains QoS
*       profile, the QoS profile assigned to the packet is assigned from the
*       DSA tag.
*       Relevant for cascading port only.
*
* APPLICABLE DEVICES:  All DxCh Devices.
*
* INPUTS:
*       devNum     - device number.
*       port       -  physical port number, CPU port.
*
* OUTPUTS:
*       enablePtr  - trust DSA tag QoS mode.
*                    GT_FALSE - The QoS profile isn't assigned from DSA tag.
*                    GT_TRUE  - If the packets DSA tag contains a QoS profile,
*                               it is assigned to the packet.
*
* RETURNS:
*       GT_OK                    - on success.
*       GT_BAD_PARAM             - wrong devNum or port.
*       GT_TIMEOUT      - after max number of retries checking if PP ready.
*       GT_NOT_APPLICABLE_DEVICE - on not applicable device
*
* COMMENTS:
*       None.
*
*******************************************************************************/
GT_STATUS cpssDxChCosTrustDsaTagQosModeGet
(
    IN  GT_U8      devNum,
    IN  GT_U8      port,
    OUT GT_BOOL    *enablePtr
);

/*******************************************************************************
* cpssDxChCosTrustExpModeSet
*
* DESCRIPTION:
*       Enable/Disable trust EXP mode for MPLS packets.
*
* APPLICABLE DEVICES:  DxChXCat and above devices.
*
* INPUTS:
*       devNum  - device number.
*       port    - port number, CPU port.
*       enable  - trust the MPLS header's EXP field.
*                 GT_FALSE - QoS profile from Exp To Qos Profile table
*                            not assigned to the MPLS packet.
*                 GT_TRUE  - QoS profile from Exp To Qos Profile table
*                            assigned to the MPLS packet.
*
* OUTPUTS:
*       None.
*
* RETURNS:
*       GT_OK                    - on success.
*       GT_BAD_PARAM             - wrong devNum or port.
*       GT_NOT_APPLICABLE_DEVICE - on not applicable device
*
* COMMENTS:
*       None.
*
*******************************************************************************/
GT_STATUS cpssDxChCosTrustExpModeSet
(
    IN GT_U8      devNum,
    IN GT_U8      port,
    IN GT_BOOL    enable
);

/*******************************************************************************
* cpssDxChCosTrustExpModeGet
*
* DESCRIPTION:
*       Get Enable/Disable state of trust EXP mode for MPLS packets.
*
* APPLICABLE DEVICES:  DxChXCat and above devices.
*
*
* INPUTS:
*       devNum     - device number.
*       port       - port number, CPU port.
*
* OUTPUTS:
*       enablePtr  - (pointer to) trust the MPLS header's EXP field.
*                    GT_FALSE - QoS profile from Exp To Qos Profile table
*                               not assigned to the MPLS packet.
*                    GT_TRUE  - QoS profile from Exp To Qos Profile table
*                               assigned to the MPLS packet.
*
* RETURNS:
*       GT_OK                    - on success.
*       GT_BAD_PARAM             - wrong devNum or port.
*       GT_TIMEOUT               - after max number of retries checking if PP ready.
*       GT_BAD_PTR               - one of the parameters is NULL pointer
*       GT_NOT_APPLICABLE_DEVICE - on not applicable device
*
* COMMENTS:
*       None.
*
*******************************************************************************/
GT_STATUS cpssDxChCosTrustExpModeGet
(
    IN  GT_U8      devNum,
    IN  GT_U8      port,
    OUT GT_BOOL    *enablePtr
);

/*******************************************************************************
* cpssDxChCosL2TrustModeVlanTagSelectSet
*
* DESCRIPTION:
*       Select type of VLAN tag (either Tag0 or Tag1) for Trust L2 Qos mode.
*
* APPLICABLE DEVICES:  DxChXCat and above devices.
*
* INPUTS:
*       devNum          - device number.
*       port            - port number, CPU port.
*       vlanTagType     - Vlan Tag Type (tag0 or tag1)
*
* OUTPUTS:
*       None.
*
* RETURNS:
*       GT_OK                    - on success.
*       GT_BAD_PARAM             - wrong devNum or port or vlanTagType.
*       GT_NOT_APPLICABLE_DEVICE - on not applicable device
*
* COMMENTS:
*       None.
*
*******************************************************************************/
GT_STATUS cpssDxChCosL2TrustModeVlanTagSelectSet
(
    IN GT_U8                     devNum,
    IN GT_U8                     port,
    IN CPSS_VLAN_TAG_TYPE_ENT    vlanTagType
);

/*******************************************************************************
* cpssDxChCosL2TrustModeVlanTagSelectGet
*
* DESCRIPTION:
*       Get Selected type of VLAN tag (either Tag0 or Tag1) for Trust L2 Qos mode.
*
* APPLICABLE DEVICES:  DxChXCat and above devices.
*
*
* INPUTS:
*       devNum     - device number.
*       port       - port number, CPU port.
*
* OUTPUTS:
*       vlanTagTypePtr  - (pointer to)Vlan Tag Type (tag0 or tag1)
*
* RETURNS:
*       GT_OK                    - on success.
*       GT_BAD_PARAM             - wrong devNum or port.
*       GT_BAD_PTR               - one of the parameters is NULL pointer
*       GT_NOT_APPLICABLE_DEVICE - on not applicable device
*
* COMMENTS:
*       None.
*
*******************************************************************************/
GT_STATUS cpssDxChCosL2TrustModeVlanTagSelectGet
(
    IN  GT_U8                     devNum,
    IN  GT_U8                     port,
    OUT CPSS_VLAN_TAG_TYPE_ENT    *vlanTagTypePtr
);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* __cpssDxChCosh */
