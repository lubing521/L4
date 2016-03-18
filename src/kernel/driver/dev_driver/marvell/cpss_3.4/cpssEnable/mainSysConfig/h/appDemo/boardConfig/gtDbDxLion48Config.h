/*******************************************************************************
*                Copyright 2009, Marvell International Ltd.
* This code contains confidential information of Marvell semiconductor, inc.
* no rights are granted herein under any patent, mask work right or copyright
* of Marvell or any third party.
* Marvell reserves the right at its sole discretion to request that this code
* be immediately returned to Marvell. This code is provided "as is".
* Marvell makes no warranties, express, implied or otherwise, regarding its
* accuracy, completeness or performance.
********************************************************************************
* gtDbDxLion48Config.h
*
* DESCRIPTION:
*       This file includes  serdes configuration and port mapping for Lion 48 board
*
* DEPENDENCIES:
*
*
* FILE REVISION NUMBER:
*       $Revision: 16 $
*
*******************************************************************************/

#ifndef __gtDbDxLion48XGh
#define __gtDbDxLion48XGh

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#ifndef ASIC_SIMULATION

/* SMI addresses for DB board */
static GT_U8 lioncubSmiAddrDB[] =
{ 
0x05, 0x05, 0x04, 0x04, 0x07, 0x07, 0x06, 0x06, 0x09, 0x09, 0x08, 0x08, 0x00, 0x00, 0x00, 0x00,
0x05, 0x05, 0x04, 0x04, 0x07, 0x07, 0x06, 0x06, 0x09, 0x09, 0x08, 0x08, 0x00, 0x00, 0x00, 0x00,
0x05, 0x05, 0x04, 0x04, 0x07, 0x07, 0x06, 0x06, 0x09, 0x09, 0x08, 0x08, 0x00, 0x00, 0x00, 0x00,
0x05, 0x05, 0x04, 0x04, 0x07, 0x07, 0x06, 0x06, 0x09, 0x09, 0x08, 0x08, 0x00, 0x00, 0x00, 0x00
};

/* SMI addresses for RD board */
static GT_U8 lioncubSmiAddrRD[] =
{ 
0x11, 0x11, 0x10, 0x10, 0x13, 0x13, 0x12, 0x12, 0x15, 0x15, 0x14, 0x14, 0x00, 0x00, 0x00, 0x00,
0x14, 0x14, 0x15, 0x15, 0x12, 0x12, 0x13, 0x13, 0x10, 0x10, 0x11, 0x11, 0x00, 0x00, 0x00, 0x00,
0x11, 0x11, 0x10, 0x10, 0x13, 0x13, 0x12, 0x12, 0x15, 0x15, 0x14, 0x14, 0x00, 0x00, 0x00, 0x00,
0x14, 0x14, 0x15, 0x15, 0x12, 0x12, 0x13, 0x13, 0x10, 0x10, 0x11, 0x11, 0x00, 0x00, 0x00, 0x00
};


/* XPCS port of Lioncub - Up0 or Up1 - for both DB and RD boards */
static GT_U32 lion48LcXpcsPortArray[] =
{
/* port group 0 */
     0,1,1,0,0,1,1,0,0,1,1,0,0xffffffff,0xffffffff,0xffffffff,0xffffffff,
/* port group 1 */    
     0,1,1,0,0,1,1,0,0,1,1,0,0xffffffff,0xffffffff,0xffffffff,0xffffffff,
/* port group 2 */     
     0,1,1,0,0,1,1,0,0,1,1,0,0xffffffff,0xffffffff,0xffffffff,0xffffffff,
/* port group 3 */     
     0,1,1,0,0,1,1,0,0,1,1,0,0xffffffff,0xffffffff,0xffffffff,0xffffffff
};     

