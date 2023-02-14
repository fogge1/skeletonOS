#ifndef STRING_H_
#define STRING_H_

#include "stddef.h"
#include "stdint.h"

static inline void *memset(void *dst, uint8_t val, size_t n) {
    uint8_t *d = dst;
    while(n-- > 0) *d++ = val;
    return d;
}

static inline void *memcpy(void *__restrict dst, const void *__restrict src, size_t n) {
    uint8_t *d = dst;
    const uint8_t *s = src;
    while(n-- > 0) *d++ = *s++;
    return d;
}

/* TODO: memmove, memcmp */

#endif // STRING_H_


