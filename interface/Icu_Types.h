/**
 * @file Icu_Types.h
 * @author Guillaume Sottas
 * @date 15/01/2018
 */

#ifndef ICU_TYPES_H
#define ICU_TYPES_H

#ifdef __cplusplus

extern "C" {

#endif /* ifdef __cplusplus */

/*------------------------------------------------------------------------------------------------*/
/* included files (#include).                                                                     */
/*------------------------------------------------------------------------------------------------*/

/**
 * @addtogroup ICU_TYPES_H
 * @{
 */

#include "Std_Types.h"

/** @} */

/*------------------------------------------------------------------------------------------------*/
/* global data type definitions (typedef, struct).                                                */
/*------------------------------------------------------------------------------------------------*/

/**
 * @addtogroup ICU_H_GTDEF
 * @{
 */

/**
 * @brief Numeric identifier of an ICU channel
 */
typedef uint32 Icu_ChannelType;

/**
 * @brief Width of the buffer for timestamp ticks and measured elapsed timeticks
 */
typedef uint32 Icu_ValueType;

/**
 * @brief Type, to abstract the return value of the service Icu_GetTimestampIndex(). Since circular
 * buffer handling is supported and Icu_GetTimestampIndex can return '0' as a legally true value
 * (not as an error according to ICU107 and ICU135), Icu_IndexType may be implemented to have values
 * 1..xyz
 */
typedef uint32 Icu_IndexType;

/**
 * @brief Type, to abstract the return value of the service Icu_GetEdgeNumbers()
 */
typedef uint32 Icu_EdgeNumberType;

/**
 * @brief Allow enabling / disabling of all interrupts which are not required for the ECU wakeup
 */
typedef enum
{
    /**
     * @brief Normal operation, all used interrupts are enabled according to the notification
     * requests
     */
    ICU_MODE_NORMAL,

    /**
     * @brief Reduced power operation. In sleep mode only those notifications are available which
     * are configured as wakeup capable
     */
    ICU_MODE_SLEEP

} Icu_ModeType;

/**
 * @brief Input state of an ICU channel
 */
typedef enum
{

    /**
     * @brief An activation edge has been detected
     */
    ICU_ACTIVE,

    /**
     * @brief No activation edge has been detected since the last call of Icu_GetInputState() or
     * Icu_Init()
     */
    ICU_IDLE
} Icu_InputStateType;

/**
 * @brief Definition of the type of activation of an ICU channel
 */
typedef enum
{
    /**
     * @brief An appropriate action shall be executed when a rising edge occurs on the ICU input
     * signal
     */
    ICU_RISING_EDGE,

    /**
     * @brief An appropriate action shall be executed when a falling edge occurs on the ICU input
     * signal
     */
    ICU_FALLING_EDGE,

    /**
     * @brief An appropriate action shall be executed when either a rising or falling edge occur on
     * the ICU input signal
     */
    ICU_BOTH_EDGES
} Icu_ActivationType;

/**
 * @brief Definition of the measurement mode type
 */
typedef enum
{
    /**
     * @brief Mode for detecting edges
     */
    ICU_MODE_SIGNAL_EDGE_DETECT,

    /**
     * @brief Mode for measuring different times between various configurable edges
     */
    ICU_MODE_SIGNAL_MEASUREMENT,

    /**
     * @brief Mode for capturing timer values on configurable edges
     */
    ICU_MODE_TIMESTAMP,

    /**
     * @brief Mode for counting edges on configurable edges
     */
    ICU_MODE_EDGE_COUNTER
} Icu_MeasurementModeType;

/**
 * @brief Definition of the measurement property type
 */
typedef enum
{
    /**
     * @brief The channel is configured for reading the elapsed Signal Low Time
     */
    ICU_LOW_TIME,

    /**
     * @brief The channel is configured for reading the elapsed Signal High Time
     */
    ICU_HIGH_TIME,

    /**
     * @brief The channel is configured for reading the elapsed Signal Period Time
     */
    ICU_PERIOD_TIME,

    /**
     * @brief The channel is configured to read values which are needed for calculating the duty
     * cycle (coherent Active and Period Time)
     */
    ICU_DUTY_CYCLE
} Icu_SignalMeasurementPropertyType;

/**
 * @brief Definition of the timestamp measurement property type
 */
typedef enum
{
    /**
     * @brief The buffer will just be filled once
     */
    ICU_LINEAR_BUFFER,

    /**
     * @brief After reaching the end of the buffer, the driver restarts at the beginning of the
     * buffer
     */
    ICU_CIRCULAR_BUFFER
} Icu_TimestampBufferType;

/**
 * @brief Type which shall contain the values, needed for calculating duty cycles
 */
typedef struct
{
    /**
     * @brief This shall be the coherent active-time measured on a channel
     */
    Icu_ValueType ActiveTime;

    /**
     * @brief This shall be the coherent period-time measured on a channel
     */
    Icu_ValueType PeriodTime;
} Icu_DutyCycleType;

/* SRS_Icu_12368 */
typedef struct
{
    uint16 IcuChannelId; /* ECUC_Icu_00027 */
    Icu_ActivationType IcuDefaultStartEdge; /* ECUC_Icu_00222 */
    Icu_MeasurementModeType IcuMeasurementMode; /* ECUC_Icu_00223 */
    boolean IcuWakeupCapability; /* ECUC_Icu_00224 */
    void (*Icu_SignalNotification)(void);
    /* TODO: add support for selectable Port pin (see SRS_Icu_12368). */
} Icu_ChannelConfigType;

/**
 * @brief This type contains initialization data
 */
typedef struct
{
    const Icu_ChannelConfigType *pChannelConfig;
    const uint32 channelCount;
} Icu_ConfigType;

/** @} */

#ifdef __cplusplus
};

#endif /* ifdef __cplusplus */

#endif /* define ICU_TYPES_H */
