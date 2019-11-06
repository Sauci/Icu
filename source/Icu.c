/**
 * @file Icu.c
 * @author
 * @date
 *
 * @defgroup ICU_C implementation
 * @ingroup ICU
 *
 * @defgroup ICU_C_LDEF local definitions
 * @ingroup ICU_C
 * @defgroup ICU_C_LTDEF local data type definitions
 * @ingroup ICU_C
 * @defgroup ICU_C_LMDEF local macros
 * @ingroup ICU_C
 * @defgroup ICU_C_LFDECL local function declarations
 * @ingroup ICU_C
 * @defgroup ICU_C_LCDEF local constant definitions
 * @ingroup ICU_C
 * @defgroup ICU_C_LVDEF local variable definitions
 * @ingroup ICU_C
 * @defgroup ICU_C_GCDEF global constant definitions
 * @ingroup ICU_C
 * @defgroup ICU_C_GVDEF global variable definitions
 * @ingroup ICU_C
 * @defgroup ICU_C_GFDEF global function definitions
 * @ingroup ICU_C
 * @defgroup ICU_C_GSFDEF global scheduled function definitions
 * @ingroup ICU_C
 * @defgroup ICU_C_GCFDEF global callback function definitions
 * @ingroup ICU_C
 * @defgroup ICU_C_LFDEF local function definitions
 * @ingroup ICU_C
 */

/*------------------------------------------------------------------------------------------------*/
/* included files (#include).                                                                     */
/*------------------------------------------------------------------------------------------------*/

/**
 * @addtogroup ICU_C
 * @{
 */

#ifdef __cplusplus

