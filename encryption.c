/*
    给字母加密，字母中的字符按ASCII码的顺序往后移四位
    */
#include <stdio.h>
int main(){
    char c;
    while((c=getchar())!='\n'){
        if((c>='a'&&c<='z')||(c>='A'&&c<='Z')){
            c+=4;
            if(c>='Z'&&c<='Z'+4||c>'z') c-=26;
        }
        printf("%c",c);
    }
    printf("\n");
    return 0;
}