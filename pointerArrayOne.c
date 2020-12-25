/*
    一个实参数组想要在函数中改变此数组的元素值，形参与实参的对应关系有两种，
    这里采用，指针对数组，与指针对指针的方式，强调"当指针做实参时必须先使指针变量有确定值，指向一个已经定义的对象。;
    当用数组名作为函数参数时，由于数组名代表的是数组首元地址，因此传递的值是地址，所以要求形参为指针变量；
    在c语言中[]实际上是变址运算符，即将a[i]按ａ+i计算地址，然后再找出地址单元中的值，而指针法则是直接用指针指向元素
    ，不必每次计算地址；
    *采用选择法对数组中的10数进行排序。
    */

#include <stdio.h>
//void sort(int x[],int n);
void sort(int *x,int n);
int main(){
    int i,a[10],*p=a;
    printf("please input 10 numbers:\n");
    for(i=0;i<10;i++)
        scanf("%d",p++);
    p=a;
    sort(a,10);
    printf("the sorted 10 numbers:\n");
    for(i=0;i<10;i++){
        printf("%d\t",*p);
        p++;
    }
    printf("\n");
    return 0;
}

/*void sort(int x[],int n){
    int i,j,k,t;
    for(i=0;i<n-1;i++){
        k=i;
        for(j=i+1;j<n;j++){
            if(x[k]>x[j]) k=j;
        t=x[i];x[i]=x[k];x[k]=t;
        }
    }
}
*/
void sort(int *x,int n){
    int i,j,k,t;
    for(i=0;i<n-1;i++){
        k=i;
        for(j=i+1;j<n;j++){
            if(*(x+k)<*(x+j)) k=j;
            t=*(x+i);*(x+i)=*(x+k);*(x+k)=t;
        }
    }
}
