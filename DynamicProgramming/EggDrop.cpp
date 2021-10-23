#include<iostream>
using namespace std;


//Guide: https://brilliant.org/wiki/egg-dropping/
//n eggs and k floor
int findMinDrop(int n,int k)
{
    if(n==1)
        return k;
    if(k == 0)
        return 0;
    if(k==1)
        return 1;

    int minTry = INT_MAX;

    for(int t=1;t<=k;t++)
    {
        int breakAtTFloorCount = findMinDrop(n-1,k-1);
        int NotBreakAtTFloorCount = findMinDrop(n,k-t);

        minTry = min(minTry , 1 + max(breakAtTFloorCount,NotBreakAtTFloorCount));
    }

    return minTry;
}
int main()
{

    return 0;
}