/******************************************************************************
 ******************************************************************************
 **** This file was automatically generated by Epilogue Technology's
 **** Emissary SNMP MIB Compiler, version 6.3.
 **** This file was generated using the -leaf switch.
 **** 
 **** This file #defines C preprocessor macros providing a variety of
 **** information for the leaf objects in the MIB.
 **** 
 **** The file includes a LEAF_xxx macro for each leaf object in the
 **** MIB (xxx is replaced by the object's name).  The value of the
 **** LEAF_xxx macro is the final component of the object's object
 **** identifier.
 **** 
 **** If the object's SYNTAX clause included named INTEGER values,
 **** then there is a VAL_xxx_yyy macro for each named value (xxx is
 **** replaced by the object's name and yyy by the value's name).  The
 **** value of the VAL_xxx_yyy macro is the value associated with the
 **** named value.
 **** 
 **** If the object's SYNTAX clause specified a set of range limitations
 **** for the value of the object, then there are one or more sets of
 **** MIN_xxx and MAX_xxx macros specifying the lower and upper bound of
 **** each range limitation.
 **** 
 **** If the object's SYNTAX clause specified a set of size constraints
 **** for the value of the object, then there are one or more sets of
 **** MINSIZE_xxx and MAXSIZE_xxx macros specifying the lower and upper
 **** bound of each size constraint.  (If the size constraint is a single
 **** value rather than a range then the MINSIZE_xxx and MAXSIZE_xxx
 **** macros are replaced by a single SIZE_xxx macro.)
 **** 
 **** DO NOT MODIFY THIS FILE BY HAND.
 **** 
 **** Last build date: Thu Jun 19 13:29:11 2003
 **** from files:
 ****  ..\MibFiles\SnmpFramework_Rfc3411.mib, ctl\SnmpFramework_Rfc3411.ctl,
 ****  ..\MibFiles\SnmpTarget_Rfc3413.mib, ctl\SnmpTarget_Rfc3413.ctl,
 ****  ..\MibFiles\SnmpNotification_Rfc3413.mib
 ******************************************************************************
 ******************************************************************************
 */
#ifndef  LEAF_3413N_H
#define  LEAF_3413N_H

#define LEAF_snmpNotifyName	1
#define MINSIZE_snmpNotifyName	1L
#define MAXSIZE_snmpNotifyName	32L
#define LEAF_snmpNotifyTag	2
#define MINSIZE_snmpNotifyTag	0L
#define MAXSIZE_snmpNotifyTag	255L
#define LEAF_snmpNotifyType	3
#define VAL_snmpNotifyType_trap	1L
#define VAL_snmpNotifyType_inform	2L
#define LEAF_snmpNotifyStorageType	4
#define VAL_snmpNotifyStorageType_other	1L
#define VAL_snmpNotifyStorageType_volatile	2L
#define VAL_snmpNotifyStorageType_nonVolatile	3L
#define VAL_snmpNotifyStorageType_permanent	4L
#define VAL_snmpNotifyStorageType_readOnly	5L
#define LEAF_snmpNotifyRowStatus	5
#define VAL_snmpNotifyRowStatus_active	1L
#define VAL_snmpNotifyRowStatus_notInService	2L
#define VAL_snmpNotifyRowStatus_notReady	3L
#define VAL_snmpNotifyRowStatus_createAndGo	4L
#define VAL_snmpNotifyRowStatus_createAndWait	5L
#define VAL_snmpNotifyRowStatus_destroy	6L
#define LEAF_snmpNotifyFilterProfileName	1
#define MINSIZE_snmpNotifyFilterProfileName	1L
#define MAXSIZE_snmpNotifyFilterProfileName	64L  /* stardard MIB is 32, needs further discussion for Leaf_3413N/T.h */
#define LEAF_snmpNotifyFilterProfileStorType	2
#define VAL_snmpNotifyFilterProfileStorType_other	1L
#define VAL_snmpNotifyFilterProfileStorType_volatile	2L
#define VAL_snmpNotifyFilterProfileStorType_nonVolatile	3L
#define VAL_snmpNotifyFilterProfileStorType_permanent	4L
#define VAL_snmpNotifyFilterProfileStorType_readOnly	5L
#define LEAF_snmpNotifyFilterProfileRowStatus	3
#define VAL_snmpNotifyFilterProfileRowStatus_active	1L
#define VAL_snmpNotifyFilterProfileRowStatus_notInService	2L
#define VAL_snmpNotifyFilterProfileRowStatus_notReady	3L
#define VAL_snmpNotifyFilterProfileRowStatus_createAndGo	4L
#define VAL_snmpNotifyFilterProfileRowStatus_createAndWait	5L
#define VAL_snmpNotifyFilterProfileRowStatus_destroy	6L
#define LEAF_snmpNotifyFilterSubtree	1
#define LEAF_snmpNotifyFilterMask	2
#define MINSIZE_snmpNotifyFilterMask	0L
#define MAXSIZE_snmpNotifyFilterMask	16L
#define LEAF_snmpNotifyFilterType	3
#define VAL_snmpNotifyFilterType_included	1L
#define VAL_snmpNotifyFilterType_excluded	2L
#define LEAF_snmpNotifyFilterStorageType	4
#define VAL_snmpNotifyFilterStorageType_other	1L
#define VAL_snmpNotifyFilterStorageType_volatile	2L
#define VAL_snmpNotifyFilterStorageType_nonVolatile	3L
#define VAL_snmpNotifyFilterStorageType_permanent	4L
#define VAL_snmpNotifyFilterStorageType_readOnly	5L
#define LEAF_snmpNotifyFilterRowStatus	5
#define VAL_snmpNotifyFilterRowStatus_active	1L
#define VAL_snmpNotifyFilterRowStatus_notInService	2L
#define VAL_snmpNotifyFilterRowStatus_notReady	3L
#define VAL_snmpNotifyFilterRowStatus_createAndGo	4L
#define VAL_snmpNotifyFilterRowStatus_createAndWait	5L
#define VAL_snmpNotifyFilterRowStatus_destroy	6L

#endif /* end of #ifndef  LEAF_3413N_H */

