/*
    指针数组的一个重要应用，就是作为main函数的形参。一般为int main()或int main(void)。
    在某些情况下有参数（形参的值不是从程序中得到的，main函数是操作系统调用的，实参只能由操作系统给出，在操作命令行DOs,UNIX,Linux的状态下，
    实参和执行文件的命令一起给出）为int main(int argc,char *argv[]),参数名可以随便取，但是第一个参数类型必须为int型，argc为argument count
    用来接收形参个数，第二个必须为字符指针数组，argv为argument vector用来接收从操作系统命令行传来的字符串中首字符的地址

    模拟echo程序**/
#include <stdio.h>
int main(int argc,char *argv[]){
    int i;
    for(i=1;i<argc;i++){
        printf("%s%c",argv[i],(i<argc-1)?' ':'\n');
                                                    //列如命令行./exe/pointerArraySuper I love you则一共有4个参数
                                                    //argc=4;argv[0],argv[1],argv[2],argv[3]分别指向./exe/pointerArraySuper
                                                    I love 还有 you 
    }
    return 0;
}