/* For Lioncub revision A0 on Lion DB board */
static GT_LIONCUB_INIT lioncubInitArrayDB_A0[] =
{
    {0x1000, 0x3c00, 0x4e00, 0xa},
    {0x1004, 0x1c04, 0x0008, 0x0},
    {0x2004, 0x3c04, 0x0008, 0xa},
    {0x120c, 0x1e0c, 0x800a, 0x0},
    {0x1210, 0x1e10, 0x4415, 0x0},
    {0x1214, 0x1e14, 0x8150, 0x1},
    {0x1214, 0x1e14, 0xa150, 0x0},
    {0x1218, 0x1e18, 0xfbaa, 0x0},
    {0x121c, 0x1e1c, 0x8720, 0x0},
    {0x13cc, 0x1fcc, 0x0000, 0x0},
    {0x122c, 0x1e2c, 0x0000, 0x0},
    {0x1230, 0x1e30, 0x0000, 0x0},
    {0x1234, 0x1e34, 0x4000, 0x0},
    {0x123c, 0x1e3c, 0x0018, 0x0},
    {0x1250, 0x1e50, 0xa060, 0x0},
    {0x1254, 0x1e54, 0x7f2D, 0x0},
    {0x1258, 0x1e58, 0x0100, 0x0},
    {0x127c, 0x1e7c, 0x90aa, 0x0},
    {0x1280, 0x1e80, 0x0800, 0x0},
    {0x128c, 0x1e8c, 0x036F, 0x0},
    {0x135c, 0x1f5c, 0x423f, 0x0},
    {0x1364, 0x1f64, 0x5554, 0x0},
    {0x136c, 0x1f6c, 0x0000, 0x0},
    {0x1234, 0x1e34, 0x4000, 0x0},
    {0x1228, 0x1e28, 0xe0c0, 0x0},
    {0x136c, 0x1f6c, 0x8040, 0x1},
    {0x136c, 0x1f6c, 0x8000, 0x5},
    {0x1224, 0x1e34, 0x0000, 0x1},
    {0x1224, 0x1e34, 0x8000, 0x1},
    {0x1224, 0x1e34, 0x0000, 0x0},
    {0x220c, 0x3e0c, 0x800a, 0x0},
    {0x2210, 0x3e10, 0x5515, 0x0},
    {0x2214, 0x3e14, 0x8150, 0x1},
    {0x2214, 0x3e14, 0xa150, 0x0},
    {0x2218, 0x3e18, 0xfbaa, 0x0},
    {0x221c, 0x3e1c, 0x8720, 0x0},
    {0x23cc, 0x3fcc, 0x0000, 0x0},
    {0x222c, 0x3e2c, 0x0000, 0x0},
    {0x2230, 0x3e30, 0x0000, 0x0},
    {0x2234, 0x3e34, 0x4000, 0x0},
    {0x223c, 0x3e3c, 0x0018, 0x0},
    {0x2250, 0x3e50, 0x8060, 0x0},
    {0x2254, 0x3e54, 0x3A09, 0x0},
    {0x2258, 0x3e58, 0x0000, 0x0},
    {0x227c, 0x3e7c, 0x905a, 0x0},
    {0x2280, 0x3e80, 0x0800, 0x0},
    {0x228c, 0x3e8c, 0x0336, 0x0},
    {0x235c, 0x3f5c, 0x423f, 0x0},
    {0x2364, 0x3f64, 0x5554, 0x0},
    {0x236c, 0x3f6c, 0x0000, 0x0},
    {0x2234, 0x3e34, 0x4000, 0x0},
    {0x2228, 0x3e28, 0xe0c0, 0x0},
    {0x236c, 0x3f6c, 0x8040, 0x0},
    {0x236c, 0x3f6c, 0x8000, 0x5},
    {0x2224, 0x3e24, 0x0000, 0x1},
    {0x2224, 0x3e24, 0x8000, 0x1},
    {0x2224, 0x3e24, 0x0000, 0x0},
    {0x1004, 0x1c04, 0x0018, 0x0},
    {0x2004, 0x3c04, 0x0018, 0xa},
    {0x1004, 0x1c04, 0x0008, 0x0},
    {0x2004, 0x3c04, 0x0008, 0xa},
    {0x1004, 0x1c04, 0x00c8, 0x0},
    {0x2004, 0x3c04, 0x0048, 0xa},

    {0xffff, 0xffff, 0xffff, 0x0}
};

