#define MAXLEN 255
#include<stdio.h>
#include<iostream>
using namespace std;
typedef struct{
    char[] ch;
    int length;
}SString;
void printString(SString S){
    for(int i = 0;i < S.length;i++){
        cout << S.ch[i];
    }
    cout << endl;
}
bool StrEmpty(SString S){
    return S.length == 0;
}

