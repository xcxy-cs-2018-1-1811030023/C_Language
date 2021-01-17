/*
    找出其中有不及格的学生的成绩和学号
    **/
#include <stdio.h>
int main(){
    float score[][4]={{67,90,76,89},{89,59,99,100},{31,74,97,70},{34,56,78,90}};
    float search((*pointer)[4]);
    float *p;
    int i,j;
    for(i=0;i<4;i++){
        p=search(score+i);
        if(p==*(score+i)){
            printf("No.%d score:",i);
            for(j=0;j<4;j++)
                printf("%5.2f",*(p+j));
            printf("\n");
        }
    }
    return 0;
}
float search((*pointer)[4]){
    int i=0;
    float *pt;
    pt=NULL;
    for(;i<4;i++)
        if(*(*pointer+i)<60) pt=*pointer;
    return(pt);
}