/* For Lioncub revision A0 on Lion Rd board */
static GT_LIONCUB_INIT lioncubInitArrayRD_A0[] =
{
    {0x1000, 0x3c00, 0x4e00, 0xa},
    {0x1004, 0x1c04, 0x0008, 0x0},
    {0x2004, 0x3c04, 0x0008, 0xa},
    {0x120c, 0x1e0c, 0x800a, 0x0},
    {0x1210, 0x1e10, 0x4415, 0x0},
    {0x1214, 0x1e14, 0x8150, 0x1},
    {0x1214, 0x1e14, 0xa150, 0x0},
    {0x1218, 0x1e18, 0xfbaa, 0x0},
    {0x121c, 0x1e1c, 0x8720, 0x0},
    {0x13cc, 0x1fcc, 0x0000, 0x0},
    {0x122c, 0x1e2c, 0x0000, 0x0},
    {0x1230, 0x1e30, 0x0000, 0x0},
    {0x1234, 0x1e34, 0x4000, 0x0},
    {0x123c, 0x1e3c, 0x0018, 0x0},
    {0x1250, 0x1e50, 0xa060, 0x0},
    {0x1254, 0x1e54, 0x7f20, 0x0},
    {0x1258, 0x1e58, 0x0100, 0x0},
    {0x127c, 0x1e7c, 0x90aa, 0x0},
    {0x1280, 0x1e80, 0x0800, 0x0},
    {0x128c, 0x1e8c, 0x0363, 0x0},
    {0x135c, 0x1f5c, 0x423f, 0x0},
    {0x1364, 0x1f64, 0x5554, 0x0},
    {0x136c, 0x1f6c, 0x0000, 0x0},
    {0x1234, 0x1e34, 0x4000, 0x0},
    {0x1228, 0x1e28, 0xe0c0, 0x0},
    {0x136c, 0x1f6c, 0x8040, 0x1},
    {0x136c, 0x1f6c, 0x8000, 0x5},
    {0x1224, 0x1e34, 0x0000, 0x1},
    {0x1224, 0x1e34, 0x8000, 0x1},
    {0x1224, 0x1e34, 0x0000, 0x0},
    {0x220c, 0x3e0c, 0x800a, 0x0},
    {0x2210, 0x3e10, 0x5515, 0x0},
    {0x2214, 0x3e14, 0x8150, 0x1},
    {0x2214, 0x3e14, 0xa150, 0x0},
    {0x2218, 0x3e18, 0xfbaa, 0x0},
    {0x221c, 0x3e1c, 0x8720, 0x0},
    {0x23cc, 0x3fcc, 0x0000, 0x0},
    {0x222c, 0x3e2c, 0x0000, 0x0},
    {0x2230, 0x3e30, 0x0000, 0x0},
    {0x2234, 0x3e34, 0x4000, 0x0},
    {0x223c, 0x3e3c, 0x0018, 0x0},
    {0x2250, 0x3e50, 0x8060, 0x0},
    {0x2254, 0x3e54, 0x3A09, 0x0},
    {0x2258, 0x3e58, 0x0000, 0x0},
    {0x227c, 0x3e7c, 0x905a, 0x0},
    {0x2280, 0x3e80, 0x0800, 0x0},
    {0x228c, 0x3e8c, 0x0336, 0x0},
    {0x235c, 0x3f5c, 0x423f, 0x0},
    {0x2364, 0x3f64, 0x5554, 0x0},
    {0x236c, 0x3f6c, 0x0000, 0x0},
    {0x2234, 0x3e34, 0x4000, 0x0},
    {0x2228, 0x3e28, 0xe0c0, 0x0},
    {0x236c, 0x3f6c, 0x8040, 0x0},
    {0x236c, 0x3f6c, 0x8000, 0x5},
    {0x2224, 0x3e24, 0x0000, 0x1},
    {0x2224, 0x3e24, 0x8000, 0x1},
    {0x2224, 0x3e24, 0x0000, 0x0},
    {0x1004, 0x1c04, 0x0018, 0x0},
    {0x2004, 0x3c04, 0x0018, 0xa},
    {0x1004, 0x1c04, 0x0008, 0x0},
    {0x2004, 0x3c04, 0x0008, 0xa},
    {0x1004, 0x1c04, 0x00c8, 0x0},
    {0x2004, 0x3c04, 0x0048, 0xa},

    {0xffff, 0xffff, 0xffff, 0x0}
};

