/*
eccioa loves playing minecraft, but he is on fire now!
He looks at the mini map, and he wants to found out if there is any water nearby to put out the fire on him. 
Unfortunately, there is also some lava nearby, and he can't pass through it 
(he forgot to bring the potion of fire resistance). 
If he can't reach any of the water on the map, he will be burned to death miserably.

eccioa now gives you the mini map sized m ✕ n consists of four symbols:

'e' stands for the current position of eccioa.

'.' stands for the regular road he can pass through.

'^' stands for lava he cannot pass through.

'~' stands for water. (There may be multiple of them)

Can you tell him whether he can stay alive or not? 

Input
The first line contains two integer m, n, representing the size of the map eccioa gives to you.
The next m lines contain n characters, either 'e', '.', '^', '~', 
representing the status of position aij.
1 ≤ m, n ≤ 1000
*/

/*
Output
If eccioa can stay alive, please print "Alive!", otherwise please print "Dead!".

Sample Input
3 4
~~..
^^^.
e...

Sample Output 
Alive!
*/

//If he can't reach any of the water on the map, he will be burned to death miserably.
int row, col;
char map[1001][1001];
int map_visited[1001][1001] = {0};
int e_position_y, e_position_x;
int ans;


#include <stdio.h>
void readmap(){
  scanf("%d %d", &row, &col);
  int i, j;
  for(i = 0; i < row; i++){
    for(j = 0; j < col; j++){
      scanf(" %c", &map[i][j]);
    }
  }
}

void draw(){
  int i, j;
  for(i = 0; i < row; i++){
    for(j = 0; j < col; j++){
      printf("%c", map[i][j]);
    }
    printf("\n");
  }
}

int find_water(int x, int y)
{
  //check the (x, y) within the boundary and unvisited
  if (x < row && y < col && x >= 0 && y >= 0 && map_visited[x][y] == 0) {
    if (map[x][y] == '~') return 1;
    else if (map[x][y] == '^') return 0;
    else {
      map_visited[x][y] = 1;
      return find_water(x+1, y) || find_water(x-1, y) || find_water(x, y+1) || find_water(x, y-1);
    }
  }
  else {
    return 0;
  }
}
/*
// f(e, ~) = f(up) + f(down) + f(left) + f(right)
int recursive(int e_position_x, int e_position_y, char come_from_direction){
  //printf("DEBUG: x = %d, y = %d : ", e_position_x, e_position_y);


  if(e_position_x == -1 || e_position_y == -1){
    //printf("-1 return 0\n");
    return 0;
  }

  if(e_position_x == col || e_position_y == row){
    //printf("return 0\n");
    return 0;
  }

  if(map[e_position_y][e_position_x] == '.'){
    //printf(". try on\n");

    if (come_from_direction == 'e') {
      return  recursive(e_position_x, e_position_y-1, 's') + 
          recursive(e_position_x, e_position_y+1, 'n') + 
          recursive(e_position_x-1, e_position_y, 'e');
    }
    if (come_from_direction == 's') {
      return  recursive(e_position_x, e_position_y-1, 's') + 
          recursive(e_position_x-1, e_position_y, 'e') + 
          recursive(e_position_x+1, e_position_y, 'w');
    }
    if (come_from_direction == 'n') {
      return  recursive(e_position_x, e_position_y+1, 'n') + 
          recursive(e_position_x-1, e_position_y, 'e') + 
          recursive(e_position_x+1, e_position_y, 'w');
    }
    if (come_from_direction == 'w') {
      return  recursive(e_position_x, e_position_y-1, 's') + 
          recursive(e_position_x, e_position_y+1, 'n') + 
          recursive(e_position_x+1, e_position_y, 'w');
    }

  }

  if(map[e_position_y][e_position_x] == '~'){
    //printf("~ return 1\n");
    return 1;
  }

  if(map[e_position_y][e_position_x] == '^'){
    //printf("^ return 0\n");
    return 0;
  }

  if(map[e_position_y][e_position_x] == 'e'){
    //printf("e try on\n");
    return  recursive(e_position_x, e_position_y-1, 's') + 
          recursive(e_position_x, e_position_y+1, 'n') + 
          recursive(e_position_x-1, e_position_y, 'e') + 
          recursive(e_position_x+1, e_position_y, 'w');
  }

}
*/

int main(){
  readmap();
  //draw();
  // target is ~
  // find is it has a path to reach ~
  // f(e, ~) = f(up) + f(down) + f(left) + f(right)

  // find e
  for(int i = 0; i < row; i++){
      for(int j = 0; j < col; j++){
        if(map[i][j] == 'e'){
          e_position_x = i;
          e_position_y = j;
          //printf("i=%d, j=%d\n", i, j);
        }
      }
  }
  
  ans = find_water(e_position_x, e_position_y);
  
  if(ans > 0) {
    printf("Alive!\n");
  }
  else {
    printf("Dead!\n");
  }

  return 0;
}

