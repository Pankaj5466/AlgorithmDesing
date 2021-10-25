//Problem Link: https://practice.geeksforgeeks.org/problems/0-1-knapsack-problem0945/1#
#include<iostream>
#include<vector>
using namespace std;

const int MAX_VALUE = 3000;
const int MAX_WEIGHT = 1010;
int mem[MAX_VALUE][MAX_WEIGHT];

int bestProfitKnapSack(int idx,const  vector<int> value,const  vector<int> weight, int aW)
{
    if(idx>=value.size())
        return 0; //no iteam avaialbe
    if(aW <= 0)
        return 0; //KnapSack if full
    
    if(mem[idx][aW] != -1)
        return mem[idx][aW];
    
    int inclusive = 0;
    int exclusive = 0;
    
    if(aW-weight[idx] >= 0)
        inclusive = value[idx] + bestProfitKnapSack(idx+1,value,weight,aW - weight[idx]);
    
    exclusive = bestProfitKnapSack(idx+1,value,weight,aW);
    
    int rVal = max(inclusive,exclusive);
    mem[idx][aW] = rVal;
    
    return rVal;
}

//Top-Down?
/*
int inclusive = value[i-1] + dp[i-1][j - weight[i-1]] //For unbounded it would be value[i-1] + dp[i][j-weight[i-1] 
int exclusive = dp[i-1][j]

dp[i][j] = max(inclusive,exclusive)
*/
int main()
{
    return 0;
}