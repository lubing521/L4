/*
 * Copyright (C) 2009 Realtek Semiconductor Corp. 
 * All Rights Reserved.
 *
 * This program is the proprietary software of Realtek Semiconductor
 * Corporation and/or its licensors, and only be used, duplicated, 
 * modified or distributed under the authorized license from Realtek. 
 *
 * ANY USE OF THE SOFTWARE OTHER THAN AS AUTHORIZED UNDER 
 * THIS LICENSE OR COPYRIGHT LAW IS PROHIBITED. 
 *
 * $Revision: 34373 $
 * $Date: 2012-11-15 16:09:52 +0800 (Thu, 15 Nov 2012) $
 *
 * Purpose : Definition those public watchdog APIs and its data type in the SDK.
 *
 * Feature : The file have include the following module and sub-modules
 *            1) mode set & get
 *            2) scale set & get
 */
#ifndef __WATCHDOG_R8380_H__ 
#define __WATCHDOG_R8380_H__

/*
 * Include Files
 */
#include <drv/watchdog/watchdog.h>

/*
 * Symbol Definition
 */

/*
 * Data Type Definition
 */

/*
 * Data Declaration
 */

/*
 * Macro Definition
 */

/*
 * Function Declaration
 */

/* Function Name:
 *      r8380_watchdog_init
 * Description:
 *      Init the watchdog module of the specified device.
 * Input:
 *      unit - unit id 
 * Output:
 *      None
 * Return:
 *      RT_ERR_OK
 *      RT_ERR_FAILED
 * Note:
 *      None
 */
extern int32
r8380_watchdog_init(uint32 unit);

/* Function Name:
 *      r8380_watchdog_mode_set
 * Description:
 *      Set watchdog as normal or interrupt mode
 * Input:
 *      unit - unit id
 *      mode - watchdog mode
 * Output:
 *      None
 * Return:
 *      RT_ERR_OK     - set watchdog mode success.
 *      RT_ERR_FAILED - set watchdog mode fail.
 * Note:
 *      None
 */
extern int32
r8380_watchdog_mode_set(uint32 unit, drv_watchdog_mode_t mode);

/* Function Name:
 *      r8380_watchdog_mode_get
 * Description:
 *      Get watchdog mode
 * Input:
 *      unit  - unit id
 * Output:
 *      pMode - watchdog mode
 * Return:
 *      RT_ERR_OK           - get watchdog mode successfully.
 *      RT_ERR_NULL_POINTER - pMode is a null pointer.
 * Note:
 *      None
 */
extern int32
r8380_watchdog_mode_get(uint32 unit, drv_watchdog_mode_t *pMode);

/* Function Name:
 *      r8380_watchdog_scale_set
 * Description:
 *      Set watchdog expired period
 * Input:
 *      unit  - unit id
 *      scale - period scale
 * Output:
 *      None
 * Return:
 *      RT_ERR_OK     - succeed in setting watchdog expired period.
 *      RT_ERR_FAILED - fail to set watchdog expired period.
 * Note:
 *      None
 */
extern int32 
r8380_watchdog_scale_set(uint32 unit, drv_watchdog_scale_t scale);

/* Function Name:
 *      r8380_watchdog_scale_get
 * Description:
 *      Get watchdog expired period scale
 * Input:
 *      unit   - unit id
 * Output:
 *      pScale - period scale
 * Return:
 *      RT_ERR_OK           - get watchdog expired period scale successfully.
 *      RT_ERR_FAILED       - fail to get get watchdog expired period scale. 
 *      RT_ERR_NULL_POINTER - pScale is a null pointer.
 * Note:
 *      None
 */
extern int32 
r8380_watchdog_scale_get(uint32 unit, drv_watchdog_scale_t *pScale);

/* Function Name:
 *      r8380_watchdog_enable_set
 * Description:
 *      Set watchdog enable/disable
 * Input:
 *      unit   - unit id
 *      enable - enable or disable request
 * Output:
 *      None
 * Return:
 *      RT_ERR_OK     - enable watchdog successfully.
 *      RT_ERR_FAILED - fail to enable watchdog.
 * Note:
 *      None
 */
extern int32 
r8380_watchdog_enable_set(uint32 unit, uint32 enable);

/* Function Name:
 *      r8380_watchdog_enable_get
 * Description:
 *      Get watchdog enable/disable status
 * Input:
 *      unit    - unit id
 * Output:
 *      pEnable - watchdog enable/disable status
 * Return:
 *      RT_ERR_OK           - get watchdog enable/disable status successfully.
 *      RT_ERR_NULL_POINTER - pEnable is a null pointer.
 * Note:
 *      None
 */
extern int32 
r8380_watchdog_enable_get(uint32 unit, uint32 *pEnable);

/* Function Name:
 *      r8380_watchdog_kick
 * Description:
 *      Kick watchdog
 * Input:
 *      unit - unit id
 * Output:
 *      None
 * Return:
 *      RT_ERR_OK - kick watchdog successfully.
 * Note:
 *      None
 */
extern int32 
r8380_watchdog_kick(uint32 unit);

/* Function Name:
 *      r8380_watchdog_threshold_set
 * Description:
 *      Set watchdog threshold counter of the specified device
 * Input:
 *      unit       - unit id
 *      pThreshold - watchdog threshold
 * Output:
 *      None
 * Return:
 *      RT_ERR_OK           - successfully.
 *      RT_ERR_NULL_POINTER - pThreshold is a null pointer.
 *      RT_ERR_INPUT        - invalid input argument
 * Note:
 *      None
 */
extern int32 
r8380_watchdog_threshold_set(uint32 unit, drv_watchdog_threshold_t *pThreshold);

/* Function Name:
 *      r8380_watchdog_threshold_get
 * Description:
 *      Get watchdog threshold counter of the specified device
 * Input:
 *      unit       - unit id
 * Output:
 *      pThreshold - watchdog threshold
 * Return:
 *      RT_ERR_OK - successfully.
 *      RT_ERR_NULL_POINTER - pThreshold is a null pointer.
 * Note:
 *      None
 */
extern int32 
r8380_watchdog_threshold_get(uint32 unit, drv_watchdog_threshold_t *pThreshold);

#endif /* __WATCHDOG_R8380_H__ */
