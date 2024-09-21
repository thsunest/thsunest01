#include <stdio.h>
#include <string.h>
#define Maxsize 255
typedef struct{
    char ch[Maxsize];
    int length;
}SString;
int main (){
    SString S;
    S.ch[0] = 'X';
    printf("%c",S.ch[0]);
    
    char f[10]= "hello";
    for(int i = 0;i < 10 ; i++){
        printf("%c",f[i]);
    }
    return 0;
}