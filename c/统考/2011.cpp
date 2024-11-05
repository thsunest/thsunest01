#include<iostream>
using namespace std;
#define MAXSIZE 5 //数组最大长度
int sort(int A[],int B[]){
    int a = 1;//指向A，B,C数组的第一个元素
    int b = 1;//指向A，B,C数组的第一个元素
    int c = 1;//指向A，B,C数组的第一个元素
    // int temp; //临时存放元素
    int C[2 *MAXSIZE];
    while(c != 2 * MAXSIZE){ //当C数组未满时
        while(c != 2 * MAXSIZE && A[a] <= B[b]){
            C[c++] = A[a];
            a++;
        }
        while(c != 2 *MAXSIZE && B[b] <= A[a]){
            C[c++] =B[b];
            b++;
        }
    }
    return C[MAXSIZE];

}
int main(){
    int A [] = {0,3,5,7,9,12};
    int B [] = {0,8,10,11,13};
    cout << sort(A,B) << endl;
    

    return 0;
}