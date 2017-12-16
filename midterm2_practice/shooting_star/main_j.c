#include <stdio.h>
#include <stdbool.h>

/*
Input
The first line has three numbers, C, F and H, which respectively means the length of the ceiling, the length of the floor, and the height between the ceilings and floors.

The second line has a number S, which means the start point of shooting object. It's noted that the location below the ceiling is 1, and the location below that is 2, and so on.

1 ≤ C, F ≤ 20
2 ≤ H ≤ 20
1 ≤ S ≤ H
The third line has a character 'u' or 'd'. It  corresponds to the initial direction of shooting.

u: upper-right in 45 degree
d: lower-right in 45 degree
There are only one case for each testcase

Output
Draw the map and the route of the shooting object.
The route of shooting object is marked as '*', which appears until the object is out of boundaries.

You need to use a (H+2)*(max{C, F, the horizontal length of route of shooting}) array to print out the result

(for example, 範例一 print 5*10 array)

Remember there is '\n' in the end.

Sample Input 1
5 7 3
1
d

Sample Output 1
-----    *
*   *   * 
 * * * *  
  *   *   
------- 

Sample Input 2
8 7 4
4
u

Sample Output 2
--------  *
   *     * 
  * *   *  
 *   * *   
*     *    
-------
*/

char map[22][40];
int C, F, H;
int S;
int L = 40;
char D;

void display() {
    for (int i=0; i<H+2; i++) {
        for (int j=0; j<L; j++) {
            printf("%c", map[i][j]);
        }
        printf("\n");
    }
}

bool out_of_bound(int y, int x) {
    //printf("DEBUG: map[%d][%d] out_of_bound? %d\n", y, x, (y == 0 && x>=C) || (y == (H+1) && x>=F));
    return (y == 0 && x>=C) || (y == (H+1) && x>=F);
}

bool returned(int y, int x, char d) {
    //printf("DEBUG: map[%d][%d] returned? %d\n", y, x, (d == 'u' && y == 1 && x<C) || (d == 'd' && y == H && x<F));
    return (d == 'u' && y == 1 && x<C) || (d == 'd' && y == H && x<F);
}

bool the_ceil(int y, int x) {
    //printf("DEBUG: map[%d][%d] the_ceil? %d\n", y, x, (y == 0 && x<C));
    return (y == 0 && x<C);
}

bool the_floor(int y, int x) {
    //printf("DEBUG: map[%d][%d] the_floor? %d\n", y, x, (y == (H+1) && x<F));
    return (y == (H+1) && x<F);
} 

void paint_shoot(int origin_y, int origin_x, char d) {
    //printf("DEBUG: paint_shoot(%d, %d, %c)\n", origin_y, origin_x, d);
    int y = origin_y;
    int x = origin_x;
    char next_d;
    bool stopped = false;

    map[y][x] = '*';
    if ( d == 'u' ) {
        //printf("DEBUG: shoot up\n");
        while (true) {
            if (returned(y, x, d)) {
                break;
            }
            else {
                y--;
                x++;
                if (!the_ceil(y, x) && !out_of_bound(y, x)) map[y][x] = '*';
                else {
                    stopped = out_of_bound(y, x);
                    y++;
                    x--;
                    break;
                }
            }
        }
        next_d = 'd';
    }
    else { // i.e., (d == 'd')
        //printf("DEBUG: shoot down\n");
        while (true) {
            if (returned(y, x, d)) {
                break;
            }
            else {
                y++;
                x++;
                if (!the_floor(y, x) && !out_of_bound(y, x)) map[y][x] = '*';
                else {
                    stopped = out_of_bound(y, x);
                    y--;
                    x--;
                    break;
                }
            }
        }
        next_d = 'u';
    }

    //printf("DEBUG: next paint_shoot(%d, %d, %c)\n", y, x, next_d);
    if (!stopped) paint_shoot(y, x, next_d);
    else {
        //printf("DEBUG: stopped y=%d x=%d d=%c\n", y, x, d);

        if (d=='u') {
            map[y-1][x+1] = '*';
        }
        else { // i.e., (d == 'd')
            map[y+1][x+1] = '*';
        }
        L = x+2;
        //printf("DEBUG: L=%d\n", L);
    }
}

void paint_map() {
    for (int i=0; i<H+2; i++) for(int j=0; j<L; j++) map[i][j] = ' ';
    for (int i=0; i<C; i++) map[0][i] = '-';
    for (int i=0; i<F; i++) map[H+1][i] = '-';
    map[S][0] = '*';
}

void load() {
    scanf(" %d %d %d", &C, &F, &H);
    scanf(" %d", &S);
    scanf(" %c", &D);
}

int main() {

    /*
    ceil  starts from (0, 0)    ends to (0, C-1);
    shoot starts from (S, 0)    ends to (?, L-1);
    floor starts from (H+1, 0)  ends to (H+1, F-1);
    */

    load();
    paint_map();
    paint_shoot(S, 0, D);
    display();
}