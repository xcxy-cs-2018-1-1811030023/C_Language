/*一个函数可以返回一个字符型，整型值，实型值，也可以返回指针型的数据，即地址。只不过函数的返回值类型为指针型而已。
    
    有a个学生，每个学生有b门课的成绩。要求用户输入学生序号以后，能够输出该学生的全部成绩。用指针函数实现
    **/
#include <stdio.h>
int main(){
    float score[][4]={{67,90,76,89},{89,59,99,100},{31,74,97,70},{34,56,78,90}};
    float *search(float (*pointer)[4],int n);
    float *p;
    int i,k;
    printf("enter the number of students:");
    scanf("%d",&k);
    printf("the scores of %d student are:\t",k);
    p=search(score,k);
    for(i=0;i<4;i++)
        printf("%5.2f\t",*(p+i));
    printf("\n");
    return 0;
}

float *search(float (*pointer)[4],int n){
    float *pt;
    pt=*(pointer+n-1);
    return(pt);
}