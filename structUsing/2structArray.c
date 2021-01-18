/*
    每个数组元素都是一个结构体类型的数据，他们都分别包含各个成员项。
    **/
//对三个选民进行选票，后输出选票结果
/*
#include <stdio.h>
struct Person{
    char name[20];
    int count;
}leader[3]={"a",0,"b",0,"c",0};

int main(){
    int i,j;
    char leader_name[20];
    for(i=0;i<10;i++){
        scanf("%s",leader_name);
        for(j=0;j<3;j++)
            if(strcmp(leader_name,leader[j].name)==0) leader[j].count++;
    }
    printf("\nResult:\n");
    for(i=0;i<3;i++)
        printf("%5s:%d\n",leader[i].name,leader[i].count);
    return 0;
}
*/
//有n个学生的信息（包括学号，姓名，成绩），要求按照成绩的高低顺序输出各个学生的成绩
#include <stdio.h>
struct Student{
    int num;
    char name[20];
    float score;
};
int main(){
    struct Student stu[5]={{100,"aa",89},{101,"bb",59.5},{78,"as",100},{45,"adf",45},{22,"yu",89.5}};
    const int n=5;          //const 修饰类的成员变量，表示成员常量，不能被修改。为常变量。
    struct Student temp;    //只有同类型的结构体才能相互赋值
    int i,j,k;
    printf("The order is:\n");
    for(i=0;i<n-1;i++){
        k=i;
        for(j=i+1;j<n;j++){
            if(stu[k].score<stu[j].score) k=j;
        }
        temp=stu[i];stu[i]=stu[k];stu[k]=temp;
    }
    for(i=0;i<n;i++){
        printf("%6d%8s\t%6.2f\n",stu[i].num,stu[i].name,stu[i].score);
    }
    return 0;
}