/*******************************************************************************
*              Copyright 2001, GALILEO TECHNOLOGY, LTD.
*
* THIS CODE CONTAINS CONFIDENTIAL INFORMATION OF MARVELL. NO RIGHTS ARE GRANTED
* HEREIN UNDER ANY PATENT, MASK WORK RIGHT OR COPYRIGHT OF MARVELL OR ANY THIRD
* PARTY. MARVELL RESERVES THE RIGHT AT ITS SOLE DISCRETION TO REQUEST THAT THIS
* CODE BE IMMEDIATELY RETURNED TO MARVELL. THIS CODE IS PROVIDED "AS IS".
* MARVELL MAKES NO WARRANTIES, EXPRESS, IMPLIED OR OTHERWISE, REGARDING ITS
* ACCURACY, COMPLETENESS OR PERFORMANCE. MARVELL COMPRISES MARVELL TECHNOLOGY
* GROUP LTD. (MTGL) AND ITS SUBSIDIARIES, MARVELL INTERNATIONAL LTD. (MIL),
* MARVELL TECHNOLOGY, INC. (MTI), MARVELL SEMICONDUCTOR, INC. (MSI), MARVELL
* ASIA PTE LTD. (MAPL), MARVELL JAPAN K.K. (MJKK), GALILEO TECHNOLOGY LTD. (GTL)
* AND GALILEO TECHNOLOGY, INC. (GTI).
********************************************************************************
* gtEnvDep.h
*
* DESCRIPTION:    Hardware environment depended types definition
*
* DEPENDENCIES:   Operating System.
*
* FILE REVISION NUMBER:
*       $Revision: 13 $
*******************************************************************************/

#ifndef __gtEnvDeph
#define __gtEnvDeph


typedef void  GT_VOID, *GT_VOID_PTR;
typedef char  GT_8,   *GT_8_PTR;
typedef short GT_16,  *GT_16_PTR;
typedef long  GT_32,  *GT_32_PTR;

typedef unsigned char  GT_U8,   *GT_U8_PTR;
typedef unsigned short GT_U16,  *GT_U16_PTR;
typedef unsigned long  GT_U32,  *GT_U32_PTR;

typedef void   *GT_PTR;

typedef union
{
    GT_U8   c[8];
    GT_U16  s[4];
    GT_U32  l[2];
}GT_U64;

/*
 * typedef: enum GT_BOOL
 *
 * Description: Enumeration of boolean.
 *
 * Enumerations:
 *    GT_FALSE - false.
 *    GT_TRUE  - true.
 */
typedef enum
{
    GT_FALSE = 0,
    GT_TRUE  = 1
} GT_BOOL;


/* added macro for memory barrier synchronize   */

#ifdef PPC_CPU
#ifdef __GNUC__
#ifdef _FreeBSD
#define GT_SYNC __asm __volatile (" eieio")
#else
#define GT_SYNC __asm__("   eieio")
#endif
#else
#ifdef _DIAB_TOOL 
#define GT_SYNC asm(" eieio ")
#else
#error 
#endif
#endif
#endif

#ifdef MIPS_CPU
#define GT_SYNC __asm__ __volatile__ ("sync")
#endif

#ifdef INTEL_CPU
#define GT_SYNC
#endif

#ifdef CPU_ARM
#define GT_SYNC
#endif


#endif   /* __gtEnvDeph */


