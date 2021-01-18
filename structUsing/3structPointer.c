/*
    一个结构体变量的起始位置就是这里结构体变量的指针。结构体变量的基类型必须与结构体变量的类型相同。
    struct Student stu;
    struct Student *p
    p=&stu;
    指针变量p指向stu结构体，访问成员变量的时候有三种方法：stu.成员名 或 (*p).成员名 或 p->成员名
    */
//有3个学生信息，放在结构体数组中，要求输出全部学生的信息
/*
#include <stdio.h>
struct Student{
    int num;
    char name[20];
    char sex;
    int age;
};
struct Student stu[3]={{1,"aa",'W',18,},{4,"bb",'M',20},{23,"lq",'M',20}};
int main(){
    struct Student *p;                                      //p可以指向结构体的一个成员变量如: p=(struct Student*)stu[0].name
                                                            //只不过要求基类型必须相同，相加减的跨度增量是结构体struct Student的长度
    for(p=stu;p<stu+3;p++)
        printf("%5d %-20s %2c %4d\n",p->num,p->name,p->sex,p->age);          //%-20s表示空出来的位置在值得右边
    return 0;
}
*/

//用结构体变量和结构体变量的指针作函数参数，三种方法：1.用结构体变量的成员作参数属于值传递的方式。2.用结构体变量作实参,也是属于值传递，空间开销大
//用指向结构体变量（或数组元素）的指针作实参，将结构体变量（或数组变量）的地址传递给形参。

//有n个结构体变量，内含学生学号，姓名和3门课程成绩。要求输出平均成绩最高的学生的信息（包括学号，姓名，3门课程成绩和平均成绩）
#include <stdio.h>
#define N 3
struct Student{
    int num;
    char name[20];
    float score[3];
    float aver;
};

int main(){
    void input(struct Student stu[]);
    struct Student max(struct Student stu[]);
    void print(struct Student stu);
    struct Student stu[N],*p=stu;
    input(p);                   //调用input和max函数时，实参是指针变量p,形参是结构体数组，传递的是结构体数组的起始地址
    print(max(p));              //调用print函数时候，实参是结构体变量（结构体数组元素），形参是结构体变量，传递的是结构体变量中各成员的值
    return 0;
}

void input(struct Student stu[]){                  // 在调用input函数时，将主函数中的stu数组的首元素的起始地址传给形参数组stu，使形参数组
                                                    //stu与主函数中的stu数组具有相同的地址，因此在input函数中向形参数组stu输入数据就等于向
                                                    //主函数中的stu数组输入数据。
    int i;
    printf("请输入各个学生的信息：学号、姓名、3门功课成绩：\n");
    for(i=0;i<N;i++){
        scanf("%d %s %f %f %f",&stu[i].num,stu[i].name,&stu[i].score[0],&stu[i].score[1],&stu[i].score[2]);
        stu[i].aver=(stu[i].score[0]+stu[i].score[1]+stu[i].score[2])/3.0;
    }
}

struct Student max(struct Student stu[]){
    int i,m=0;
    for(i=0;i<N;i++){
        if(stu[i].aver>stu[m].aver) m=i;
    }
    return stu[m];
}

void print(struct Student stud){
    printf("\n成绩最高的学生是:\n");
    printf("学号:%d\n姓名：%s\n三门课的成绩:%5.1f,%5.1f,%5.1f\n平均成绩:%6.2f\n",stud.num,stud.name,stud.score[0],stud.score[1],stud.score[2],stud.aver);
}