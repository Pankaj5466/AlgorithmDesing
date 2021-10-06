#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<string>
using namespace std;
void printMatrix(vector<vector<int> >& vec1);

class Solution {
public:
    bool subsetSumRecursive(int x, int sum, const vector<int>& arr)
    {
        if (sum == 0)
            return true;
        if (x >= arr.size())
            return false;

        bool val1 = subsetSumRecursive(x + 1, sum - arr[0], arr); //taking xth element in set
        bool val2 = subsetSumRecursive(x + 1, sum, arr);//not taking x element in set

        return val1 || val2;

    }

    bool subsetSumDP(const vector<int>& arr, int sum)
    {
        int NRow = arr.size();
        int NCol = sum;
        NRow++;
        NCol++;

        //Row has arr element, Col has Sum
        vector<vector<int> > dp(NRow, vector<int>(NCol));
        for (int j = 0; j < NCol; j++) //OBSERVE: when array is empty, then we can not make desired sum
            dp[0][j] = false;
        for (int i = 0; i < NRow; i++)//OBSERVE: when target sum is '0' then it can be made each time
            dp[i][0] = true;

        dp[0][0] = true;

        for (int i = 1; i < NRow; i++)
        {
            for (int j = 1; j < NCol; j++)
            {
                //determine if sum = i can be formed by taking array element from [0..i] or not

                bool notIncluding = dp[i - 1][j];
                bool including = (j - arr[i - 1] >= 0) ? dp[i - 1][j - arr[i - 1]] : false;

                dp[i][j] = including || notIncluding;
            }
        }
#if 0
        printf("dp matrix is\n");
        printMatrix(dp);
        printf("\n");
#endif


        return dp[NRow - 1][NCol - 1];

    }
public:
    bool isSubsetSum(int N, int arr[], int sum)
    {
        // code here 

     //   return subsetSumRecursive(0, sum, vector<int>(arr, arr + N));
        return subsetSumDP(vector<int>(arr, arr + N), sum);

    }
};

#define MAX_SIZE 10000
int main()
{
    freopen("sample_input.txt", "r", stdin);

    int t = 1;
    cin >> t;
    while (t--)
    {
        int N, sum;
        cin >> N;

        int arr[MAX_SIZE];
        for (int i = 0; i < N; i++)
            cin >> arr[i];

        cin >> sum;
        Solution ob;
        // cout<<"Recusive = \n"<<ob.subsetSumRecursive(0, sum, vector<int>(arr, arr + N));
        cout << ob.isSubsetSum(N, arr, sum) << endl;
    }
    return 0;
}


void printMatrix(vector<vector<int> >& vec1)
{
    for (int i = 0; i < vec1.size(); i++)
    {
        for (int j = 0; j < vec1[0].size(); j++)
        {
            printf("%d ", vec1[i][j]);
        }
        printf("\n");
    }
}