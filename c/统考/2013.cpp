#include<iostream>
#define MAXSIZE 7//定义数组最大长度
using namespace std;
int Bowyer_Moore(int A[]){
    int candidate;
    int cout = 0;
    for(int i = 0;i < MAXSIZE;i++){
        if(cout == 0){
            candidate = A[i];
            cout = 1;
        }else if(A[i] == candidate){
            cout++;
        }else{
            cout--;
        }
    }
    cout = 0;
    for(int i = 0; i <MAXSIZE;i++){ //重新统计投票
        if(candidate == A[i])
        cout++;
    }
    if(cout > MAXSIZE / 2){
        return candidate;
    }
    else return -1;
}
int main(){
    int A[] = {6,5,5,4,5,5,7};
    cout << Bowyer_Moore(A) << endl;
    return 0;
}