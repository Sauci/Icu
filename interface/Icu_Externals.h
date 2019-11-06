/**
 * @file Icu_Externals.h
 * @author Guillaume Sottas
 * @date 04/11/2019
 *
 * @defgroup ICU Input Capture Unit
 *
 * @defgroup ICU_H_GFDECL global function declarations
 * @ingroup ICU_H
 */

#ifndef ICU_EXTERNALS_H
#define ICU_EXTERNALS_H

#ifdef __cplusplus

extern "C" {

#endif /* #ifdef __cplusplus */

/*------------------------------------------------------------------------------------------------*/
/* global function declarations.                                                                  */
/*------------------------------------------------------------------------------------------------*/

/**
 * @addtogroup ICU_H_GFDECL
 * @{
 */

#define Icu_START_SEC_CODE_SLOW
#include "Icu_MemMap.h"

/**
 * @brief According to the last call of Icu_EnableNotification, this notification function to be
 * called if the requested signal edge (rising / falling / both edges) occurs (once per edge).
 */
extern void Icu_SignalNotification_1(void);

#define Icu_STOP_SEC_CODE_SLOW
#include "Icu_MemMap.h"

#define Icu_START_SEC_CODE_SLOW
#include "Icu_MemMap.h"

/**
 * @brief According to the last call of Icu_EnableNotification, this notification function to be
 * called if the requested signal edge (rising / falling / both edges) occurs (once per edge).
 */
extern void Icu_SignalNotification_2(void);

#define Icu_STOP_SEC_CODE_SLOW
#include "Icu_MemMap.h"

#define Icu_START_SEC_CODE_SLOW
#include "Icu_MemMap.h"

/**
 * @brief According to the last call of Icu_EnableNotification, this notification function to be
 * called if the requested signal edge (rising / falling / both edges) occurs (once per edge).
 */
extern void Icu_SignalNotification_3(void);

#define Icu_STOP_SEC_CODE_SLOW
#include "Icu_MemMap.h"

#define Icu_START_SEC_CODE_SLOW
#include "Icu_MemMap.h"

/**
 * @brief According to the last call of Icu_EnableNotification, this notification function to be
 * called if the requested signal edge (rising / falling / both edges) occurs (once per edge).
 */
extern void Icu_SignalNotification_4(void);

#define Icu_STOP_SEC_CODE_SLOW
#include "Icu_MemMap.h"

#define Icu_START_SEC_CODE_SLOW
#include "Icu_MemMap.h"

/**
 * @brief According to the last call of Icu_EnableNotification, this notification function to be
 * called if the requested signal edge (rising / falling / both edges) occurs (once per edge).
 */
extern void Icu_SignalNotification_5(void);

#define Icu_STOP_SEC_CODE_SLOW
#include "Icu_MemMap.h"

#define Icu_START_SEC_CODE_SLOW
#include "Icu_MemMap.h"

/**
 * @brief According to the last call of Icu_EnableNotification, this notification function to be
 * called if the requested signal edge (rising / falling / both edges) occurs (once per edge).
 */
extern void Icu_SignalNotification_6(void);

#define Icu_STOP_SEC_CODE_SLOW
#include "Icu_MemMap.h"

/** @} */

#ifdef __cplusplus
};

#endif /* #ifdef __cplusplus */

#endif /* #ifndef ICU_EXTERNALS_H */
