/*
 *  backdoor_mgr.c
 *  sysrsc
 *
 *  Created by yehjunying on 2011/4/28.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#include "backdoor_mgr.h"

/*-------------------------------------------------------------------------
 * FUNCTION NAME : BACKDOOR_MGR_InitiateSystemResources
 *-------------------------------------------------------------------------
 * PURPOSE:
 *      Initiate system resource for BACKDOOR_MGR
 *
 * INPUT:
 *      None.
 *
 * OUTPUT:
 *      None.
 *
 * RETURN:
 *      None.
 *
 * NOTES:
 *      private om API
 *-------------------------------------------------------------------------
 */
void BACKDOOR_MGR_InitiateSystemResources(void)
{
}

/*-------------------------------------------------------------------------
 * FUNCTION NAME : BACKDOOR_MGR_AttachSystemResources
 *-------------------------------------------------------------------------
 * PURPOSE:
 *      Attach system resource for BACKDOOR_MGR in the context of the
 *      calling process.
 *
 * INPUT:
 *      None.
 *
 * OUTPUT:
 *      None.
 *
 * RETURN:
 *      None.
 *
 * NOTES:
 *      private om API
 *-------------------------------------------------------------------------
 */
void BACKDOOR_MGR_AttachSystemResources(void)
{
}

/*-------------------------------------------------------------------------
 * FUNCTION NAME : BACKDOOR_MGR_GetShMemInfo
 *-------------------------------------------------------------------------
 * PURPOSE:
 *      Provide shared memory information of BACKDOOR_MGR for SYSRSC.
 *
 * INPUT:
 *      None.
 *
 * OUTPUT:
 *      segid_p  --  shared memory segment id
 *      seglen_p --  length of the shared memroy segment
 *
 * RETURN:
 *      None.
 *
 * NOTES:
 *      private om API
 *-------------------------------------------------------------------------
 */
void BACKDOOR_MGR_GetShMemInfo(SYSRSC_MGR_SEGID_T *segid_p, UI32_T *seglen_p)
{
    *segid_p = SYSRSC_MGR_BACKDOOR_MGR_SHMEM_SEGID;
    *seglen_p = 100;
}
