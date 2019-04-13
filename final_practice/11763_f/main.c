#include <stdio.h>
#include <stdbool.h>

bool coloring(int *color, int vertice, int mark) {
//    printf("DEBUG: v2 = %d, mark = %x, ~mark=%x \n", vertice, color[vertice], ~color[vertice]);

    if (color[vertice] == 0) {
        color[vertice] = mark;
        return true;
    }

    if (color[vertice] != mark) return false;
    else return true;
}

void update_points(int *points, int point) {
    for (int i=0; i<1000; i++) {
        if (points[i] == point) break;
        else if (points[i] == 0) {
            points[i] = point;
            break;
        }
    }
}

int main() {
    int T;
    scanf("%d", &T);

    while (T--) {
        int n, m;
        scanf("%d %d", &n, &m);

        int a[1001][1001] = { 0 };
        int points[1000] = { 0 };
        while (m--) {
            int u, v;
            scanf("%d %d", &u, &v);
            a[u][v] = 1;
            a[v][u] = 1;

            update_points(points, u);
            update_points(points, v);
        }

        bool ans = true;
        int color[1000] = { 0 };
        color[points[0]] = 0xff000000;
        for (int i=0; i<n; i++) {
            int v1 = points[i];
            int mark = color[v1];
//            printf("DEBUG: v1 = %d, mark = %x, ~mark=%x \n", v1, mark, ~mark);
            for (int j=0; j<n; j++) {
                int v2 = points[j];
                if (a[v1][v2] == 1) ans &= coloring(color, v2, ~mark);
            }
        }

        if (ans) printf("Yes\n");
        else printf("No\n");
    }
}