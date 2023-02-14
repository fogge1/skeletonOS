#ifndef STDINT_H_
#define STDINT_H_

typedef char               int8_t;
typedef short              int16_t;
typedef int                int32_t;
typedef long long          int64_t;

typedef unsigned char      uint8_t;
typedef unsigned short     uint16_t;
typedef unsigned int       uint32_t;
typedef unsigned long long uint64_t;

#define INT8_WIDTH   (8)
#define INT16_WIDTH  (16)
#define INT32_WIDTH  (32)
#define INT64_WIDTH  (64)

#define UINT8_WIDTH  (8)
#define UINT16_WIDTH (16)
#define UINT32_WIDTH (32)
#define UINT64_WIDTH (64)

#define INT8_MAX     (127)
#define INT16_MAX    (32767)
#define INT32_MAX    (INT32_C(2147483647))
#define INT64_MAX    (INT64_C(9223372036854775807))

#define INT8_MIN     (-128)
#define INT16_MIN    (-32768)
#define INT32_MIN    (-INT32_C(2147483648))
#define INT64_MIN    (-INT64_C(9223372036854775808))

#define UINT8_MAX    (255)
#define UINT16_MAX   (65535)
#define UINT32_MAX   (UINT32_C(4294967295))
#define UINT64_MAX   (UINT64_C(18446744073709551615))

#define INT8_C(c)    c
#define INT16_C(c)   c
#define INT32_C(c)   c ## L
#define INT64_C(c)   c ## LL

#define UINT8_C(c)   c ## U
#define UINT16_C(c)  c ## U
#define UINT32_C(c)  c ## UL
#define UINT64_C(c)  c ## ULL

#endif // STDINT_H_