static GT_LIONCUB_INIT lioncubInitArrayRD_A1_10G[] =
{
    /* up ports - SERDES Settings for 6.25G (RXAUI Mode) */
    {0x1000, 0x3c00, 0x4e00, 0xa},
    {0x1004, 0x1c04, 0x0008, 0x0},
    {0x2004, 0x3c04, 0x0008, 0xa},    
    {0x120c, 0x1e0c, 0x800a, 0x0},
    {0x1210, 0x1e10, 0x4415, 0x0},
    {0x1214, 0x1e14, 0xa150, 0x0},
    {0x1218, 0x1e18, 0xfbaa, 0x0},
    {0x121c, 0x1e1c, 0x8720, 0x0},
    {0x13cc, 0x1fcc, 0x2000, 0x0},
    {0x122c, 0x1e2c, 0x0000, 0x0},
    {0x1230, 0x1e30, 0x0000, 0x0},
    {0x1234, 0x1e34, 0x4000, 0x0},
    {0x123c, 0x1e3c, 0x0018, 0x0},
    {0x1250, 0x1e50, 0xA0C0, 0x5},
    {0x1250, 0x1e50, 0xA060, 0x0},
    {0x1254, 0x1e54, 0x7f20, 0x0},
    {0x1258, 0x1e58, 0x0100, 0x0},
    {0x127c, 0x1e7c, 0x90aa, 0x0},
    {0x1280, 0x1e80, 0x0800, 0x0},
    {0x128c, 0x1e8c, 0x0363, 0x0},
    {0x135c, 0x1f5c, 0x423f, 0x0},
    {0x1364, 0x1f64, 0x5555, 0x0},
    {0x136c, 0x1f6c, 0x0000, 0x0},
    {0x1234, 0x1e34, 0x4000, 0x0},
    {0x1228, 0x1e28, 0xe0c0, 0x0},
    {0x136c, 0x1f6c, 0x8040, 0x1},
    {0x136c, 0x1f6c, 0x8000, 0x5},
    {0x1224, 0x1e34, 0x0000, 0x1},
    {0x1224, 0x1e34, 0x8000, 0x1},
    {0x1224, 0x1e34, 0x0000, 0x1},
    {0x220c, 0x3e0c, 0x800a, 0x0},
    {0x2210, 0x3e10, 0x5515, 0x0},
    {0x2214, 0x3e14, 0xa150, 0x0},
    {0x2218, 0x3e18, 0xfbaa, 0x0},
    {0x221c, 0x3e1c, 0x8720, 0x0},
    {0x23cc, 0x3fcc, 0x2000, 0x0},
    {0x222c, 0x3e2c, 0x0000, 0x0},
    {0x2230, 0x3e30, 0x0000, 0x0},
    {0x2234, 0x3e34, 0x4000, 0x0},
    {0x223c, 0x3e3c, 0x0018, 0x0},
    {0x2250, 0x3e50, 0x80C0, 0x5},
    {0x2250, 0x3e50, 0x8060, 0x0},
    {0x2254, 0x3e54, 0x3A09, 0x0},
    {0x2258, 0x3e58, 0x0000, 0x0},
    {0x227c, 0x3e7c, 0x905a, 0x0},
    {0x2280, 0x3e80, 0x0800, 0x0},
    {0x228c, 0x3e8c, 0x0336, 0x0},
    {0x235c, 0x3f5c, 0x423f, 0x0},
    {0x2364, 0x3f64, 0x5555, 0x0},
    {0x236c, 0x3f6c, 0x0000, 0x0},
    {0x2234, 0x3e34, 0x4000, 0x0},
    {0x2228, 0x3e28, 0xe0c0, 0x0},
    {0x236c, 0x3f6c, 0x8040, 0x0},
    {0x236c, 0x3f6c, 0x8000, 0x5},
    {0x2224, 0x3e24, 0x0000, 0x1},
    {0x2224, 0x3e24, 0x8000, 0x1},
    {0x2224, 0x3e24, 0x0000, 0x1},
    {0x1004, 0x1c04, 0x0018, 0x0},
    {0x2004, 0x3c04, 0x0018, 0xa},
    {0x1004, 0x1c04, 0x0008, 0x0},
    {0x2004, 0x3c04, 0x0008, 0xa},
    {0x007C, 0x007c, 0x000f, 0xa},    
    {0x1010, 0x1c10, 0x013f, 0x0},
    {0x2010, 0x3c10, 0x013f, 0x0},

    {0xffff, 0xffff, 0xffff, 0x0}
};

