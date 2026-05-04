#include "pattern_verification.h"

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
    // Safety check (prevents out-of-bounds access)
    if (verifier->currentIndex >= verifier->patternLength)
    {
        return PATTERN_ROUND_COMPLETE;
    }

    uint8_t expectedInput = pattern[verifier->currentIndex];

    // Check if user input matches expected pattern
    if (userInput != expectedInput)
    {
        return PATTERN_WRONG_INPUT;
    }

    // Move to next position in sequence
    verifier->currentIndex++;

    // Check if user completed full sequence
    if (verifier->currentIndex >= verifier->patternLength)
    {
        return PATTERN_ROUND_COMPLETE;
    }

    // Otherwise still correct, keep going
    return PATTERN_STILL_CORRECT;
}

void PatternVerifier_nextLevel(PatternVerifier *verifier)
{
    // Reset index for next round
    verifier->currentIndex = 0;

    // Increase difficulty (longer sequence)
    if (verifier->patternLength < MAX_PATTERN_LENGTH)
    {
        verifier->patternLength++;
        verifier->level++;
    }
}

void PatternVerifier_resetToBase(PatternVerifier *verifier)
{
    // Reset everything back to starting level
    verifier->currentIndex = 0;
    verifier->patternLength = BASE_PATTERN_LENGTH;
    verifier->level = 1;
}