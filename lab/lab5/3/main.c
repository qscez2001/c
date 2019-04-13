#include <stdio.h>
#include <string.h>

int main(){
  int tcnum;
  char a[101];
  scanf("%d\n", &tcnum);
  for(int i=0; i<tcnum; i++) {
    
    if(fgets(a, 99, stdin) != NULL){
      // printf("%s\n", a);
      int count = 0;
      for(int i=0; i<strlen(a); i++){
        for(int j=i+1;j<strlen(a);j++){
          if(a[i] == a[j] - 32 || a[i] == a[j] + 32){
            a[i] = ' ';
            a[j] = ' ';
          }
        }
      }
      // printf("%s\n", a);
      for(int i=0; i<strlen(a); i++){
        if(a[i] != ' ' && a[i] != '\n') count++;
      }
      printf("%d\n", count);
    }
  }
  return 0;
}