#endif /* #ifndef ASIC_SIMULATION*/

/* 10G port speed; lioncub upstream serdes mode/speed RXAUI/6.25, downstream XAUI/3.125G */
/* For Lioncub revision A1 and above */
static GT_LIONCUB_INIT lioncubInitArrayDB_A1_10G[] =
{
    /* up ports - SERDES Settings for 6.25G (RXAUI Mode) */
    {0x1000, 0x3c00, 0x4e00, 0xa},
    {0x1004, 0x1c04, 0x0008, 0x0},
    {0x2004, 0x3c04, 0x0008, 0xa},    
    {0x120c, 0x1e0c, 0x800a, 0x0},
    {0x1210, 0x1e10, 0x4415, 0x0},
    {0x1214, 0x1e14, 0xa150, 0x0},
    {0x1218, 0x1e18, 0xfbaa, 0x0},
    {0x121c, 0x1e1c, 0x8720, 0x0},
    {0x13cc, 0x1fcc, 0x2000, 0x0},
    {0x122c, 0x1e2c, 0x0000, 0x0},
    {0x1230, 0x1e30, 0x0000, 0x0},
    {0x1234, 0x1e34, 0x4000, 0x0},
    {0x123c, 0x1e3c, 0x0018, 0x0},
    {0x1250, 0x1e50, 0xA0C0, 0x5},
    {0x1250, 0x1e50, 0xA060, 0x0},
    {0x1254, 0x1e54, 0x7f2d, 0x0},
    {0x1258, 0x1e58, 0x0100, 0x0},
    {0x127c, 0x1e7c, 0x90aa, 0x0},
    {0x1280, 0x1e80, 0x0800, 0x0},
    {0x128c, 0x1e8c, 0x036F, 0x0},
    {0x135c, 0x1f5c, 0x423f, 0x0},
    {0x1364, 0x1f64, 0x5555, 0x0},
    {0x136c, 0x1f6c, 0x0000, 0x0},
    {0x1234, 0x1e34, 0x4000, 0x0},
    {0x1228, 0x1e28, 0xe0c0, 0x0},
    {0x136c, 0x1f6c, 0x8040, 0x1},
    {0x136c, 0x1f6c, 0x8000, 0x5},
    {0x1224, 0x1e34, 0x0000, 0x1},
    {0x1224, 0x1e34, 0x8000, 0x1},
    {0x1224, 0x1e34, 0x0000, 0x1},
    {0x220c, 0x3e0c, 0x800a, 0x0},
    {0x2210, 0x3e10, 0x5515, 0x0},
    {0x2214, 0x3e14, 0xa150, 0x0},
    {0x2218, 0x3e18, 0xfbaa, 0x0},
    {0x221c, 0x3e1c, 0x8720, 0x0},
    {0x23cc, 0x3fcc, 0x2000, 0x0},
    {0x222c, 0x3e2c, 0x0000, 0x0},
    {0x2230, 0x3e30, 0x0000, 0x0},
    {0x2234, 0x3e34, 0x4000, 0x0},
    {0x223c, 0x3e3c, 0x0018, 0x0},
    {0x2250, 0x3e50, 0x80C0, 0x5},
    {0x2250, 0x3e50, 0x8060, 0x0},
    {0x2254, 0x3e54, 0x3A09, 0x0},
    {0x2258, 0x3e58, 0x0000, 0x0},
    {0x227c, 0x3e7c, 0x905a, 0x0},
    {0x2280, 0x3e80, 0x0800, 0x0},
    {0x228c, 0x3e8c, 0x0336, 0x0},
    {0x235c, 0x3f5c, 0x423f, 0x0},
    {0x2364, 0x3f64, 0x5555, 0x0},
    {0x236c, 0x3f6c, 0x0000, 0x0},
    {0x2234, 0x3e34, 0x4000, 0x0},
    {0x2228, 0x3e28, 0xe0c0, 0x0},
    {0x236c, 0x3f6c, 0x8040, 0x0},
    {0x236c, 0x3f6c, 0x8000, 0x5},
    {0x2224, 0x3e24, 0x0000, 0x1},
    {0x2224, 0x3e24, 0x8000, 0x1},
    {0x2224, 0x3e24, 0x0000, 0x1},
    {0x1004, 0x1c04, 0x0018, 0x0},
    {0x2004, 0x3c04, 0x0018, 0xa},
    {0x1004, 0x1c04, 0x0008, 0x0},
    {0x2004, 0x3c04, 0x0008, 0xa},
    {0x007C, 0x007c, 0x000f, 0xa},    
    {0x1010, 0x1c10, 0x013f, 0x0},
    {0x2010, 0x3c10, 0x013f, 0x0},

    {0xffff, 0xffff, 0xffff, 0x0}
};

