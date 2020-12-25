/*
    理解掌握内外for循环之间的配合；
    *创建g根据输入的x和y创建x*y的矩阵
    */
#include <stdio.h>
int main(){
    printf("please input x and y:\n");
    int x,y;
    scanf("%d",&x);
    scanf("%d",&y);
    int i,j,n=0;
    for(i=1;i<=x;i++){
        for(j=1;j<=y;j++,n++){
            if(n%5==0)  printf("\n");
            printf("%d\t",i*j);
        }
    }
    printf("\n");
    return 0;
}