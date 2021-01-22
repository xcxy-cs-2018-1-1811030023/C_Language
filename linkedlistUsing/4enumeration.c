/*
    如果一个变量只有几种可能的值，这可以定义为枚举类型，所谓枚举就是把可能的值一一列举出来，变量的值只限于列举出来的值的范围内。
    特点：1.c编译对枚举类型的枚举元素按常量处理，故称枚举常量，不能对它们赋值
        2.每个枚举元素都代表一个整数，c语言的编译按定义时的顺序默认他们的值为0,1,2,3,4,5,6....。也可以人为的指定枚举元素的数值
        enum Weekday{sun=7,mon=1,tue,wed,thu,fri,sat}workday,week_end,指定枚举常量sun的值为7，mon为1，以后顺序加1,sat为6.
        **/
//口袋中有红，黄，蓝，白，黑5种颜色的球。每一次从口袋中先后取3个球，问得到三种颜色的球的可能取法，输出每种排列的情况。使用穷举法。
#include <stdio.h>
int main(){
    enum Color{red,yellow,blue,white,black};
    enum Color i,j,k,pri;
    int n,loop;
    n=0;
    for(i=red;i<=black;i++){
        for(j=red;j<=black;j++){
            if(i!=j){
                for(k=red;k<=black;k++){
                    if((k!=i)&&(k!=j)){
                        n++;
                        printf("%-4d",n);
                        for(loop=1;loop<=3;loop++){
                            switch(loop){
                                case 1: pri=i;break;
                                case 2: pri=j;break;
                                case 3: pri=k;break;
                                default:break;
                            }
                            switch(pri){
                                case red:   printf("%-10s","red"); break;
                                case yellow:    printf("%-10s","yellow"); break;
                                case blue:  printf("%-10s","blue"); break;
                                case white: printf("%-10s","white"); break;
                                case black: printf("%-10s","black"); break;
                                default: break; 
                            }
                        }
                        printf("\n");
                    }
                }
                
            }
        }
    }
    printf("\ntotal:%5d\n",n);
    return 0;
}