#include<iostream>
#include<vector>
using namespace std;

const int MAX_ARR_SIZE = 100+ 10;
int mem[MAX_ARR_SIZE][MAX_ARR_SIZE];

//MUST_OBSERVE1: this function will be called with l = 1 (i.e at lest two matrix should be ther for multiplication)
int matrixChainMultiplicatino(int l, int r, const vector<int>&arr)
{
    if(l==r)
        return 0; //multiplication cost for single matrix is ZERO
    
    if(l>r)
        return 0;

    if(mem[l][r] != -1)
        return mem[l][r];
    int bCost = INT_MAX; //best cost
    //Try out all possible place
    for(int k=l;k<r;k++)
    {
        //[i-1,k] [k+1,r] <== these are two matrix which are going to be multiplied
        //hence multiplicatinCost = arr[i-1] * arr[k] * arr[r]
        int leftCost =  matrixChainMultiplicatino(l,k,arr);
        int rightCost = matrixChainMultiplicatino(k+1,r,arr);

       // printf("(%d,%d):: LeftCost = %d, RightCost = %d\n",l,r,leftCost,rightCost);

        int multiplicatinCost = (arr[l-1] * arr[k] * arr[r]) + leftCost + rightCost;

        bCost = min(bCost,multiplicatinCost);
    }
  //  printf("Best Cost to Multiply %d = %d\n",l,bCost);
    int rVal =  bCost;
    mem[l][r] = rVal;
    return rVal;
}

int main()
{

    vector<int> vec{40,20,30,10,30};
    memset(mem,-1,sizeof(int)*MAX_ARR_SIZE*MAX_ARR_SIZE);
    
    int ans = matrixChainMultiplicatino(1,vec.size()-1,vec);

    printf("Multiplicaton Cost = %d\n",ans);

    return 0;
}