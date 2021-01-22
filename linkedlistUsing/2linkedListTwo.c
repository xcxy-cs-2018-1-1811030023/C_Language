//创建动态链表,并输出。
/*
原理：首先动态分配创立个结点，在声明三个指针head为头指针,两个工作指针：p1,p2，其中head初值为NULL先不指向任何地址，倘若链表有一个结点了就把p1的地址赋给它，
先用指针p1指向新开辟的地址空间，输入的数据符合条件就把p1赋值给前一个结点的next值如：p2->next=p1,这样结点就连接起来了，再把p2指向新开辟的地址空间，这样一直往复下去。

*/
#include <stdio.h>
#include <stdlib.h>
#define LEN sizeof(struct Student)
struct Student{
    long num;
    float score;
    struct Student *next;
};
int n;
struct Student *create(void){
    struct Student *head,*p1,*p2;               //头指针，两个工作指针
    n=0;
    head=NULL;
    p1=p2=(struct Student *)malloc(LEN);
    scanf("%ld,%f",&p1->num,&p1->score);
    while(p1->num!=0){
        n=n+1;
        if(n==1)head=p1;
        else p2->next=p1;
        p2=p1;
        p1=(struct Student *)malloc(LEN);
        scanf("%ld,%f",&p1->num,&p1->score);
    }
    p2->next=NULL;
    return(head);
}

void print(struct Student *head){
    struct Student *p;
    printf("\nNow,These %d records are:\n",n);
    p=head;
    if(head!=NULL){
        do{
            printf("%ld %5.1f\n",p->num,p->score);
            p=p->next;
        }while(p!=NULL);
    }
}
int main(){
    struct Student *pt;
    pt=create();
    print(pt);
    return 0;
}