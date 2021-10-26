#include<iostream>
#include<vector>
using namespace std;


//Guide: https://brilliant.org/wiki/egg-dropping/
//Practice link: https://leetcode.com/problems/super-egg-drop/

//n eggs and k floor
int mem[110][10010];
typedef long long int lli;
int findMinDropRecursive(int n,int k)
{
    if(n==1)
        return k;
    if(k == 0)
        return 0;
    if(k==1)
        return 1;

    if(mem[n][k] != -1)
        return mem[n][k];
    int minTry = INT_MAX;

    for(int t=1;t<=k;t++)
    {
        int breakAtTFloorCount = findMinDropRecursive(n-1,t-1);
        int NotBreakAtTFloorCount = findMinDropRecursive(n,k-t);

        minTry = min(minTry , 1 + max(breakAtTFloorCount,NotBreakAtTFloorCount));
    }

    mem[n][k] = minTry;
    return minTry;
}

void pritVector(vector<vector<lli>> dp);

class Solution {
    //DP walkThrough: https://www.youtube.com/watch?v=xsOCvSiSrSs
    int superEggDropDP(int NEgg,int NFloor)
    {

        int NRow = NEgg+1;
        int NCol = NFloor + 1;
        vector<vector<lli>> dp(NRow,vector<lli>(NCol,0));
        
        for(int j=1;j<NCol;j++) //Fill base case with '1' egg and 'j' tryout avaiable
            dp[1][j] = j; // f(1,k) = k
#if 1       
        for(int i=1;i<NRow;i++) //Fill base case with '1' tryout and i eggs
            dp[i][1] = 1;
        dp[1][0] = 0;
#endif
        
        //f(d,n) = 1 + d(d-1,n-1) + f(d-1,n); //1+ eggBreak + eggDoNotBreak
        for(int i=2;i<NRow;i++) //Egg '0' and '1' were base case, which already filled
        {
            for(int j=2;j<NCol;j++) //Base. cases were '0' tryout and '1' tryout maximum distance. Which already filled. Now, we we find tryout greator than 2
            {
                dp[i][j] = dp[i-1][j-1] + dp[i-1][j] + 1;
            }
        }
        
        //Dp Calculated 
        //do linear or binary search in column 'n'
        //i.e we have data when we have n eggs, and d number of experiment to try out.  We will pick experiment where we first reach 'NFloor'
#if 1      
        cout<<"DP Formed is\n";
        pritVector(dp);
        cout<<endl;
 #endif       
        vector<lli> tvec = dp[NEgg]; //tvec will be fllor we could cover in jth Experiment
        //Linear Search 
        int ansTry = 0;
        for(int i=0;i<tvec.size();i++)
        {
            if(tvec[i] >= NFloor)
            {
                ansTry = i;
                break;
            }
        }
        return ansTry;
    }
    
    int superEggDropPascalTraiangleRelation(int NEgg, int NFloor)
    {
        //ADVANCE: TO-DO:
        return 0;
    }
    
public:
    int superEggDrop(int egg, int floor) 
    {
    //    memset(mem,-1,sizeof(mem));
   //     return findMinDrop(egg,floor);
        
        int ans = superEggDropDP(egg,floor);
        return ans;
    }
};

void pritVector(vector<vector<lli>> dp)
{
    for(int i=0;i<10 && i<dp.size();i++)
    {
        for(int j=0;j<10 && j<dp[0].size();j++)
        {
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
}
int main()
{

    return 0;
}