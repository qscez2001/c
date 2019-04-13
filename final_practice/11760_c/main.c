#include <stdio.h>
#include <stdbool.h>
#include <string.h>

struct Record {
    char name[21];
    int score;
};

int main() {
    int n;
    scanf("%d", &n);

    struct Record records[100000];
    for (int i=0; i<n; i++) {
        scanf("%s %d", records[i].name, &records[i].score);
    }

    // bubble sort in decreasing order
    for (int i=0; i<n-1; i++) {
        for (int j=0; j<n-1; j++) {
            if (records[j].score < records[j+1].score) {
                // swap
                struct Record tmp = records[j];
                records[j] = records[j+1];
                records[j+1] = tmp;
            }
        }
    }

    // print the sored list
    for (int i=0; i<n; i++) {
        printf("%s\n", records[i].name);
    }
}