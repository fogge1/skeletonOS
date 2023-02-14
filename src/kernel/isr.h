#ifndef _ISR_H
#define _ISR_H

#include "stdint.h"

void isrs_install(void);
void exception_handler();

#endif
