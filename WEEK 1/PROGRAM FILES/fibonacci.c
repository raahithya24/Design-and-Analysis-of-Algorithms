#include <stdio.h>
int main(){
int a,b,c,n;
printf("enter the a number n\n");
scanf("%d",&n);
a=0;
b=1;
printf("the fibonacci numbers are \n");
while(a<n){
printf("%d ",a);
 c=a+b;
 a=b;
 b=c;
 }
 }

