#include<iostream>
using namespace std;

void maxHeapify(int arr[], int len, int index)  // 构建最大堆
{
    int left = index * 2 + 1;
    int right = index * 2 + 2;
    int maxid = index;
    if(arr[maxid] < arr[left] && left < len){
        maxid = left;
    }
    if(arr[maxid] < arr[right] && right < len){
        maxid = right;
    }
    if(maxid != index){
        swap(arr[maxid], arr[index]);
        maxHeapify(arr, len, maxid);
    }
}

void heapSort(int arr[], int size){
    for(int i = size/2 - 1; i >=0; i--){ //先构建成最大堆
        maxHeapify(arr, size, i);
    }
    for(int i = size - 1; i >=1; i--){  // 堆排序，将最大的放最后
        swap(arr[0], arr[i]);
        maxHeapify(arr, i, 0);
    }
}

int main()
{
    int array[8] = {8, 1, 14, 3, 21, 5, 7, 10};
    heapSort(array, 8);
    for(auto it: array)
    {
        cout<<it<<endl;
    }
    return 0;
}
