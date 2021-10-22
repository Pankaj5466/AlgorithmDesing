//problem link: https://practice.geeksforgeeks.org/problems/coin-change2448/1
#include<iostream>
#include<vector>
#include<string>
using namespace std;
typedef long long int lli;

#define MAX_COIN_COUNT 1000
#define MAX_SUM 1000
#define LIMIT_COUNT 1000

int mem[MAX_COIN_COUNT][MAX_SUM][LIMIT_COUNT]; //better to use map to avoid uncessary init

class Solution {

    //SOLUTION not verifed by online judge. so below is treat below just as pesudo code
    lli countWasyRecursiveLimitedNumberOfCoin(int idx, int tSum, const vector<int>&arr,vector<int>& limit)
    {
        if(tSum == 0)
            return 1;
    
        if(tSum < 0)
            return 0;

        if(idx >= arr.size())
            return 0;

        int l = limit[idx];
        if(mem[arr[idx]][tSum][l] != -1)
            return mem[arr[idx]][tSum][l];
        
        int iSize = 0;
        if(limit[idx] > 0)
        {
            limit[idx]--; //decrease limit by 1
            iSize = countWasyRecursiveLimitedNumberOfCoin(idx,tSum-arr[idx],arr,limit); 
            limit[idx]++; //backtrack
        }

        int eSize = countWasyRecursiveLimitedNumberOfCoin(idx+1,tSum,arr,limit);

        mem[arr[idx]][tSum][l] = eSize + iSize;
        return mem[arr[idx]][tSum][l];
    }

    lli countWaysRecurisve(int idx, int tSum,const vector<int>&arr)
    {
        if(tSum == 0)
            return 1;
        if(tSum < 0)
            return 0;
        if(idx>=arr.size())
            return 0;
        
        int iSize = countWaysRecurisve(idx,tSum-arr[idx],arr); //OBSERVE1: include idx , REPETIVELY (notice we do not icreae idx here)
        //OBSERVE3: in sumbset sum. we were allowed to include the number only 1 numbe of time ==> once included, we need to go to next element.
        //but as in coinChange , we can pick same element unlimited number of time, hence while including, we DO NOT ADVACE idx BY 1

        //OBSERVATION4: subsetSum = CointChange where each every coin is present only 1 number of time.
        int eSize = countWaysRecurisve(idx+1,tSum,arr); //OBSERVE2: do not include idx coint

        return iSize+eSize;
    }

    lli countWaysDP(const vector<int>& arr, int sum)
    {
        int NRow = arr.size();
        int NCol = sum;

        NRow++;
        NCol++;

        vector<vector<lli>> dp(NRow, vector<lli>(NCol));

        for (int j = 1; j < NCol; j++)
            dp[0][j] = 0;
        for (int i = 1; i < NRow; i++)
            dp[i][0] = 1;

        dp[0][0] = 1;

        for (int i = 1; i < NRow; i++)
        {
            for (int j = 1; j < NCol; j++)
            {
                lli takingCurrentOneMoreTime = (j - arr[i - 1] >= 0) ? dp[i][j - arr[i - 1]] : 0; //MUST_OBSERVE: when we do NRow++, then when accessing orignal arr or original string. 
                //Then we must take care the fact 1st data of arr is at '0', but our matrix 1st data is at '1'.
                //So, conversion from matrix index to arr/string result in -1. (ex arr[i-1] OR s1[i-1] ,s2[j-1] in substring problem
                lli notTakingCurrent = dp[i - 1][j];

                dp[i][j] = takingCurrentOneMoreTime + notTakingCurrent;
            }
        }
#if 0
        cout << "dp is\n";
        printMatrix(dp);
        cout << endl;

#endif
        return dp[NRow - 1][NCol - 1];
    }
public:
    long long int count(int S[], int n, int sum)
    {

        int rVal =  countWaysDP(vector<int>(S, S + n), sum);
        printf("countWaysDP = %d\n",rVal);

        rVal =  countWaysRecurisve(0,sum,vector<int>(S, S + n));
        printf("countWaysRecurisve = %d\n",rVal);

        return rVal;
    }
};

#define MAX_ARR 100000
int main() {
    freopen("sample_input.txt","r",stdin);
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        int arr[MAX_ARR];
        for (int i = 0; i < m; i++) cin >> arr[i];
        Solution ob;
        cout << ob.count(arr, m, n) << endl;
    }

    return 0;
}

//Variation2
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

//Variation3: print all ways of variation2
void printCoinWayAllPermutation(int idx, int tSum,vector<int>& arr,vector<int>&tans)
{
    if(tSum == 0)
    {
       for(auto k:tans)
            cout<<k<<" ";
        cout<<endl;    
    }
    if(tSum < 0)
        return;
    if(idx>=arr.size())
        return;
    
    int  count = 0;
    for(int i=idx;i<arr.size();i++)
    {
        tans.push_back(arr[i]);
        printCoinWayAllPermutation(idx,tSum-arr[i],arr,tans);
        tans.pop_back();
    }
}

void printMatrix(vector<vector<lli> >& vec1)
{
    for (int i = 0; i < vec1.size(); i++)
    {
        for (int j = 0; j < vec1[0].size(); j++)
        {
            printf("%lld ", vec1[i][j]);
        }
        printf("\n");
    }
}