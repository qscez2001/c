/*
https://acm.cs.nthu.edu.tw/contest/1365/

10 5 5
TOYOTA 10 100
GM 20 90
FORD 30 80
Volkswagen 40 70
Daimler 50 60
Honda 60 50
Nissan 70 40
PEUGEOT 80 30
FIAT 90 20
BMW 100 10

BMW
FIAT
Honda
Nissan
PEUGEOT
*/
#include <stdio.h>
#include <stdbool.h>

typedef struct _Factory {
char name[21];  // factory name
//    int a;          // profit of producing car A
//    int b;          // profit of producing car B
int x;          // x = a-b
} Factory;

int main() {
    // init n, x, y
    int n;
    int x;
    int y;
    scanf("%d %d %d", &n, &x, &y);

    // init factories
    Factory factories[n];
    for (int i=0; i<n; i++) {
        int a, b;
        scanf("%s %d %d", factories[i].name, &a, &b);
        factories[i].x = a-b;
    }

    // sort factories by x
    for (int i=0; i<n-1; i++) {
        for (int j=0; j<n-1; j++) {
            if (factories[j].x < factories[j+1].x) {
                // swap
                Factory tmp = factories[j];
                factories[j] = factories[j+1];
                factories[j+1] = tmp;
            }
        }
    }

    // sort factories by name
    for (int i=0; i<x-1; i++) {
        for (int j=0; j<x-1; j++) {
            int k = 0;
            while (true) {
                if (factories[j].name[k] > factories[j+1].name[k]) {
                    // swap
                    Factory tmp = factories[j];
                    factories[j] = factories[j+1];
                    factories[j+1] = tmp;
                    break;
                }
                else if (factories[j].name[k] == factories[j+1].name[k]) k++;
                else break;
            }
        }
    }

    // print top x
    for (int i=0; i<x; i++) printf("%s\n", factories[i].name);
}