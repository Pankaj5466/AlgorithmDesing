//Practice Problem Link: https://practice.geeksforgeeks.org/problems/optimal-strategy-for-a-game-1587115620/1
#include<iostream>
#include<vector>
using namespace std;

typedef long long int lli;
const int NRow  = 1000 +10;
const int NCol = NRow;
int mem[NRow][NCol];

lli maxScoreTwo(int l, int r, const vector<int> &arr)
{
    if(l>r)
        return 0;
    if(l==r)
        return arr[l];
    
    if(mem[l][r] != -1)
        return mem[l][r];

    lli t[4];
    t[0]  = maxScoreTwo(l+2,r,arr); //Maximum score of Player1 if Player2  chose l+1 (so our player 1 is left with array of [l+2,r])
    t[1]  = maxScoreTwo(l+1,r-1,arr); //Maximum score of Player1 if Player2 choses r (so our player1 is left with array of [l+1,r-1])
    lli lScore = arr[l] + min(t[0],t[1]); //    //Player1 pick left side + Choice Such that Player2 score is maximum.
    /*
    (Now after this game control will reach to player2, which he will PLAY TO WIN.
    Hence, he will NOT LET player1 pick max. He will force player1 to pick MIN . 
    So, that's why out of two scenerio. We need to add MIN only,as playe2 will force us to pick this(as he will maximize his profit by picking max for himself)
    */


    t[2] =  maxScoreTwo(l,r-2,arr); //Maximum score of Player1 if Player2 also picks right element from remaining array
    t[3] =  maxScoreTwo(l+1,r-1,arr); //Maximum score of Player1 if   Player2 pick rom left , from remainign array

    lli rScore = arr[r] + min(t[2],t[3]); //  Player1 Pick right side element + Player2 force us to pick min amoung rest of element

    int rVal = max(lScore,rScore);
    mem[l][r] = rVal;
    return rVal;
}

int main()
{
       for(int i=0;i<NRow;i++)
        for(int j=0;j<NCol;j++)
            mem[i][j] = -1;
               for(int i=0;i<NRow;i++)
        for(int j=0;j<NCol;j++)
            mem[i][j] = -1;
   vector<int> arr{5,3,7,10};
    int ans = maxScoreTwo(0,arr.size()-1,arr);
    int tSum = 0;
    for(auto k:arr)
        tSum = tSum + k;

 

    printf("Player 1 MaX pOSSBILE SCORe = %d\n",ans);
    printf("Difference b/w score when both play optimal is = %d\n",tSum - ans);


    return 0;
    }