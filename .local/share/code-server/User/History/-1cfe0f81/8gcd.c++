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
    printf("%d",S.length);
    for(int i = 1 ;i <= S.length;i++)
    printf("%c",S.ch[i]);
}
bool insertStr(SString &S,int index,char value){
    for(int j = S.length + 1;j >= index;j--){
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
    insertStr(S,0,'V');
    insertStr(S,2,'V');
    printStr(S);
    printf("%c",S.ch[1]);

    printf("main");
    return 0;
}