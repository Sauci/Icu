/**
 * @file Icu.h
 * @author Guillaume Sottas
 * @date 04/11/2019
 *
 * @defgroup ICU Input Capture Unit
 *
 * @defgroup ICU_H_GDEF identification informations
 * @ingroup ICU_H
 * @defgroup ICU_H_E errors classification
 * @ingroup ICU_H
 * @defgroup ICU_H_E_D development errors
 * @ingroup ICU_H_E
 * @defgroup ICU_H_E_R runtime errors
 * @ingroup ICU_H_E
 * @defgroup ICU_H_E_T transient faults
 * @ingroup ICU_H_E
 * @defgroup ICU_H_GTDEF global data type definitions
 * @ingroup ICU_H
 * @defgroup ICU_H_EFDECL external function declarations
 * @ingroup ICU_H
 * @defgroup ICU_H_GCDECL global constant declarations
 * @ingroup ICU_H
 * @defgroup ICU_H_GVDECL global variable declarations
 * @ingroup ICU_H
 * @defgroup ICU_H_GFDECL global function declarations
 * @ingroup ICU_H
 * @defgroup ICU_H_GSFDECL global scheduled function declarations
 * @ingroup ICU_H
 */

#ifndef ICU_H
#define ICU_H

#ifdef __cplusplus

