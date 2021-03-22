#include <iostream>
#include <vector>

using namespace std;

#define MAXSUM 60000
/*
一个最大字串的分治算法
结构体定义参考：https://blog.csdn.net/u011477670/article/details/48575527
运行：g++ -std=c++11 maxSubArray.cpp
*/

// 定义一个结构体保存数据
typedef struct array_info_message  //储存子数组位置和加和的结构体
{
    int low;
    int high;
    int sum;
}array_info;

array_info findCrossArray(vector<int> array, int low, int mid, int hight){
  int leftsum = -MAXSUM;
  int tempsum = 0;
  int leftindex;
  for(int i = mid; i >= low; i--){
    tempsum += array[i];
    if (tempsum >= leftsum){
      leftsum = tempsum;
      leftindex = i;
    }
  }
  int rightsum = -MAXSUM;
  tempsum = 0;
  int rightindex;
  for(int i = mid + 1; i <= hight; i++){  // 加1
    tempsum += array[i];
    if(tempsum >= rightsum){
      rightsum = tempsum;
      rightindex = i;
    }
  }
  array_info result = {leftindex, rightindex, leftsum+rightsum};
  return result;
}

array_info findSubArray(vector<int> array, int low, int hight){
  if(low == hight){
       array_info result = {low, hight, array[low]};
       return result;
  }
  else
  {
      int mid = (hight + low) / 2;
      array_info leftsum= findSubArray(array, low, mid);
      array_info rightsum = findSubArray(array, mid+1, hight);  // 加1
      array_info midsum = findCrossArray(array, low, mid, hight);
      if(leftsum.sum >= rightsum.sum && leftsum.sum >= midsum.sum)
          return leftsum;
      else if(rightsum.sum >= leftsum.sum && rightsum.sum >= midsum.sum)
          return rightsum;
      else
          return midsum;
  }
}

int main()  // 主函数
{
  cout<<"test"<<endl;
  vector<int> array = {13,-3,-25,20,-3,-16,-23,18,20,-7,12,-5,-22,-4,7};
  array_info result = findSubArray(array, 0, array.size()-1);
  cout<< result.sum<<endl;
  return 0;
}
