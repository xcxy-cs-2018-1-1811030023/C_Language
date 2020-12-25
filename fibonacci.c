/*  
    fibonacci值，1 1 2 3 5 8 13 21 34 55 .......;
    *根据输入的数值，得到所输入数值后的Fibonacci值
    */
#include <stdio.h>
int main(){
    int f1=1,f2=1;
    int i,j;
    printf("please input how many month you to get:\n");
    scanf("%d",&j);
    for(i=1;i<=j;i++){
        printf("%12d %12d",f1,f2);
        if(i%2==0) printf("\n");
        f1=f1+f2;
        f2=f2+f1;
    }
    return 0;
}