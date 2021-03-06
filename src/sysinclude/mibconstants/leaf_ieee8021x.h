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
 **** Last build date: Thu Sep 12 16:50:31 2002
 **** from files:
 ****  ..\mib_files\ianaiftype.mib, ..\mib_files\Rfc1907.mib,
 ****  ..\mib_files\Rfc2863-IF-updated.mib,
 ****  ..\mib_files\Rfc2271-SNMP-FRAMEWORK.MIB, ..\mib_files\IEEE8021-PAE.mib,
 ****  ..\mib_files\ieee8021x.ctl
 ******************************************************************************
 ******************************************************************************
 */
#ifndef  LEAF_IEEE8021X_H
#define  LEAF_IEEE8021X_H

#define LEAF_dot1xPaeSystemAuthControl	1
#define VAL_dot1xPaeSystemAuthControl_enabled	1L
#define VAL_dot1xPaeSystemAuthControl_disabled	2L
#define LEAF_dot1xPaePortNumber	1
#define MIN_dot1xPaePortNumber	1L
#define MAX_dot1xPaePortNumber	2147483647L
#define LEAF_dot1xPaePortProtocolVersion	2
#define LEAF_dot1xPaePortCapabilities	3
#define VAL_dot1xPaePortCapabilities_dot1xPaePortAuthCapable	0L
#define VAL_dot1xPaePortCapabilities_dot1xPaePortSuppCapable	1L
#define LEAF_dot1xPaePortInitialize	4
#define VAL_dot1xPaePortInitialize_true	1L
#define VAL_dot1xPaePortInitialize_false	2L
#define LEAF_dot1xPaePortReauthenticate	5
#define VAL_dot1xPaePortReauthenticate_true	1L
#define VAL_dot1xPaePortReauthenticate_false	2L
#define LEAF_dot1xAuthPaeState	1
#define VAL_dot1xAuthPaeState_initialize	1L
#define VAL_dot1xAuthPaeState_disconnected	2L
#define VAL_dot1xAuthPaeState_connecting	3L
#define VAL_dot1xAuthPaeState_authenticating	4L
#define VAL_dot1xAuthPaeState_authenticated	5L
#define VAL_dot1xAuthPaeState_aborting	6L
#define VAL_dot1xAuthPaeState_held	7L
#define VAL_dot1xAuthPaeState_forceAuth	8L
#define VAL_dot1xAuthPaeState_forceUnauth	9L
#define LEAF_dot1xAuthBackendAuthState	2
#define VAL_dot1xAuthBackendAuthState_request	1L
#define VAL_dot1xAuthBackendAuthState_response	2L
#define VAL_dot1xAuthBackendAuthState_success	3L
#define VAL_dot1xAuthBackendAuthState_fail	4L
#define VAL_dot1xAuthBackendAuthState_timeout	5L
#define VAL_dot1xAuthBackendAuthState_idle	6L
#define VAL_dot1xAuthBackendAuthState_initialize	7L
#define LEAF_dot1xAuthAdminControlledDirections	3
#define VAL_dot1xAuthAdminControlledDirections_both	0L
#define VAL_dot1xAuthAdminControlledDirections_in	1L
#define LEAF_dot1xAuthOperControlledDirections	4
#define VAL_dot1xAuthOperControlledDirections_both	0L
#define VAL_dot1xAuthOperControlledDirections_in	1L
#define LEAF_dot1xAuthAuthControlledPortStatus	5
#define VAL_dot1xAuthAuthControlledPortStatus_authorized	1L
#define VAL_dot1xAuthAuthControlledPortStatus_unauthorized	2L
#define LEAF_dot1xAuthAuthControlledPortControl	6
#define VAL_dot1xAuthAuthControlledPortControl_forceUnauthorized	1L
#define VAL_dot1xAuthAuthControlledPortControl_auto	2L
#define VAL_dot1xAuthAuthControlledPortControl_forceAuthorized	3L
#define LEAF_dot1xAuthQuietPeriod	7
#define LEAF_dot1xAuthTxPeriod	8
#define LEAF_dot1xAuthSuppTimeout	9
#define LEAF_dot1xAuthServerTimeout	10
#define LEAF_dot1xAuthMaxReq	11
#define MIN_dot1xAuthMaxReauthReq       1L
#define MAX_dot1xAuthMaxReauthReq       10L
#define LEAF_dot1xAuthReAuthPeriod	12
#define LEAF_dot1xAuthReAuthEnabled	13
#define VAL_dot1xAuthReAuthEnabled_true	1L
#define VAL_dot1xAuthReAuthEnabled_false	2L
#define LEAF_dot1xAuthKeyTxEnabled	14
#define VAL_dot1xAuthKeyTxEnabled_true	1L
#define VAL_dot1xAuthKeyTxEnabled_false	2L
#define LEAF_dot1xAuthEapolFramesRx	1
#define LEAF_dot1xAuthEapolFramesTx	2
#define LEAF_dot1xAuthEapolStartFramesRx	3
#define LEAF_dot1xAuthEapolLogoffFramesRx	4
#define LEAF_dot1xAuthEapolRespIdFramesRx	5
#define LEAF_dot1xAuthEapolRespFramesRx	6
#define LEAF_dot1xAuthEapolReqIdFramesTx	7
#define LEAF_dot1xAuthEapolReqFramesTx	8
#define LEAF_dot1xAuthInvalidEapolFramesRx	9
#define LEAF_dot1xAuthEapLengthErrorFramesRx	10
#define LEAF_dot1xAuthLastEapolFrameVersion	11
#define LEAF_dot1xAuthLastEapolFrameSource	12
#define SIZE_dot1xAuthLastEapolFrameSource	6L
#define LEAF_dot1xAuthEntersConnecting	1
#define LEAF_dot1xAuthEapLogoffsWhileConnecting	2
#define LEAF_dot1xAuthEntersAuthenticating	3
#define LEAF_dot1xAuthAuthSuccessWhileAuthenticating	4
#define LEAF_dot1xAuthAuthTimeoutsWhileAuthenticating	5
#define LEAF_dot1xAuthAuthFailWhileAuthenticating	6
#define LEAF_dot1xAuthAuthReauthsWhileAuthenticating	7
#define LEAF_dot1xAuthAuthEapStartsWhileAuthenticating	8
#define LEAF_dot1xAuthAuthEapLogoffWhileAuthenticating	9
#define LEAF_dot1xAuthAuthReauthsWhileAuthenticated	10
#define LEAF_dot1xAuthAuthEapStartsWhileAuthenticated	11
#define LEAF_dot1xAuthAuthEapLogoffWhileAuthenticated	12
#define LEAF_dot1xAuthBackendResponses	13
#define LEAF_dot1xAuthBackendAccessChallenges	14
#define LEAF_dot1xAuthBackendOtherRequestsToSupplicant	15
#define LEAF_dot1xAuthBackendNonNakResponsesFromSupplicant	16
#define LEAF_dot1xAuthBackendAuthSuccesses	17
#define LEAF_dot1xAuthBackendAuthFails	18
#define LEAF_dot1xAuthSessionOctetsRx	1
#define LEAF_dot1xAuthSessionOctetsTx	2
#define LEAF_dot1xAuthSessionFramesRx	3
#define LEAF_dot1xAuthSessionFramesTx	4
#define LEAF_dot1xAuthSessionId	5
#define MINSIZE_dot1xAuthSessionId	0L
#define MAXSIZE_dot1xAuthSessionId	255L
#define LEAF_dot1xAuthSessionAuthenticMethod	6
#define VAL_dot1xAuthSessionAuthenticMethod_remoteAuthServer	1L
#define VAL_dot1xAuthSessionAuthenticMethod_localAuthServer	2L
#define LEAF_dot1xAuthSessionTime	7
#define LEAF_dot1xAuthSessionTerminateCause	8
#define VAL_dot1xAuthSessionTerminateCause_supplicantLogoff	1L
#define VAL_dot1xAuthSessionTerminateCause_portFailure	2L
#define VAL_dot1xAuthSessionTerminateCause_supplicantRestart	3L
#define VAL_dot1xAuthSessionTerminateCause_reauthFailed	4L
#define VAL_dot1xAuthSessionTerminateCause_authControlForceUnauth	5L
#define VAL_dot1xAuthSessionTerminateCause_portReInit	6L
#define VAL_dot1xAuthSessionTerminateCause_portAdminDisabled	7L
#define VAL_dot1xAuthSessionTerminateCause_notTerminatedYet	999L
#define LEAF_dot1xAuthSessionUserName	9
#define MINSIZE_dot1xAuthSessionUserName	0L
#define MAXSIZE_dot1xAuthSessionUserName	255L

