/*
 * Platform_Types.h
 *
 *  Created on:
 *      Author: Badreddine Merareb
 *
 *  Description:
 *  Standard type definitions for portable embedded development.
 */

#ifndef PLATFORM_TYPES_H_
#define PLATFORM_TYPES_H_

// Unsigned integer types
typedef unsigned char           uint8_t;
typedef unsigned short          uint16_t;
typedef unsigned int            uint32_t;
typedef unsigned long long      uint64_t;

// Signed integer types
typedef signed char             sint8_t;
typedef signed short            sint16_t;
typedef signed int              sint32_t;
typedef signed long long        sint64_t;

// Volatile unsigned types
typedef volatile uint8_t        vuint8_t;
typedef volatile uint16_t       vuint16_t;
typedef volatile uint32_t       vuint32_t;
typedef volatile uint64_t       vuint64_t;

// Volatile signed types
typedef volatile sint8_t        vsint8_t;
typedef volatile sint16_t       vsint16_t;
typedef volatile sint32_t       vsint32_t;
typedef volatile sint64_t       vsint64_t;

// Floating-point types
typedef float                   float32_t;
typedef double                  float64_t;

// Boolean type
typedef enum
{
    FALSE = 0,
    TRUE  = 1
} bool_t;


// Null pointer
#ifndef NULL
#define NULL ((void *)0)
#endif

#endif /* PLATFORM_TYPES_H_ */

