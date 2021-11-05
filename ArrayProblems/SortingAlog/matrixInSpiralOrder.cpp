//problem Practice Link: https://leetcode.com/problems/spiral-matrix/
//Intution: LogicMojo
#include<iostream>
#include<vector>
using namespace std;

vector<int> printSpiral(vector<vector<int>>& mat)
{
    vector<int> ans;
    
    int m=0,n=0,NRow=mat.size()-1,NCol = mat[0].size()-1; //OBSERVE1: Boundary points to valid element
    
    while(m<=NRow && n <=NCol) //OBSERVE2: Observe Equality Condition
    {
        for(int j=n;j<=NCol;j++)
            ans.push_back(mat[m][j]);
        m++;
        
        for(int i=m;i<=NRow;i++)
            ans.push_back(mat[i][NCol]);
        NCol--;
        
        if(m<=NRow) //OBSERVE3: if(m>NRow) break; would fail :: Reason why
        {
            for(int j=NCol;j>=n;j--)
                ans.push_back(mat[NRow][j]); 
            NRow--;
        }
        
        if(n<=NCol) //OBSERVE4: Observe Equality Condition
        {
            for(int i=NRow;i>=m;i--)
                ans.push_back(mat[i][n]);
            n++;
        }
    }//while loop ends here
    return ans;
}

int main()
{
    return 0;
}