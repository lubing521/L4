
////////////////////////////////////////////////////////////////////////////////
// cpss.c
////////////////////////////////////////////////////////////////////////////////
#include "cpss.c"

#include "cpss_utest_cases.c"

////////////////////////////////////////////////////////////////////////////////
// dev_rm.c
////////////////////////////////////////////////////////////////////////////////

/* Replace marco, PRV_CPSS_PHY_PORT_IS_EXIST_MAC
 */
#include <cpss/generic/config/private/prvCpssConfigTypes.h>

#ifdef PRV_CPSS_PHY_PORT_IS_EXIST_MAC
#undef PRV_CPSS_PHY_PORT_IS_EXIST_MAC
#endif

#define PRV_CPSS_PHY_PORT_IS_EXIST_MAC(devNum, portNum)     \
(devNum==0 && portNum<SYS_ADPT_MAX_NBR_OF_SWITCH_PORT_PER_CHIP)


#undef BIT_0
#undef BIT_1
#undef BIT_2
#undef BIT_3
#undef BIT_4
#undef BIT_5
#undef BIT_6
#undef BIT_7
#undef BIT_8
#undef BIT_9
#undef BIT_10
#undef BIT_11
#undef BIT_12
#undef BIT_13
#undef BIT_14
#undef BIT_15
#undef BIT_16
#undef BIT_17
#undef BIT_18
#undef BIT_19
#undef BIT_20
#undef BIT_21
#undef BIT_22
#undef BIT_23
#undef BIT_24
#undef BIT_25
#undef BIT_26
#undef BIT_27
#undef BIT_28
#undef BIT_29
#undef BIT_30
#undef BIT_31

//#include "dev_rm_lib.h"
#include "dev_rm_lib.c"
#include "dev_rm.c"

#include "dev_rm_utest_cases.c"

#include "dev_rm_layoff.c"

////////////////////////////////////////////////////////////////////////////////
// dev_rm_pmgr.c
////////////////////////////////////////////////////////////////////////////////

#ifndef BIT_29
#define BIT_29      	(1 << 29)
#endif

#define ipcmsgq_handle  dev_rm_pmgr_ipcmsgq_handle

#include "dev_rm_pmgr.c"

#undef ipcmsgq_handle

////////////////////////////////////////////////////////////////////////////////
// dev_swdrv.c  dev_swdrv_pmgr.c
////////////////////////////////////////////////////////////////////////////////
#include "dev_swdrv.c"
#include "dev_swdrv_pmgr.c"

////////////////////////////////////////////////////////////////////////////////
// cos_om.c
////////////////////////////////////////////////////////////////////////////////

#define shmem_data      cos_om_shmem_data
#define shmem_data_p    cos_om_shmem_data_p

#include "cos_om.c"

#undef  shmem_data
#undef  shmem_data_p

////////////////////////////////////////////////////////////////////////////////
// rule_om.c
////////////////////////////////////////////////////////////////////////////////

#define shmem_data      rule_om_shmem_data
#define shmem_data_p    rule_om_shmem_data_p

#include "rule_om.c"

#include "rule_om_utest_cases.c"

#undef shmem_data
#undef shmem_data_p

#undef RULE_OM_INST2PTR
#undef RULE_OM_PTR2INST
#undef RULE_OM_VALIDATE_INST
#undef RULE_OM_INDEX_OF

#undef  PRINTF
#undef  LOG

////////////////////////////////////////////////////////////////////////////////
// rule_ctrl.c
////////////////////////////////////////////////////////////////////////////////

#if __WIN32__
#define fflush(stdout)
#endif

#ifndef SWDRV_FIX_STANDALONE_TYPE
#define SWDRV_FIX_STANDALONE_TYPE TRUE /* NO STACKING */
#endif

#define shmem_data      rule_ctrl_shmem_data
#define shmem_data_p    rule_ctrl_shmem_data_p

#ifndef BIT_1
#define BIT_1      	(1 << 1)
#endif

#ifndef BIT_5
#define BIT_5      	(1 << 5)
#endif

#define RULE_CTRL_ISC_Handler RULE_CTRL_ISC_Handler_Original
#include "rule_ctrl.c"
#undef RULE_CTRL_ISC_Handler

#include "rule_ctrl_utest_cases.c"

#undef  shmem_data
#undef  shmem_data_p

#undef  PRINTF
#undef  LOG

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
int RULE_CTRL_UT_Init()
{
    DEVRM_PMGR_InitiateProcessResource();

    SYSFUN_RegisterIPCHandler(dev_rm_pmgr_ipcmsgq_handle,
                              DEVRM_HandleIPCReqMsg);


    //_cpssInit();

    //DEVRM_Initial();

    return 0;
}

int RULE_CTRL_UT_Main(int argc, char *const argv[])
{
    RULE_CTRL_UT_Init();

    CPSS_UT_RunTestCaese();
    DEVRM_UT_RunTestCaese();
    RULE_OM_UT_RunTestCaese();
    RULE_CTRL_UT_RunTestCaese();

    return 0;
}




