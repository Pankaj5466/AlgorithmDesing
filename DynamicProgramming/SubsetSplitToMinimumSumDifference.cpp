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
int targetSum(int idx,  const vector<int>&arr,lli sum,const lli TOTAL_SUM)
{
    if(idx >=arr.size())
        return 0;
    
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
    
    include  = targetSum(idx+1,arr,sum+arr[idx],TOTAL_SUM);
 
    exclude = targetSum(idx+1,arr,sum,TOTAL_SUM);
 
    lli rVal =  min(include,exclude);
    mMap[{idx,sum}] = rVal;
    
    return rVal;
}
 
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
    lli ans = targetSum(0,vec,tSum,total_sum);
 
  //  printf("Desired Sum = %d\n",ans);
    cout<<ans<<endl;
    return 0;
}