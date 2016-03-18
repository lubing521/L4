/*
 * Copyright(c) Realtek Semiconductor Corporation, 2008
 * All rights reserved.
 *
 * $Revision: 10406 $
 * $Date: 2010-06-23 19:26:54 +0800 (Wed, 23 Jun 2010) $
 *
 * Purpose : Common API for DAL
 *
 * Feature : The file have include the following module and sub-modules
 *           1) Common unsupported function
 *
 */
#ifndef __DAL_COMMON_H__ 
#define __DAL_COMMON_H__

/*  
 * Include Files 
 */
#include <common/rt_type.h>
#include <common/rt_error.h>

/* 
 * Symbol Definition 
 */
typedef int32 (*dal_link_change_callback_f)(int32 unit, rtk_portmask_t *pChangedPortmask);


/* 
 * Data Declaration 
 */

/*
 * Macro Definition
 */

/* 
 * Function Declaration 
 */

/* Module Name : */

/* Function Name: 
 *      dal_common_unavail
 * Description: 
 *      Initilize DAL(semaphore, database clear)
 * Input:  
 *      None
 * Output: 
 *      None 
 * Return: 
 *      RT_ERR_FAILED   - initialize fail
 *      RT_ERR_OK       - initialize success
 * Note: 
 *      RTK must call this function before do other kind of action.
 */ 
extern int32
dal_common_unavail(void);

#endif /* __DAL_COMMON_H__ */