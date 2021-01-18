/*
    一个数组如果元素全为指针类型数据，则为指针数组，即每个元素都存放一个地址，相当于指针变量
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
    /*这里要明白，每一个数组元素，就是一个指针变量，指向一个字符串
    在name上面加减，就是对各个元素地址的切换（系统自动会根据数组类型进行寻址转换），
    name[i]则是一个指针变量存储的每个字符串的首地址，存储的只是个地址，
    *name[i]则是指针变量所代表的值指向第i个字符串首个地址的字符，存储指向的时候个字符串。*/
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
            /*注意这里不能用strcmp(*name[k],*name[j])>0,不然就是比较指向字符串的第一个字符了,我们要传入的是字符串
            这里介绍一下strcmp的用法:
            strcmp() 用来比较字符串（区分大小写），其原型为：int strcmp(const char *s1, const char *s2);s1, s2 为需要比较的两个字符串。
            字符串大小的比较是以ASCII码表上的顺序来决定，此顺序亦为字符的值。strcmp()首先将s1 第一个字符值减去s2 第一个字符值，若差值为0
            则再继续比较下个字符，若差值不为0 则将差值返回。例如字符串"Ac"和"ba"比较则会返回字符"A"(65)和'b'(98)的差值(－33)。
            所以这里我们传入的是字符串的首地址和跟传入字符串对系统来说都是一样的，但是就是不能传入字符
            举例：
            #include <string.h>
            main(){
                char *a = "aBcDeF";
                char *b = "AbCdEf";
                char *c = "aacdef";
                char *d = "aBcDeF";
                printf("strcmp(a, b) : %d\n", strcmp(a, b));
                printf("strcmp(a, c) : %d\n", strcmp(a, c));
                printf("strcmp(a, d) : %d\n", strcm p(a, d));
            }
            输出结果：
            strcmp(a, b) : 32
            strcmp(a, c) :-31
            strcmp(a, d) : 0
            */
        if(k!=i){
            temp=name[i];name[i]=name[k];name[k]=temp;
            //这里我们交换的是指针变量，也就是改变的是指针数组各元素的指向（指向互换），而不是指向的值
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