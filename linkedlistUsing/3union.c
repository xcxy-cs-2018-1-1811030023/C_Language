/*
    共用体类型：有时想用同一段内存开始单元存放不同类型的变量，这种使几个不同的变量共享同一段内存的结构。
    使用范围：往往在数据处理中，有时需要对同一段空间安排不同的用途，这个时候用共用体比较方便，能增加程序处理的灵活性。
    结构体变量所占内存的长度等于各成员占的内存长度之和，而共用体变量所占的内存长度等于最长的成员的长度。
    特点：1.同一个内存段可以用来存放几种不同类型的成员，但在每个瞬间只能存放其中一个成员，而不是同时存放几个。也就是共用体变量只能存放一个值
        2.可以对共用体变量初始化，只能初始化表中的一个成员变量
        3.共用体中起作用的成员是最后一次被赋值的成员，在对共用体变量其中一个赋值后，原有变量存储的值就被替代了。（因此在赋值的时候，要明白之前存取的值是什么）
**/
//有若干人员的数据，其中有学生和教师。学生的数据中包括：姓名，号码，性别，职业，班级。教师的数据包括：姓名，号码，性别，职业，职务。要求用统一表格来处理。
#include <stdio.h>
union Categ{
    int classNum;
    char position[10];
};

struct{
    int num;
    char name[10];
    char sex;
    char job;
    union Categ category;
}person[2];

int main(){
    int i;
    for(i=0;i<2;i++){
        printf("please input the data of person:\n");
        scanf("%d %s %c %c",&person[i].num,person[i].name,&person[i].sex,&person[i].job);
        if(person[i].job=='s')  scanf("%d",&person[i].category.classNum);
        else if(person[i].job=='t') scanf("%s",person[i].category.position);
        else printf("Input error!!!");
    }
    printf("\n");
    printf("No.     name    sex job class/position\n");
    for(i=0;i<2;i++){
        if(person[i].job=='s')   printf("%-6d%-10s%-4c%-4c%-10d\n",person[i].num,person[i].name,person[i].sex,person[i].job,person[i].category.classNum);
        else    printf("%-6d%-10s%-4c%-4c%-10s\n",person[i].num,person[i].name,person[i].sex,person[i].job,person[i].category.position);
    }
    return 0;
}