//Problem Link: https://leetcode.com/problems/minimum-increment-to-make-array-unique/
#include<iostream>
#include<vector>
using namespace std;
const int MAX_NUM = 5* 100000 + 10;

int incrementalIncrement(vector<int>&num)
{
    vector<vector<int>> mMap(MAX_NUM,vector<int>());
    
    for(int i=0;i<num.size();i++)
    {
        int n = num[i];
        mMap[n].push_back(i); //save all places where n occurrs
    }
    
    int moves = 0;
    for(int i=0;i<mMap.size();i++)
    {
        vector<int> &vec = mMap[i];
        if(vec.size() == 0 || vec.size() ==1)
            continue;
        
        
        int n = i;
        for(int j=1;j<vec.size();j++) //just leave 1 element here, and increment all by 1
        {
           mMap[n+1].push_back(j); 
            moves++;
        }
    }
        
    return moves;
}

int incrementalCountIncrement(vector<int>&num)
{
    vector<int> count(MAX_NUM);
    
    for(int i=0;i<num.size();i++)
    {
        int n = num[i];
        count[n]++; //number of occurrane of 'n' (no need to store exact place of occurrance)
    }
    
    int moves = 0;
    for(int i=0;i<MAX_NUM;i++)
    {
       
        if(count[i] == 0 || count[i] == 1)
            continue;
        
        
        int n = i;
        int extra_element = count[i]-1;
        count[n+1] += extra_element;
        
        moves = moves + extra_element; //each extra elment need to be incremented by 1
       // count[i] = count[i] - extra_element;
        //or better as '1'
        count[i] = 1;
    }
        
    return moves;
}

int sortFirst(vector<int>& num)
{
    sort(num.begin(),num.end());
    
    if(num.size()<=1)
        return 0;
    
    int moves = 0;
    for(int i=1;i<num.size();i++)
    {
        if(num[i] > num[i-1])
            continue; //both unique
        
        //if reahed here means we must change arr[i]
        #if 0
             //If reached here 'i' need increment
             int increment_by = num[i-1] - num[i] + 1;
        
            num[i] = num[i] + increment_by;
            moves = moves + increment_by;
        #else
            
            int oVal = num[i];
            num[i] = num[i-1] + 1; //we need to change 'i', to make differnet than 'i-1' we can incremt by +1 of previous vlaue
            moves = moves + ( num[i] - oVal); //i is incrementd by (new-old)
        
        #endif
        
    }
    
    return moves;
}

class Solution {
    

public:
    int minIncrementForUnique(vector<int>& nums) 
    {
        return sortFirst(nums);
    }
};

int main()
{

    return 0;
}