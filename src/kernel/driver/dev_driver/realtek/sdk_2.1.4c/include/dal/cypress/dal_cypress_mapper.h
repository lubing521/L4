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
 * $Revision: 25951 $
 * $Date: 2011-12-20 19:05:11 +0800 (Tue, 20 Dec 2011) $
 *
 * Purpose : Smart Switch RTK API mapper table
 *
 * Feature : 
 *
 */

/*
 * Include Files
 */
#include <common/rt_type.h>
#include <common/rt_error.h>
#include <dal/dal_mapper.h>


/* 
 * Symbol Definition
 */

/*
 * Data Declaration
 */
extern dal_mapper_t dal_cypress_mapper;

/*
 * Macro Declaration
 */ 

/*
 * Function Declaration
 */


/* Module Name    :  */

/* Function Name: 
 *      dal_cypress_init
 * Description: 
 *      Initilize DAL of smart switch 
 * Input:  
 *      unit    - unit id
 * Output: 
 *      None 
 * Return: 
 *      RT_ERR_FAILED   - initialize fail
 *      RT_ERR_OK       - initialize success
 * Note: 
 *      RTK must call this function before do other kind of action.
 */ 
extern int32 dal_cypress_init(uint32 unit);

