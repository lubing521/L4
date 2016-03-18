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
 **** Last build date: Fri Nov  9 23:34:03 2001
 **** from files:
 ****  Rfc1213.mib, Rfc1493-BRIDGE.mib, V-BRIDGE.mib, v-bridge.ctl
 ******************************************************************************
 ******************************************************************************
 */
#ifndef  LEAF_VBRIDGE_H
#define  LEAF_VBRIDGE_H

#define LEAF_dot1vProtocolTemplateFrameType	1
#define VAL_dot1vProtocolTemplateFrameType_ethernet	1L
#define VAL_dot1vProtocolTemplateFrameType_rfc1042	2L
#define VAL_dot1vProtocolTemplateFrameType_snap8021H	3L
#define VAL_dot1vProtocolTemplateFrameType_snapOther	4L
#define VAL_dot1vProtocolTemplateFrameType_llcOther	5L
#define LEAF_dot1vProtocolTemplateProtocolValue	2
#define SIZE_dot1vProtocolTemplateProtocolValue_1	2L
#define SIZE_dot1vProtocolTemplateProtocolValue_2	5L
#define LEAF_dot1vProtocolGroupId	3
#define MIN_dot1vProtocolGroupId	0L
#define MAX_dot1vProtocolGroupId	2147483647L
#define LEAF_dot1vProtocolGroupRowStatus	4
#define VAL_dot1vProtocolGroupRowStatus_active	1L
#define VAL_dot1vProtocolGroupRowStatus_notInService	2L
#define VAL_dot1vProtocolGroupRowStatus_notReady	3L
#define VAL_dot1vProtocolGroupRowStatus_createAndGo	4L
#define VAL_dot1vProtocolGroupRowStatus_createAndWait	5L
#define VAL_dot1vProtocolGroupRowStatus_destroy	6L
#define LEAF_dot1vProtocolPortGroupId	1
#define MIN_dot1vProtocolPortGroupId	1L
#define MAX_dot1vProtocolPortGroupId	2147483647L
#define LEAF_dot1vProtocolPortGroupVid	2
#define MIN_dot1vProtocolPortGroupVid	1L
#define MAX_dot1vProtocolPortGroupVid	4094L
#define LEAF_dot1vProtocolPortRowStatus	3
#define VAL_dot1vProtocolPortRowStatus_active	1L
#define VAL_dot1vProtocolPortRowStatus_notInService	2L
#define VAL_dot1vProtocolPortRowStatus_notReady	3L
#define VAL_dot1vProtocolPortRowStatus_createAndGo	4L
#define VAL_dot1vProtocolPortRowStatus_createAndWait	5L
#define VAL_dot1vProtocolPortRowStatus_destroy	6L

#endif /* end of #ifndef  LEAF_VBRIDGE_H */