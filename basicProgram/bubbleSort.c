/*  
    使用冒泡排序法思想:"大数往下沉，小数往上冒",对n个数排序，进行n-1次比较。在第1次比较中要进行n-1次两两比较，第j次比较中进行n-j次两两比较；
    *对数组十个数使用冒泡法进行排序
    */
#include <stdio.h>
int main(){
    int a[10];
    int i,j,t;
    printf("please input 10 numbers:\n");
    for(i=0;i<10;i++)
        scanf("%d",&a[i]);
    printf("\n");
    for(j=0;j<9;j++)
        for(i=0;i<9-j;i++){
            if(a[i]>a[i+1]){
                t=a[i];a[i]=a[i+1];a[i+1]=t;
            }
        }
    printf("the sorted numbers:\n");
    for(i=0;i<10;i++){
        printf("%d\t",a[i]);
    }
    printf("\n");
    return 0;
}