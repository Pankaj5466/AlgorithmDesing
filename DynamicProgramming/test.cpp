//Setup for Window https://code.visualstudio.com/docs/cpp/config-mingw 
#include<iostream>
#include<vector>
using namespace std;

//https://leetcode.com/problems/combination-sum-iv/
//aka permutation ways
int countCoinWayAllPermutation(int idx, int tSum,vector<int>& arr)
{
    if(tSum == 0)
        return 1;
    if(tSum < 0)
        return 0;
    if(idx>=arr.size())
        return 0;
    
    int  count = 0;
    for(int i=idx;i<arr.size();i++)
    {
        count += countCoinWayAllPermutation(idx,tSum-arr[i],arr);
    }

    return count;

}

void test()
{
    
    int size,sum;
    cin>>size>>sum;

    vector<int> arr(size);
    for(int i=0;i<size;i++)
        cin>>arr[i];
    
    int way = countCoinWayAllPermutation(0,sum,arr);
    printf("ways is = %d\n",way);

}
int main(int argc, char** argv)
{

    test();

    return 0;
}
    
