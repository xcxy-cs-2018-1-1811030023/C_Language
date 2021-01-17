/*
    在Two的基础上，查找有一门以上不及格的学生，输出全部课程成绩
    **/
#include <stdio.h>
    int main(){
        void search(float (*p)[4],int n);
        float score[3][4]={{56,89,99,67},{63,80,58,89},{75,60,94,91}};
        search(score,3);
        return 0;
    }

    void search(float (*p)[4],int n){
        int i,j,flag;
        for(j=0;j<n;j++){
            flag=0;
            for(i=0;i<4;i++)
                if(*(*(p+j)+i)<60) flag=1;
            if(flag==1){
                printf("N0.%d fails,his scores are:\n",j+1);
                for(i=0;i<4;i++){
                    printf("%5.1f",*(*(p+j)+i));
                }
                printf("\n");
            }
        }
    }