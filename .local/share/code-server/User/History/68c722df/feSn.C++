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
    
}
int main(){
    return 0;
}