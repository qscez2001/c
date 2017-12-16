#include <stdio.h>
int main(void)
{
    int * px;
    int x = 3;
    double y = 2.5;
    double * py;
    px = &x;
    py = &y;

    printf("%p, %p\n", &x, &y);
    printf("%u, %u\n", sizeof(px), sizeof(py));
    printf("%u, %u\n", sizeof(*px), sizeof(*py));
    printf("%d\n", *py);

    return 0;
}