#include <stdio.h>
#include <string.h>

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
    if(init_dir == 'N'){
    }
    else if(init_dir == 'E'){
        map[center_x-1][center_y-1] = 'O';
        map[center_x][center_y-1] = 'O';
        map[center_x+1][center_y+1] = 'x';
        map[center_x+1][center_y] = 'o';

    }
    else if(init_dir == 'S'){
        map[center_x-1][center_y-1] = 'O';
        map[center_x][center_y-1] = 'O';
        map[center_x+1][center_y-1] = 'O';

        map[center_x-1][center_y+1] = 'x';
        map[center_x][center_y+1] = 'o';
        map[center_x+1][center_y+1] = 'x';
    }
    else if(init_dir == 'T'){
        map[center_x+1][center_y-1] = 'O';
        map[center_x][center_y-1] = 'O';
        map[center_x-1][center_y+1] = 'x';
        map[center_x-1][center_y] = 'o';
    }
}

void take_a_step()
{
    if (dir_now == NORTH){
        /// Detect wall first
        if ( ??? ){

        }
        /// And then detect hill
        else if (( ??? )) {

        }
        /// If there is no obstacle, take a step
        else {

        }
    }
    else if (dir_now == SOUTH){

    }
    else if (dir_now == EAST){

    }
    else if (dir_now == WEST){

    }
}

void pick_the_coins()
{
    int j, k;
    for (j = center_x - 1; j <= center_x + 1; j++){
        for (k = center_y - 1; k <= center_y + 1; k++){
            /// determine whether there are coins under the tank

 

        }
    }
}

void turn_right()
{
    /// Change direction depending on dir_now
}

 

void turn_left()
{
    /// Change direction depending on dir_now
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
            take_a_step();
            pick_the_coins();
        }
        else{
            if (actions[i] == 'R'){
                turn_right();
            }
            if (actions[i] == 'L'){
                turn_left();
            }
        }
    }

    printf("%d\n", coin_amount);

    return 0;
}