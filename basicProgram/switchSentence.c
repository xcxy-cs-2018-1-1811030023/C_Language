/*
    c语言中程序的结构分为三大类：顺序结构，选择结构，循环结构，常见的选择结构的语句有（if,if else,if else if ...else,switch)
    常见的循环结构有（while，do while,for);
    *使用switch实现百分制分数段
    */

#include <stdio.h>
int main(){
    char grade;
    scanf("%c",&grade);
    printf("Your score:");
    switch(grade){
        case 'A':printf("85-100\n");break;
        case 'B':printf("70-84\n");break;
        case 'C':printf("60-69\n");break;
        case 'D':printf("<60\n");break;
        default:printf("enter data error!!!\n");
    }
    return 0;
}