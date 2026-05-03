/*
 * ============================================
 * Project: Sonya Says Memory Game
 * Platform: TI MSPM0G3507 LaunchPad
 *
 * Description:
 * This project implements a "Simon Says" style memory game using LEDs
 * for pattern display and buttons for user input. The system generates
 * a sequence of LED patterns that the user must replicate.
 *
 * Authors: Aleeza Huraira, Jasmine Kurian, Gul Nayab, Eden Reader, Zoya Shamak
 * Course: CMPE 146 Sec 01
 * Due Date: May 15, 2026
 * ============================================
 *
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
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

/*
Seqeunce Manager design:
 - Sequence is stored in a fixed-size array (memory constrained system)
 - Each LED is represented as a value from 0–3
 - Sequence grows by 1 element per round
*/

#define MAX_SEQ 25   // max sequence length


uint8_t sequence[MAX_SEQ]; //each value corresponds to one LED/button
uint8_t seq_length = 0; //tracks how many valid elements are currently in the sequence



void init_sequence() { 
    seq_length = 4;  // Round 1 starts with 4 elements

    for (int i = 0; i < seq_length; i++) {
        sequence[i] = rand() % 4;  // generate values between 0–3
    }
}


void generate_next_step() { //extends sequence by appending by 1 random LED
    if (seq_length >= MAX_SEQ) {
        // prevents writing past array bounds
        return;
    }

    sequence[seq_length] = rand() % 4;  // Generate next LED
    seq_length++;  // increase sequence size
}

void reset_sequence() { //clears sequence state when game restarts
    seq_length = 0;
}

void print_sequence() { // just for debugging Sequence Manager
    printf("Sequence: ");
    for (int i = 0; i < seq_length; i++) {
        printf("%d ", sequence[i]);
    }
    printf("\n");
}


int main(void)
{
    SYSCFG_DL_init();  /

    
    srand(1); 

    // test: initialize first pattern
    init_sequence();
    print_sequence();

    // test: simulate next round
    generate_next_step();
    print_sequence();

    while (1) {
        // (FSM will go here later)
    }
}
