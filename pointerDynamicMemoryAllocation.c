/*
    全局变量分配在内存中的静态储存区，非静态的局部变量（包括形参）是分配在内存的动态储存区的，这个储存区称为栈的区域。
    除此之外，C语言允许建立内存动态分配区域，用来存放一些临时用的数据，这些数据不必在程序的声明部分定义，也不必等到函
    数结束时候才释放，而是需要的时候随时开辟。这些数据是临时存放在一个特别的自由存储区，称为堆。可以根据需要向系统申请所需的
    空间大小。
    由于未在声明部分定义他们为变量或数组，因此不能通过变量名或者数组名去应用这些数据，只能通过指针来应用。
    动态分配的函数在<stdlib.h>的库函数中：
    1.用malloc函数开辟动态存储区 void *malloc(unsigned int size); 如malloc(100) 功能是在内存的动态存储区中分配一个长度为size的连续空间.分配不成功则放回空指针NULL
    一定注意，指针的基类型为void，表示不指向任何类型的数据，不能企图通过它来存取数据，在程序中它只是过渡性的，只提供一个纯地址，
    只有转换为有指向的地址（即赋值给有基类型的指针），才能存取数据
    如int *pt;
    pt=(int *)mcaloc(100);
    或者简化为pt=mcaloc(100);
    其实可以不用强制类型转换，因为在将它的值赋值给另一个指针变量的时候由系统对它进行类型转换（隐式转换），以使用被赋值的变量类型（指针赋值的时候基类型必须一样）

    2.用calloc函数开辟动态储存区 void *calloc(unsigned n,unsigned size); 如p=calloc(50,4) 其作用就是在内存的动态存储区中分配n个长度为size的连续空间，这个空间一般较大，
    足以保存一个数组。函数返回指向所分配的第一个字节的指针，分配不成功，返回NULL。

    3.用realloc函数重新分配动态存储区 void *realloc(void *p,unsigned int size); 如realloc(p,50) 经过以上的两个函数分配了空间，如果想要改变大小可以用recalloc函数重新分配。
    将p所指向的动态空间大小改变为size。p的值不变，如果重分配不成功，返回NULL.

    4.用free函数释放动态存储区 void free(void *p); 如free(p) 释放指针变量p所指向的动态空间，使这部分空间能够被其他变量使用。p为最近一次调用calloc或malloc时的返回值。
    free函数无返回值

    建立动态数组，输入5个学生的成绩，另外用一个函数检查其中有无低于60分的，输出不合格的成绩
    **/
#include <stdio.h>
#include <stdlib.h>
int main(){
    void check(int *);
    int *p1,i;
    p1=(int *)malloc(5*sizeof(int));
    printf("enter five numbers:");
    for(i=0;i<5;i++){
        scanf("%d",p1+i);
    }
    check(p1);
    return 0;
}

void check(int *p){
    int i;
    printf("They are fail:");
    for(i=0;i<5;i++){
        if(p[i]<60) printf("%d\t",p[i]);
    }
    printf("\n");
}