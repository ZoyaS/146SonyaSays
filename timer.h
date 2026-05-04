#ifndef TIMER_H
#define TIMER_H

#include <stdint.h>

void Timer_init(void);
uint32_t Timer_getTicks(void);
void Timer_delayMs(uint32_t ms);

#endif