/* 1G port speed; lioncub serdes both up and down-stream mode/speed SGMII/1.25G */
/* For Lioncub revision A1 and above */
static GT_LIONCUB_INIT lioncubInitArrayDB_A1_1G[] =
{
    /* up lioncub ports - SERDES Settings for 1.25G (SGMII Mode) */
    {0x1000, 0x3c00, 0xce00, 0xa},
    {0x1004, 0x1c04, 0x0008, 0x0},
    {0x2004, 0x3c04, 0x0008, 0xa},    
    {0x120c, 0x1e0c, 0x800a, 0x0},
    {0x1210, 0x1e10, 0x6614, 0x0},
    {0x1214, 0x1e14, 0xa140, 0x0},
    {0x1218, 0x1e18, 0xbaab, 0x0},
    {0x121c, 0x1e1c, 0x8b2c, 0x0},
    {0x13cc, 0x1fcc, 0x2000, 0x0},
    {0x122c, 0x1e2c, 0x0000, 0x0},
    {0x1230, 0x1e30, 0x0000, 0x0},
    {0x1234, 0x1e34, 0x4000, 0x0},
    {0x123c, 0x1e3c, 0x0018, 0x0},
    {0x1250, 0x1e50, 0xA0C0, 0x5},
    {0x1250, 0x1e50, 0xA060, 0x0},
    {0x1254, 0x1e54, 0x7F2D, 0x0},
    {0x1258, 0x1e58, 0x0100, 0x0},
    {0x127c, 0x1e7c, 0x90aa, 0x0},
    {0x1280, 0x1e80, 0x0800, 0x0},
    {0x128c, 0x1e8c, 0x033F, 0x0},
    {0x135c, 0x1f5c, 0x423f, 0x0},
    {0x1364, 0x1f64, 0x5555, 0x0},
    {0x136c, 0x1f6c, 0x0000, 0x0},
    {0x1234, 0x1e34, 0x4000, 0x0},
    {0x1228, 0x1e28, 0xe0c0, 0x0},
    {0x136c, 0x1f6c, 0x8040, 0x1},
    {0x136c, 0x1f6c, 0x8000, 0x5},
    {0x1224, 0x1e34, 0x0000, 0x1},
    {0x1224, 0x1e34, 0x8000, 0x1},
    {0x1224, 0x1e34, 0x0000, 0x0},
    {0x220c, 0x3e0c, 0x800a, 0x0},
    {0x2210, 0x3e10, 0x6614, 0x0},
    {0x2214, 0x3e14, 0xa140, 0x0},
    {0x2218, 0x3e18, 0xbaab, 0x0},
    {0x221c, 0x3e1c, 0x8b2c, 0x0},
    {0x23cc, 0x3fcc, 0x2000, 0x0},
    {0x222c, 0x3e2c, 0x0000, 0x0},
    {0x2230, 0x3e30, 0x0000, 0x0},
    {0x2234, 0x3e34, 0x4000, 0x0},
    {0x223c, 0x3e3c, 0x0018, 0x0},
    {0x2250, 0x3e50, 0xA0C0, 0x5},
    {0x2250, 0x3e50, 0xA060, 0x0},
    {0x2254, 0x3e54, 0x7F2D, 0x0},
    {0x2258, 0x3e58, 0x0100, 0x0},
    {0x227c, 0x3e7c, 0x90aa, 0x0},
    {0x2280, 0x3e80, 0x0800, 0x0},
    {0x228c, 0x3e8c, 0x033F, 0x0},
    {0x235c, 0x3f5c, 0x423f, 0x0},
    {0x2364, 0x3f64, 0x5555, 0x0},
    {0x236c, 0x3f6c, 0x0000, 0x0},
    {0x2234, 0x3e34, 0x4000, 0x0},
    {0x2228, 0x3e28, 0xe0c0, 0x0},
    {0x236c, 0x3f6c, 0x8040, 0x0},
    {0x236c, 0x3f6c, 0x8000, 0x5},
    {0x2224, 0x3e24, 0x0000, 0x1},
    {0x2224, 0x3e24, 0x8000, 0x1},
    {0x2224, 0x3e24, 0x0000, 0x0},
    {0x1004, 0x1c04, 0x0018, 0x0},
    {0x2004, 0x3c04, 0x0018, 0xa},
    {0x1004, 0x1c04, 0x0008, 0x0},
    {0x2004, 0x3c04, 0x0008, 0xa},
    {0x007C, 0x007C, 0x000F, 0xa},      
    {0x1010, 0x1c10, 0x013f, 0x0},
    {0x2010, 0x3c10, 0x013f, 0x0},

    {0xffff, 0xffff, 0xffff, 0x0}
};

