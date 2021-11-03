//Print Minimum Cost Matrix Problem:
//Print Bracket in MCM Problem: https://practice.geeksforgeeks.org/problems/brackets-in-matrix-chain-multiplication1024/1
#include<iostream>
#include<vector>
using namespace std;
#define cc if(1)

const int MAX_ARR_SIZE = 100+ 10;
int mem[MAX_ARR_SIZE][MAX_ARR_SIZE];

//MUST_OBSERVE1: this function will be called with l = 1 (i.e at lest two matrix should be ther for multiplication)
int matrixChainMultiplicatinoRec(int l, int r, const vector<int>&arr)
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
        int leftCost =  matrixChainMultiplicatinoRec(l,k,arr);
        int rightCost = matrixChainMultiplicatinoRec(k+1,r,arr);

       // printf("(%d,%d):: LeftCost = %d, RightCost = %d\n",l,r,leftCost,rightCost);

        int multiplicatinCost = (arr[l-1] * arr[k] * arr[r]) + leftCost + rightCost;

        bCost = min(bCost,multiplicatinCost);
    }
  //  printf("Best Cost to Multiply %d = %d\n",l,bCost);
    int rVal =  bCost;
    mem[l][r] = rVal;
    return rVal;
}

void printMCMRec(int l, int r, string& ans,const vector<vector<int>> bracket,int &cMatrix)
{
    if(l==r)
    {
        ans.push_back(cMatrix+'a'); //problem reduce to single matrix. Output Matrix
        cMatrix++;
        return;
    }

    printf("(%d,%d)\n",l,r);

    ans.push_back('(');
    printMCMRec(l,bracket[l][r], ans, bracket,cMatrix);

    printMCMRec(bracket[l][r]+1,r , ans,bracket,cMatrix);
    ans.push_back(')');
    
}
void printVector(const vector<vector<int>>& vec);
int matrixChainMultiplicationDP(const vector<int>& arr)
{
    int NRow = arr.size();
    int NCol = arr.size();

#if 0
    printf("input is(size = %d)\n",arr.size());
    for(int i=0;i<arr.size();i++)
        printf("%d ",arr[i]);
    printf("\n");
#endif
    vector<vector<int>> dp(NRow,vector<int>(NCol,INT_MAX));
    vector<vector<int>> bracket(NRow,vector<int>(NCol,0));
    for(int i=0;i<NRow;i++)
        dp[i][i] = 0; //Base Case: Single matrix multiplication cost is ZERO
    dp[0][0] = 0;

    for(int l=2;l<=NRow-1;l++)
    {
        for(int i=1;i<NRow-l+1;i++) //OBSERVE: same as reusion , we are starting 'l' from 1 [ as else l-1 would not be valid]
        {
            int j = i+l-1;

     cc       printf("(%d,%d) :: ",i,j);
            for(int k=i;k<j;k++)
            {
     cc           printf("-> %d",k);
                int leftCost = dp[i][k];
                int rightCost = dp[k+1][j];

                int multiplicatinoCostAtK = leftCost + rightCost
                                            + arr[i-1] * arr[k] *arr[j];
      cc        printf("L(%d), R(%d), C(%d)\n",leftCost,rightCost,multiplicatinoCostAtK);
                if(dp[i][j] > multiplicatinoCostAtK)
                    bracket[i][j] = k; //store info that i <--> j has been broken at some middle place k
                dp[i][j] = min(dp[i][j],multiplicatinoCostAtK);
            }
      cc      printf("\n");
        }
    cc    printf("\n");
    }
  cc  cout<<"PrintDP Vector\n";
 cc   printVector(dp);

    printf("Printing MCM\n");
    string bString;
    int cMatrix = 0;
    //OBSERVE Below: Call is from 1st matrix to total matix size
    //henc f(1,nMatrixSize)
    printMCMRec(1,arr.size()-1,bString,bracket,cMatrix);
    printf("Expression with Optimal Bracket is = %s\n",bString.c_str());
    int ans = dp[1][NCol-1]; //OBSERVE: our anser exist at l==1, r = NCol-1 EVEN though we have not NRow++,NCol++
    return ans;

}

int main()
{

    vector<int> vec{40,20,30,10,30};
    memset(mem,-1,sizeof(int)*MAX_ARR_SIZE*MAX_ARR_SIZE);
    
    int ans = matrixChainMultiplicatinoRec(1,vec.size()-1,vec);
    printf("matrixChainMultiplicatinoRec CostRec = %d\n",ans);

    ans = matrixChainMultiplicationDP(vec);
    printf("matrixChainMultiplicationDP = %d\n",ans);


    return 0;
}
void printVector(const vector<vector<int>>& vec)
{
    int NRow = vec.size();
    int NCol = vec[0].size();
    for(int i=0;i<NRow;i++)
    {
        for(int j=0;j<NCol;j++)
        {
            if(vec[i][j] == INT_MAX)
                printf("- "); //OBSERVE For better formatting, print '-' in place of INT_MAX
            else
                printf("%d ",vec[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}