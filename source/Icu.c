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

#define ECAP_TSCTR_OFFSET (0x00u)
#define ECAP_CTRPHS_OFFSET (0x04u)
#define ECAP_CAP1_OFFSET (0x08u)
#define ECAP_CAP2_OFFSET (0x0Cu)
#define ECAP_CAP3_OFFSET (0x10u)
#define ECAP_CAP4_OFFSET (0x14u)
#define ECAP_ECCTL2_OFFSET (0x28u)
#define ECAP_ECCTL1_OFFSET (0x2Au)
// #define ECAP_ECFLG_OFFSET (0x2Cu)
#define ECAP_ECEINT_OFFSET (0x2Eu)
#define ECAP_ECFRC_OFFSET (0x30u)
#define ECAP_ECCLR_OFFSET (0x32u)

#define ECAP1_BASE_ADDRESS (0xFCF79300u)
#define ECAP2_BASE_ADDRESS (0xFCF79400u)
#define ECAP3_BASE_ADDRESS (0xFCF79500u)
#define ECAP4_BASE_ADDRESS (0xFCF79600u)
#define ECAP5_BASE_ADDRESS (0xFCF79700u)
#define ECAP6_BASE_ADDRESS (0xFCF79800u)

#define ECAP_ECCTL1_CAPPOL_MASK (0x01u | (0x01u << 0x02u) | (0x01u << 0x04u) | (0x01u << 0x06u))

#define ICU_ECAP_CHANNEL_COUNT (0x06u)

/** @} */

/*------------------------------------------------------------------------------------------------*/
/* local data type definitions (typedef, struct).                                                 */
/*------------------------------------------------------------------------------------------------*/

/**
 * @addtogroup ICU_C_LTDEF
 * @{
 */

typedef struct
{
    Icu_ChannelType channel_id_ext;
    Icu_ChannelType channel_id_int;
    Icu_InputStateType input_state;
} Icu_ChannelRtType;

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

#define Icu_START_SEC_CODE_FAST
#include "Icu_MemMap.h"

static Std_ReturnType Icu_GetRtChannel(Icu_ChannelType channel, Icu_ChannelRtType **pChannel);

#define Icu_STOP_SEC_CODE_FAST
#include "Icu_MemMap.h"

/** @} */

/*------------------------------------------------------------------------------------------------*/
/* local constant definitions (static const).                                                     */
/*------------------------------------------------------------------------------------------------*/

/**
 * @addtogroup ICU_C_LCDEF
 * @{
 */

#define Icu_START_SEC_CONST_32
#include "Icu_MemMap.h"

static const uint32 Icu_EcapBaseAddr[ICU_ECAP_CHANNEL_COUNT] = {ECAP1_BASE_ADDRESS,
                                                                ECAP2_BASE_ADDRESS,
                                                                ECAP3_BASE_ADDRESS,
                                                                ECAP4_BASE_ADDRESS,
                                                                ECAP5_BASE_ADDRESS,
                                                                ECAP6_BASE_ADDRESS};

#define Icu_STOP_SEC_CONST_32
#include "Icu_MemMap.h"

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

#define Icu_START_SEC_VAR_FAST_INIT_UNSPECIFIED
#include "Icu_MemMap.h"

static Icu_ChannelRtType Icu_Rt[ICU_ECAP_CHANNEL_COUNT];

