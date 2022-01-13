//Practice Link: https://leetcode.com/problems/max-number-of-k-sum-pairs/
#include<iostream>
#include<vector>
#include<set>
#include<map>
#include<algorithm>
using namespace std;

class Solution {
    int generateAllPair(vector<int>& arr, int k)
    {
        int count = 0;
        
        int size = arr.size();
        
        set<int> mSet;
        
        for(int i=0;i<size;i++)
        {
            for(int j=i+1;j<size;j++)
            {
               if(mSet.find(i) != mSet.end() || mSet.find(j) != mSet.end()) //that index already accounted for
                   continue;
                
                if(arr[i] + arr[j] == k)
                {
                    count++;
                    mSet.insert(i);
                    mSet.insert(j);
                }
            }
        }
        return count;
    }
    
    int hashBased(vector<int> &arr , int k)
    {
        int count = 0;
        map<int,int> mMap;
        
        int size = arr.size();
        for(int i=0;i<size;i++)
        {
            int num1 = arr[i];
            int num2 = k - arr[i];
            if(mMap[num2] > 0)
            {
                count++;
                mMap[num2]--; //one valid pair is  arr[i] + arr[j]
            }
            else
            {
                mMap[num1]++; //num1 not taken, and its count is increased
            }
        }
        
        return count;
    }
    
    int twoPointer(vector<int> &arr, int k)
    {
        int count = 0;
        
        sort(arr.begin(),arr.end());
#ifdef DEBUG
        cout<<"Array after sorting is\n";
        for(auto k:arr)
            cout<<k<<" ";
        cout<<endl;
#endif
        int size = arr.size();
        int l=0,r=size-1;
        
        while(l<r)
        {
            int sum = arr[l] + arr[r];
        //    printf("(%d,%d) [%d]\n",l,r,sum);
            
            if(sum == k)
            {
                count++;
                l++;
                r--;
            }
            else if(sum >  k) //Need to decrease the sum
            {
               r--; 
            }
            else //need to increase the sum
            {
                l++;
            }
        }
        
        return count;
    }
public:
    int maxOperations(vector<int>& nums, int k)
    {
       // return generateAllPair(nums,k);
       // return hashBased(nums,k);
        return twoPointer(nums,k);
    }
};                                  

int main()
{

    return 0;
}