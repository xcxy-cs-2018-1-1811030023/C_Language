/*
    一个数组如何元素全为指针类型数据，则为指针数组，即每个元素都存放一个地址，相当于指针变量
    使用环境：比较适合用来指向若干个字符串，使字符串处理更加灵活。如，我们要存储多个字符串，
    以前常规的话使用二位数组，但是如果每个字符串长度都不一样，使用二位数组就必须满足最大长度，
    这样太浪费空间了。这里我们使用指针字符串，每个数组元素指向每个字符串数组个首地址，这样就共同管理起来了。
    
    将若干字符串按字母顺序（有小到大）输出**/
#include <stdio.h>
#include <string.h>
int main(){
    void sort(char *name[],int n);
    void print(char *name[],int n);
    char *name[]={"Faladsf","Aaeraewra","Iafadf","Bljppp","Haadsfadfa"};
    int n=5;
    sort(name,n);
    print(name,n);
    return 0;
}

void sort(char *name[],int n){
    char *temp;
    int i,j,k;
    for(i=0;i<n-1;i++){
        k=i;
        for(j=i+1;j<n;j++)
            if(strcmp(name[k],name[j])>0) k=j;
        if(k!=i){
            temp=name[i];name[i]=name[k];name[k]=temp;
        }
    }
}

void print(char *name[],int n){
    int i=0;
    char *p;
    p=name[0];
    while(i<n){
        p=*(name+i++);
        printf("%s\n",p);
    }
}