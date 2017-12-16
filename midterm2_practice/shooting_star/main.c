/*
You want to stimulate shooting route in a room. You know the boundery of room, 
start point of a shooting object, and the direction of shooting. 
When the object hitting the boundary, it would reflect with 45 degree. 
Your mission is to show the route of the shooting object.
You are asked to use 2-D array to solve this problem


Input
The first line has three numbers, C, F and H, which respectively means the length of 
the ceiling, the length of the floor, and the height between the ceilings and floors.

The second line has a number S, which means the start point of shooting object. 
It's noted that the location below the ceiling is 1, 
and the location below that is 2, and so on.
1 ≤ C, F ≤ 20
2 ≤ H ≤ 20
1 ≤ S ≤ H

The third line has a character 'u' or 'd'. 
It  corresponds to the initial direction of shooting.
u: upper-right in 45 degree
d: lower-right in 45 degree
There are only one case for each testcase

Output
Draw the map and the route of the shooting object.
The route of shooting object is marked as '*', 
which appears until the object is out of boundaries.

You need to use a (H+2)*(max{C, F, the horizontal length of route of shooting}) 
array to print out the result
(for example, 範例一 print 5*10 array)
Remember there is '\n' in the end.
*/
/*
Sample Input
範例一:
5 7 3
1
d

範例二:
8 7 4
4
u

Sample Output
範例一:
-----    *
*   *   * 
 * * * *  
  *   *   
------- 

範例二:
--------  *
   *     * 
  * *   *  
 *   * *   
*     *    
-------    
*/

#include <stdio.h>
int c, f, h, l;
int s;
char u_or_d;
char map[20][20];

int maxCFL(){
  if(c >= f){
    if(c >= l){
      return c;
    }
    else{
      return l;
    }
  }
  else{
    if(f >= l){
      return f;
    }
    else{
      return l;
    }
  }
}

void init(){
  for (int i=0; i<h+2; i++) for(int j=0; j<20; j++) map[i][j] = ' ';
  for(int j=0; j<c; j++) map[0][j] = '-';
  for(int j=0; j<f; j++) map[h+1][j] = '-';
  map[s][0] = '*';

}

void draw(){
  int max = maxCFL();
  for(int i=0; i<h+2;i++){
    for(int j=0;j<max;j++){
      printf("%c", map[i][j]);
    }
    printf("\n");
  }
}

void down(int i, int j);
void up(int i, int j)
{
  if (i > 1) {
    //changing i, j to correct position
    i--;
    j++;
    map[i][j] = '*';
    up(i, j);
  }
  else if(j >= c) {
    map[i-1][j+1] = '*';
    l = j+2;
  }
  else
    down(i, j);
}

void down(int i, int j)
{
  if (i < h) {
    //changing i, j to correct position
    i++;
    j++;
    map[i][j] = '*';
    down(i, j);
  }
  else if(j >= f) {
    map[i+1][j+1] = '*';
    l = j+2;
  }
  else
    up(i, j);
}

int main(){

  scanf(" %d %d %d", &c, &f, &h);
  scanf(" %d", &s);
  scanf(" %c", &u_or_d);

  init();
  // draw();
  if (u_or_d == 'd') {
    down(s, 0);
  }
  else if(u_or_d == 'u') {
    up(s, 0);
  }
  
  draw();
  //boundary case 1 : ceiling

  //boundary case 2 : floor

  //boundary case 3 : end of shooting star
  return 0;
}
