//Problem Link: https://practice.geeksforgeeks.org/problems/merge-sort/1

#include<iostream>
#include<vector>
using namespace std;


int findMax(int l, int r, const vector<int>& arr)
{
    if(l==r)
        return arr[l];
    
    if(l+1 == r) //exactly 2 element left ==> compare them here
    {   
        return (arr[l]>=arr[r]) ? arr[l] : arr[r];
    }

    int mid = (r-l)/2 + l;

    if(arr[l] < arr[mid] && arr[mid] > arr[r]) //this is the inflection point (cur element is max for left and right)
        return arr[mid]; 
    
    if(arr[mid-1] < arr[mid] && arr[mid] < arr[mid+1]) //left is less, right is more ==> we are in increasign half of array => max will be at right side
        return findMax(mid+1,r,arr);
    else
        return findMax(l,mid-1,arr);
    //OBSERVE: mid is not passed to any child call, as mid check condition is already handled
}

int main()
{
    vector<int> arr {1, 3, 50, 10, 9, 7, 6};
    int size = arr.size();

    int ans = findMax(0,size-1,arr);
    cout<<"Max is = "<<ans<<endl;
    return 0;
}