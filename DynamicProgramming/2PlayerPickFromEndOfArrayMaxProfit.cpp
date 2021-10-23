//Practice Problem Link: https://practice.geeksforgeeks.org/problems/optimal-strategy-for-a-game-1587115620/1
#include<iostream>
#include<vector>
using namespace std;


int maxScore(int l, int r, const vector<int> &arr)
{
    if(l>r)
        return 0;
    if(l==r)
        return arr[l];
    if(l+1 ==r )
        return max(arr[l],arr[r]);


    int t[4];
    t[0]  = arr[l+1] +  maxScore(l+2,r,arr); //Player2 user chose l+1 (so our player 1 is left with array of [l+2,r])
    t[1]  =arr[r] +  maxScore(l+1,r-1,arr); //Player2 choses r (so our player1 is left with array of [l+1,r-1])
    int lScore = arr[l] + max(t[0],t[1]); //    //Player1 pick left side + Target is to minimize Player2 Score


    t[2] = arr[r-1] + maxScore(l,r-2,arr); //Player2 also picks right element from remaining array
    t[3] = arr[l] +  maxScore(l+1,r-1,arr); //Player1 pick rom left , from remainign array

    int rScore = arr[r] + max(t[2],t[3]); //  Player1 Pick right side element + minimize Player2 score

    return max(lScore,rScore);
}

int main()
{
   vector<int> arr{5,3,7,10};
    int ans = maxScore(0,arr.size()-1,arr);
    int tSum = 0;
    for(auto k:arr)
        tSum = tSum + k;


    printf("Player 1 MaX pOSSBILE SCORe = %d\n",ans);
    printf("Difference b/w score when both play optimal is = %d\n",tSum - ans);


    return 0;
    }