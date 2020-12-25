/*
    递归问题可以分为"回朔"和"递推"两个阶段，过度的条件就是看最终想要的值找到没有；
    *用递归的方式求n!
    */
#include <stdio.h>
int main(){
    int fac(int n);
    int n,y;
    printf("input an integer number:");
    scanf("%d",&n);
    y=fac(n);
    printf("%d!=%d\n",n,y);
    return 0;

}
int fac(int n){
    int f;
    if(n<0) printf("n<0,data error");
    else if(n==0||n==1) f=1;
    else f=fac(n-1)*n;
    return f;
}