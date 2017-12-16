//11665 - World war   
#include<stdio.h>
#include<string.h>
#include<stdbool.h>

/*
Input
The first line of the input contains four things: 

1. The rows of the map (0 < rows < 100)

2. The columns of the map (0 < cols < 100)

3. The total length of instructions (0 < instructions's length < 100)

4. The initial tank's direction(N, S, E, W)

The second line is the content of instructions.

For the next lines, they illustrate the map.

Output
The number of military informations you get. (printf "\n" in the end)

Sample Input
6 8 10 N
JFFRJFFJRJ
########
#=^$^==#
#=xox==#
#$OOO$$#
#=OOO==#
########

Sample Output
2
*/

#define EAST 0
#define SOUTH 1
#define WEST 2
#define NORTH 3

char map[100][100];
char actions[100]={};
int coin_amount = 0;

// tank's initial direction
char init_dir;
// tank's direction now
int dir_now;
// tank's center x and y
int center_x, center_y;

void decide_initial_direction()
{
    /// Decide tank's initial direction
    /// Using init_dir
    /// To determine dir_now

    // 
    // XOX
    // OCO
    // XOX
    //
    
    if (init_dir == 'N') {
        dir_now = NORTH;
        //printf("DEBUG: init_dir = N, dir_now = NORTH\n");
    }
    else if (init_dir == 'E') {
        dir_now = EAST;
        //printf("DEBUG: init_dir = E, dir_now = EAST\n");
    }
    else if (init_dir == 'S') {
        dir_now = SOUTH;
        //printf("DEBUG: init_dir = S, dir_now = SOUTH\n");
    }
    else if (init_dir == 'W') {
        dir_now = WEST;
        //printf("DEBUG: init_dir = W, dir_now = WEST\n");
    }
}

bool check_if_hit_wall_if_move_forward(int steps) {
    if (dir_now == NORTH) {
        for (int i=1; i<=steps; i++) {
            //printf("DEBUG: dir_now == NORTH, checking map[%d][%d]\n", center_x-1-i, center_y-1);
            //printf("DEBUG: dir_now == NORTH, checking map[%d][%d]\n", center_x-1-i, center_y);
            //printf("DEBUG: dir_now == NORTH, checking map[%d][%d]\n", center_x-1-i, center_y+1);
            if (map[center_x-1-i][center_y-1] == '#' || map[center_x-1-i][center_y] == '#' || map[center_x-1-i][center_y+1] == '#') {
                //printf("DEBUG: dir_now == NORTH, hit wall\n");
                return true;
            }
        }
    }
    else if (dir_now == EAST) {
        for (int i=1; i<=steps; i++) {
            if (map[center_x-1][center_y+1+i] == '#' || map[center_x][center_y+1+i] == '#' || map[center_x+1][center_y+1+i] == '#') {
                //printf("DEBUG: dir_now == EAST, hit wall\n");
                return true;
            }
        }
    }
    else if (dir_now == SOUTH) {
        for (int i=1; i<=steps; i++) {
            if (map[center_x+1+i][center_y-1] == '#' || map[center_x+1+i][center_y] == '#' || map[center_x+1+i][center_y+1] == '#') {
                //printf("DEBUG: dir_now == SOUTH, hit wall\n");
                return true;
            }
        }
    }
    else if (dir_now == WEST) {
        for (int i=1; i<=steps; i++) {
            if (map[center_x-1][center_y-1-i] == '#' || map[center_x][center_y-1-i] == '#' || map[center_x+1][center_y-1-i] == '#') {
                //printf("DEBUG: dir_now == WEST, hit wall\n");
                return true;
            }
        }
    }

    //printf("DEBUG: dir_now = %d, no wall in front, safe to move\n", dir_now);
    return false;
}

