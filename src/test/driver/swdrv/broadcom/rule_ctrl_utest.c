#include <bcm.h>

////////////////////////////////////////////////////////////////////////////////
// drv.c
////////////////////////////////////////////////////////////////////////////////

#include <bcm/types.h>
#include <soc/drv.h>

soc_control_t   g_soc_control[2];
soc_control_t   *soc_control[SOC_MAX_NUM_DEVICES];


////////////////////////////////////////////////////////////////////////////////
// control.c
////////////////////////////////////////////////////////////////////////////////

#include <bcm_int/dispatch.h>
#include <bcm_int/control.h>

bcm_control_t   g_bcm_control[2];
bcm_control_t   *bcm_control[BCM_CONTROL_MAX];


////////////////////////////////////////////////////////////////////////////////
// port.c
////////////////////////////////////////////////////////////////////////////////
#include <src/bcm/esw/port.c>

////////////////////////////////////////////////////////////////////////////////
// field.c
////////////////////////////////////////////////////////////////////////////////
#include <src/bcm/esw/field.c>

//#include "cpss_utest_cases.c"

#if (SDK_VERSION >= 6)
#include "src/customer/accton_field.c"
#include <src/shared/pbmp.c>
#include <src/shared/util.c>
#endif

////////////////////////////////////////////////////////////////////////////////
// error.c
////////////////////////////////////////////////////////////////////////////////
#include <src/shared/error.c>
#include <src/bcm/error.c>

////////////////////////////////////////////////////////////////////////////////
// dispatch.c
////////////////////////////////////////////////////////////////////////////////
#include <src/bcm/dispatch.c>
#include <src/bcm/esw_dispatch.c>


////////////////////////////////////////////////////////////////////////////////
// dev_rm.c
////////////////////////////////////////////////////////////////////////////////

#define soc_ndev    (2)


#include "dev_rm.c"
#include "dev_rm_utest_cases.c"
#include "dev_rm_layoff.c"

#undef soc_ndev


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


#include "rule_ctrl.c"

#include "rule_ctrl_utest_cases.c"

#undef  shmem_data
#undef  shmem_data_p

#undef  PRINTF
#undef  LOG

#define shmem_data      fp_config_shmem_data
#define shmem_data_p    fp_config_shmem_data_p

#include "fp_config.c"

#undef  shmem_data
#undef  shmem_data_p


////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
int RULE_CTRL_UT_Init()
{
    unsigned int i;

    memset(g_soc_control, 0, sizeof(g_soc_control));
    memset(g_bcm_control, 0, sizeof(g_bcm_control));

    for (i=0; i < _countof(g_soc_control); ++i)
    {
#if (SDK_VERSION >= 6)
        g_soc_control[i].info.chip |= (SOC_INFO_CHIP_TR_VL | SOC_INFO_CHIP_TRX);
#else
        g_soc_control[i].info.chip |= (SOC_INFO_FB | SOC_INFO_XGS3_SWITCH);
#endif /* SDK_VERSION */


        soc_control[i] = &g_soc_control[i];
    }

    for (i=0; i < _countof(g_bcm_control); ++i)
    {
        g_bcm_control[i].dispatch = &bcm_esw_dispatch;
        bcm_control[i] = &g_bcm_control[i];
    }

    DEVRM_PMGR_InitiateProcessResource();
    SYSFUN_RegisterIPCHandler(dev_rm_pmgr_ipcmsgq_handle,
                              DEVRM_HandleIPCReqMsg);
//    DEVRM_PMGR_FieldInit();

    return 0;
}

int RULE_CTRL_UT_Main(int argc, char *const argv[])
{
    RULE_CTRL_UT_Init();

    DEVRM_UT_RunTestCaese();

    RULE_OM_UT_RunTestCaese();
    RULE_CTRL_UT_RunTestCaese();

    return 0;
}