extern "C" {

#endif /* ifdef __cplusplus */

#include "Icu.h"

/** @} */

/*------------------------------------------------------------------------------------------------*/
/* local definitions (#define).                                                                   */
/*------------------------------------------------------------------------------------------------*/

/**
 * @addtogroup ICU_C_LDEF
 * @{
 */

/** @} */

/*------------------------------------------------------------------------------------------------*/
/* local data type definitions (typedef, struct).                                                 */
/*------------------------------------------------------------------------------------------------*/

/**
 * @addtogroup ICU_C_LTDEF
 * @{
 */

/** @} */

/*------------------------------------------------------------------------------------------------*/
/* local macros definitions (#define, inline).                                                    */
/*------------------------------------------------------------------------------------------------*/

/**
 * @addtogroup ICU_C_LMDEF
 * @{
 */

LOCAL_INLINE void Icu_ReportError(uint8 instanceId, uint8 apiId, uint8 errorId)
{
#if (ICU_DEV_ERROR_DETECT == STD_ON)

    (void)Det_ReportError(ICU_MODULE_ID, instanceId, apiId, errorId);

#else

    (void)instanceId;
    (void)apiId;
    (void)errorId;

#endif /* #if (ICU_DEV_ERROR_DETECT == STD_ON) */
}

/** @} */

/*------------------------------------------------------------------------------------------------*/
/* local function declarations (static).                                                          */
/*------------------------------------------------------------------------------------------------*/

/**
 * @addtogroup ICU_C_LFDECL
 * @{
 */

/** @} */

/*------------------------------------------------------------------------------------------------*/
/* local constant definitions (static const).                                                     */
/*------------------------------------------------------------------------------------------------*/

/**
 * @addtogroup ICU_C_LCDEF
 * @{
 */

/** @} */

/*------------------------------------------------------------------------------------------------*/
/* local variable definitions (static).                                                           */
/*------------------------------------------------------------------------------------------------*/

/**
 * @addtogroup ICU_C_LVDEF
 * @{
 */

#define Icu_START_SEC_VAR_FAST_INIT_BOOLEAN
#include "Icu_MemMap.h"

static boolean Icu_Initialized = FALSE;

#define Icu_STOP_SEC_VAR_FAST_INIT_BOOLEAN
#include "Icu_MemMap.h"

/** @} */

/*------------------------------------------------------------------------------------------------*/
/* global constant definitions (extern const).                                                    */
/*------------------------------------------------------------------------------------------------*/

/**
 * @addtogroup ICU_C_GCDEF
 * @{
 */

/** @} */

/*------------------------------------------------------------------------------------------------*/
/* global variable definitions (extern).                                                          */
/*------------------------------------------------------------------------------------------------*/

/**
 * @addtogroup ICU_C_GVDEF
 * @{
 */

#define Icu_START_SEC_VAR_FAST_INIT_BOOLEAN
#include "Icu_MemMap.h"

Icu_ModeType Icu_Mode = ICU_MODE_SLEEP;

#define Icu_STOP_SEC_VAR_FAST_INIT_BOOLEAN
#include "Icu_MemMap.h"

/** @} */

/*------------------------------------------------------------------------------------------------*/
/* global function definitions.                                                                   */
/*------------------------------------------------------------------------------------------------*/

/**
 * @addtogroup ICU_C_GFDEF
 * @{
 */

void Icu_Init(const Icu_ConfigType *ConfigPtr)
{
    /* SWS_Icu_00220: If development error detection for the ICU module is enabled and the function
     * Icu_Init is called when the ICU driver and hardware are already initialized, the function
     * Icu_Init shall raise development error ICU_E_ALREADY_INITIALIZED and return without any
     * action. */
    if (Icu_Initialized == FALSE)
    {
        /* SWS_Icu_00138: The initialization function of this module shall always have a pointer as
         * a parameter, even though for Variant PC no configuration set shall be given. Instead a
         * NULL pointer shall be passed to the initialization function. */
        if (ConfigPtr != NULL_PTR)
        {
        }
        else
        {
            /* MISRA C, do nothing. */
        }

        Icu_Initialized = TRUE;

        /* SWS_Icu_00060: The function Icu_Init shall set the module mode to ICU_MODE_NORMAL. */
        Icu_Mode = ICU_MODE_NORMAL;
    }
    else
    {
        Icu_ReportError(0x00u, ICU_INIT_API_ID, ICU_E_ALREADY_INITIALIZED);
    }
}

void Icu_DeInit(void)
{
}

void Icu_SetMode(Icu_ModeType Mode)
{
    (void)Mode;
}

void Icu_DisableWakeup(Icu_ChannelType Channel)
{
    (void)Channel;
}

void Icu_EnableWakeup(Icu_ChannelType Channel)
{
    (void)Channel;
}

#if (ICU_CHECK_WAKEUP_API == STD_ON)

void Icu_CheckWakeup(EcuM_WakeupSourceType WakeupSource)
{
    (void)WakeupSource;
}

#endif /* #if (ICU_CHECK_WAKEUP_API == STD_ON) */

void Icu_SetActivationCondition(Icu_ChannelType Channel, Icu_ActivationType Activation)
{
    (void)Channel;
    (void)Activation;
}

void Icu_DisableNotification(Icu_ChannelType Channel)
{
    (void)Channel;
}

void Icu_EnableNotification(Icu_ChannelType Channel)
{
    (void)Channel;
}

Icu_InputStateType Icu_GetInputState(Icu_ChannelType Channel)
{
    (void)Channel;

    return ICU_IDLE;
}

void Icu_StartTimestamp(Icu_ChannelType Channel,
                        Icu_ValueType *BufferPtr,
                        uint16 BufferSize,
                        uint16 NotifyInterval)
{
    (void)Channel;
    (void)BufferPtr;
    (void)BufferSize;
    (void)NotifyInterval;
}

void Icu_StopTimestamp(Icu_ChannelType Channel)
{
    (void)Channel;
}

Icu_IndexType Icu_GetTimestampIndex(Icu_ChannelType Channel)
{
    (void)Channel;

    return 0u;
}

void Icu_ResetEdgeCount(Icu_ChannelType Channel)
{
    (void)Channel;
}

void Icu_EnableEdgeCount(Icu_ChannelType Channel)
{
    (void)Channel;
}

void Icu_EnableEdgeDetection(Icu_ChannelType Channel)
{
    (void)Channel;
}

void Icu_DisableEdgeDetection(Icu_ChannelType Channel)
{
    (void)Channel;
}

void Icu_DisableEdgeCount(Icu_ChannelType Channel)
{
    (void)Channel;
}

Icu_EdgeNumberType Icu_GetEdgeNumbers(Icu_ChannelType Channel)
{
    (void)Channel;

    return 0u;
}

void Icu_StartSignalMeasurement(Icu_ChannelType Channel)
{
    (void)Channel;
}

void Icu_StopSignalMeasurement(Icu_ChannelType Channel)
{
    (void)Channel;
}

Icu_ValueType Icu_GetTimeElapsed(Icu_ChannelType Channel)
{
    (void)Channel;

    return 0u;
}

void Icu_GetDutyCycleValues(Icu_ChannelType Channel, Icu_DutyCycleType *DutyCycleValues)
{
    (void)Channel;
    (void)DutyCycleValues;
}

void Icu_GetVersionInfo(Std_VersionInfoType *versioninfo)
{
    (void)versioninfo;
}

void Icu_DisableNotificationAsync(Icu_ChannelType Channel)
{
    (void)Channel;
}

void Icu_EnableNotificationAsync(Icu_ChannelType Channel)
{
    (void)Channel;
}

/** @} */

/*------------------------------------------------------------------------------------------------*/
/* global scheduled function definitions.                                                         */
/*------------------------------------------------------------------------------------------------*/

/**
 * @addtogroup ICU_C_GSFDEF
 * @{
 */

/** @} */

/*------------------------------------------------------------------------------------------------*/
/* global callback function definitions.                                                          */
/*------------------------------------------------------------------------------------------------*/

/**
 * @addtogroup ICU_C_GCFDEF
 * @{
 */

/** @} */

#ifdef __cplusplus
}

#endif /* ifdef __cplusplus */
