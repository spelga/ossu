/**
 * helpers.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Helper functions for Problem Set 3.
 */
       
#include <cs50.h>

#include "helpers.h"
#include <stdio.h>

/**
 * Returns true if value is in array of n values, else false.
 */
bool search(int value, int values[], int n)
{
    // linear search
    /*if (n < 0)
    {
        return false;
    }
    
    for (int i = 0; i < n; i++)
    {
        if (value == values[i])
        {
            return true;
        }
    }
    return false;*/
    
    // binary search
    if (n < 0)
    {
        return false;
    }
    
    int start_index = 0;
    int end_index = n - 1;
    
    while (start_index <= end_index)
    
    {
        
        int midpoint = (start_index + end_index) / 2;
        
        if (values[midpoint] == value)
        {
            return true;
        }
        else if (values[midpoint] < value)
        {
            start_index = (midpoint + 1);
        }
        else
        {
            end_index = (midpoint - 1);
        }
    }
    return false;
}

/**
 * Sorts array of n values.
 */
void sort(int values[], int n)
{
    // TODO: implement an O(n^2) sorting algorithm
    // Use Bubble Sort
    
    bool unsorted = true;
    
    while (unsorted == true)
    {
        // iterate over the list n - 1 times
        for (int i = 0; i < n - 1; i++)
        {
            int left_value = values[i];
            int right_value = values[i + 1];
            
            if (left_value > right_value)
            {
                left_value = right_value;
                right_value = left_value;
            }
        }
        unsorted = false;
    }
    return;
}