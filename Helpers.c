#include <cs50.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h> //atoi - converts str to int
#include <string.h>

#include "helpers.h"

// Converts a fraction formatted as X/Y to eighths
int duration(string fraction)
{
    int numr = atoi(&fraction[0]);
    int den = atoi(&fraction[2]);

    switch (den) {
        case 2 :
        return numr * 4;

        case 4 :
        return numr * 2;

        case 8 :
        return numr;

        default :
        printf("Sorry Invalid Answer !");
    }

        printf("The number of eights is i%\n", numr);
        return numr;

}
    int main(void)
    {
        int numr = duration("1/2");
        printf("i%\n", numr);
    }