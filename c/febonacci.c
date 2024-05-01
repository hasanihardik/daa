#include<stdio.h>
int main(){
    int a,b,sum,n;
    a=1;
    b=1;
    sum=0;
    scanf("%d",&n);
    for(int i=1;i<=n-2;i++){
        sum=a+b;
        a=b;
        b=sum;
    }
    printf("nth term is %d",sum);
}