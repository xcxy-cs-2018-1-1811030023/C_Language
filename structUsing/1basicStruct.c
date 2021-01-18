/*
    c语言提供了一些系统已经定义好了的数据类型，如:int,float,char。但在处理复杂问题的时候需要我们自己定义数据类型，
    c语言允许用户自己建立由不同类型数据组合的组合型的数据结构，称为结构体。
    一般形式为：
    struct 结构体名         //结构体名又叫结构体标记，以区别于其他结构体类型。所以如果一个结构体没有名字（只能在定义变量的时候一次性使用），显然不能再以此结构体去定义其他变量
        {
            类型名 成员名;  //成员列表又称域表，每个成员是结构体的一个域。当然，成员也可以属于另一个结构体类型。
        };

    我们要清除，建立了一个结构体类型，它相当于一个模型，并没有定义变量，其中无具体数据，系统对它也不分配存储单元，它只是个类型而已，
    c编译系统在预编译c程序的时候，对定义了的变量，是会根据其类型给变量进行分配内存空间的。同样对于数组，我们定义的时候是必须要给出大小的，
    从而分配空间，所以减少定义变量可减少内存开销。

    注意：结构体类型中的成员名可以与程序中的变量名相同，但二者不是同一个变量。
        我们可以通过结构体变量名引用成员变量，输出他的成员值，而不能企图通过输出结构体变量名来达到输出结构体变量名所有成员的值。
        对某一成员初始化：struct Student b={.name="Liu Qiang"};没有被赋值得则根据类型按系统默认值。
    **/
/*#include <stdio.h>
int main(){
    struct Student{
        long int num;
        char name[20];
        char sex;
        char addr[20];
    }a={1811030023,"LiuQiang",'M',"Sicuan Neijiang"};
    printf("NO.:%d\nname:%s\nsex:%c\naddress:%s\n",a.num,a.name,a.sex,a.addr);
    return 0;
}
*/
#include<stdio.h>
int main(){
    struct Student{
        int num;
        char name[20];
        float score;
    }student1,student2;
    scanf("%d%s%f",&student1.num,student1.name,&student1.score);
    scanf("%d%s%f",&student2.num,student2.name,&student2.score);
    printf("The higher score is:\n");
    if(student1.score>student2.score){
        printf("%d %s %6.2f\n",student1.num,student1.name,student1.score);
    }
    else if(student1.score<student2.score){
        printf("%d %s %6.2f\n",student2.num,student2.name,student2.score);
    }
    else {
        printf("%d %s %6.2f\n",student1.num,student1.name,student1.score);
         printf("%d %s %6.2f\n",student2.num,student2.name,student2.score);
    }
    return 0;
}
