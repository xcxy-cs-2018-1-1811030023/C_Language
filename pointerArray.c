/*
    通过地址可以找到所需的变量单元，此地址为变量的指针；
    有一个专门用来存放另一个变量的地址(指针)的变量，称为指针变量；
    int *a;int为定义指针所必须的基类型，*为运算符只跟指针变量在一起，为指向的对象，*a等同于被指向的变量；
    明白储存单元的地址与储存单元的内容，如int *a中指针变量a储存的地址不仅有地址信息还有所指的数据的类型信息；
    涉及数组元素遍历的方法：下标法，数组名位移法，指针法；
    *通过指针法对数组进行遍历
    
    */

#include <stdio.h>
int main(){
    int a[10],i,*p=a;
    printf("please input 10 numbers:");
    for(i=0;i<10;i++)
        scanf("%d",p++);
    p=a;
    printf("the content of array is:");
    for(i=0;i<10;i++,p++)
        printf("%d",*p);
    printf("\n");
    return 0;
}