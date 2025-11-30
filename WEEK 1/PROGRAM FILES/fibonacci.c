#include <stdio.h>
int main(){
  int n,i;
  int a=0, b=1, c;
  printf("Enter the number of Fibonacci Numbers: ");
  scanf("%d" , &n);
  if(n<=0){
    printf("Please enter a positive integer");
    return 0;
  }
  printf("Fibonacci Series: ");
  for (i=1; i<=n;i++){
    if (i==1){
      printf("%d ", a);
      continue;
    }
    if (i==2){
      printf("%d ",b);
      continue;
    }
    c = a+b;
    printf("%d ", c);
    a=b;
    b=c;
  }
  printf("\n");
  return 0;
}
