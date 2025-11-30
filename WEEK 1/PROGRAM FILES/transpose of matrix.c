#include <stdio.h>
int main(){
int M[3][3];
printf("enter matrix elements\n");
for(int i=0;i<3;i++){
    for(int j=0;j<3;j++){
     scanf("%d",&M[i][j]);
     }
     }
     printf("the transpose of matrix is\n");
for(int i=0;i<3;i++){
    for(int j=0;j<3;j++){
     printf("%d ",M[j][i]);
    }
    printf("\n");
    
     }
     return 0;
     }
  