extern "C" {

#endif /* #ifdef __cplusplus */

/*------------------------------------------------------------------------------------------------*/
/* included files (#include).                                                                     */
/*------------------------------------------------------------------------------------------------*/

/**
 * @addtogroup ICU_H
 * @{
 */

#include "Icu_Types.h"

#if defined(ICU_BUILD_CFFI_INTERFACE)

#if (ICU_DEV_ERROR_DETECT == STD_ON)

#include "Det.h"

#endif /* #if (ICU_DEV_ERROR_DETECT == STD_ON) */

#endif /* #if defined(ICU_BUILD_CFFI_INTERFACE) */

/** @} */

/*------------------------------------------------------------------------------------------------*/
/* global definitions (#define).                                                                  */
/*------------------------------------------------------------------------------------------------*/

/**
 * @addtogroup ICU_H_GDEF
 * @{
 */

/**
 * @brief unique identifier of the Input Capture Unit.
 * @note this value corresponds to document ID of corresponding Autosar software specification.
 */
#define ICU_MODULE_ID (0x17u)

#ifndef ICU_SW_MAJOR_VERSION

/**
 * @brief Input Capture Unit major version number.
 */
#define ICU_SW_MAJOR_VERSION (0x00u)

#endif /* #ifndef ICU_SW_MAJOR_VERSION */

#ifndef ICU_SW_MINOR_VERSION

/**
 * @brief Input Capture Unit minor version number.
 */
#define ICU_SW_MINOR_VERSION (0x01u)

#endif /* #ifndef ICU_SW_MINOR_VERSION */

#ifndef ICU_SW_PATCH_VERSION

/**
 * @brief Input Capture Unit patch version number.
 */
#define ICU_SW_PATCH_VERSION (0x00u)

#endif /* #ifndef ICU_SW_PATCH_VERSION */

/**
 * @brief @ref Icu_Init API ID.
 */
#define ICU_INIT_API_ID (0x00u)

/**
 * @brief @ref Icu_DeInit API ID.
 */
#define ICU_DE_INIT_API_ID (0x01u)

/**
 * @brief @ref Icu_SetMode API ID.
 */
#define ICU_SET_MODE_API_ID (0x02u)

/**
 * @brief @ref Icu_DisableWakeup API ID.
 */
#define ICU_DISABLE_WAKEUP_API_ID (0x03u)

/**
 * @brief @ref Icu_EnableWakeup API ID.
 */
#define ICU_ENABLE_WAKEUP_API_ID (0x04u)

/**
 * @brief @ref Icu_CheckWakeup API ID.
 */
#define ICU_CHECK_WAKEUP_API_ID (0x15u)

/**
 * @brief @ref Icu_SetActivationCondition API ID.
 */
#define ICU_SET_ACTIVATION_CONDITION_API_ID (0x05u)

/**
 * @brief @ref Icu_DisableNotification API ID.
 */
#define ICU_DISABLE_NOTIFICATION_API_ID (0x06u)

/**
 * @brief @ref Icu_EnableNotification API ID.
 */
#define ICU_ENABLE_NOTIFICATION_API_ID (0x07u)

/**
 * @brief @ref Icu_GetInputState API ID.
 */
#define ICU_GET_INPUT_STATE_API_ID (0x08u)

/**
 * @brief @ref Icu_StartTimestamp API ID.
 */
#define ICU_START_TIMESTAMP_API_ID (0x09u)

/**
 * @brief @ref Icu_StopTimestamp API ID.
 */
#define ICU_STOP_TIMESTAMP_API_ID (0x0Au)

/**
 * @brief @ref Icu_GetTimestampIndex API ID.
 */
#define ICU_GET_TIMESTAMP_INDEX_API_ID (0x0Bu)

/**
 * @brief @ref Icu_ResetEdgeCount API ID.
 */
#define ICU_RESET_EDGE_COUNT_API_ID (0x0Cu)

/**
 * @brief @ref Icu_EnableEdgeCount API ID.
 */
#define ICU_ENABLE_EDGE_COUNT_API_ID (0x0Du)

/**
 * @brief @ref Icu_EnableEdgeDetection API ID.
 */
#define ICU_ENABLE_EDGE_DETECTION_API_ID (0x16u)

/**
 * @brief @ref Icu_DisableEdgeDetection API ID.
 */
#define ICU_DISABLE_EDGE_DETECTION_API_ID (0x17u)

/**
 * @brief @ref Icu_DisableEdgeCount API ID.
 */
#define ICU_DISABLE_EDGE_COUNT_API_ID (0x0Eu)

/**
 * @brief @ref Icu_GetEdgeNumbers API ID.
 */
#define ICU_GET_EDGE_NUMBERS_API_ID (0x0Fu)

/**
 * @brief @ref Icu_StartSignalMeasurement API ID.
 */
#define ICU_START_SIGNAL_MEASUREMENT_API_ID (0x13u)

/**
 * @brief @ref Icu_StopSignalMeasurement API ID.
 */
#define ICU_STOP_SIGNAL_MEASUREMENT_API_ID (0x14u)

/**
 * @brief @ref Icu_GetTimeElapsed API ID.
 */
#define ICU_GET_TIME_ELAPSED_API_ID (0x10u)

/**
 * @brief @ref Icu_GetDutyCycleValues API ID.
 */
#define ICU_GET_DUTY_CYCLE_VALUES_API_ID (0x11u)

/**
 * @brief @ref Icu_GetVersionInfo API ID.
 */
#define ICU_GET_VERSION_INFO_API_ID (0x12u)

/**
 * @brief @ref Icu_DisableNotificationAsync API ID.
 */
#define ICU_DISABLE_NOTIFICATION_ASYNC_API_ID (0x18u)

/**
 * @brief @ref Icu_EnableNotificationAsync API ID.
 */
#define ICU_ENABLE_NOTIFICATION_ASYNC_API_ID (0x18u)

/** @} */

/**
 * @addtogroup ICU_H_E_D
 * @{
 */

/**
 * @brief API is called with invalid pointer.
 */
#define ICU_E_PARAM_POINTER (0x0Au)

/**
 * @brief API service used with an invalid channel identifier or channel was not configured for the
 * functionality of the calling API.
 */
#define ICU_E_PARAM_CHANNEL (0x0Bu)

/**
 * @brief API service used with an invalid or not feasible activation.
 */
#define ICU_E_PARAM_ACTIVATION (0x0Cu)

/**
 * @brief Init function failed.
 */
#define ICU_E_INIT_FAILED (0x0Du)

/**
 * @brief API service used with an invalid buffer size.
 */
#define ICU_E_PARAM_BUFFER_SIZE (0x0Eu)

/**
 * @brief API service Icu_SetMode used with an invalid mode.
 */
#define ICU_E_PARAM_MODE (0x0Fu)

/**
 * @brief API service used without module initialization.
 */
#define ICU_E_UNINIT (0x14u)

/**
 * @brief API service Icu_SetMode is called while a running operation.
 */
#define ICU_E_BUSY_OPERATION (0x16u)

/**
 * @brief API Icu_Init service is called and when the ICU driver and the Hardware are already
 * initialized.
 */
#define ICU_E_ALREADY_INITIALIZED (0x17u)

/**
 * @brief API Icu_StartTimeStamp is called and the parameter NotifyInterval is invalid (e.g."0",
 * NotifyInterval < 1).
 */
#define ICU_E_PARAM_NOTIFY_INTERVAL (0x18u)

/**
 * @brief API Icu_GetVersionInfo is called and the parameter versioninfo is is invalid (e.g. NULL).
 */
#define ICU_E_PARAM_VINFO (0x19u)

/** @} */

/**
 * @addtogroup ICU_H_E_R
 * @{
 */

/**
 * @brief API service Icu_StopTimestamp called on a channel which was not started or already
 * stopped.
 */
#define ICU_E_NOT_STARTED (0x15u)

/** @} */

/*------------------------------------------------------------------------------------------------*/
/* external function declarations (extern).                                                       */
/*------------------------------------------------------------------------------------------------*/

/**
 * @addtogroup ICU_H_EFDECL
 * @{
 */

/** @} */

/*------------------------------------------------------------------------------------------------*/
/* global constant declarations (extern const).                                                   */
/*------------------------------------------------------------------------------------------------*/

/**
 * @addtogroup ICU_H_GCDECL
 * @{
 */

/** @} */

/*------------------------------------------------------------------------------------------------*/
/* global variable declarations (extern).                                                         */
/*------------------------------------------------------------------------------------------------*/

/**
 * @addtogroup ICU_H_GVDECL
 * @{
 */

/** @} */

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
 * @brief This function initializes the driver.
 * @param [in] Pointer to a selected configuration structure
 */
void Icu_Init(const Icu_ConfigType *ConfigPtr);

#define Icu_STOP_SEC_CODE_SLOW
#include "Icu_MemMap.h"

#define Icu_START_SEC_CODE_SLOW
#include "Icu_MemMap.h"

/**
 * @brief This function de-initializes the ICU module.
 */
void Icu_DeInit(void);

#define Icu_STOP_SEC_CODE_SLOW
#include "Icu_MemMap.h"

#define Icu_START_SEC_CODE_SLOW
#include "Icu_MemMap.h"

/**
 * @brief This function sets the ICU mode.
 * @param [in] Mode
 *     - ICU_MODE_NORMAL: Normal operation, all used interrupts are enabled according to the
 *       notification requests
 *     - ICU_MODE_SLEEP: Reduced power mode. In sleep mode only those notifications are available
 *       which are configured as wakeup capable
 */
void Icu_SetMode(Icu_ModeType Mode);

#define Icu_STOP_SEC_CODE_SLOW
#include "Icu_MemMap.h"

#define Icu_START_SEC_CODE_SLOW
#include "Icu_MemMap.h"

/**
 * @brief This function disables the wakeup capability of a single ICU channel.
 * @param [in] Channel Numeric identifier of the ICU channel
 */
void Icu_DisableWakeup(Icu_ChannelType Channel);

#define Icu_STOP_SEC_CODE_SLOW
#include "Icu_MemMap.h"

#define Icu_START_SEC_CODE_SLOW
#include "Icu_MemMap.h"

/**
 * @brief This function (re-)enables the wakeup capability of the given ICU channel.
 * @param [in] Channel Numeric identifier of the ICU channel
 */
void Icu_EnableWakeup(Icu_ChannelType Channel);

#define Icu_STOP_SEC_CODE_SLOW
#include "Icu_MemMap.h"

#if (ICU_CHECK_WAKEUP_API == STD_ON)

#define Icu_START_SEC_CODE_SLOW
#include "Icu_MemMap.h"

/**
 * @brief Checks if a wakeup capable ICU channel is the source for a wakeup event and calls the ECU
 * state manager service EcuM_SetWakeupEvent in case of a valid ICU channel wakeup event.
 * @param [in] WakeupSource Information on wakeup source to be checked. The associated ICU channel
 *     can be determined from configuration data
 */
void Icu_CheckWakeup(EcuM_WakeupSourceType WakeupSource);

#define Icu_STOP_SEC_CODE_SLOW
#include "Icu_MemMap.h"

#endif /* #if (ICU_CHECK_WAKEUP_API == STD_ON) */

#define Icu_START_SEC_CODE_SLOW
#include "Icu_MemMap.h"

/**
 * @brief This function sets the activation-edge for the given channel.
 * @param [in] Channel Numeric identifier of the ICU channel
 * @param [in] Activation Type of activation (if supported by hardware)
 *     - ICU_RISING_EDGE
 *     - ICU_FALLING_EDGE
 *     - ICU_BOTH_EDGES
 */
void Icu_SetActivationCondition(Icu_ChannelType Channel, Icu_ActivationType Activation);

#define Icu_STOP_SEC_CODE_SLOW
#include "Icu_MemMap.h"

#define Icu_START_SEC_CODE_SLOW
#include "Icu_MemMap.h"

/**
 * @brief This function disables the notification of a channel.
 * @param [in] Channel Numeric identifier of the ICU channel
 */
void Icu_DisableNotification(Icu_ChannelType Channel);

#define Icu_STOP_SEC_CODE_SLOW
#include "Icu_MemMap.h"

#define Icu_START_SEC_CODE_SLOW
#include "Icu_MemMap.h"

/**
 * @brief This function enables the notification on the given channel.
 * @param [in] Channel Numeric identifier of the ICU channel
 */
void Icu_EnableNotification(Icu_ChannelType Channel);

#define Icu_STOP_SEC_CODE_SLOW
#include "Icu_MemMap.h"

#define Icu_START_SEC_CODE_SLOW
#include "Icu_MemMap.h"

/**
 * @brief This function returns the status of the ICU input.
 * @param [in] Channel Numeric identifier of the ICU channel
 * @retval ICU_ACTIVE: An activation edge has been detected
 * @retval ICU_IDLE: No activation edge has been detected since the last call of Icu_GetInputState()
 *     or Icu_Init()
 */
Icu_InputStateType Icu_GetInputState(Icu_ChannelType Channel);

#define Icu_STOP_SEC_CODE_SLOW
#include "Icu_MemMap.h"

#define Icu_START_SEC_CODE_SLOW
#include "Icu_MemMap.h"

/**
 * @brief This function starts the capturing of timer values on the edges.
 * @param [in] Channel Numeric identifier of the ICU channel
 * @param [in] BufferSize Size of the external buffer (number of entries)
 * @param [in] NotifyInterval Notification interval (number of events). This parameter can not be
 *     checked in a reasonable way
 * @param [out] BufferPtr Pointer to the buffer-array where the timestamp values shall be placed
 */
void Icu_StartTimestamp(Icu_ChannelType Channel,
                        Icu_ValueType *BufferPtr,
                        uint16 BufferSize,
                        uint16 NotifyInterval);

#define Icu_STOP_SEC_CODE_SLOW
#include "Icu_MemMap.h"

#define Icu_START_SEC_CODE_SLOW
#include "Icu_MemMap.h"

/**
 * @brief This function stops the timestamp measurement of the given channel.
 * @param [in] Channel Numeric identifier of the ICU channel
 */
void Icu_StopTimestamp(Icu_ChannelType Channel);

#define Icu_STOP_SEC_CODE_SLOW
#include "Icu_MemMap.h"

#define Icu_START_SEC_CODE_SLOW
#include "Icu_MemMap.h"

/**
 * @brief This function reads the timestamp index of the given channel.
 * @param [in] Channel Numeric identifier of the ICU channel
 * @return Abstract return type to cover different microcontrollers
 */
Icu_IndexType Icu_GetTimestampIndex(Icu_ChannelType Channel);

#define Icu_STOP_SEC_CODE_SLOW
#include "Icu_MemMap.h"

#define Icu_START_SEC_CODE_SLOW
#include "Icu_MemMap.h"

/**
 * @brief This function resets the value of the counted edges to zero.
 * @param [in] Channel Numeric identifier of the ICU channel
 */
void Icu_ResetEdgeCount(Icu_ChannelType Channel);

#define Icu_STOP_SEC_CODE_SLOW
#include "Icu_MemMap.h"

#define Icu_START_SEC_CODE_SLOW
#include "Icu_MemMap.h"

/**
 * @brief This function enables the counting of edges of the given channel.
 * @param [in] Channel Numeric identifier of the ICU channel
 */
void Icu_EnableEdgeCount(Icu_ChannelType Channel);

#define Icu_STOP_SEC_CODE_SLOW
#include "Icu_MemMap.h"

#define Icu_START_SEC_CODE_SLOW
#include "Icu_MemMap.h"

/**
 * @brief This function enables / re-enables the detection of edges of the given channel.
 * @param [in] Channel Numeric identifier of the ICU channel
 */
void Icu_EnableEdgeDetection(Icu_ChannelType Channel);

#define Icu_STOP_SEC_CODE_SLOW
#include "Icu_MemMap.h"

#define Icu_START_SEC_CODE_SLOW
#include "Icu_MemMap.h"

/**
 * @brief This function disables the detection of edges of the given channel.
 * @param [in] Channel Numeric identifier of the ICU channel
 */
void Icu_DisableEdgeDetection(Icu_ChannelType Channel);

#define Icu_STOP_SEC_CODE_SLOW
#include "Icu_MemMap.h"

#define Icu_START_SEC_CODE_SLOW
#include "Icu_MemMap.h"

/**
 * @brief This function disables the counting of edges of the given channel.
 * @param [in] Channel Numeric identifier of the ICU channel
 */
void Icu_DisableEdgeCount(Icu_ChannelType Channel);

#define Icu_STOP_SEC_CODE_SLOW
#include "Icu_MemMap.h"

#define Icu_START_SEC_CODE_SLOW
#include "Icu_MemMap.h"

/**
 * @brief This function reads the number of counted edges.
 * @param [in] Channel Numeric identifier of the ICU channel
 * @return Abstract return type to cover different microcontrollers
 */
Icu_EdgeNumberType Icu_GetEdgeNumbers(Icu_ChannelType Channel);

#define Icu_STOP_SEC_CODE_SLOW
#include "Icu_MemMap.h"

#define Icu_START_SEC_CODE_SLOW
#include "Icu_MemMap.h"

/**
 * @brief This function starts the measurement of signals.
 * @param [in] Channel Numeric identifier of the ICU channel
 */
void Icu_StartSignalMeasurement(Icu_ChannelType Channel);

#define Icu_STOP_SEC_CODE_SLOW
#include "Icu_MemMap.h"

#define Icu_START_SEC_CODE_SLOW
#include "Icu_MemMap.h"

/**
 * @brief This function stops the measurement of signals of the given channel.
 * @param [in] Channel Numeric identifier of the ICU channel
 */
void Icu_StopSignalMeasurement(Icu_ChannelType Channel);

#define Icu_STOP_SEC_CODE_SLOW
#include "Icu_MemMap.h"

#define Icu_START_SEC_CODE_SLOW
#include "Icu_MemMap.h"

/**
 * @brief This function reads the elapsed Signal Low Time for the given channel.
 * @param [in] Channel Numeric identifier of the ICU channel
 * @return Elapsed Signal Low Time
 */
Icu_ValueType Icu_GetTimeElapsed(Icu_ChannelType Channel);

#define Icu_STOP_SEC_CODE_SLOW
#include "Icu_MemMap.h"

#define Icu_START_SEC_CODE_SLOW
#include "Icu_MemMap.h"

/**
 * @brief This function reads the coherent active time and period time for the given ICU Channel.
 * @param [in] Channel Numeric identifier of the ICU channel
 * @param [out] DutyCycleValues Pointer to a buffer where the results (high time and period time)
 * shall be placed
 */
void Icu_GetDutyCycleValues(Icu_ChannelType Channel, Icu_DutyCycleType *DutyCycleValues);

#define Icu_STOP_SEC_CODE_SLOW
#include "Icu_MemMap.h"

#define Icu_START_SEC_CODE_SLOW
#include "Icu_MemMap.h"

/**
 * @brief This function returns the version information of this module.
 * @param [out] Pointer to where to store the version information of this module
 * shall be placed
 */
void Icu_GetVersionInfo(Std_VersionInfoType *versioninfo);

#define Icu_STOP_SEC_CODE_SLOW
#include "Icu_MemMap.h"

#define Icu_START_SEC_CODE_SLOW
#include "Icu_MemMap.h"

/**
 * @brief This function disables the notification of a channel.
 * @param [in] Channel Numeric identifier of the ICU channel
 */
void Icu_DisableNotificationAsync(Icu_ChannelType Channel);

#define Icu_STOP_SEC_CODE_SLOW
#include "Icu_MemMap.h"

#define Icu_START_SEC_CODE_SLOW
#include "Icu_MemMap.h"

/**
 * @brief This function enables the notification on the given channel.
 * @param [in] Channel Numeric identifier of the ICU channel
 */
void Icu_EnableNotificationAsync(Icu_ChannelType Channel);

#define Icu_STOP_SEC_CODE_SLOW
#include "Icu_MemMap.h"

/** @} */

#ifdef __cplusplus
};

#endif /* #ifdef __cplusplus */

#endif /* #ifndef ICU_H */
