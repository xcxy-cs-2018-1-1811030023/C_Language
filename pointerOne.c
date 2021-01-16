/*
    通过地址可以找到所需的变量单元，此地址为变量的指针；
    有一个专门用来存放另一个变量的地址(指针)的变量，称为指针变量；
    int *a;int为定义指针所必须的基类型，*为运算符只跟指针变量在一起，为指向的对象，*a等同于被指向的变量；
    明白储存单元的地址与储存单元的内容，如int *a中指针变量a储存的地址包含三个信息：1.表示内存编号的存地址
    2.它本身的类型，即指针类型 3.以它为标示的存储单元中存放的是什么类型的数据，即基类型。只有指针类型与基类型相同
    才能在相应的指针变量中存放地址
    
    指针在在c语言中最重要的就是作为函数的参数参与单向传递，来影响n个参数，因为函数中的变量是存储在动态区的
    所以通过一般的函数间值的单项传递执行之后就被释放了，所以起不到影响多值，或者返回多值的作用，当然你也可以使用
    别的方法（使用全局变量，或直接在函数中输出，或在在函数中定义静态变量等）。
    指针可以为空值，即该指针变量不指向任何变量 ，如p=NULL;NULL是一个符号常量，代表整数0 任何指针变量都可以与其作比较，
    因为在stdio.h头文件中对NULL进行了定义,#define NULL 0 它使p指向地址为0的单元，系统保证使该单元不做他用（不存放数据）
    注意p的值为NULL与未对p赋值是两个概念，前者为不指向任何变量，后者的值是一个无法估料的值，可能指向一个事先未指定的单元，
    这种情况很危险，因此应用指针变量之前应对它进行赋值。
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