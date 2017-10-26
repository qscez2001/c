//
//  main.c
//  main.c
//
//  Created by 陳瑀芋 on 2017/10/12.
//  Copyright © 2017年 yuyu. All rights reserved.
//

#include <stdio.h>

int n, m, t;

int main()

{
    int T;
    scanf("%d", &T);
    for(int i=0;i<T;i++)
    {
        scanf("%d %d %d", &n, &m, &t);
        draw();
    }
}

int draw()
{
    if (t == 0 || t > n+m) {
        // e.g., 10 5 0
        for(int i=1; i<=n; i++) {
            printf("-");
        }
    }
    else if (t<=m) {
        // e.g., 10 5 1
        // e.g., 10 5 5
        for(int i=1; i<=n; i++) {
            if (i <= t) {
                printf("^");
            }
            else {
                printf("-");
            }
        }
    }
    else if (t<=n){
        // e.g., 10 5 6
        // e.g., 10 5 10
        // fix this section
        for(int i=1; i<=n; i++) {
            
            if(i >t-m && i <= t) {
                printf("^");
            }
            else {
                //5 3 4 n m t
                //t=4 m=3 n=5
                //i=1 "-"
                //i=2 "^"
                //i=3 "^"
                //i=4 "^"
                //i=5 "-"
                printf("-");
            }
        }
    }
    else if(t<=n+m){
        // e.g., 10 5 11
        // e.g., 10 5 12
        // fix this section
        for(int i=1; i<=n; i++) {
            if (i > t-m) {
                printf("^");
            }
            else {
                printf("-");
            }
        }
    }
    printf("\n");
}
