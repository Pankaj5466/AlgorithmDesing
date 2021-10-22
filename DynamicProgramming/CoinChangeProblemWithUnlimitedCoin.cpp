//problem link: https://practice.geeksforgeeks.org/problems/coin-change2448/1
#include<iostream>
#include<vector>
#include<string>
using namespace std;
typedef long long int lli;

class Solution {

    lli countWaysRecurisve(int idx, int tSum,const vector<int>&arr)
    {
        if(tSum == 0)
            return 1;
        if(tSum < 0)
            return 0;
        if(idx>=arr.size())
            return 0;
        
        int iSize = countWaysRecurisve(idx,tSum-arr[idx],arr); //OBSERVE1: include idx , REPETIVELY (notice we do not icreae idx here)
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