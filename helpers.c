/**
 * helpers.c
 *
 * Helper functions for Problem Set 3.
 */
 
#include <cs50.h>

#include "helpers.h"

/**
 * Returns true if value is in array of n values, else false.
 */
bool search(int value, int values[], int n)
{
    // TODO: implement a searching algorithm
    int boolnum = 0;
    
    // Return false right away if n is negative.
    if (n < 1)
        return false;
        
    // Perform a linear search seeking value in values.
    for (int i = 0; i < n; i++) {
        if (values[i] == value) {
            boolnum = 1;
            break;
        }
    }
    
    if (boolnum == 1)
        return true;
    else
        return false;
}

/**
 * Sorts array of n values.
 */
void sort(int values[], int n)
{
    // TODO: implement a sorting algorithm
    //int j = values[0];
    for (int i = 0; i < n; i++) {
        int smallest_index = i;
        for (int j = i+1; j < n; j++) {
            if (values[j] < values[smallest_index])
                smallest_index = j;
        }
        // Swap the smallest element with the first element of the unsorted array.
        int temp = values[i];
        values[i] = values[smallest_index];
        values[smallest_index] = temp;
    }
    return;
    
}
