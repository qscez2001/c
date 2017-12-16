// 11657
#include <stdio.h>

#include "function.h"

/*
Input
The specific month N 
Output
Total pairs of rabbits
Sample Input
6
Sample Output
8
*/

int Rabbit(int month)
{
/*
                    *
1   2   3   4   5   6   7
2   2
                        2
                    2   2
                2   2
                        2
            2   2
                        2
                    2   2
        2   2
                        2
                    2   2
                2   2
                        2
-------------------------
1   1   2   3   5   8   13
      1+1 1+2 2+3 3+5 5+8
*/

    // Write your code here
    if ( month == 1 ) return 1;
    else if (month == 2) return 1;
    else return Rabbit(month-1) + Rabbit(month-2);

}