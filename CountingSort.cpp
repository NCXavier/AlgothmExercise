#include<iostream>
# define MAXNUM  10

using namespace std;

int* countingSort(int a[],int length, int k){
    int c[k+1];
    cout<<"length"<<length<<endl;
    int * b = new int [length];
    for(int i = 0; i<=k; i++ ){
        c[i] = 0;
    }
    for(int i = 0; i < length; i++){
        c[a[i]] = c[a[i]] + 1; // 计数
    }
    for(int i = 1; i <= k; i++){
        c[i] = c[i] + c[i-1]; // 遍历数组求和
    }

    for(int i = 0; i <= k; i++){
        cout<<i<<" "<<c[i]<<endl;
    }
    for(int i = length-1; i>=0; i--){
        b[c[a[i]]-1] = a[i]; // 索引位要减1
        c[a[i]] -= 1;
    }
    for(int i = 0; i<length; i++)
        cout<<"rank"<<i<<" "<<b[i]<<endl;
    return b;
}

int main(){
    int a[] = {2,5,3,0,2,3,0,3};
    int length = sizeof(a)/sizeof(int);
    int *b = countingSort(a, length, MAXNUM);
    for(int i = 0; i<length; i++){
        cout<<i<<'\t'<<b[i]<<endl;
    }
}
