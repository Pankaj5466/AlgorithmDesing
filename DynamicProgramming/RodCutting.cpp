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

int maxCutCostDP(const vector<int>& price,vector<int> length)
{
    int NRow = price.size();
    int NCol = length.size();
    NRow++;
    NCol++;
    
    vector<vector<int>> dp(NRow,vector<int>(NCol,0)); 
    for(int j=0;j<NCol;j++)
        dp[0][j] = 0; //case when we do not want to cut
    
    for(int i=0;i<NRow;i++)
        dp[i][0] = 0; //when rod length is '0' we could not make any profit

    for(int i=1;i<NRow;i++)
    {
        for(int j=1;j<NCol;j++)
        {
            int inclusive = 0;
            int exclusive = 0;
            if(j-length[i-1] >= 0)
                inclusive = price[i-1] + dp[i][j-length[i-1]];  //OBSERVE2: in inclusive case, current ans will depedent upon Rod Length of 'Current Total Rod Len(==j)- Length We gain if picked current set(a2)
                                                                //OBSERVE3: As usual, when NRow++,NCol++ ==> to access original data we need to handle offset of '-1'
            exclusive = dp[i-1][j];

            dp[i][j] = max(inclusive,exclusive);
        }
    }
    
    return dp[NRow-1][NCol-1];
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
        printf("Recusive maxCutCost = %d\n",ans);

        ans = maxCutCostDP(priceVec,length);
        printf("DP-TOPDOwn maxCutCost = %d\n",ans);
        return ans;
    }
};/*
8
3 5 8 9 10 17 17 20
*/

// { Driver Code Starts.

int main() {
    int t=1;
   // cin >> t;
    while (t--) {
        vector<int> a{3,5,8,9,10,17,17,20};
        int n = a.size();

        Solution ob;

        int ans = ob.cutRod(a, n);
        
        

    }
    return 0;
}  // } Driver Code Ends