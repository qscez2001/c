#include <iostream>

using namespace std;

const int X = 8, Y = 8;
int c[X][Y];
 
void staircase_walk()
{
    // [Initial]
    for (int i=0; i<X; i++) c[i][0] = 1;
    for (int j=0; j<Y; j++) c[0][j] = 1;
 
    // [Compute]
    for (int i=1; i<X; i++)
        for (int j=1; j<Y; j++)
            c[i][j] = c[i-1][j] + c[i][j-1];
 
    // 輸出結果
    cout << "由(0,0)走到(7,7)有" << c[7][7] << "種走法";
//  cout << "由(0,0)走到(7,7)有" << c[X-1][Y-1] << 種走法;
 
    // int x, y;
    // while (cin >> x >> y)
    //     cout << "由(0,0)走到(x,y)有" << c[x][y] << "種走法";
}

int main(){
    staircase_walk();
}