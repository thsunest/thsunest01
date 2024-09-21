#include <stdio.h>
#include <stdlib.h>
#define Maxsize 255
typedef struct{
    char ch[Maxsize];
    int length;
}SString;
void initStr(SString &S){
    S.length = 0;
}
void printStr(SString S){
    for(int i = 0 ;i < S.length;i++){
            printf("reach");
        printf("%c",S.ch[i]);
    }
}
bool insertStr(SString &S,int index,char value){
    for(int j = S.length + 1;j >= index;j--){
            printf("reach");
        S.ch[j] = S.ch[j - 1]; 
    }
    
    S.ch[index] = value;
            S.length++;
    if(S.length == Maxsize)
    return false;
    else
    return true;
}
int main(){
    SString S;
    initStr(S);
    insertStr(S,1,'X');
    printStr(S);

    printf("main");
    return 0;
}