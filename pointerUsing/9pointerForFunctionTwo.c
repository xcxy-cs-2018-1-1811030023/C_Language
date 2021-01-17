/*
    指向函数的指针充当函数的参数，当我们的函数每次调用的函数都没有变得时候显得有点鸡肋，但是当我们每次
    的函数参数调用其他函数时，其他函数的返回值类型，参数类型都不变，但是函数不固定改变的时候，就取到了非常大的作用，
    不同函数对号入座，不用每次调整程序改变函数名，这种方法是符合结构化程序设计方法原则的，是程序中常使用的。
    
    用户输入两个整数，在输入1或2，或3，分别表示最大值，最小值，和。
    **/
#include <stdio.h>
int main(){
    void function(int ,int ,void (*p)(int,int));
    void max(int,int);
    void min(int,int);
    void sum(int,int);
    printf("please input two numbers:");
    int a,b;
    scanf("%d,%d",&a,&b);
    printf("please input 1 or 2 or 3,to get max or min or sum:");
    int n;
    scanf("%d",&n);
    if(n==1)    function(a,b,max);
    else if(n==2) function(a,b,min);
    else if(n==3) function(a,b,sum);
    else printf("error order!!!\n");
    return 0;
}

void function(int a,int b,void(*p)(int,int)){
    (*p)(a,b);
}

void max(int x,int y){
    int r=x>y?x:y;
    printf("the max of both a and b is %d\n",r);
}

void min(int x,int y){
    int r=x<y?x:y;
    printf("the min of both a and b is %d\n",r);
}

void sum(int x,int y){
    int sum=x+y;
    printf("the sum of both a and b is %d\n",sum);
}
