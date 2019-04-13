#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct A{
    char name[25];
    int x;
    int y;
}factory;
int str_cmp(const void*a,const void*b)
{
    const factory*va=(const factory*)a;
    const factory*vb=(const factory*)b;
    return strcmp(va->name, vb->name);
}
int int_cmp(const void*a,const void*b)
{
    const factory*va=(const factory*)a;
    const factory*vb=(const factory*)b;
    return (va->x - va->y)-(vb->x - vb->y);
}
int int_cmpx(const void*a,const void*b)
{
    const factory*va=(const factory*)a;
    const factory*vb=(const factory*)b;
    if  (va->x >= vb->x) return -1;
    else return 1;
}
int int_cmpy(const void*a,const void*b)
{
    const factory*va=(const factory*)a;
    const factory*vb=(const factory*)b;
    if  (va->y >= vb->y) return -1;
    else return 1;
}
int main(int argc, const char * argv[]) {
    int i,n,a,b,c=0,tmp=0,place;
    scanf("%d%d%d",&n,&a,&b);
    int array[n];
    for(i=1;i<n;i++) array[i]=0;
    factory f[n];
    while(c<n)
    {
        scanf("%s",f[c].name);
        scanf("%d",&f[c].x);
        scanf("%d",&f[c].y);
        c++;
    }
    
    if(a!=n){
        qsort(f, n, sizeof(factory), int_cmp);
        for(i=1;i<n-1;i++)
        {
            qsort(f, i, sizeof(factory), int_cmpy);
            qsort(f+i, n-i, sizeof(factory), int_cmpx);
            array[i]=f[0].y+f[i].x;
        }
        for(i=0;i<n-1;i++)
        {
            if(array[i]>=tmp)
            {
                tmp=array[i];
                place=i;
            }
        }
        qsort(f, n, sizeof(factory), int_cmp);
        qsort(f, place, sizeof(factory), int_cmpy);
        qsort(f+place, n-place, sizeof(factory), int_cmpx);
        qsort(f+place, a, sizeof(factory), str_cmp);
        for(i=place;i<a+place;i++) printf("%s\n",f[i].name);
    }
    else{
        qsort(f, n, sizeof(factory), str_cmp);
        for(i=0;i<n;i++) printf("%s\n",f[i].name);
    }
    
  
    return 0;
}