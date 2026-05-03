#ifndef PATTERN_VERIFICATION_H
#define PATTERN_VERIFICATION_H

#include <stdint.h>

#define BASE_PATTERN_LENGTH 4
#define MAX_PATTERN_LENGTH 25

typedef enum {
    PATTERN_STILL_CORRECT,
    PATTERN_ROUND_COMPLETE,
    PATTERN_WRONG_INPUT
} PatternResult;

typedef struct {
    uint8_t currentIndex;
    uint8_t patternLength;
    uint8_t level;
} PatternVerifier;

// Function declarations
void PatternVerifier_init(PatternVerifier *verifier);

PatternResult PatternVerifier_checkInput(
    PatternVerifier *verifier,
    uint8_t userInput,
    const uint8_t pattern[]
);

void PatternVerifier_nextLevel(PatternVerifier *verifier);

void PatternVerifier_resetToBase(PatternVerifier *verifier);

#endif