bool check_if_hit_hill_if_move_forward(int steps) {
    if (dir_now == NORTH) {
        for (int i=1; i<=steps; i++) {
            if (map[center_x-1-i][center_y-1] == '^' || map[center_x-1-i][center_y] == '^' || map[center_x-1-i][center_y+1] == '^') {
                //printf("DEBUG: dir_now == NORTH, hit hill\n");
                return true;
            }
        }
    }
    else if (dir_now == EAST) {
        for (int i=1; i<=steps; i++) {
            if (map[center_x-1][center_y+1+i] == '^' || map[center_x][center_y+1+i] == '^' || map[center_x+1][center_y+1+i] == '^') {
                //printf("DEBUG: dir_now == EAST, hit hill\n");
                return true;
            }
        }
    }
    else if (dir_now == SOUTH) {
        for (int i=1; i<=steps; i++) {
            if (map[center_x+1+i][center_y-1] == '^' || map[center_x+1+i][center_y] == '^' || map[center_x+1+i][center_y+1] == '^') {
                //printf("DEBUG: dir_now == SOUTH, hit hill\n");
                return true;
            }
        }
    }
    else if (dir_now == WEST) {
        for (int i=1; i<=steps; i++) {
            if (map[center_x-1][center_y-1-i] == '^' || map[center_x][center_y-1-i] == '^' || map[center_x+1][center_y-1-i] == '^') {
                //printf("DEBUG: dir_now == WEST, hit hill\n");
                return true;
            }
        }
    }

    //printf("DEBUG: dir_now = %d, no hill in front, safe to move\n", dir_now);
    return false;
}

void move(int steps) {
    if (dir_now == NORTH) {
        center_x -= steps;

        /*
        // Update map
        // ...
        // ...
        */
    }
    else if (dir_now == EAST) {
        center_y += steps;

        /*
        // Update map
        // ...
        // ...
        */

    }
    else if (dir_now == SOUTH) {
        center_x += steps;

        /*
        // Update map
        // ...
        // ...
        */
    }
    else if (dir_now == WEST) {
        center_y -= steps;

        /*
        // Update map
        // ...
        // ...
        */
    }
}

void take_two_steps()
{
    if (check_if_hit_wall_if_move_forward(2)) {
        // Do nothing
        //printf("DEBUG: will not move 2 steps\n");
    }
    else if (check_if_hit_hill_if_move_forward(2)) {
        // Do nothing
        //printf("DEBUG: will not move 2 steps\n");
    }
    else {
        move(2);
        //printf("DEBUG: moved 2 steps\n");
    }
}

void take_a_step()
{
    if (check_if_hit_wall_if_move_forward(1)) {
        // Do nothing
        //printf("DEBUG: will not move 1 step\n");
    }
    else if (check_if_hit_hill_if_move_forward(1)) {
        // Do nothing
        //printf("DEBUG: will not move 1 step\n");
    }
    else {
        move(1);
        //printf("DEBUG: moved 1 step\n");
    }
}

void pick_the_coins()
{
    int j, k;
    for (j = center_x - 1; j <= center_x + 1; j++){
        for (k = center_y - 1; k <= center_y + 1; k++){
            /// determine whether there are coins under the tank
            if (map[j][k] == '$') {
                //printf("DEBUG: got $ at map[%d][%d]\n", j, k);
                coin_amount++;
                // Update map
                map[j][k] = '=';
            }
        }
    }
}

void turn_right()
{
    /// Change direction depending on dir_now

    //
    // XOX    OOX    OOO    XOO    XOX
    // OOO -> OOO -> OOO -> OOO -> OOO
    // OOO    OOX    XOX    XOO    OOO
    //

    if (dir_now == NORTH) {
        // Change direction from NORTH to EAST
        dir_now = EAST;

        /*
        // Update map
        map[center_x-1][center_y+1] = 'X';
        map[center_x][center_y+1]   = 'O';
        map[center_x+1][center_y+1] = 'X';

        map[center_x-1][center_y-1] = 'O';
        map[center_x-1][center_y]   = 'O';
        map[center_x-1][center_y+1] = 'O';
        */
    }
    else if (dir_now == EAST) {
        // Change direction from EAST to SOUTH
        dir_now = SOUTH;

        /*
        // Update map
        map[center_x+1][center_y-1] = 'X';
        map[center_x+1][center_y]   = 'O';
        map[center_x+1][center_y+1] = 'X';

        map[center_x-1][center_y+1] = 'O';
        map[center_x][center_y+1]   = 'O';
        map[center_x+1][center_y+1] = 'O';
        */
    }
    else if (dir_now == SOUTH) {
        // Change direction from SOUTH to WEST
        dir_now = WEST;

        /*
        // Update map
        map[center_x-1][center_y-1] = 'X';
        map[center_x][center_y-1]   = 'O';
        map[center_x+1][center_y-1] = 'X';

        map[center_x+1][center_y-1] = 'O';
        map[center_x+1][center_y]   = 'O';
        map[center_x+1][center_y+1] = 'O';
        */
    }
    else if (dir_now == WEST) {
        // Change direction from WEST to NORTH
        dir_now = NORTH;

        /*
        // Update map
        map[center_x-1][center_y-1] = 'X';
        map[center_x-1][center_y]   = 'O';
        map[center_x-1][center_y+1] = 'X';

        map[center_x-1][center_y-1] = 'O';
        map[center_x][center_y-1]   = 'O';
        map[center_x+1][center_y-1] = 'O';
        */
    }
}

 

