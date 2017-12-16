//11691 - pC - Ponds   

/*
Frank Lin likes to go mountain climbing. 
Every time before he goes mountain climbing, 
he needs to look up the map to plan for the route. 
According to Frank’s experience, it is very important to locate the position of ponds, 
since it is usually the best place for resting. 
Now, Frank gives you a map sized m ✕ n consists of only two symbols '~' and '.', 
representing water and land, respectively. 
Frank wonders how many ponds (consecutive position of water) are there on the map.

If you can help Frank solve this problem, 
maybe he will teach you how to build a tent within five minutes.
*/

/*
The first line contains two integer m, n, 
representing the size of the map Frank gives to you.
The next m lines contain n characters, either '~' or '.', r
epresenting the status of position aij.
1 ≤ m, n ≤ 1000

Please output the number of ponds on the map.

Sample Input
2 3
~.~
~..

Sample Output
2
*/

#include <stdio.h>
#include <string.h>
char map[1000][1000];
int row, col;
int i, j;
int num = 0;

void search(int i, int j){
  if(map[i][j] == '~'){
    map[i][j] = '.';

    if(j != 0) search(i, j-1);
    if(j != col-1) search(i, j+1);
    if(i != row-1) search(i+1, j);
    if(i != 0) search(i-1, j);

  }
}

int main(){

scanf(" %d %d", &row, &col);

for ( i = 0; i < row; i++ ) {
    for ( j = 0; j < col; j++ ) {
      //printf("i=%d, j=%d\n", i, j);
      scanf(" %c", &map[i][j]);
    }
}

for ( i = 0; i < row; i++ ) {
    for ( j = 0; j < col; j++ ) {
      if(map[i][j] == '~'){
        //printf("i=%d, j=%d\n", i, j);
        num++;
        search(i, j);
      }
    }
}

printf("%d\n", num);

return 0;
}


