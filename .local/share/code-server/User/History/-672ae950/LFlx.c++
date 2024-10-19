#include<stdio.h>
#include<stdlib.h>
#include<string.h>
# define Maxsize 255
typedef struct{
    char ch[Maxsize];
    int length;
}SString;
bool StrAssign(SString &S,int x,char s){
    if(S.length < Maxsize){
        S.ch[x] = s;
        S.length++;

        return true;
        
    }
    else 
        return false; //溢出      
}
bool PrintStr(SString &S){
    for (int i = 0;i <= S.length;i++){
        char x = S.ch[i];
        printf("%s",x);
        
    }
    if (S.length == 0)
        return false;
    else 
        return true;
}
int main(){
    SString S;
    S.ch[2] = 'H';
    StrAssign(S,1,'H');
    StrAssign(S,2,'e');
    StrAssign(S,3,'l');
    StrAssign(S,4,'o');
    StrAssign(S,5,'o');
    StrAssign(S,6,'!');
    StrAssign(S,7,'W');
    StrAssign(S,8,'o');
    StrAssign(S,9,'r');
    StrAssign(S,10,'l');
    StrAssign(S,11,'d');
    PrintStr(S);  
    return 0;
}