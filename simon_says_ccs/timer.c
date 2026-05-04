//timer module
/*
 Configures TIMG12 as a free-running 32-bit timer using BUSCLK. It is used to create
 accurate time delays (ms) without relying on delay_cycles()

 Assuming that BUSCLK = 32 MHz -> timer increments every 1 / 32,000,000 sec
*/


#include "ti_msp_dl_config.h"
#include "timer.h"
#include <stdint.h>

//Timer frequency (must match BUSCLK from SysConfig)
#define TIMER_FREQ_HZ 32000000UL


void Timer_init(void) //initializes TIMG12 as a free-running 32-bit timer
{
    DL_Timer_enablePower(TIMG12); 

    //configures timer clock source
    DL_Timer_ClockConfig config;
    config.clockSel = DL_TIMER_CLOCK_BUSCLK;     // Use system bus clock
    config.divideRatio = DL_TIMER_CLOCK_DIVIDE_1; // No division
    config.prescale = 0;                         // No prescaling
    DL_Timer_setClockConfig(TIMG12, &config);

    //configures timer mode
    DL_Timer_TimerConfig timerConfig;
    timerConfig.timerMode = DL_TIMER_TIMER_MODE_PERIODIC_UP; // count up continuously
    timerConfig.period = 0xFFFFFFFF;                         // max 32 bit value
    timerConfig.startTimer = DL_TIMER_START;                 // start immediately
    timerConfig.genIntermInt = DL_TIMER_INTERM_INT_DISABLED; // no interrupts
    timerConfig.counterVal = 0;                              // start from 0

    DL_Timer_initTimerMode(TIMG12, &timerConfig);
}



uint32_t Timer_getTicks(void) //returns the current timer count value
{
    return DL_Timer_getTimerCount(TIMG12);
}

void Timer_delayMs(uint32_t ms) //creates a blocking delay for a specified number of milliseconds using the free-running timer
{
    //record starting time
    uint32_t start = Timer_getTicks();

    //converts ms to clock ticks
    uint32_t ticksNeeded = (TIMER_FREQ_HZ / 1000) * ms;

    //wait until desired time has elapsed
    while ((Timer_getTicks() - start) < ticksNeeded);
}