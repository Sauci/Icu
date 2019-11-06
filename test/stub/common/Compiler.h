/**
 * @file Compiler.h
 * @author Guillaume Sottas
 * @date 30/07/2019
 */

#ifndef COMPILER_H
#define COMPILER_H

#ifdef __cplusplus

extern "C" {

#endif /* ifdef __cplusplus */

/* SWS_COMPILER_00057
#define INLINE inline */

/* SWS_COMPILER_00060 */
#define LOCAL_INLINE static inline

/*lint -save */
/*lint -e9026 [MISRA 2012 Directive 4.9, advisory] */

/**
 * @brief read value from 16 bit register.
 * @param address register's address
 */
#define REG_READ_16(address) \
/*lint -save */ \
/*lint -e9078 [MISRA 2012 Rule 11.4, advisory] */ \
/*lint -e923 [MISRA 2012 Rule 11.6, required] */ \
(*(volatile uint16 *)(address)) \
/*lint -restore */

/*lint -restore */

/*lint -save */
/*lint -e9026 [MISRA 2012 Directive 4.9, advisory] */

/**
 * @brief write direct value to 16 bit register, using the '=' operator.
 * @param address register's address
 * @param value value to write
 */
#define REG_WRITE_16(address, value) \
/*lint -save */ \
/*lint -e9078 [MISRA 2012 Rule 11.4, advisory] */ \
/*lint -e923 [MISRA 2012 Rule 11.6, required] */ \
(*(volatile uint16 *)(address) = value) \
/*lint -restore */

/*lint -restore */

/*lint -save */
/*lint -e9026 [MISRA 2012 Directive 4.9, advisory] */

/**
 * @brief write direct value to 32 bit register, using the '=' operator.
 * @param address register's address
 * @param value value to write
 */
#define REG_WRITE_32(address, value) \
/*lint -save */ \
/*lint -e9078 [MISRA 2012 Rule 11.4, advisory] */ \
/*lint -e923 [MISRA 2012 Rule 11.6, required] */ \
(*(volatile uint32 *)(address) = value) \
/*lint -restore */

/*lint -restore */

/*lint -save */
/*lint -e9026 [MISRA 2012 Directive 4.9, advisory] */

/**
 * @brief set bit(s) to 16 bit register, using the '|=' operator.
 * @param address register's address
 * @param value value to write
 */
#define REG_SET_16(address, value) \
/*lint -save */ \
/*lint -e9078 [MISRA 2012 Rule 11.4, advisory] */ \
/*lint -e923 [MISRA 2012 Rule 11.6, required] */ \
(*(volatile uint16 *)(address) |= value) \
/*lint -restore */

/*lint -restore */

/*lint -save */
/*lint -e9026 [MISRA 2012 Directive 4.9, advisory] */

/**
 * @brief set bit(s) to 32 bit register, using the '|=' operator.
 * @param address register's address
 * @param value value to write
 */
#define REG_SET_32(address, value) \
/*lint -save */ \
/*lint -e9078 [MISRA 2012 Rule 11.4, advisory] */ \
/*lint -e923 [MISRA 2012 Rule 11.6, required] */ \
(*(volatile uint32 *)(address) |= value) \
/*lint -restore */

/*lint -restore */

#ifdef __cplusplus
}

#endif /* ifdef __cplusplus */

#endif /* #ifndef COMPILER_H */
