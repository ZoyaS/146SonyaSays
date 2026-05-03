/*
 * Copyright (c) 2021, Texas Instruments Incorporated
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * *  Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * *  Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * *  Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include "ti_msp_dl_config.h"
#include "pattern_verification.h"
#include <stdio.h>

PatternVerifier verifier;

uint8_t pattern[MAX_PATTERN_LENGTH];

PatternVerifier_init(&verifier);

int main(void)
{
    SYSCFG_DL_init();

    uint8_t buttonPressed;  // comes from your input module

    // PATTERN VERIFCATION

        PatternResult result;

        result = PatternVerifier_checkInput(&verifier, buttonPressed, pattern);

        if (result == PATTERN_STILL_CORRECT)
        {
            // keep waiting for next button press
        }
        else if (result == PATTERN_ROUND_COMPLETE)
        {
            PatternVerifier_nextLevel(&verifier);
            // move to SUCCESS state → next round
        }
        else if (result == PATTERN_WRONG_INPUT)
        {
            PatternVerifier_resetToBase(&verifier);
            // move to ERROR state → reset game
        }

    // PATTERN VERIFCATION
    
    while (1) {
    }
}
