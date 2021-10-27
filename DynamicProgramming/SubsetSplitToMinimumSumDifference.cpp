//PROBLEM LINK: https://cses.fi/problemset/task/1623/
//NOTE: Above link is super cool , as it have question for all standard problem!!
//Just solve it 2,3 times while understading for interview problem
#include<iostream>
#include<vector>
#include<map>
using namespace std;
typedef unsigned long long int lli;
//typedef int lli;
 
std::map<pair<lli,lli>,lli> mMap;
 
int cSum = 0;
int subsetSumDifferenceMin(int idx,  const vector<int>&arr,lli sum,const lli TOTAL_SUM)
{
    if(idx >=arr.size())
        return 0;
    
    //NOTE: Question is still generation of subset.
    /*
    Think like, we could have two set here set1, set2. with set1 + set2 = arr
    Now we could perform any operation or validity on both the subset.
    //SO key takeaway is that, this question is still brute force, but now we need to check check both subset for some condition. (whers in case of subsetSum we cared about onlly 1 subset!)
    */
    if(idx == arr.size()-1) //sum is final here
    {
        lli s1 = sum;
        lli s2 = TOTAL_SUM - s1;
/*
        if(s1 == s2) //Equal Sum partition
            return true;
*/
 
        if(s1>s2)
            return  s1-s2;
        else
            return s2-s1;
 
    }
   
    if(mMap.find({idx,sum}) != mMap.end())
        return mMap[{idx,sum}];
 
    lli include = 0,exclude = 0;
    
    include  = subsetSumDifferenceMin(idx+1,arr,sum+arr[idx],TOTAL_SUM);
 
    exclude = subsetSumDifferenceMin(idx+1,arr,sum,TOTAL_SUM);
 
    lli rVal =  min(include,exclude);
    mMap[{idx,sum}] = rVal;
    
    return rVal;
}
 
 int subsetSumDifferenceTopDownDP(const vector<int>& arr)
 {
     int TOTAL_SUM = 0;
     for(int i=0;i<arr.size();i++)
        TOTAL_SUM = TOTAL_SUM + arr[i];

     int NRow = arr.size() + 1;
     int NCol = TOTAL_SUM;

     NRow++;
     NCol++;
     vector<vector<bool>> dp(NRow,vector<bool>(NCol,false));

    for(int i=1;i<NRow;i++)
        dp[i][0] = true;
    
    for(int j=1;j<NCol;j++)
        dp[0][j] = false;
    
    dp[0][0] = true;

    for(int i=1;i<NRow;i++)
    {
        for(int j=1;j<NCol;j++)
        {
            int inclusive = (j-arr[i] >= 0) ? dp[i-1][j-arr[i]] : 0;
            int exclusive = dp[i-1][j];

            dp[i][j] = inclusive || exclusive;
            
        }
    }
    //OBSERVE above logic is same as subsetSum (i.e we will first try if 1 subset able to make given sum or not)
    //then in 2nd step, we would check dp[n][x] to check if x is formed by set1 or not

    //OBSERVE: now dp[n][j] would be true if set1 sum is 'j'
    //==> set2 sum at same place = TOTAL_SUM - set1

    int minDiff = INT_MAX;
    //Now pick min value
    for(int j=0;j<NCol;j++)
    {
        if(dp[NRow-1][j] == true)
        {
            int sum1 = j;
            int sum2 = TOTAL_SUM - j;
            minDiff = min(minDiff, abs(sum1-sum2));
        }
    }
    return minDiff;
 }
 
//OBSERVE4: an space optimized version of O(TOTAL_SUM) also exist. check gfg for same
int main()
{
    //vector<int> vec{3,2,7,4,1};
   // vector<int> vec{15,6,11,5};
   int arr_size=0;
   cin>>arr_size;
 
    vector<int> vec;
   for(int i=0;i<arr_size;i++)
   {
       int t;
       cin>>t;
 
       vec.push_back(t);
   }
 
    lli total_sum = 0;
    for(auto k:vec)
        total_sum += k;
    
    lli tSum = 0;
    lli ans = subsetSumDifferenceMin(0,vec,tSum,total_sum);
    
    printf("subsetSumDiffereneRec = %d\n",ans);
    ans = subsetSumDifferenceTopDownDP(vec);
    
    printf("subsetSumDiffereneDP = %d\n",ans);

    return 0;
}