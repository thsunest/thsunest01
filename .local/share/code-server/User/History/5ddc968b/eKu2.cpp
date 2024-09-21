#include<stdio.h>
int main(){
    int a[10];
    for(int i = 0;i < 5;i++){
        scanf("%d",&a[i]);
    }
    for(int i = 0; i < 5;i++){
        printf("%d",a[i]);
    }
    printf("%d",a[2]);
    return 0;
}