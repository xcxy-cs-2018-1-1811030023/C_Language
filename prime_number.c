/*
    判断给定区间的素数
    */
#include <stdio.h>
#include <math.h>
int main(){
    int x,y;
    printf("请输入区间两端值：\n");
    scanf("%d",&x);
    scanf("%d",&y);
    int n,k,i,m=0;
    for(n=x;n<=y;n++){
        k=sqrt(n);
        for(i=2;i<=k;i++)
            if(n%i==0) break;
        if(i==k+1){
            printf("%d\t",n);
            m++;
        }
        if(m%10==0) printf("\n");
        

    }
    printf("\n");
    return 0;
}