void turn_left()
{
    /// Change direction depending on dir_now

    //
    // XOX    OOX    OOO    XOO    XOX
    // OOO <- OOO <- OOO <- OOO <- OOO
    // OOO    OOX    XOX    XOO    OOO
    //

    if (dir_now == NORTH) {
        // Change direction from NORTH to WEST
        dir_now = WEST;

        /*
        // Update map
        map[center_x-1][center_y-1] = 'X';
        map[center_x][center_y-1]   = 'O';
        map[center_x+1][center_y-1] = 'X';

        map[center_x-1][center_y-1] = 'O';
        map[center_x-1][center_y]   = 'O';
        map[center_x-1][center_y+1] = 'O';
        */
    }
    else if (dir_now == EAST) {
        // Change direction from EAST to NORTH
        dir_now = NORTH;

        /*
        // Update map
        map[center_x-1][center_y-1] = 'X';
        map[center_x-1][center_y]   = 'O';
        map[center_x-1][center_y+1] = 'X';

        map[center_x-1][center_y+1] = 'O';
        map[center_x][center_y+1]   = 'O';
        map[center_x+1][center_y+1] = 'O';
        */
    }
    else if (dir_now == SOUTH) {
        // Change direction from SOUTH to EAST
        dir_now = EAST;

        /*
        // Update map
        map[center_x-1][center_y+1] = 'X';
        map[center_x][center_y+1]   = 'O';
        map[center_x+1][center_y+1] = 'X';

        map[center_x+1][center_y-1] = 'O';
        map[center_x+1][center_y]   = 'O';
        map[center_x+1][center_y+1] = 'O';
        */
    }
    else if (dir_now == WEST) {
        // Change direction from WEST to SOUTH
        dir_now = SOUTH;

        /*
        // Update map
        map[center_x+1][center_y-1] = 'X';
        map[center_x+1][center_y]   = 'O';
        map[center_x+1][center_y+1] = 'X';

        map[center_x-1][center_y-1] = 'O';
        map[center_x][center_y-1]   = 'O';
        map[center_x+1][center_y-1] = 'O';
        */
    }
}

int main()
{
    int i, j, k, rows, cols;
    int actions_number;
    int component = 0;

    /// Raed problem's input
    scanf("%d %d %d %c", &rows, &cols, &actions_number, &init_dir);
    while (getchar() != '\n');
    for (i = 0; i < actions_number; i++){
        scanf("%c", &actions[i]);
    }

    /// Read map
    for (i = 1; i <= rows; i++){
        while (getchar() != '\n');
        for (j = 1; j <= cols; j++){
            scanf("%c", &map[i][j]);
            /// Find tank's center x and y
            if (((map[i][j]) == 'x') || ((map[i][j]) == 'o') || ((map[i][j]) == 'O')){
                component++;
                if (component == 5){
                    center_x = i;
                    center_y = j;
                }
            }
        }
    }

    decide_initial_direction();

    for (i = 0; i < actions_number; i++){
        if (actions[i] == 'F'){
            //printf("DEBUG: action F\n");
            take_a_step();
            pick_the_coins();
        }
        else if (actions[i] == 'J'){
           /* Implement the instruction "J" here */
            //printf("DEBUG: action J\n");
            take_two_steps();
            pick_the_coins();
       }         
        else{
            if (actions[i] == 'R'){
                //printf("DEBUG: action R\n");
                turn_right();
            }
            if (actions[i] == 'L'){
                //printf("DEBUG: action L\n");
                turn_left();
            }
        }
    }

    printf("%d\n", coin_amount);

    return 0;
}