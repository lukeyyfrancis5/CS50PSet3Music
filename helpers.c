// Helper functions for music
#include <math.h>
#include <cs50.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "helpers.h"


// Converts a fraction formatted as X/Y to eighths
int duration(string fraction)
{


    int numr = atoi(&fraction[0]);
    int den = atoi(&fraction[2]);

    int frac = (8 / den) * numr;
    return frac;

}

// Calculates frequency (in Hz) of a note
int frequency(string note)
{
    int letter = note[0];
    int noteLen = strlen(note);
    float letterHz = 0.00;

    int octave;
    float octaveHz;

    int accidental = 0;
    float accidentalHz = 0.0;
    float accidentalHzTtl;

    // Takes user input and determines whether the note has an accidental
    if(noteLen == 3)
    {
        octave = note[2];
        accidental = note[1];
    }
    else
    {
       octave = note[1];
    }

    // SS gets freq of letters A - G
    switch (letter)
    {
        case 'A' :
            letterHz = 440;
            break;

        case 'B' :
            letterHz = 440. * pow(2, 2. / 12);
            break;

        case 'C' :
            letterHz = 440. / pow(2.00, 9.00 / 12);
            break;

        case 'D' :
            letterHz = 440. / pow(2, 7. / 12);
            break;

        case 'E' :
            letterHz = 440. / pow(2, 5. / 12);
            break;

        case 'F' :
            letterHz = 440. / pow(2, 4. / 12);
            break;

        case 'G' :
            letterHz = 440. / pow(2, 2. / 12);
            break;
    }

    // Accidental Flat
    if(accidental == 'b')
    {
         accidentalHz = letterHz / pow(2, 1. / 12);
         accidentalHzTtl = accidentalHz;

    }
    // Accidental #
    else if(accidental == '#')
    {
        accidentalHz = letterHz * pow(2, 1. / 12);
        accidentalHzTtl = accidentalHz;
    }

    else
    {
        accidentalHzTtl = letterHz;
    }


    // SS gets feq for octaves
    switch (octave)
    {
        case '4' :
        octaveHz = accidentalHzTtl;
        break;

        case '3' :
        octaveHz = accidentalHzTtl / 2.;
        break;

        case '2' :
        octaveHz = accidentalHzTtl / 4.;
        break;

        case '1' :
        octaveHz = accidentalHzTtl / 8.;
        break;

        case '5' :
        octaveHz = accidentalHzTtl * 2.;
        break;

        case '6' :
        octaveHz = accidentalHzTtl * 4.;
        break;

        case '7' :
        octaveHz = accidentalHzTtl * 8.;
        break;

        case '8' :
        octaveHz = accidentalHzTtl * 16.;
    }

    int f = round(octaveHz);

    return f;

}

// Determines whether a string represents a rest
bool is_rest(string s)
{
    string space = "";
    if(strcmp(s, space) == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
//comment
