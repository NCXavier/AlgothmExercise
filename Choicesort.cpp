#include <iostream>
#include <vector>
using namespace :: std;


void ChoiceSort(vector<int> &ilist){
    int size = ilist.size();
    if (size > 0){
        for(int i=1; i<size; i++){
            int j = i - 1;
            int temp = ilist[i];
            while (j>=0 & ilist[j] > temp){
                    ilist[j+1] = ilist[j];
                    j--;
                }
            ilist[j+1] = temp;
            }
        }
    }

int main()
{
    vector<int> ilist= {3,2,1,5,5};
    ChoiceSort(ilist);
    for(int i = 0; i<ilist.size(); i++)
        cout<<ilist[i]<<endl;
    return 0;
}
