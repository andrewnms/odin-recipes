#include <stdio.h>
#define IN 1
#define OUT 0
#define MAXH 15
#define MAXV 11

// CTRL + D for the EOF signal.
int main()
{
    int c, i, state = OUT, chcount = 0, valM = 0, len;
    int wl[MAXV];
    for (i = 0; i < MAXV; ++i)
        wl[i] = 0;
    // goes thru each character
    while ((c = getchar()) != EOF)
    {
        // checks if it's a space or newline
        if (c == ' ' || c == '\t' || c == '\n')
        {
            state = OUT;
            // checks if character check count is 1 or more
            if (chcount > 0)
                // adds the value for the index counter
                ++wl[chcount];
            // returns it back to 0 since new word
            chcount = 0;
        }
        else if (state == OUT)
        {
            // starts new word
            chcount = 1;
            state = IN;
        }
        else
            // increases count since it's STATE = IN aka still in word whilst not being a space or newline
            ++chcount;
    }
    // changes the max value of each index to increase the word count (word count check)
    for (i = 0; i < MAXV; ++i)
        if (wl[i] > valM)
            valM = wl[i];
    // Prints out the * and places in the appropriate location ex. index 4: 3words ****long
    for (i = 1; i < MAXV; ++i)
    {
        printf("%5d - %5d : ", i, wl[i]);
        if (wl[i] > 0)
        {
            if ((len = wl[i] * MAXH / MAXV) <= 0)
                len = 1;
        }
        else
            len = 0;
        // repeats on pasting in the * until len is 0 for the appropriate index in the parent loop
        while (len > 0)
        {
            putchar('*');
            --len;
        }
        putchar('\n');
    }
    return 0;
}
