/*
    指针在在c语言中最重要的就是作为函数的参数参与单向传递，来影响n个参数，因为函数中的变量是存储在动态区的
    所以通过一般的函数间值的单项传递执行之后就被释放了，所以起不到影响多值，或者返回多值的作用，当然你也可以使用
    别的方法（使用全局变量，或直接在函数中输出，或在在函数中定义静态变量等），
    *通过使用指针作为函数的参数，改变多个数的值（对三个数降序排列）
    */
#include <stdio.h>
void exchange(int *q1,int *q2,int *q3);
void swap(int *pt1,int *pt2);

int main(){
    int a,b,c,*p1,*p2,*p3;
    printf("please input three numbers:\n");
    scanf("%d,%d,%d",&a,&b,&c);
    p1=&a;p2=&b;p3=&c;
    exchange(p1,p2,p3);
    printf("The order is %d\t,%d\t,%d\n",a,b,c);
    return 0;
}

void exchange(int *q1,int *q2,int *q3){
    if(*q1<*q2) swap(q1,q2);
    if(*q1<*q3) swap(q1,q3);
    if(*q2<*q3) swap(q2,q3);
}

void swap(int *pt1,int *pt2){
    int temp;
    temp=*pt1;
    *pt1=*pt2;
    *pt2=temp;
}