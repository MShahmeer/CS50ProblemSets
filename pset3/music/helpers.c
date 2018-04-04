// Helper functions for music

#include <cs50.h>
#include <math.h>
#include <string.h>
#include <stdio.h>

#include "helpers.h"

// Converts a fraction formatted as X/Y to eighths
int duration(string fraction)
{
    // Splitting fraction into numerator and denominator
    int x = fraction[0] - '0';
    int y = fraction[2] - '0';
    // Calculating duration relative to 1/8th of a note
    int timeLength = x * (8 / y);
    return timeLength;
}

// Calculates frequency (in Hz) of a note
int frequency(string note)
{
    // Define variable components of note
    int keyLetterDelta;
    int accidental;
    int octave;

    // Calculate value of difference in no of semitones due to change in key
    // A means no change in key
    if (note[0] == 'A')
    {
        keyLetterDelta = 0;
    }
    // B means change in no of semitones by +1
    else if (note[0] == 'B')
    {
        keyLetterDelta = 2;
    }
    // Change in no of semitones for G or F  keys maps to 72 (ASCII value of A (65) + 7, the number of letetrs) subtracted from ASCII value of key then doubled
    else if (note[0] == 'G' || note[0] == 'F')
    {
        keyLetterDelta = ((int) note[0] - 72) * 2;
    }
    else
    {
        keyLetterDelta = (((int) note[0] - 72) * 2) + 1;
    }

    // Split note input into letter of key and octave
    // If white keys
    if (strlen(note) == 2)
    {
        accidental = 0;
        octave = note[1] - '0';
    }
    // If black keys
    else
    {
        // Add one semitone if accidental is a sharp
        if (note[1] == '#')
        {
            accidental = 1;
        }
        // Subtract one semitone if accidental is a flat
        else
        {
            accidental = -1;
        }
        octave = note[2] - '0';
    }

    // Calculate number of semitones from input note to note A4 since there are 12 semitones in an octave
    int noOfSemitones = keyLetterDelta + accidental + ((octave - 4) * 12);
    // Calculate frequency using formula
    double exponent = (double) noOfSemitones / 12.0;
    int f = round(pow(2.0, exponent) * 440.0);
    return f;
}

// Determines whether a string represents a rest
bool is_rest(string s)
{
    // Empty line is ""
    if (strcmp(s, "") == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}