/* TBD: check if both upstream/downstream for 2.5G should be 3.125G */
/* 2.5G port speed; lioncub upstream/downstream serdes mode/speed XAUI/3.125G */
/* For Lioncub revision A1 and above */
static GT_LIONCUB_INIT lioncubInitArrayDB_A1_2_5G[] =
{
    {0x1000, 0x3c00, 0x4e00, 0xa},
    {0x1004, 0x1c04, 0x0008, 0x0},
    {0x2004, 0x3c04, 0x0008, 0xa},
/* up ports - SERDES Settings for 3.125G (XAUI Mode) */
    {0x120c, 0x1e0c, 0x800a, 0x0},
    {0x1210, 0x1e10, 0x5515, 0x0},
    {0x1214, 0x1e14, 0xa150, 0x0},
    {0x1218, 0x1e18, 0xfbaa, 0x0},
    {0x121c, 0x1e1c, 0x8720, 0x0},
    {0x13cc, 0x1fcc, 0x2000, 0x0},
    {0x122c, 0x1e2c, 0x0000, 0x0},
    {0x1230, 0x1e30, 0x0000, 0x0},
    {0x1234, 0x1e34, 0x4000, 0x0},
    {0x123c, 0x1e3c, 0x0018, 0x0},
    {0x1250, 0x1e50, 0x80C0, 0x5},
    {0x1250, 0x1e50, 0x8060, 0x0},
    {0x1254, 0x1e54, 0x3A09, 0x0},
    {0x1258, 0x1e58, 0x0000, 0x0},
    {0x127c, 0x1e7c, 0x905a, 0x0},
    {0x1280, 0x1e80, 0x0800, 0x0},
    {0x128c, 0x1e8c, 0x0336, 0x0},
    {0x135c, 0x1f5c, 0x423f, 0x0},
    {0x1364, 0x1f64, 0x5555, 0x0},
    {0x136c, 0x1f6c, 0x0000, 0x0},
    {0x1234, 0x1e34, 0x4000, 0x0},
    {0x1228, 0x1e28, 0xe0c0, 0x0},
    {0x136c, 0x1f6c, 0x8040, 0x1},
    {0x136c, 0x1f6c, 0x8000, 0x5},
    {0x1224, 0x1e34, 0x0000, 0x1},
    {0x1224, 0x1e34, 0x8000, 0x1},
    {0x1224, 0x1e34, 0x0000, 0x1},
/* downstream serdes XAUI 3.125 */
    {0x220c, 0x3e0c, 0x800a, 0x0},
    {0x2210, 0x3e10, 0x5515, 0x0},
    {0x2214, 0x3e14, 0xa150, 0x0},
    {0x2218, 0x3e18, 0xfbaa, 0x0},
    {0x221c, 0x3e1c, 0x8720, 0x0},
    {0x23cc, 0x3fcc, 0x2000, 0x0},
    {0x222c, 0x3e2c, 0x0000, 0x0},
    {0x2230, 0x3e30, 0x0000, 0x0},
    {0x2234, 0x3e34, 0x4000, 0x0},
    {0x223c, 0x3e3c, 0x0018, 0x0},
    {0x2250, 0x3e50, 0x80C0, 0x5},
    {0x2250, 0x3e50, 0x8060, 0x0},
    {0x2254, 0x3e54, 0x3A09, 0x0},
    {0x2258, 0x3e58, 0x0000, 0x0},
    {0x227c, 0x3e7c, 0x905a, 0x0},
    {0x2280, 0x3e80, 0x0800, 0x0},
    {0x228c, 0x3e8c, 0x0336, 0x0},
    {0x235c, 0x3f5c, 0x423f, 0x0},
    {0x2364, 0x3f64, 0x5555, 0x0},
    {0x236c, 0x3f6c, 0x0000, 0x0},
    {0x2234, 0x3e34, 0x4000, 0x0},
    {0x2228, 0x3e28, 0xe0c0, 0x0},
    {0x236c, 0x3f6c, 0x8040, 0x0},
    {0x236c, 0x3f6c, 0x8000, 0x5},
    {0x2224, 0x3e24, 0x0000, 0x1},
    {0x2224, 0x3e24, 0x8000, 0x1},
    {0x2224, 0x3e24, 0x0000, 0x1},

    {0x1004, 0x1c04, 0x0018, 0x0},
    {0x2004, 0x3c04, 0x0018, 0xa},
    {0x1004, 0x1c04, 0x0008, 0x0},
    {0x2004, 0x3c04, 0x0008, 0xa},
    {0x007C, 0x007c, 0x000f, 0xa},    
    {0x1010, 0x1c10, 0x013f, 0x0},
    {0x2010, 0x3c10, 0x013f, 0x0},

    {0xffff, 0xffff, 0xffff, 0x0}
};

