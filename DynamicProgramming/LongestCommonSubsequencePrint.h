#include<iostream>
#include<vector>
#include<string>
#include<stdio.h>
using namespace std;

string printLCS(string s1, string s2, const vector<vector<int>>& dp)
{

    int NRow = dp.size();
    int NCol = dp.size();

    string aS;
    for(int i=NRow-1 ; i>= 1;) //s1
    {
        for(int j=NCol-1; j>=1 ;) //s2
        {
            if(s1[i-1] == s2[j-1])
             {
                aS += s1[i-1];
                i--;
                j--;
             }
            else
            {
                if(dp[i-1][j] == dp[i][j]) //Determine from where it came
                    i--;
                else
                    j--;
            }
        }
    }

   reverse(aS.begin(),aS.end());
   return aS;
}