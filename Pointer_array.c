/*
    通过指针法对数组进行遍历
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