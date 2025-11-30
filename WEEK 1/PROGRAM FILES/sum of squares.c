#include <stdio.h>
int main(){
  int n,i,sum=0;
 printf("enter a number n:\n");
 scanf("%d",&n);
for(i=1;i<=n;i++){
      sum+=i*i;
      }
 printf("the sum squares of %d natural numbers is %d\n",n,sum);
 return 0;
 }
