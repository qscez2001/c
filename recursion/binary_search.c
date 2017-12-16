/*
在一個排序過後的數列中找尋一個數，最快的方式是什麼呢？
當然，一個一個掃過一定是沒問題的，這樣的時間複雜度是O(n)。但是其實有另一個更快的方法。

因為數列是已經排序過的，所以我們可以先取排列在中間的值，看這個值跟我們所要找的數是不是一樣大。
若是一樣大，那我們就找到了；若是這個值比較小，那我們可以從比它大的那一群數中再找，反之亦然。
如此一步一步取區間內中間位置的值比對，和第一個方法相比，可以省下很多時間。
這樣的方法的時間複雜度是O(logn)，在數列的大小越大時，時間的差距就會越明顯。

這樣的例子，我們是已經提供一組排序過的資料。若需要在一組未排序的資料中找值這樣的方法是不行的，
唯一的方法是一個一個掃過。這樣的方法在搜尋的數字比較少時沒問題，但壞處是當尋找的數字很多時就很沒效率。
但是我們可以先對未排序的資料先排序 (sort) ，再用 binary search 。
這樣的優缺點和前面的方法相反，在搜尋的數字少時，因為一開始需要 sort ，所以會多花時間；
但是當尋找的數字多時，binary search的速度就會體現出來。
而sort的方法有很多種，下面要介紹的就是用遞迴實現Merge Sort。
*/

// A piece of C code
#include <stdio.h>
int data[]={1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
void find(int, int, int);

int main(void)
{
    int number;
    printf("Enter a number between 1 and 10 you want to find:\n");
    scanf("%d", &number);
    find(number, 0, 9);
}

void find(int number, int head, int tail)
{
    int middle=(head+tail)/2;
    if(head>tail){
        printf("%d is not in the data.\n", number);
    }
    else if(data[middle]==number){
        printf("%d is at position %d.\n", number, middle);
    }
    else if(data[middle]>number){
        find(number, head, middle-1);
    }
    else{
        find(number, middle+1, tail);
    }
}