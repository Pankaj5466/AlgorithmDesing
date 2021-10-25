#include<unordered_map>
#include<iostream>
#include<vector>
#include<map>
using namespace std;

map<pair<int,int>,int> mMap;
//int mem[MAX_PRICE][MAX_LEN];

//OBSERVE: its unbounded knapsnac 
//Youtbue: https://www.youtube.com/watch?v=SZqAQLjDsag
int maxCutCost(int idx, const vector<int>& price,const vector<int>&length, int aLen)
{
    if(idx>=price.size())
        return 0;
    if(aLen <=0)
        return 0;
    
    if(mMap.find({idx,aLen}) != mMap.end())
        return mMap[{idx,aLen}];
    
    int inclusive = 0;
    int exclusive = 0;
    if((aLen - length[idx]) >= 0) //check if aLen sufficent to cut by length[idx]
    {
        inclusive = price[idx] + maxCutCost(idx,price,length,aLen-length[idx]); //not f(idx, ..)  is called instad 0f o f(idx+1) as picesame length piece can be cut any number of time
        exclusive = maxCutCost(idx+1,price,length,aLen);
    }
    else
    {
        exclusive = maxCutCost(idx+1,price,length,aLen);
    }

    int rVal = max(inclusive,exclusive); //we need to maximize profit
    mMap[{idx,aLen}] = rVal;
    return rVal; 
}

class Solution{
  public:
    int cutRod(vector<int> price, int n) 
    {
        vector<int> priceVec(price.begin(),price.begin()+n);
        vector<int> length; //When 2nd paramete is not given, then create it
        for(int i=1;i<=n;i++)
            length.push_back(i);
        
        mMap = {};
        int ans  = maxCutCost(0,priceVec,length,n);
        return ans;
    }
};/*
8
3 5 8 9 10 17 17 20
*/

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}  // } Driver Code Ends