#include <stdio.h>
int sumNum(int n){
    int i,sum=0;
    for(i=1;i<=n;i++){
      sum+=i;
      }
      return sum;
      }
int main(){
  int n,result;
 printf("enter a number n:\n");
 scanf("%d",&n);
 result=sumNum(n);
 printf("the sum of %d natural numbers is %d\n",n,result);
 return 0;
 }
