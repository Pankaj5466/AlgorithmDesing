#include<iostream>
#include<vector>
using namespace std;

//find occuurance of elemnt in sorted array from right
int findIndex(int l, int r, const vector<int>&arr, int target)
{
    if(l>r)
        return r;
    
    int mid = l + (r-l)/2;
    
    if(target < arr[mid])
        return findIndex(l,mid-1,arr,target);
    if(target > arr[mid])
        return findIndex(mid+1,r,arr,target);
    
    //if duplicate find , then we need to find the upperone
    int index1 = mid;
    int index2 =  findIndex(mid+1,r,arr,target);
    return max(index1,index2);
}

int main()
{  
    vector<int> vec{1,3,5,6,7,7,7,9,9,9,20};

    int size = vec.size();
    int k = -1;
    int i = findIndex(0,size-1,vec,k);
    printf("%d found at = %d\n",k,i);



    return 0;
}