#define Icu_STOP_SEC_VAR_FAST_INIT_UNSPECIFIED
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
    uint32 idx;
    uint16 tmp_16_reg;
    uint32 ecap_base_addr;
    const Icu_ChannelConfigType *p_channel_config;

    /* SWS_Icu_00220: If development error detection for the ICU module is enabled and the function
     * Icu_Init is called when the ICU driver and hardware are already initialized, the function
     * Icu_Init shall raise development error ICU_E_ALREADY_INITIALIZED and return without any
     * action. */
    if (Icu_Initialized == FALSE)
    {
        for (idx = 0x00u; idx < ICU_ECAP_CHANNEL_COUNT; idx++)
        {
            ecap_base_addr = Icu_EcapBaseAddr[idx];

            REG_WRITE_32(ecap_base_addr + ECAP_TSCTR_OFFSET, 0x00000000u);
            REG_WRITE_32(ecap_base_addr + ECAP_CTRPHS_OFFSET, 0x00000000u);
            REG_WRITE_32(ecap_base_addr + ECAP_CAP1_OFFSET, 0x00000000u);
            REG_WRITE_32(ecap_base_addr + ECAP_CAP2_OFFSET, 0x00000000u);
            REG_WRITE_32(ecap_base_addr + ECAP_CAP3_OFFSET, 0x00000000u);
            REG_WRITE_32(ecap_base_addr + ECAP_CAP4_OFFSET, 0x00000000u);
            /* eCAP ECFLG register is read-only (SPNU563A 33.5.9). */
            REG_WRITE_32(ecap_base_addr + ECAP_ECEINT_OFFSET, 0x00000000u);
            REG_WRITE_32(ecap_base_addr + ECAP_ECFRC_OFFSET, 0x00000000u);
            REG_WRITE_32(ecap_base_addr + ECAP_ECCLR_OFFSET, 0x00000000u);

            /* SWS_Icu_00138: The initialization function of this module shall always have a pointer
             * as a parameter, even though for Variant PC no configuration set shall be given.
             * Instead a NULL pointer shall be passed to the initialization function. */
            if (ConfigPtr != NULL_PTR)
            {
                p_channel_config = &ConfigPtr->pChannelConfig[idx];

                Icu_Rt[idx].channel_id_ext = p_channel_config->IcuChannelId;
                Icu_Rt[idx].channel_id_int = idx;

                /* SWS_Icu_00006: The function Icu_Init shall initialize all relevant registers of
                 * the configured hardware with the values of the structure referenced by the
                 * parameter ConfigPtr. */
                Icu_SetActivationCondition(p_channel_config->IcuChannelId,
                                           p_channel_config->IcuDefaultStartEdge);

                tmp_16_reg = REG_READ_16(ecap_base_addr + ECAP_ECCTL1_OFFSET);

                /* reset counter after event 1..4 timestamp has been captured. */
                tmp_16_reg |= (0x01u << 0x01u);
                tmp_16_reg |= (0x01u << 0x03u);
                tmp_16_reg |= (0x01u << 0x05u);
                tmp_16_reg |= (0x01u << 0x07u);

                /* enable loading of CAP 1..4 registers on a capture event. */
                tmp_16_reg |= (0x01u << 0x08u);

                /* set input prescaler from configuration parameter. */
                tmp_16_reg |= (uint16)((uint16)(p_channel_config->Prescaler >> 0x02u) << 0x09u);

                REG_WRITE_16(ecap_base_addr + ECAP_ECCTL1_OFFSET, tmp_16_reg);
                tmp_16_reg = REG_READ_16(ecap_base_addr + ECAP_ECCTL2_OFFSET);

                /* run in continuous mode. */
                tmp_16_reg &= ~(0x01u);

                /* wrap after event 2 has been captured. */
                tmp_16_reg &= ~(0x03u << 0x01u);
                tmp_16_reg |= (0x01u << 0x01u);

                /* set mode of operation to capture. */
                tmp_16_reg &= ~(0x01u << 0x09u);

                /* start timestamp counter. */
                tmp_16_reg |= (0x01u << 0x04u);

                REG_WRITE_16(ecap_base_addr + ECAP_ECCTL2_OFFSET, tmp_16_reg);
            }
            else
            {
                REG_WRITE_32(ecap_base_addr + ECAP_ECCTL2_OFFSET, 0x00000000u);
                REG_WRITE_32(ecap_base_addr + ECAP_ECCTL1_OFFSET, 0x00000000u);
            }

            /* SWS_Icu_00040: The function Icu_Init shall set all used ICU channels to status
             * ICU_IDLE. */
            Icu_Rt[idx].input_state = ICU_IDLE;
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
    uint16 tmp_16_reg;
    Icu_ChannelRtType *p_channel_rt;

    if (Icu_GetRtChannel(Channel, &p_channel_rt) == E_OK)
    {
        const uint32 ecap_base_addr = Icu_EcapBaseAddr[p_channel_rt->channel_id_int];
        tmp_16_reg = REG_READ_16(ecap_base_addr + ECAP_ECCTL1_OFFSET);

        switch (Activation)
        {
            case ICU_RISING_EDGE:
            {
                tmp_16_reg &= ~ECAP_ECCTL1_CAPPOL_MASK;
                break;
            }
            case ICU_FALLING_EDGE:
            {
                tmp_16_reg |= ECAP_ECCTL1_CAPPOL_MASK;
                break;
            }
            case ICU_BOTH_EDGES:
            {
                tmp_16_reg &= ~ECAP_ECCTL1_CAPPOL_MASK;
                tmp_16_reg |= ((0x01u << 0x02u) /* CAP2POL set to falling edge. */
                               | (0x01u << 0x06u) /* CAP4POL set to falling edge. */
                );
                break;
            }
            default:
            {
                tmp_16_reg = 0x0000u;
                break;
            }
        }

        REG_WRITE_16(ecap_base_addr + ECAP_ECCTL1_OFFSET, tmp_16_reg);
    }
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
/* local function definitions (static). */
/*------------------------------------------------------------------------------------------------*/

/**
 * @addtogroup CANTP_C_LFDEF
 * @{
 */

static Std_ReturnType Icu_GetRtChannel(Icu_ChannelType channel, Icu_ChannelRtType **pChannel)
{
    Std_ReturnType result = E_NOT_OK;
    Icu_ChannelRtType *p_channel_rt = NULL_PTR;
    uint32_least idx;

    for (idx = 0x00u; idx < ICU_ECAP_CHANNEL_COUNT; idx++)
    {
        if (Icu_Rt[idx].channel_id_ext == channel)
        {
            p_channel_rt = &Icu_Rt[idx];
            result = E_OK;
            break;
        }
    }

    *pChannel = p_channel_rt;

    return result;
}

/** @} */

/*------------------------------------------------------------------------------------------------*/
/* global scheduled function definitions. */
/*------------------------------------------------------------------------------------------------*/

/**
 * @addtogroup ICU_C_GSFDEF
 * @{
 */

/** @} */

/*------------------------------------------------------------------------------------------------*/
/* global callback function definitions. */
/*------------------------------------------------------------------------------------------------*/

/**
 * @addtogroup ICU_C_GCFDEF
 * @{
 */

/** @} */

#ifdef __cplusplus
}

#endif /* ifdef __cplusplus */
