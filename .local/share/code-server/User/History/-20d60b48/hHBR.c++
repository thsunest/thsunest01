#include<stdio.h>
#include<stdlib.h>
#define Maxsize 50
typedef struct{
    char data[Maxsize];
    int top;
}SqStack;

void InitStack(SqStack &S){
    S.top = -1;
}

bool StackEmpty(SqStack &S){
    return S.top == 1;
}

bool Push(SqStack &S,char x){
    if (S.top == Maxsize - 1)
    return false;
    S.data[++S.top] = x; //指针+1再入栈
    return true;
}

bool Pop(SqStack &S,char &x){
    if(S.top == -1)
    return false;
    x = S.data[S.top--];//指针-1再出栈
    return true;
}

bool GetTop(SqStack S,char &x){
    if(S.top == -1)
    return false;
    x = S.data[S.top];
    return true;
}
//括号匹配算法
bool bracketCheck(char str[]){
    SqStack S;
    InitStack(S);
    for(int i = 0;i != '\0';i++){
        if(str[i] == '('||str[i] == '['||str[i] =='{'){
            Push(S,str[i]);
        }else{
            if(StackEmpty(S))
            return false;
        
        char topElem;
        Pop(S,topElem);
        printf("%d",topElem);
        if(str[i] == ')' && topElem != '(')
            return false;
        if(str[i] == ']' && topElem != '[')
            return false;
        if(str[i] == '}' && topElem != '{')
            return false;
        }
    }
    return StackEmpty(S);
}

int main(){
//    int flag;
//    char str[] = "{{{}}}";

//    flag = bracketCheck(str);
//   printf("%d",flag);
    //printf("%d",bracketCheck(str,))
    //printf("%d",bracketCheck("{{{}}}",6))
    return 0;
}