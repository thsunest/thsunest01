#include<stdio.h>
#include<stdlib.h>
#include<string.h>
# define Maxsize 255
typedef struct{
    char ch[Maxsize];
    int length;
}SString;
bool StrAssign(SString &S,char s,int x){
    if(S.length < Maxsize){
        S.ch[x] = s;
        S.length++;
    }
    else 
        return false; //溢出       
}
bool PrintStr(SString S){
    for (int i = 1;i <S.length;i++)
    printf("%d",S.ch[i]);
    if (S.length == 0)
        return false;
    else 
        return true;
}
int main(){
    SString S;
    StrAssign(S,1,'H');
    StrAssign(S,1,'e');
    StrAssign(S,1,'l');
    StrAssign(S,1,'o');
    StrAssign(S,1,'o');
    StrAssign(S,1,'!');
    StrAssign(S,1,'W');
    StrAssign(S,1,'o');
    StrAssign(S,1,'r');
    StrAssign(S,1,'l');
    StrAssign(S,1,'d');
    PrintStr(S);  
    return 0;
}