#include "Queue.h"
#include <stdbool.h>
int main(){
    bool flag = NULL;
    int value = 0;
    SqQueue q;
    InitQueue(q);
    int data;
    for(int i = 0; i < 5;i++){
        cin >> data;
        EnQueue(q,data);
    }
    PrintQueue(q);
    cout << endl;
    DeQueue(q,value);
    PrintQueue(q);
    cout << endl;
    EnQueue(q,6);
    PrintQueue(q);
    
    return 0;
}