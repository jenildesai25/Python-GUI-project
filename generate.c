/**
 * generate.c
 *
 * Generates pseudorandom numbers in [0,MAX), one per line.
 *
 * Usage: generate n [s]
 *
 * where n is number of pseudorandom numbers to print
 * and s is an optional seed
 */
 
#define _XOPEN_SOURCE

#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// upper limit on range of integers that can be generated
#define LIMIT 65536

int main(int argc, string argv[])
{
    // TODO: comment me
    //Here we check if user has enter any input rather than ./generate and
    //if not enter any input it just gives message and return 1
    if (argc != 2 && argc != 3)
    {
        printf("Usage: ./generate n [s]\n");
        return 1;
    }

    // TODO: comment me
    //atoi convers the 1st argument passed by user and convert 
    //it into int if it is string and then store it in a varible called n. 
    int n = atoi(argv[1]);

    // TODO: comment me
    //Here we checked that if arguments are equal to 3 then it returns the srand48 funtion
    //srand48 is the function which always uses before drand48 function because srand48
    //initialize the values.
    if (argc == 3)
    {
        srand48((long) atoi(argv[2]));
    }
    else
    {
        srand48((long) time(NULL));
    }

    // TODO: comment me
    //Here we have loop through the element and drand48 function return 
    //non negative double precision floating point values between [0.0,1.0)
    for (int i = 0; i < n; i++)
    {
        printf("%i\n", (int) (drand48() * LIMIT));
    }

    // success
    return 0;
}
