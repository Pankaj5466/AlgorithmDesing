//Setup for Window https://code.visualstudio.com/docs/cpp/config-mingw 
#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;

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

void test()
{
    
    int size,sum;
    cin>>size>>sum;

    vector<int> arr(size);
    for(int i=0;i<size;i++)
        cin>>arr[i];
    
    int way = countCoinWayAllPermutation(0,sum,arr);
    printf("ways is = %d\n",way);

}

//Variaton1: https://stackoverflow.com/questions/32538294/how-do-i-maximise-the-sum-in-this-game
//https://brilliant.org/wiki/egg-dropping/
int maxScore(int l, int r, const vector<int> &arr)
{
    if(l>r)
        return 0;
    if(l==r)
        return arr[l];
    

    //Player1 pick left side
    int t[4];
    t[0]  = maxScore(l+2,r,arr); //Player2 user chose l+1 (so our player 1 is left with array of [l+2,r])
    t[1]  = maxScore(l+1,r-1,arr); //Player2 choses r (so our player1 is left with array of [l+1,r-1])
    int lScore = arr[l] + max(t[0],t[1]); //Target is to minimize Player2 Score

    //Player2 Pick right side element
    t[2] = maxScore(l,r-2,arr); //Player2 also picks right element from remaining array
    t[3] = maxScore(l+1,r-1,arr); //Player1 pick rom left , from remainign array

    int rScore = arr[r] + max(t[2],t[3]);

    return max(lScore,rScore);
}

int maxScoreTwo(int l, int r, const vector<int> &arr)
{
    if(l>r)
        return 0;
    if(l==r)
        return arr[l];
    


    int t[4];
    t[0]  = arr[l+1] +  maxScoreTwo(l+2,r,arr); //Player2 user chose l+1 (so our player 1 is left with array of [l+2,r])
    t[1]  =arr[r] +  maxScoreTwo(l+1,r-1,arr); //Player2 choses r (so our player1 is left with array of [l+1,r-1])
    int lScore = arr[l] + min(t[0],t[1]); //    //Player1 pick left side + Target is to minimize Player2 Score


    t[2] = arr[r-1] + maxScoreTwo(l,r-2,arr); //Player2 also picks right element from remaining array
    t[3] = arr[l] +  maxScoreTwo(l+1,r-1,arr); //Player1 pick rom left , from remainign array

    int rScore = arr[r] + min(t[2],t[3]); //  Player1 Pick right side element + minimize Player2 score

    return max(lScore,rScore);
}

int main(int argc, char** argv)
{

   // test();
   vector<int> arr{1,5,3,7,10};
    int ans = maxScoreTwo(0,arr.size()-1,arr);
    int tSum = 0;
    for(auto k:arr)
        tSum = tSum + k;


    printf("Player 1 MaX pOSSBILE SCORe = %d\n",ans);
    printf("Difference b/w score when both play optimal is = %d\n",tSum - ans);


    return 0;
}
    
