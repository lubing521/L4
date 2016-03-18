/*******************************************************************************
*              (c), Copyright 2001, Marvell International Ltd.                 *
* THIS CODE CONTAINS CONFIDENTIAL INFORMATION OF MARVELL SEMICONDUCTOR, INC.   *
* NO RIGHTS ARE GRANTED HEREIN UNDER ANY PATENT, MASK WORK RIGHT OR COPYRIGHT  *
* OF MARVELL OR ANY THIRD PARTY. MARVELL RESERVES THE RIGHT AT ITS SOLE        *
* DISCRETION TO REQUEST THAT THIS CODE BE IMMEDIATELY RETURNED TO MARVELL.     *
* THIS CODE IS PROVIDED "AS IS". MARVELL MAKES NO WARRANTIES, EXPRESSED,       *
* IMPLIED OR OTHERWISE, REGARDING ITS ACCURACY, COMPLETENESS OR PERFORMANCE.   *
********************************************************************************
* cpssDxChNetIf.h
*
* DESCRIPTION:
*       Include DxCh network interface API functions
*
*
* FILE REVISION NUMBER:
*       $Revision: 14 $
*******************************************************************************/
#ifndef __cpssDxChNetIfh
#define __cpssDxChNetIfh

#ifdef __cplusplus
extern "C" {
#endif

#include <cpss/generic/networkIf/cpssGenNetIfTypes.h>
#include <cpss/dxCh/dxChxGen/networkIf/cpssDxChNetIfTypes.h>

/*******************************************************************************
* cpssDxChNetIfInit
*
* DESCRIPTION:
*       Initialize the network interface SDMA structures, Rx descriptors & buffers
*       and Tx descriptors.
*
* APPLICABLE DEVICES:  All DxCh devices.
*
* INPUTS:
*       devNum  - The device to initialize.
*
* OUTPUTS:
*       None.
*
* RETURNS:
*       GT_OK                    - on success,
*       GT_FAIL                  - otherwise.
*       GT_NOT_APPLICABLE_DEVICE - on not applicable device
*
* COMMENTS:
*   The application must call only one of the following APIs per device:
*   cpssDxChNetIfMiiInit - for MII/RGMII Ethernet port networkIf initialization.
*   cpssDxChNetIfInit - for SDMA networkIf initialization.
*   In case more than one of the mentioned above API is called
*   GT_FAIL will be return.
*
*******************************************************************************/
GT_STATUS cpssDxChNetIfInit
(
    IN  GT_U8       devNum
);

/*******************************************************************************
* cpssDxChNetIfRemove
*
* DESCRIPTION:
*       This function is called upon Hot removal of a device, inorder to release
*       all Network Interface related structures.
*
* APPLICABLE DEVICES: ALL DXCH Devices
*
* INPUTS:
*       devNum  - The device that was removed.
*
* OUTPUTS:
*       None.
*
* RETURNS:
*       GT_OK                    - on success,
*       GT_FAIL                  - otherwise.
*       GT_BAD_PARAM             - one of the parameters value is wrong
*       GT_NOT_APPLICABLE_DEVICE - on not applicable device
*
* COMMENTS:
*       None.
*
*******************************************************************************/
GT_STATUS cpssDxChNetIfRemove
(
    IN  GT_U8   devNum
);

/*******************************************************************************
* cpssDxChNetIfPrePendTwoBytesHeaderSet
*
* DESCRIPTION:
*       Enables/Disable pre-pending a two-byte header to all packets forwarded
*       to the CPU (via the CPU port or the PCI interface).
*       This two-byte header is used to align the IPv4 header to 32 bits.
*
* APPLICABLE DEVICES: All DxCh devices
*
* INPUTS:
*        devNum    - device number
*        enable    - GT_TRUE  - Two-byte header is pre-pended to packets
*                               forwarded to the CPU.
*                    GT_FALSE - Two-byte header is not pre-pended to packets
*                               forward to the CPU.
*
* OUTPUTS:
*       None.
*
* RETURNS:
*       GT_OK                    - on success
*       GT_FAIL                  - on error
*       GT_BAD_PARAM             - on bad parameters
*       GT_NOT_APPLICABLE_DEVICE - on not applicable device
*
* COMMENTS:
*
*
*******************************************************************************/
GT_STATUS cpssDxChNetIfPrePendTwoBytesHeaderSet
(
    IN  GT_U8                           devNum,
    IN  GT_BOOL                         enable
);

/*******************************************************************************
* cpssDxChNetIfPrePendTwoBytesHeaderGet
*
* DESCRIPTION:
*       Get the Enable/Disable status of pre-pending a two-byte header to all
*       packets forwarded to the CPU (via the CPU port or the PCI interface).
*       This two-byte header is used to align the IPv4 header to 32 bits.
*
* APPLICABLE DEVICES: All DxCh devices
*
* INPUTS:
*        devNum    - device number
*
* OUTPUTS:
*        enablePtr -  (pointer to) GT_TRUE  - Two-byte header is pre-pended
*                                  to packets forwarded to the CPU.
*                    GT_FALSE - Two-byte header is not pre-pended to packets
*                               forward to the CPU.
*
* RETURNS:
*       GT_OK                    - on success
*       GT_FAIL                  - on error
*       GT_BAD_PARAM             - on bad parameters
*       GT_NOT_APPLICABLE_DEVICE - on not applicable device
*
* COMMENTS:
*
*
*******************************************************************************/
GT_STATUS cpssDxChNetIfPrePendTwoBytesHeaderGet
(
    IN  GT_U8        devNum,
    OUT  GT_BOOL    *enablePtr
);

/*******************************************************************************
* cpssDxChNetIfRxBufFree
*
* DESCRIPTION:
*       Frees a list of buffers, that where previously passed to the upper layer
*       in an Rx event.
*
* APPLICABLE DEVICES: All DxCh devices
*
* INPUTS:
*       devNum      - The device number through which these buffers where
*                     received.
*       rxQueue     - The Rx queue number through which these buffers where
*                     received.
*       rxBuffList  - List of Rx buffers to be freed.
*       buffListLen - Length of rxBufList.
*
* OUTPUTS:
*       None.
*
* RETURNS:
*       GT_OK on success, or
*       GT_FAIL otherwise.
*       GT_BAD_PARAM             - one of the parameters value is wrong
*       GT_BAD_PTR               - one of the parameters is NULL pointer
*       GT_NOT_INITIALIZED       - the library was not initialized
*       GT_NOT_APPLICABLE_DEVICE - on not applicable device
*
* COMMENTS:
*       None.
*
*******************************************************************************/
GT_STATUS cpssDxChNetIfRxBufFree
(
    IN GT_U8    devNum,
    IN GT_U8    rxQueue,
    IN GT_U8    *rxBuffList[],
    IN GT_U32   buffListLen
);

/*******************************************************************************
* cpssDxChNetIfRxBufFreeWithSize
*
* DESCRIPTION:
*       Frees a list of buffers, that where previously passed to the upper layer
*       in an Rx event.
*
* APPLICABLE DEVICES: All DxCh devices
*
* INPUTS:
*       devNum      - The device number through which these buffers where
*                     received.
*       rxQueue     - The Rx queue number through which these buffers where
*                     received.
*       rxBuffList  - List of Rx buffers to be freed.
*       rxBuffSizeList  - List of Rx Buffers sizes.
*       buffListLen - Length of rxBuffList and rxBuffSize lists.
*
* OUTPUTS:
*       None.
*
* RETURNS:
*       GT_OK on success, or
*       GT_FAIL otherwise.
*       GT_BAD_PARAM             - one of the parameters value is wrong
*       GT_BAD_PTR               - one of the parameters is NULL pointer
*       GT_NOT_INITIALIZED       - the library was not initialized
*       GT_NOT_APPLICABLE_DEVICE - on not applicable device
*
* COMMENTS:
*       None.
*
*******************************************************************************/
GT_STATUS cpssDxChNetIfRxBufFreeWithSize
(
    IN GT_U8    devNum,
    IN GT_U8    rxQueue,
    IN GT_U8    *rxBuffList[],
    IN GT_U32   rxBuffSizeList[],
    IN GT_U32   buffListLen
);

/*******************************************************************************
* cpssDxChNetIfSdmaRxPacketGet
*
* DESCRIPTION:
*       This function returns packets from PP destined to the CPU port.
*        -- SDMA relate.
*
* APPLICABLE DEVICES: All DxCh devices exclude DxCh1_Diamond
*
* INPUTS:
*       devNum      - Device number.
*       queueIdx    - The queue from which this packet was received.
*       numOfBuffPtr- Num of buffs in packetBuffsArrPtr.
*
* OUTPUTS:
*       numOfBuffPtr        - Num of used buffs in packetBuffsArrPtr.
*       packetBuffsArrPtr   - (pointer to)The received packet buffers list.
*       buffLenArr          - List of buffer lengths for packetBuffsArrPtr.
*       rxParamsPtr         - (Pointer to)information parameters of received packets
*
* RETURNS:
*       GT_NO_MORE               - no more packets on the device/queue
*       GT_OK                    - packet got with no error.
*       GT_FAIL                  - failed to get the packet
*       GT_BAD_PTR               - one of the parameters is NULL pointer
*       GT_BAD_PARAM             - wrong devNum,portNum,queueIdx.
*       GT_NOT_INITIALIZED       - the library was not initialized
*       GT_DSA_PARSING_ERROR     - DSA tag parsing error.
*       GT_NOT_APPLICABLE_DEVICE - on not applicable device
*
* COMMENTS:
*       It is recommended to call cpssDxChNetIfRxBufFree for this queue
*       i.e. return the buffer to their original queue.
*
*
*******************************************************************************/
GT_STATUS cpssDxChNetIfSdmaRxPacketGet
(
    IN GT_U8                                devNum,
    IN GT_U8                                queueIdx,
    INOUT GT_U32                            *numOfBuffPtr,
    OUT GT_U8                               *packetBuffsArrPtr[],
    OUT GT_U32                              buffLenArr[],
    OUT CPSS_DXCH_NET_RX_PARAMS_STC         *rxParamsPtr
);

/*******************************************************************************
* cpssDxChNetIfSdmaRxCountersGet
*
* DESCRIPTION:
*       For each packet processor, get the Rx packet counters from its SDMA
*       packet interface.  Return the aggregate counter values for the given
*       traffic class queue. -- SDMA relate
*
* APPLICABLE DEVICES: All DxCh devices exclude DxCh1_Diamond
*
* INPUTS:
*     devNum    - device number
*     queueIdx  - traffic class queue
*
* OUTPUTS:
*     rxCountersPtr   - (pointer to) rx counters on this queue
*
* RETURNS:
*       GT_OK                    - on success
*       GT_FAIL                  - on error
*       GT_BAD_PTR               - one of the parameters is NULL pointer
*       GT_BAD_PARAM             - on bad parameters
*       GT_NOT_APPLICABLE_DEVICE - on not applicable device
*
* COMMENTS:
*       Counters are reset on every read.
*
*******************************************************************************/
GT_STATUS cpssDxChNetIfSdmaRxCountersGet
(
    IN    GT_U8      devNum,
    IN    GT_U8      queueIdx,
    OUT   CPSS_DXCH_NET_SDMA_RX_COUNTERS_STC *rxCountersPtr
);

/*******************************************************************************
* cpssDxChNetIfSdmaRxErrorCountGet
*
* DESCRIPTION:
*       Returns the total number of Rx resource errors that occurred on a given
*       Rx queue . -- SDMA relate
*
* APPLICABLE DEVICES: All DxCh devices exclude DxCh1_Diamond
*
* INPUTS:
*       devNum      - device number
*
* OUTPUTS:
*       rxErrCountPtr  - (pointer to) The total number of Rx resource errors on
*                        the device for all the queues.
*
* RETURNS:
*       GT_OK                    - on success,
*       GT_BAD_PTR               - one of the parameters is NULL pointer
*       GT_BAD_PARAM             - on bad parameters
*       GT_FAIL                  - otherwise.
*       GT_NOT_APPLICABLE_DEVICE - on not applicable device
*
* COMMENTS:
*       The counters returned by this function reflects the number of Rx errors
*       that occurred since the last call to this function.
*
*******************************************************************************/
GT_STATUS cpssDxChNetIfSdmaRxErrorCountGet
(
    IN GT_U8                                    devNum,
    OUT CPSS_NET_SDMA_RX_ERROR_COUNTERS_STC     *rxErrCountPtr
);

/*******************************************************************************
* cpssDxChNetIfSdmaTxPacketSend
*
* DESCRIPTION:
*       This function receives packet buffers & parameters from Application .
*       Prepares them for the transmit operation, and enqueues the prepared
*       descriptors to the PP's tx queues.  -- SDMA relate.
*       function activates Tx SDMA , function doesn't wait for event of
*       "Tx buffer queue" from PP
*
* APPLICABLE DEVICES: All DxCh devices exclude DxCh1_Diamond
*
* INPUTS:
*       devNum       - Device number.
*       pcktParamsPtr- The internal packet params to be set into the packet
*                      descriptors.
*       buffList     - The packet data buffers list.
*       buffLenList  - A list of the buffers len in buffList.
*       numOfBufs    - Length of buffList.
*
* OUTPUTS:
*       None.
*
* RETURNS:
*       GT_OK          - on success, or
*       GT_NO_RESOURCE - if there is not enough free elements in the fifo
*                        associated with the Event Request Handle.
*       GT_EMPTY       - if there are not enough descriptors to do the sending.
*                        relevant only to mode that CPSS not handling the events
*                        of the device , meaning during 'phase 1 init' application
*                        stated that the CPSS will not bind it's ISR -->
*                        CPSS_DXCH_PP_PHASE1_INIT_INFO_STC::intVecNum ==
*                        CPSS_PP_INTERRUPT_VECTOR_NOT_USED_CNS
*       GT_ABORTED     - if command aborted (during shutDown operation)
*       GT_HW_ERROR    - when  synchronicSend = GT_TRUE and after transmission
*                        the last descriptor own bit wasn't changed for long time.
*       GT_BAD_PARAM             - the data buffer is longer than allowed.
*                        buffer data can occupied up to the maximum
*                        number of descriptors defined.
*       GT_BAD_PTR               - one of the parameters is NULL pointer
*       GT_NOT_INITIALIZED       - the library was not initialized
*       GT_NOT_APPLICABLE_DEVICE - on not applicable device
*       GT_FAIL otherwise.
*
* COMMENTS:
*           support both :
*           ===== regular DSA tag  ====
*           ===== extended DSA tag ====
*
*       If returned status is GT_NO_RESOURCE then the application should free
*       the elements in the fifo (associated with the Handle) by calling
*       cpssExMxNetIfTxBufferQueueGet, and send the packet again.
*
*******************************************************************************/
GT_STATUS cpssDxChNetIfSdmaTxPacketSend
(
    IN GT_U8                                    devNum,
    IN CPSS_DXCH_NET_TX_PARAMS_STC              *pcktParamsPtr,
    IN GT_U8                                    *buffList[],
    IN GT_U32                                   buffLenList[],
    IN GT_U32                                   numOfBufs
);

/*******************************************************************************
* cpssDxChNetIfSdmaSyncTxPacketSend
*
*       This function receives packet buffers & parameters from Applications .
*       Prepares them for the transmit operation, and enqueues the prepared
*       descriptors to the PP's tx queues.
*       After transmition end all transmitted packets descriptors are freed.
*        -- SDMA relate.
*       function activates Tx SDMA , function wait for PP to finish processing
*       the buffers.
*
* APPLICABLE DEVICES: All DxCh devices exclude DxCh1_Diamond
*
* INPUTS:
*       devNum       - Device number.
*       pcktParamsPtr- The internal packet params to be set into the packet
*                      descriptors.
*       buffList     - The packet data buffers list.
*       buffLenList  - A list of the buffers len in buffList.
*       numOfBufs    - Length of buffList.
*
* OUTPUTS:
*       None
*
* RETURNS:
*       GT_OK          - on success, or
*       GT_NO_RESOURCE - if there is not enough free elements in the fifo
*                        associated with the Event Request Handle.
*       GT_EMPTY       - if there are not enough descriptors to do the sending.
*                        relevant only to mode that CPSS not handling the events
*                        of the device , meaning during 'phase 1 init' application
*                        stated that the CPSS will not bind it's ISR -->
*                        CPSS_DXCH_PP_PHASE1_INIT_INFO_STC::intVecNum ==
*                        CPSS_PP_INTERRUPT_VECTOR_NOT_USED_CNS
*       GT_ABORTED     - if command aborted (during shutDown operation)
*       GT_HW_ERROR    - when  synchronicSend = GT_TRUE and after transmission
*                        the last descriptor own bit wasn't changed for long time.
*       GT_BAD_PARAM             - the data buffer is longer than allowed.
*                        buffer data can occupied up to the maximum
*                        number of descriptors defined.
*       GT_BAD_PTR               - one of the parameters is NULL pointer
*       GT_NOT_INITIALIZED       - the library was not initialized
*       GT_NOT_APPLICABLE_DEVICE - on not applicable device
*       GT_FAIL otherwise.
*
* COMMENTS:
*           support both :
*           ===== regular DSA tag  ====
*           ===== extended DSA tag ====
*
*******************************************************************************/
GT_STATUS cpssDxChNetIfSdmaSyncTxPacketSend
(
    IN GT_U8                                    devNum,
    IN CPSS_DXCH_NET_TX_PARAMS_STC              *pcktParamsPtr,
    IN GT_U8                                    *buffList[],
    IN GT_U32                                   buffLenList[],
    IN GT_U32                                   numOfBufs
);

/*******************************************************************************
* cpssDxChNetIfSdmaRxQueueEnable
*
* DESCRIPTION:
*       Enable/Disable the specified traffic class queue for RX
*       on all packet processors in the system. -- SDMA relate
*
* APPLICABLE DEVICES: All DxCh devices exclude DxCh1_Diamond
*
* INPUTS:
*        devNum    - device number
*        queue     - traffic class queue
*        enable    - GT_TRUE, enable queue
*                    GT_FALSE, disable queue
*
* OUTPUTS:
*       None.
*
* RETURNS:
*       GT_OK                    - on success
*       GT_FAIL                  - on error
*       GT_BAD_PARAM             - on bad parameters
*       GT_NOT_APPLICABLE_DEVICE - on not applicable device
*
* COMMENTS:
*
*******************************************************************************/
GT_STATUS cpssDxChNetIfSdmaRxQueueEnable
(
    IN  GT_U8                           devNum,
    IN  GT_U8                           queue,
    IN  GT_BOOL                         enable
);

/*******************************************************************************
* cpssDxChNetIfSdmaTxQueueEnable
*
* DESCRIPTION:
*       Enable/Disable the specified traffic class queue for TX
*       on all packet processors in the system. -- SDMA relate
*
* APPLICABLE DEVICES: All DxCh devices exclude DxCh1_Diamond
*
* INPUTS:
*        devNum    - device number
*        queue     - traffic class queue
*        enable    - GT_TRUE, enable queue
*                    GT_FALSE, disable queue
*
* OUTPUTS:
*       None.
*
* RETURNS:
*       GT_OK                    - on success
*       GT_FAIL                  - on error
*       GT_BAD_PARAM             - on bad parameters
*       GT_NOT_APPLICABLE_DEVICE - on not applicable device
*       GT_BAD_STATE             - on CPU port is not SDMA
*
* COMMENTS:
*
*
*******************************************************************************/
GT_STATUS cpssDxChNetIfSdmaTxQueueEnable
(
    IN  GT_U8                           devNum,
    IN  GT_U8                           queue,
    IN  GT_BOOL                         enable
);

/*******************************************************************************
* cpssDxChNetIfTxBufferQueueGet
*
* DESCRIPTION:
*       This routine returns the caller the TxEnd parameters for a transmitted
*       packet.
*
* APPLICABLE DEVICES: All DxCh devices
*
* INPUTS:
*       hndl        - Handle got from gtEventBind.
*
* OUTPUTS:
*       devPtr      - The device the packet was transmitted from.
*       cookiePtr   - The user cookie handed on the transmit request.
*       queuePtr    - The queue from which this packet was transmitted
*       statusPtr   - GT_OK if packet transmission was successful, GT_FAIL on
*                     packet reject.
*
* RETURNS:
*       GT_OK on success, or
*       GT_BAD_PARAM             - one of the parameters value is wrong
*       GT_BAD_PTR               - one of the parameters is NULL pointer
*       GT_BAD_STATE             - the CPSS not handling the ISR for the device
*                                  so function must not be called
*       GT_NOT_INITIALIZED       - the library was not initialized
*       GT_NOT_APPLICABLE_DEVICE - on not applicable device
*       GT_FAIL otherwise.
*
* COMMENTS:
*       None.
*
*******************************************************************************/
GT_STATUS cpssDxChNetIfTxBufferQueueGet
(
    IN  GT_U32               hndl,
    OUT GT_U8               *devPtr,
    OUT GT_PTR              *cookiePtr,
    OUT GT_U8               *queuePtr,
    OUT GT_STATUS           *statusPtr
);

/*******************************************************************************
* cpssDxChNetIfDsaTagBuild
*
* DESCRIPTION:
*       Build DSA tag bytes on the packet from the DSA tag parameters .
*
* APPLICABLE DEVICES:  All DxCh devices.
*
* INPUTS:
*       devNum - device number (different DXCH devices may support differently
*                the DSA tag)
*       dsaInfoPtr - (pointer to) the DSA parameters that need to be built into
*                   the packet
*
* OUTPUTS:
*       dsaBytesPtr - pointer to the start of DSA tag in the packet
*                     This pointer in the packet should hold space for :
*                     4 bytes when using regular DSA tag.
*                     8 bytes when using extended DSA tag.
*                     This function only set values into the 4 or 8 bytes
*                     according to the parameters in parameter dsaInfoPtr.
*                     NOTE : this memory is the caller's responsibility (to
*                     allocate / free)
*
* RETURNS:
*       GT_OK                    - on success
*       GT_BAD_PARAM             - on bad device number
*       GT_BAD_PTR               - one of the parameters in NULL pointer.
*       GT_NOT_APPLICABLE_DEVICE - on not applicable device
*
*
* COMMENTS:
*           support both :
*           ===== regular DSA tag  ====
*           ===== extended DSA tag ====
*
*******************************************************************************/
GT_STATUS cpssDxChNetIfDsaTagBuild
(
    IN  GT_U8                          devNum,
    IN  CPSS_DXCH_NET_DSA_PARAMS_STC   *dsaInfoPtr,
    OUT GT_U8                          *dsaBytesPtr
);

/*******************************************************************************
* cpssDxChNetIfDsaTagParse
*
* DESCRIPTION:
*       parse the DSA tag parameters from the DSA tag on the packet.
*
* APPLICABLE DEVICES:  All DxCh devices.
*
* INPUTS:
*       devNum - device number (different DXCH devices may support differently
*                the DSA tag)
*       dsaBytesPtr - pointer to the start of DSA tag in the packet
*
* OUTPUTS:
*       dsaInfoPtr - (pointer to) the DSA parameters that were parsed from the
*                   packet
*
* RETURNS:
*       GT_OK                    - on success
*       GT_BAD_PARAM             - on bad device number
*       GT_BAD_PTR               - one of the parameters in NULL pointer.
*       GT_DSA_PARSING_ERROR     - DSA tag parsing error.
*       GT_NOT_APPLICABLE_DEVICE - on not applicable device
*
*
* COMMENTS:
*           support both :
*           ===== regular DSA tag  ====
*           ===== extended DSA tag ====
*
*******************************************************************************/
GT_STATUS cpssDxChNetIfDsaTagParse
(
    IN  GT_U8                          devNum,
    IN  GT_U8                          *dsaBytesPtr,
    OUT CPSS_DXCH_NET_DSA_PARAMS_STC   *dsaInfoPtr
);

/*******************************************************************************
* cpssDxChNetIfDuplicateEnableSet
*
* DESCRIPTION:
*       Enable descriptor duplication (mirror, STC and ingress mirroring
*       to analyzer port when the analyzer port is the CPU), Or Disable any kind
*       of duplication.
*
*
* APPLICABLE DEVICES: DxCh2 and above
*
* INPUTS:
*       devNum - device number
*       enable -
*               GT_FALSE = Disable any kind of duplication
*
*               GT_TRUE = enable descriptor duplication (mirror, STC and ingress
*                         mirroring to analyzer port when the analyzer port is
*                         the CPU).
*
* OUTPUTS:
*       None
*
* RETURNS:
*       GT_OK                    - on success
*       GT_FAIL                  - on error
*       GT_HW_ERROR              - on hardware error
*       GT_BAD_PARAM             - on bad device number
*       GT_NOT_APPLICABLE_DEVICE - on not applicable device
*
*
* COMMENTS:
*
*
*******************************************************************************/
GT_STATUS cpssDxChNetIfDuplicateEnableSet
(
    IN  GT_U8                          devNum,
    IN  GT_BOOL                        enable
);


/*******************************************************************************
* cpssDxChNetIfPortDuplicateToCpuSet
*
* DESCRIPTION:
*       set per ingress port if Packets received from the port that are
*       duplicated and their duplication target is the CPU, ( mirror, STC and
*       ingress mirroring to analyzer port when the analyzer port is the CPU)
*       are will be duplicated or just are only forwarded to their original
*       target.
*       NOTE : port may be "CPU port" (63)
*
* APPLICABLE DEVICES: DxCh2 and above
*
* INPUTS:
*       devNum - device number
*       portNum - port number
*       enable -
*               GT_FALSE = Packets received from the port that are duplicated
*                          and their duplication target is the CPU, (mirror, STC
*                          and ingress mirroring to analyzer port when the
*                          analyzer port is the CPU) are not duplicated and are
*                          only forwarded to their original target.
*
*               GT_TRUE = Packets received from the port that are duplicated and
*                         their duplication target is the CPU, (mirror, STC and
*                         ingress mirroring to analyzer port when the analyzer
*                         port is the CPU) are duplicated and are only forwarded
*                         to their original target and to the CPU.
*
* OUTPUTS:
*       None
*
* RETURNS:
*       GT_OK                    - on success
*       GT_FAIL                  - on error
*       GT_HW_ERROR              - on hardware error
*       GT_BAD_PARAM             - on bad device number or port number
*       GT_NOT_APPLICABLE_DEVICE - on not applicable device
*
*
* COMMENTS:
*
*
*******************************************************************************/
GT_STATUS cpssDxChNetIfPortDuplicateToCpuSet
(
    IN  GT_U8                          devNum,
    IN  GT_U8                          portNum,
    IN  GT_BOOL                        enable
);

/*******************************************************************************
* cpssDxChNetIfAppSpecificCpuCodeTcpSynSet
*
* DESCRIPTION:
*       Enable/Disable Application Specific CPU Code for TCP SYN packets
*       forwarded to the CPU - TCP_SYN_TO_CPU.
*       The feature enabled for packets if one of conditions are true:
*       1. MAC DA is found in the FDB and Application Specific CPU Code field
*           of FDB entry is True (see appCpuCodeEn in GT_MAC_ENTRY)
*       2. Packet passed Routing and Application Specific CPU Code field is
*           True in the Route entry (Next Hop)
*
* APPLICABLE DEVICES: DxCh2 and above
*
* INPUTS:
*       devNum - Device number.
*       enable - GT_TRUE  - enable application specific CPU Code for TCP SYN
*                           packets.
*               GT_FALSE - disable application specific CPU Code for TCP SYN
*                           packets.
*
* OUTPUTS:
*       None.
*
* RETURNS:
*       GT_OK                    - on success
*       GT_FAIL                  - on error
*       GT_HW_ERROR              - on hardware error
*       GT_BAD_PARAM             - on bad device number
*       GT_NOT_APPLICABLE_DEVICE - on not applicable device
*
* COMMENTS:
*
*
*******************************************************************************/
GT_STATUS cpssDxChNetIfAppSpecificCpuCodeTcpSynSet
(
    IN  GT_U8                          devNum,
    IN  GT_BOOL                        enable
);

/*******************************************************************************
* cpssDxChNetIfAppSpecificCpuCodeTcpSynGet
*
* DESCRIPTION:
*       Get whether Application Specific CPU Code for TCP SYN packets forwarded
*       to the CPU - TCP_SYN_TO_CPU.
*
* APPLICABLE DEVICES: DxCh2 and above
*
* INPUTS:
*       devNum - Device number.
*
* OUTPUTS:
*       enablePtr - (pointer to) is the feature enabled
*               GT_TRUE  - enabled ,application specific CPU Code for TCP SYN
*                           packets.
*               GT_FALSE - disabled ,application specific CPU Code for TCP SYN
*                           packets.
*
* RETURNS:
*       GT_OK                    - on success
*       GT_FAIL                  - on error
*       GT_HW_ERROR              - on hardware error
*       GT_BAD_PARAM             - on bad device number
*       GT_BAD_PTR               - one of the parameters in NULL pointer.
*       GT_NOT_APPLICABLE_DEVICE - on not applicable device
*
* COMMENTS:
*
*
*******************************************************************************/
GT_STATUS cpssDxChNetIfAppSpecificCpuCodeTcpSynGet
(
    IN  GT_U8                          devNum,
    OUT GT_BOOL                        *enablePtr
);

/*******************************************************************************
* cpssDxChNetIfAppSpecificCpuCodeIpProtocolSet
*
* DESCRIPTION:
*       Set IP Protocol in the IP Protocol CPU Code Table  with specific
*       CPU Code. There are 8 IP Protocols may be defined.
*       The feature enabled for packets if one of conditions are true:
*       1. MAC DA is found in the FDB and Application Specific CPU Code field
*           of FDB entry is True (see appCpuCodeEn in GT_MAC_ENTRY)
*       2. Packet passed Routing and Application Specific CPU Code field is
*           True in the Route entry (Next Hop)
*
* APPLICABLE DEVICES: DxCh2 and above
*
* INPUTS:
*       devNum   - Device number.
*       index     - the index of the IP Protocol (range 0..7)
*       protocol  - IP protocol (range 0..255)
*       cpuCode   - CPU Code for given IP protocol
*
* OUTPUTS:
*       None.
*
* RETURNS:
*       GT_OK                    - on success
*       GT_FAIL                  - on error
*       GT_HW_ERROR              - on hardware error
*       GT_BAD_PARAM     - on bad device number or bad index or bad cpuCode
*       GT_NOT_APPLICABLE_DEVICE - on not applicable device
*
* COMMENTS:
*
*******************************************************************************/
GT_STATUS cpssDxChNetIfAppSpecificCpuCodeIpProtocolSet
(
    IN GT_U8            devNum,
    IN GT_U32           index,
    IN GT_U8            protocol,
    IN CPSS_NET_RX_CPU_CODE_ENT   cpuCode
);

/*******************************************************************************
* cpssDxChNetIfAppSpecificCpuCodeIpProtocolInvalidate
*
* DESCRIPTION:
*       Invalidate entry in the IP Protocol CPU Code Table .
*
* APPLICABLE DEVICES: DxCh2 and above
*
* INPUTS:
*       devNum   - Device number.
*       index     - the index of the IP Protocol (range 0..7)
*
* OUTPUTS:
*       None.
*
* RETURNS:
*       GT_OK                    - on success
*       GT_FAIL                  - on error
*       GT_HW_ERROR              - on hardware error
*       GT_BAD_PARAM             - on bad device number or bad index
*       GT_NOT_APPLICABLE_DEVICE - on not applicable device
*
* COMMENTS:
*
*******************************************************************************/
GT_STATUS cpssDxChNetIfAppSpecificCpuCodeIpProtocolInvalidate
(
    IN GT_U8            devNum,
    IN GT_U32           index
);

/*******************************************************************************
* cpssDxChNetIfAppSpecificCpuCodeIpProtocolGet
*
* DESCRIPTION:
*       Get IP Protocol in the IP Protocol CPU Code Table  with specific
*       CPU Code.
*
* APPLICABLE DEVICES: DxCh2 and above
*
* INPUTS:
*       devNum   - Device number.
*       index     - the index of the IP Protocol (range 0..7)
*
* OUTPUTS:
*       validPtr     - (pointer to)valid entry.
*                       GT_FALSE - the entry is not valid
*                       GT_TRUE - the entry is valid
*       protocolPtr  - (pointer to)IP protocol (range 0..255)
*       cpuCodePtr   - (pointer to)CPU Code for given IP protocol
*
* RETURNS:
*       GT_OK                    - on success
*       GT_FAIL                  - on error
*       GT_HW_ERROR              - on hardware error
*       GT_BAD_PARAM             - on bad device number or bad index
*       GT_BAD_PTR               - one of the parameters is NULL pointer
*       GT_NOT_APPLICABLE_DEVICE - on not applicable device
*
* COMMENTS:
*
*******************************************************************************/
GT_STATUS cpssDxChNetIfAppSpecificCpuCodeIpProtocolGet
(
    IN GT_U8            devNum,
    IN GT_U32           index,
    OUT GT_BOOL         *validPtr,
    OUT GT_U8           *protocolPtr,
    OUT CPSS_NET_RX_CPU_CODE_ENT   *cpuCodePtr
);


/*******************************************************************************
* cpssDxChNetIfAppSpecificCpuCodeTcpUdpDestPortRangeSet
*
* DESCRIPTION:
*       Set range to TCP/UPD Destination Port Range CPU Code Table with specific
*       CPU Code. There are 16 ranges may be defined.
*       The feature enabled for packets if one of conditions are true:
*        1. MAC DA is found in the FDB and Application Specific CPU Code field
*           of FDB entry is True (see appCpuCodeEn in GT_MAC_ENTRY)
*        2. Packet passed Routing and Application Specific CPU Code field is
*           True in the Route entry (Next Hop)
*
* APPLICABLE DEVICES: DxCh2 and above
*
* INPUTS:
*       devNum     - Device number.
*       rangeIndex - the index of the range (range 0..15)
*       maxDstPort - the maximum destination port in this range.
*       minDstPort - the minimum destination port in this range
*       packetType - packet type (Unicast/Multicast)
*       protocol   - protocol type (UDP/TCP)
*       cpuCode    - CPU Code Index for this TCP/UDP range
*
* OUTPUTS:
*       None.
*
* RETURNS:
*       GT_OK                    - on success
*       GT_FAIL                  - on error
*       GT_HW_ERROR              - on hardware error
*       GT_BAD_PARAM             - on bad device number or bad rangeIndex or
*                          bad packetType or bad protocol or bad cpuCode
*       GT_NOT_APPLICABLE_DEVICE - on not applicable device
*
* COMMENTS:
*
*******************************************************************************/
GT_STATUS cpssDxChNetIfAppSpecificCpuCodeTcpUdpDestPortRangeSet
(
    IN GT_U8                            devNum,
    IN GT_U32                           rangeIndex,
    IN GT_U16                           minDstPort,
    IN GT_U16                           maxDstPort,
    IN CPSS_NET_TCP_UDP_PACKET_TYPE_ENT packetType,
    IN CPSS_NET_PROT_ENT                protocol,
    IN CPSS_NET_RX_CPU_CODE_ENT         cpuCode
);

/*******************************************************************************
* cpssDxChNetIfAppSpecificCpuCodeTcpUdpDestPortRangeInvalidate
*
* DESCRIPTION:
*       invalidate range to TCP/UPD Destination Port Range CPU Code Table with
*       specific CPU Code. There are 16 ranges may be defined.
*
* APPLICABLE DEVICES: DxCh2 and above
*
* INPUTS:
*       devNum     - Device number.
*       rangeIndex - the index of the range (range 0..15)
*
* OUTPUTS:
*       None.
*
* RETURNS:
*       GT_OK                    - on success
*       GT_FAIL                  - on error
*       GT_HW_ERROR              - on hardware error
*       GT_BAD_PARAM             - on bad device number or bad rangeIndex
*       GT_NOT_APPLICABLE_DEVICE - on not applicable device
*
* COMMENTS:
*
*******************************************************************************/
GT_STATUS cpssDxChNetIfAppSpecificCpuCodeTcpUdpDestPortRangeInvalidate
(
    IN GT_U8                            devNum,
    IN GT_U32                           rangeIndex
);


/*******************************************************************************
* cpssDxChNetIfAppSpecificCpuCodeTcpUdpDestPortRangeGet
*
* DESCRIPTION:
*       Get range for TCP/UPD Destination Port Range CPU Code Table with specific
*       CPU Code. There are 16 ranges may be defined.
*       The feature enabled for packets if one of conditions are true:
*        1. MAC DA is found in the FDB and Application Specific CPU Code field
*           of FDB entry is True (see appCpuCodeEn in GT_MAC_ENTRY)
*        2. Packet passed Routing and Application Specific CPU Code field is
*           True in the Route entry (Next Hop)
*
* APPLICABLE DEVICES: DxCh2 and above
*
* INPUTS:
*       devNum     - Device number.
*       rangeIndex - the index of the range (range 0..15)
*
* OUTPUTS:
*       validPtr  - (pointer to) is the entry valid
*                   GT_FALSE - range is't valid
*                   GT_TRUE  - range is valid
*       maxDstPortPtr - (pointer to)the maximum destination port in this range.
*       minDstPortPtr - (pointer to)the minimum destination port in this range
*       packetTypePtr - (pointer to)packet type (Unicast/Multicast)
*       protocolPtr- (pointer to)protocol type (UDP/TCP)
*                    NOTE : this field will hold valid value only when
*                           (*validPtr) = GT_TRUE
*                           because in HW the "valid" is one of the protocol
*                           options
*       cpuCodePtr - (pointer to)CPU Code Index for this TCP/UDP range
*
* RETURNS:
*       GT_OK                    - on success
*       GT_FAIL                  - on error
*       GT_HW_ERROR              - on hardware error
*       GT_BAD_PARAM             - on bad device number or bad rangeIndex
*       GT_BAD_PTR               - one of the parameters is NULL pointer
*       GT_NOT_APPLICABLE_DEVICE - on not applicable device
*
* COMMENTS:
*
*******************************************************************************/
GT_STATUS cpssDxChNetIfAppSpecificCpuCodeTcpUdpDestPortRangeGet
(
    IN GT_U8                             devNum,
    IN GT_U32                            rangeIndex,
    OUT GT_BOOL                          *validPtr,
    OUT GT_U16                           *minDstPortPtr,
    OUT GT_U16                           *maxDstPortPtr,
    OUT CPSS_NET_TCP_UDP_PACKET_TYPE_ENT *packetTypePtr,
    OUT CPSS_NET_PROT_ENT                *protocolPtr,
    OUT CPSS_NET_RX_CPU_CODE_ENT         *cpuCodePtr
);

/*******************************************************************************
* cpssDxChNetIfCpuCodeIpLinkLocalProtSet
*
* DESCRIPTION:
*       Configure CPU code for IPv4 and IPv6 Link Local multicast packets
*       with destination IP in range of 224.0.0.0 ... 224.0.0.255
*
* APPLICABLE DEVICES: DxCh2 and above
*
* INPUTS:
*       devNum   - Device number.
*       ipVer    - IP version: Ipv4 or Ipv6
*       protocol - Specifies the LSB of IP Link Local multicast protocol
*       cpuCode  - The CPU Code
*           The 4 CPU acceptable CPU Codes are:
*               CPSS_NET_IPV4_IPV6_LINK_LOCAL_MC_DIP_TRP_MRR_E
*               CPSS_NET_IPV4_IPV6_LINK_LOCAL_MC_DIP_TRP_MRR_1_E
*               CPSS_NET_IPV4_IPV6_LINK_LOCAL_MC_DIP_TRP_MRR_2_E
*               CPSS_NET_IPV4_IPV6_LINK_LOCAL_MC_DIP_TRP_MRR_3_E
*
* OUTPUTS:
*       None.
*
* RETURNS:
*       GT_OK                    - on success
*       GT_FAIL                  - on error
*       GT_HW_ERROR              - on hardware error
*       GT_BAD_PARAM     - on bad device number or bad ipVer or bad cpuCode
*       GT_NOT_APPLICABLE_DEVICE - on not applicable device
*
*
*******************************************************************************/
GT_STATUS cpssDxChNetIfCpuCodeIpLinkLocalProtSet
(
    IN GT_U8                devNum,
    IN CPSS_IP_PROTOCOL_STACK_ENT    ipVer,
    IN GT_U8                protocol,
    IN CPSS_NET_RX_CPU_CODE_ENT  cpuCode
);

/*******************************************************************************
* cpssDxChNetIfCpuCodeIpLinkLocalProtGet
*
* DESCRIPTION:
*       get the Configuration CPU code for IPv4 and IPv6 Link Local multicast
*       packets with destination IP in range of 224.0.0.0 ... 224.0.0.255
*
* APPLICABLE DEVICES: DxCh2 and above
*
* INPUTS:
*       devNum   - Device number.
*       ipVer    - IP version: Ipv4 or Ipv6
*       protocol - Specifies the LSB of IP Link Local multicast protocol
*
* OUTPUTS:
*       cpuCodePtr  - (pointer to) The CPU Code
*           The 4 CPU acceptable CPU Codes are:
*               CPSS_NET_IPV4_IPV6_LINK_LOCAL_MC_DIP_TRP_MRR_E
*               CPSS_NET_IPV4_IPV6_LINK_LOCAL_MC_DIP_TRP_MRR_1_E
*               CPSS_NET_IPV4_IPV6_LINK_LOCAL_MC_DIP_TRP_MRR_2_E
*               CPSS_NET_IPV4_IPV6_LINK_LOCAL_MC_DIP_TRP_MRR_3_E
*
* RETURNS:
*       GT_OK                    - on success
*       GT_FAIL                  - on error
*       GT_HW_ERROR              - on hardware error
*       GT_BAD_PARAM             - on bad device number or bad ipVer
*       GT_BAD_PTR               - one of the parameters is NULL pointer
*       GT_NOT_APPLICABLE_DEVICE - on not applicable device
*
*
*******************************************************************************/
GT_STATUS cpssDxChNetIfCpuCodeIpLinkLocalProtGet
(
    IN GT_U8                devNum,
    IN CPSS_IP_PROTOCOL_STACK_ENT    ipVer,
    IN GT_U8                protocol,
    OUT CPSS_NET_RX_CPU_CODE_ENT  *cpuCodePtr
);

/*******************************************************************************
* cpssDxChNetIfCpuCodeIeeeReservedMcastProtSet
*
* DESCRIPTION:
*       Configure CPU code for particular IEEE reserved mcast protocol
*       (01-80-C2-00-00-00  ... 01-80-C2-00-00-FF)
*
* APPLICABLE DEVICES: DxCh2 and above
*
* INPUTS:
*       devNum   - Device number.
*       protocol - Specifies the LSB of IEEE Multicast protocol
*       cpuCode  - The CPU Code
*           The 4 CPU acceptable CPU Codes are:
*               CPSS_NET_IEEE_RSRVD_MULTICAST_ADDR_E
*               CPSS_NET_IEEE_RSRVD_MULTICAST_ADDR_1_E
*               CPSS_NET_IEEE_RSRVD_MULTICAST_ADDR_2_E
*               CPSS_NET_IEEE_RSRVD_MULTICAST_ADDR_3_E
*
* OUTPUTS:
*       None.
*
* RETURNS:
*       GT_OK                    - on success
*       GT_FAIL                  - on error
*       GT_HW_ERROR              - on hardware error
*       GT_BAD_PARAM             - on bad device number or bad cpuCode
*       GT_NOT_APPLICABLE_DEVICE - on not applicable device
*
* COMMENTS:
*
*******************************************************************************/
GT_STATUS cpssDxChNetIfCpuCodeIeeeReservedMcastProtSet
(
    IN GT_U8            devNum,
    IN GT_U8            protocol,
    IN CPSS_NET_RX_CPU_CODE_ENT   cpuCode
);

/*******************************************************************************
* cpssDxChNetIfCpuCodeIeeeReservedMcastProtGet
*
* DESCRIPTION:
*       get the Configuration CPU code for particular IEEE reserved mcast protocol
*       (01-80-C2-00-00-00  ... 01-80-C2-00-00-FF)
*
* APPLICABLE DEVICES: DxCh2 and above
*
* INPUTS:
*       devNum   - Device number.
*       protocol - Specifies the LSB of IEEE Multicast protocol
*
* OUTPUTS:
*       cpuCodePtr  - (pointer to)The CPU Code
*           The 4 CPU acceptable CPU Codes are:
*               CPSS_NET_IEEE_RSRVD_MULTICAST_ADDR_E
*               CPSS_NET_IEEE_RSRVD_MULTICAST_ADDR_1_E
*               CPSS_NET_IEEE_RSRVD_MULTICAST_ADDR_2_E
*               CPSS_NET_IEEE_RSRVD_MULTICAST_ADDR_3_E
*
* RETURNS:
*       GT_OK                    - on success
*       GT_FAIL                  - on error
*       GT_HW_ERROR              - on hardware error
*       GT_BAD_PARAM             - on bad device number
*       GT_BAD_PTR               - one of the parameters is NULL pointer
*       GT_NOT_APPLICABLE_DEVICE - on not applicable device
*
* COMMENTS:
*
*******************************************************************************/
GT_STATUS cpssDxChNetIfCpuCodeIeeeReservedMcastProtGet
(
    IN GT_U8            devNum,
    IN GT_U8            protocol,
    OUT CPSS_NET_RX_CPU_CODE_ENT   *cpuCodePtr
);

/*******************************************************************************
* cpssDxChNetIfCpuCodeTableSet
*
* DESCRIPTION:
*       Function to set the "CPU code table" entry, for a specific CPU code.
*
* APPLICABLE DEVICES:  All DxCh devices.
*
* INPUTS:
*       devNum  - device number
*       cpuCode - the CPU code (key parameter to access the "CPU code table").
*                 use CPSS_NET_ALL_CPU_OPCODES_E as a wildcard to be used when
*                 need to set all the table entries with the same info.
*       entryInfoPtr - (pointer to) The entry information
*
* OUTPUTS:
*       None
*
* RETURNS:
*       GT_OK                    - on success
*       GT_FAIL                  - on error
*       GT_HW_ERROR              - on hardware error
*       GT_BAD_PARAM     - on bad device number or bad cpuCode or bad one of
*                          bad one entryInfoPtr parameters
*       GT_BAD_PTR               - one of the parameters is NULL pointer
*       GT_NOT_APPLICABLE_DEVICE - on not applicable device
*
* COMMENTS:
*
*
*******************************************************************************/
GT_STATUS cpssDxChNetIfCpuCodeTableSet
(
    IN GT_U8                    devNum,
    IN CPSS_NET_RX_CPU_CODE_ENT cpuCode,
    IN CPSS_DXCH_NET_CPU_CODE_TABLE_ENTRY_STC *entryInfoPtr
);

/*******************************************************************************
* cpssDxChNetIfCpuCodeTableGet
*
* DESCRIPTION:
*       Function to get the "CPU code table" entry, for a specific CPU code.
*
* APPLICABLE DEVICES:  All DxCh devices.
*
* INPUTS:
*       devNum  - device number
*       cpuCode - the CPU code (key parameter to access the "CPU code table").
*                 use CPSS_NET_ALL_CPU_OPCODES_E as a wildcard to be used when
*                 need to set all the table entries with the same info.
*
* OUTPUTS:
*       entryInfoPtr - (pointer to) The entry information
*
* RETURNS:
*       GT_OK                    - on success
*       GT_FAIL                  - on error
*       GT_HW_ERROR              - on hardware error
*       GT_BAD_PARAM             - on bad device number or bad cpuCode
*       GT_BAD_PTR               - one of the parameters is NULL pointer
*       GT_TIMEOUT  - after max number of retries checking if PP ready
*       GT_NOT_APPLICABLE_DEVICE - on not applicable device
*
* COMMENTS:
*
*
*******************************************************************************/
GT_STATUS cpssDxChNetIfCpuCodeTableGet
(
    IN  GT_U8                    devNum,
    IN  CPSS_NET_RX_CPU_CODE_ENT cpuCode,
    OUT CPSS_DXCH_NET_CPU_CODE_TABLE_ENTRY_STC *entryInfoPtr
);

/*******************************************************************************
* cpssDxChNetIfCpuCodeStatisticalRateLimitsTableSet
*
* DESCRIPTION:
*       Function to set the "Statistical Rate Limits Table" entry.
*       The cpssDxChNetIfCpuCodeTableSet(...) points to this table (for a
*       specific CPU Code)
*
* APPLICABLE DEVICES:  All DxCh devices.
*
* INPUTS:
*       devNum  - device number
*       index - index into the Statistical Rate Limits Table (range 0..31)
*       statisticalRateLimit - The statistical rate limit compared to the
*                              32-bit pseudo-random generator (PRNG).
*           NOTE:
*           For all packets to be forwarded to the CPU, set this field to
*           0xFFFFFFFF.
*           For all packets to be dropped, set this field to 0x0.
*
*           This mechanism is based on a hardware-based 32-bit pseudo-random
*           generator (PRNG). The PRNG generates evenly-distributed 32-bit
*           numbers ranging from 0 through 0xFFFFFFFF.
*
* OUTPUTS:
*       None
*
* RETURNS:
*       GT_OK                    - on success
*       GT_FAIL                  - on error
*       GT_HW_ERROR              - on hardware error
*       GT_BAD_PARAM             - on bad device number or bad index
*       GT_NOT_APPLICABLE_DEVICE - on not applicable device
*
* COMMENTS:
*
*
*******************************************************************************/
GT_STATUS cpssDxChNetIfCpuCodeStatisticalRateLimitsTableSet
(
    IN GT_U8        devNum,
    IN GT_U32       index,
    IN GT_U32       statisticalRateLimit
);

/*******************************************************************************
* cpssDxChNetIfCpuCodeStatisticalRateLimitsTableGet
*
* DESCRIPTION:
*       Function to get the "Statistical Rate Limits Table" entry.
*       The cpssDxChNetIfCpuCodeTableSet(...) points to this table (for a
*       specific CPU Code)
*
* APPLICABLE DEVICES:  All DxCh devices.
*
* INPUTS:
*       devNum  - device number
*       index - index into the Statistical Rate Limits Table (range 0..31)
*
* OUTPUTS:
*       statisticalRateLimitPtr - (pointer to)The statistical rate limit
*             compared to the 32-bit pseudo-random generator (PRNG).
*
*           NOTE:
*           For all packets to be forwarded to the CPU, set this field to
*           0xFFFFFFFF.
*           For all packets to be dropped, set this field to 0x0.
*
*           This mechanism is based on a hardware-based 32-bit pseudo-random
*           generator (PRNG). The PRNG generates evenly-distributed 32-bit
*           numbers ranging from 0 through 0xFFFFFFFF.
*
* RETURNS:
*       GT_OK                    - on success
*       GT_FAIL                  - on error
*       GT_HW_ERROR              - on hardware error
*       GT_BAD_PARAM             - on bad device number or bad index
*       GT_BAD_PTR               - one of the parameters is NULL pointer
*       GT_TIMEOUT  - after max number of retries checking if PP ready
*       GT_NOT_APPLICABLE_DEVICE - on not applicable device
*
* COMMENTS:
*
*
*******************************************************************************/
GT_STATUS cpssDxChNetIfCpuCodeStatisticalRateLimitsTableGet
(
    IN  GT_U8       devNum,
    IN  GT_U32      index,
    OUT GT_U32      *statisticalRateLimitPtr
);

/*******************************************************************************
* cpssDxChNetIfCpuCodeDesignatedDeviceTableSet
*
* DESCRIPTION:
*       Function to set the "designated device Table" entry.
*       The cpssDxChNetIfCpuCodeTableSet(...) points to this table (for a
*       specific CPU Code)
*
* APPLICABLE DEVICES:  All DxCh devices.
*
* INPUTS:
*       devNum  - device number
*       index - index into the designated device table (range 1..7)
*       designatedDevNum - The designated device number (range 0..31)
*
* OUTPUTS:
*       None
*
* RETURNS:
*       GT_OK                    - on success
*       GT_FAIL                  - on error
*       GT_HW_ERROR              - on hardware error
*       GT_BAD_PARAM             - on bad device number or bad index or bad
*                          designatedDevNum
*       GT_NOT_APPLICABLE_DEVICE - on not applicable device
*
* COMMENTS:
*
*
*******************************************************************************/
GT_STATUS cpssDxChNetIfCpuCodeDesignatedDeviceTableSet
(
    IN GT_U8        devNum,
    IN GT_U32       index,
    IN GT_U8        designatedDevNum
);

/*******************************************************************************
* cpssDxChNetIfCpuCodeDesignatedDeviceTableGet
*
* DESCRIPTION:
*       Function to get the "designated device Table" entry.
*       The cpssDxChNetIfCpuCodeTableSet(...) points to this table (for a
*       specific CPU Code)
*
* APPLICABLE DEVICES:  All DxCh devices.
*
* INPUTS:
*       devNum  - device number
*       index - index into the designated device table (range 1..7)
*
* OUTPUTS:
*       designatedDevNumPtr - (pointer to)The designated device number
*                              (range 0..31)
*
* RETURNS:
*       GT_OK                    - on success
*       GT_FAIL                  - on error
*       GT_HW_ERROR              - on hardware error
*       GT_BAD_PARAM             - on bad device number or bad index
*       GT_BAD_PTR               - one of the parameters is NULL pointer
*       GT_NOT_APPLICABLE_DEVICE - on not applicable device
*
* COMMENTS:
*
*
*******************************************************************************/
GT_STATUS cpssDxChNetIfCpuCodeDesignatedDeviceTableGet
(
    IN  GT_U8       devNum,
    IN  GT_U32      index,
    OUT GT_U8       *designatedDevNumPtr
);

/*******************************************************************************
* cpssDxChNetIfCpuCodeRateLimiterTableSet
*
* DESCRIPTION:
*       Configure rate limiter window size and packets limit forwarded to CPU
*       per rate limiter index.
*       The cpssDxChNetIfCpuCodeTableSet(...) points to this table (for a
*       specific CPU Code)
*
* APPLICABLE DEVICES: DxCh2 and above
*
* INPUTS:
*       devNum            - Device number.
*       rateLimiterIndex - CPU Code Rate Limiter Index
*                           range 1..31.
*       windowSize        - window size for this Rate Limiter in steps of
*                           Rate Limiter Window Resolution set by
*                       cpssDxChNetIfCpuCodeRateLimiterWindowResolutionSet(...)
*                           range 0..0xFFF (12 bits)
*       pktLimit          - number of packets allowed to be sent to CPU
*                           during within the configured windowSize
*                           range 0..0xFFFF (16 bits)
*
* OUTPUTS:
*       None.
*
* RETURNS:
*       GT_OK                    - on success
*       GT_FAIL                  - on error
*       GT_HW_ERROR              - on hardware error
*       GT_BAD_PARAM             - on bad device number or bad rateLimiterIndex
*       GT_OUT_OF_RANGE - on pktLimit >= 0x10000 or windowSize >= 0x1000
*       GT_NOT_APPLICABLE_DEVICE - on not applicable device
*
* COMMENTS:
*
*
*******************************************************************************/
GT_STATUS cpssDxChNetIfCpuCodeRateLimiterTableSet
(
    IN GT_U8  devNum,
    IN GT_U32 rateLimiterIndex,
    IN GT_U32 windowSize,
    IN GT_U32 pktLimit
);

/*******************************************************************************
* cpssDxChNetIfCpuCodeRateLimiterTableGet
*
* DESCRIPTION:
*       get the Configuration rate limiter window size and packets limit
*       forwarded to CPU per rate limiter index.
*       The cpssDxChNetIfCpuCodeTableSet(...) points to this table (for a
*       specific CPU Code)
*
* APPLICABLE DEVICES: DxCh2 and above
*
* INPUTS:
*       devNum            - Device number.
*       rateLimiterIndex - CPU Code Rate Limiter Index
*                           range 1..31.
*
* OUTPUTS:
*       windowSizePtr - (pointer to) window size for this Rate Limiter in steps
*                       of Rate Limiter Window Resolution set by
*                       cpssDxChNetIfCpuCodeRateLimiterWindowResolutionSet(...)
*                           range 0..0xFFF (12 bits)
*       pktLimitPtr - (pointer to) number of packets allowed to be sent to CPU
*                           during within the configured windowSize
*                           range 0..0xFFFF (16 bits)
*
* RETURNS:
*       GT_OK                    - on success
*       GT_FAIL                  - on error
*       GT_HW_ERROR              - on hardware error
*       GT_BAD_PARAM             - on bad device number or bad rateLimiterIndex
*       GT_BAD_PTR               - one of the parameters is NULL pointer
*       GT_NOT_APPLICABLE_DEVICE - on not applicable device
*
* COMMENTS:
*
*
*******************************************************************************/
GT_STATUS cpssDxChNetIfCpuCodeRateLimiterTableGet
(
    IN  GT_U8   devNum,
    IN  GT_U32  rateLimiterIndex,
    OUT GT_U32  *windowSizePtr,
    OUT GT_U32  *pktLimitPtr
);

/*******************************************************************************
* cpssDxChNetIfCpuCodeRateLimiterWindowResolutionSet
*
* DESCRIPTION:
*       Set the TO CPU Rate Limiter Window Resolution,
*       which is used as steps in Rate Limiter Window size by
*       cpssDxChNetIfCpuCodeRateLimiterTableSet(...)
*
* APPLICABLE DEVICES: DxCh2 and above
*
* INPUTS:
*       devNum            - Device number.
*       windowResolution - The TO CPU window size resolution -- this field is
*                          the number of NanoSeconds.
*                          NOTE:
*                          The PP's actual resolution is in 32 system clock
*                          cycles (for a system clock of 200 MHz = 5nano
*                          per tick --> from 160 nanoseconds up to 327
*                          milliseconds, steps of 160 nanoseconds)
*                          So this function will round the value to the nearest
*                          PP's option.
*
* OUTPUTS:
*       None.
*
* RETURNS:
*       GT_OK                    - on success
*       GT_FAIL                  - on error
*       GT_HW_ERROR              - on hardware error
*       GT_BAD_PARAM             - on bad device number
*       GT_OUT_OF_RANGE - on windowResolution too large(depends on system clock)
*       GT_NOT_APPLICABLE_DEVICE - on not applicable device
*
* COMMENTS:
*
*
*******************************************************************************/
GT_STATUS cpssDxChNetIfCpuCodeRateLimiterWindowResolutionSet
(
    IN GT_U8  devNum,
    IN GT_U32 windowResolution
);

/*******************************************************************************
* cpssDxChNetIfCpuCodeRateLimiterWindowResolutionGet
*
* DESCRIPTION:
*       Get the TO CPU Rate Limiter Window Resolution,
*       which is used as steps in Rate Limiter Window size by
*       cpssDxChNetIfCpuCodeRateLimiterTableSet(...)
*
* APPLICABLE DEVICES: DxCh2 and above
*
* INPUTS:
*       devNum            - Device number.
*       windowResolutionPtr - (pointer to)The TO CPU window size resolution --
*                          this field is the number of NanoSeconds.
*                          NOTE:
*                          The PP's actual resolution is in 32 system clock
*                          cycles (for a system clock of 200 MHz = 5nano
*                          per tick --> from 160 nanoseconds up to 327
*                          milliseconds, steps of 160 nanoseconds)
*
* OUTPUTS:
*       None
*
* RETURNS:
*       GT_OK                    - on success
*       GT_FAIL                  - on error
*       GT_HW_ERROR              - on hardware error
*       GT_BAD_PARAM             - on bad device number
*       GT_BAD_PTR               - one of the parameters is NULL pointer
*       GT_NOT_APPLICABLE_DEVICE - on not applicable device
*
* COMMENTS:
*
*
*******************************************************************************/
GT_STATUS cpssDxChNetIfCpuCodeRateLimiterWindowResolutionGet
(
    IN GT_U8  devNum,
    IN GT_U32 *windowResolutionPtr
);

/*******************************************************************************
* cpssDxChNetIfFromCpuDpSet
*
* DESCRIPTION:
*       Set DP for from CPU DSA tag packets.
*
* APPLICABLE DEVICES: DxCh3 and above.
*
* INPUTS:
*       devNum            - device number
*       dpLevel           - drop precedence level [Green, Red].
*
* OUTPUTS:
*       None.
*
* RETURNS:
*       GT_OK                    - on success
*       GT_FAIL                  - on error
*       GT_HW_ERROR              - on hardware error
*       GT_BAD_PARAM             - on bad device number, dpLevel
*       GT_NOT_APPLICABLE_DEVICE - on not applicable device
*
* COMMENTS:
*
*
*******************************************************************************/
GT_STATUS cpssDxChNetIfFromCpuDpSet
(
    IN GT_U8               devNum,
    IN  CPSS_DP_LEVEL_ENT  dpLevel
);

/*******************************************************************************
* cpssDxChNetIfFromCpuDpGet
*
* DESCRIPTION:
*       Get DP for from CPU DSA tag packets.
*
* APPLICABLE DEVICES: DxCh3 and above.
*
* INPUTS:
*       devNum            - device number
*
* OUTPUTS:
*       dpLevelPtr        - pointer to drop precedence level
*
* RETURNS:
*       GT_OK                    - on success
*       GT_FAIL                  - on error
*       GT_HW_ERROR              - on hardware error
*       GT_BAD_PARAM             - on bad device number
*       GT_BAD_PTR               - one of the parameters is NULL pointer
*       GT_BAD_STATE             - invalid hardware value for drop precedence level
*       GT_NOT_APPLICABLE_DEVICE - on not applicable device
*
* COMMENTS:
*
*
*******************************************************************************/
GT_STATUS cpssDxChNetIfFromCpuDpGet
(
    IN  GT_U8              devNum,
    OUT CPSS_DP_LEVEL_ENT  *dpLevelPtr
);

/*******************************************************************************
* cpssDxChNetIfSdmaRxResourceErrorModeSet
*
* DESCRIPTION:
*       Set a bit per TC queue which defines the behavior in case of
*       RX resource error
*
* APPLICABLE DEVICES: All DxCh devices.
*
* INPUTS:
*       devNum     - device number.
*       queue      - traffic class queue
*       mode       - current packet mode: retry to send or abort
*
*
* OUTPUTS:
*       None.
*
* RETURNS:
*       GT_OK                    - on success
*       GT_FAIL                  - on error
*       GT_HW_ERROR              - on hardware error
*       GT_BAD_PARAM             - on bad device number, queue, mode
*       GT_NOT_APPLICABLE_DEVICE - on not applicable device
*       GT_NOT_SUPPORTED         - the request is not supported
*
* COMMENTS:
*       None.
*
*******************************************************************************/
GT_STATUS cpssDxChNetIfSdmaRxResourceErrorModeSet
(
    IN  GT_U8                                   devNum,
    IN  GT_U8                                   queue,
    IN  CPSS_DXCH_NET_RESOURCE_ERROR_MODE_ENT   mode
);

/*******************************************************************************
* cpssDxChNetIfSdmaTxBufferQueueDescFreeAndCookieGet
*
* DESCRIPTION:
*       This routine frees all transmitted packets descriptors. In addition, all
*       user relevant data in Tx End FIFO.
*
* APPLICABLE DEVICES: All DxCh devices exclude DxCh1_Diamond
*
* INPUTS:
*       devNum     - The device number the packet was transmitted from
*       txQueue    - The queue the packet was transmitted upon (0..7)
*
* OUTPUTS:
*       cookiePtr   - (pointer to) the cookie attached to packet that was send
*                     from this queue
*
* RETURNS:
*       GT_OK - on success
*       GT_BAD_PARAM - on bad device or queue
*       GT_BAD_PTR - on NULL pointer
*       GT_NO_MORE - no more packet cookies to get
*       GT_ERROR - the Tx descriptor is corrupted
*       GT_NOT_INITIALIZED - the library was not initialized
*       GT_NOT_APPLICABLE_DEVICE - on not applicable device
*
* COMMENTS:
*  1. returns the caller the cookie attached to the frame that was sent from the
*     device on the specific queue.
*  2. put the descriptors of this sent packet back to the 'Free descriptors' list
*       --> SDMA relate
*  3. this function should be used only when the ISR of the CPSS is not in use,
*     meaning that the intVecNum (given in function cpssDxChHwPpPhase1Init) was
*    set to CPSS_PP_INTERRUPT_VECTOR_NOT_USED_CNS.
*
*   NOTE: the caller is responsible to synchronize the calls to 'Tx send' and
*   this function , since both deal with the 'Tx descriptors'.
*
*******************************************************************************/
GT_STATUS cpssDxChNetIfSdmaTxBufferQueueDescFreeAndCookieGet
(
    IN GT_U8                devNum,
    IN GT_U8                txQueue,
    OUT GT_PTR             *cookiePtr
);

/*******************************************************************************
* cpssDxChNetIfSdmaTxFreeDescripotrsNumberGet
*
* DESCRIPTION:
*       This function return the number of free Tx descriptors for given
*       device and txQueue
*
* APPLICABLE DEVICES: All DxCh devices exclude DxCh1_Diamond
*
* INPUTS:
*       devNum  - Device number.
*       txQueue - Tx queue number.
*
* OUTPUTS:
*       numberOfFreeTxDescriptorsPtr - pointer to number of free
*                                         descriptors for the given queue.
*
* RETURNS:
*       GT_OK - on success
*       GT_BAD_PARAM - on bad device or queue
*       GT_BAD_PTR - on NULL pointer
*       GT_NOT_INITIALIZED - the library was not initialized
*       GT_NOT_APPLICABLE_DEVICE - on not applicable device
*
* COMMENTS:
*       None.
*
*******************************************************************************/
GT_STATUS cpssDxChNetIfSdmaTxFreeDescripotrsNumberGet
(
    IN GT_U8                devNum,
    IN GT_U8                txQueue,
    OUT GT_U32             *numberOfFreeTxDescriptorsPtr
);

#ifdef __cplusplus
}
#endif

#endif  /* __cpssDxChNetIfh */
