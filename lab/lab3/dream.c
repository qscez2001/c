//11661
#include <stdio.h>

#include "function.h"

/*
Input
first line : array size N (0<N<20)
second line: N elements in array
Output
Maximum element in array
Sample Input
5
0 2 8 5 6
Sample Output
8
*/

int maxElement(int arr[], int n)
{

    // Write your code here
    if (n == 1) return arr[0];
    else {
        if ( arr[n-1] > arr[n-2] ) arr[n-2] = arr[n-1];
        return maxElement(arr, n-1);
    }
}