/*******************************************************************************
* gtAppDemoLionPortModeSpeedSet
*
* DESCRIPTION:
*       Example of configuration sequence of different ports interface modes 
*       and speeds
*
* INPUTS:
*       devNum   - device number
*       portNum  - port number (or CPU port)
*       ifMode   - Interface mode.
*       speed    - port speed
*
* OUTPUTS:
*       None
*
* RETURNS:
*       GT_OK   - on success,
*       GT_FAIL - otherwise.
*       GT_HW_ERROR - hw error
*
* COMMENTS:
*       At this moment supported:
*           CPSS_PORT_INTERFACE_MODE_RXAUI_E        10G
*           CPSS_PORT_INTERFACE_MODE_XGMII_E (XAUI) 10G, 20G
*           CPSS_PORT_INTERFACE_MODE_LOCAL_XGMII_E  10G
*           CPSS_PORT_INTERFACE_MODE_SGMII_E        10M, 100M, 1G, 2.5G
*           CPSS_PORT_INTERFACE_MODE_1000BASE_X_E   1G
*           CPSS_PORT_INTERFACE_MODE_XLG_E          40G
*
*******************************************************************************/
GT_STATUS gtAppDemoLionPortModeSpeedSet
(
    IN  GT_U8     devNum,
    IN  GT_U8     portNum,
    IN  CPSS_PORT_INTERFACE_MODE_ENT   ifMode, 
    IN  CPSS_PORT_SPEED_ENT  speed
);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* __gtDbDxLion48XGh */