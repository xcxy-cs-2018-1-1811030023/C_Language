/*
    程序在编译时会把函数的源码转换为可执行代码并分配一段存储空间，这段空间有个起始地址，每一次函数的调用都是从这里开始执行，
    函数名代表函数的起始地址，我们可以定义一个指向函数的指针变量，用来存放某一个函数的起始地址，这就意味着指针变量指向了该函数，
    它只指向函数的入口而不能指向函数的某一条指令，因此不能在次上面加减
    int (*p)(int,int); 由于优先级的关系，"指针变量名"要用圆括号括起来此段函数表示可以指向函数返回值为整型并且有两个整形参数的函数。
    在程序中把哪个函数的地址赋给它，它就指向哪个函数。因此在一个程序中，一个指针变量可以先后指向同类型的不同函数，用函数名调用函数，只能调用所指定
    的一个函数，而通过指针，可以根据不同情况调用不同的函数，更加灵活

    通过输入两个整数，让用户选择，1代表max函数,2代表min函数
    **/
#include<stdio.h>
int main(){
    int max(int,int);
    int min(int,int);
    int (*p)(int,int);
    int a,b,c,n;
    printf("Please enter a and band 1 or 2(如12,45,1):");
    scanf("%d,%d,%d",&a,&b,&n);
    if(n==1) 
        p=max;
    else if(n==2) 
        p=min;
    else 
        printf("error number entered!!!");
    c=(*p)(a,b);
    printf("a=%d,b=%d\n",a,b);
    if(n==1) 
        printf("max=%d",c);
    else 
        printf("min=%d",c);
    return 0;
}

int max(int x,int y){
    return(x>y?x:y);
}

int min(int x,int y){
    return(x<y?x:y);
}