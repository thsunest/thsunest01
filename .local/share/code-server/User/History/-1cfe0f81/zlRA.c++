#include <stdio.h>
#include <stdlib.h>
#define Maxsize 255
#typedef struct{
    char ch[Maxsize];
    int length;
}SString;
bool initStr(SString &S){
    S.length == 0;
    return true;
}
void printStr(SString S){
    for(int i = 0 ;i < S.length;i++){
        printf("%s",S.ch[i]);
    }
}
bool insertStr(SString &S,int index,int value){
    for(int j = S.length + 1;j > 0;j--){
        S.ch[j] = S.ch[j - 1] 
    }
}
int main(){
    printf("main");
    return 0;
}