#define LEAF_dot1xSuppPaeState   1
#define VAL_dot1xSuppPaeState_disconnected 1L
#define VAL_dot1xSuppPaeState_logoff 2L
#define VAL_dot1xSuppPaeState_connecting 3L
#define VAL_dot1xSuppPaeState_authenticating 4L
#define VAL_dot1xSuppPaeState_authenticated 5L
#define VAL_dot1xSuppPaeState_acquired 6L
#define VAL_dot1xSuppPaeState_held 7L
#define LEAF_dot1xSuppHeldPeriod   2
#define LEAF_dot1xSuppAuthPeriod   3
#define LEAF_dot1xSuppStartPeriod   4
#define LEAF_dot1xSuppMaxStart   5

#define LEAF_dot1xSuppEapolFramesRx   1
#define LEAF_dot1xSuppEapolFramesTx   2
#define LEAF_dot1xSuppEapolStartFramesTx   3
#define LEAF_dot1xSuppEapolLogoffFramesTx   4
#define LEAF_dot1xSuppEapolRespIdFramesTx   5
#define LEAF_dot1xSuppEapolRespFramesTx   6
#define LEAF_dot1xSuppEapolReqIdFramesRx   7
#define LEAF_dot1xSuppEapolReqFramesRx   8
#define LEAF_dot1xSuppInvalidEapolFramesRx   9
#define LEAF_dot1xSuppEapLengthErrorFramesRx   10
#define LEAF_dot1xSuppLastEapolFrameVersion   11
#define LEAF_dot1xSuppLastEapolFrameSource   12
#define SIZE_dot1xSuppLastEapolFrameSource 6L

#endif /* end of #ifndef  LEAF_IEEE8021X_H */

