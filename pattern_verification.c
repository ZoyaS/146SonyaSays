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

void PatternVerifier_init(PatternVerifier *verifier)
{
    verifier->currentIndex = 0;
    verifier->patternLength = BASE_PATTERN_LENGTH;
    verifier->level = 1;
}

PatternResult PatternVerifier_checkInput(
    PatternVerifier *verifier,
    uint8_t userInput,
    const uint8_t pattern[]
)
{
    uint8_t expectedInput = pattern[verifier->currentIndex];

    if (userInput != expectedInput)
    {
        return PATTERN_WRONG_INPUT;
    }

    verifier->currentIndex++;

    if (verifier->currentIndex >= verifier->patternLength)
    {
        return PATTERN_ROUND_COMPLETE;
    }

    return PATTERN_STILL_CORRECT;
}

void PatternVerifier_nextLevel(PatternVerifier *verifier)
{
    verifier->currentIndex = 0;

    if (verifier->patternLength < MAX_PATTERN_LENGTH)
    {
        verifier->patternLength++;
        verifier->level++;
    }
}

void PatternVerifier_resetToBase(PatternVerifier *verifier)
{
    verifier->currentIndex = 0;
    verifier->patternLength = BASE_PATTERN_LENGTH;
    verifier->level = 1;
}