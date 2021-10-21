#include<iostream>
#include<vector>
using namespace std;

//call as f(0,s1.lenght()-1,s1)
bool checkPalindrome(int l, int r, string s1)
{
    if(l>r) //for case when s1 size is zero
        return true;
    if( l==r ) //All single string length are palindrome
        return true;

    if(s1[l] != s1[r])
        return false; //if this condition not satisfied => no need to check further,just return false
    else
    {
        return checkPalindrome(l+1,r-1,s1); 
        //if current end matched, then need to check for all remaining paris
    }   
}

int longestPalindromeSubsequenceRecursive(int l, int r, string s1)
{
    if(l==r) //All single string length are palindrome of length 1
        return 1;
    if(l>r)
        return 0;
    
    if(s1[l] == s1[r])
    {
        return 2+ longestPalindromeSubsequenceRecursive(l+1,r-1,s1);
    }
    else
    {
        int iLeft = longestPalindromeSubsequenceRecursive(l+1,r,s1); //ignore left
        int iRight = longestPalindromeSubsequenceRecursive(l,r-1,s1); //ignore right
        return max(iLeft,iRight);
    }

}

    int longestPalindromeSubsequenceDP(string s1)
{
    int NRow = s1.length();
    int NCol = s1.length();

    //OBSERVE1: when single string DP is formed, we do not ++ row and col
    vector<vector<int> > dp(NRow,vector<int>(NCol,0));

    //Length 1 string is always valid palindrome withlength 1
    
    for(int i=0;i<NRow;i++)
        dp[i][i] = 1;
    //OBSERVE dp[0][0] case do not need overrride, as it represedng s1[0]

    for(int l=2;l<=NRow;l++) //length loop
    {
        
        for(int i=0;i<NRow-l+1;i++)
        {
            int j = i+l-1;
     //      printf("(%d,%d)\n",i,j);
                
            int val=0;
            if(s1[i] == s1[j]) //we do not start row and col with +1, so our original data is at offset of 0
            {
                val = 2 + dp[i+1][j-1];
            }
            else
            {
                int iLeft = dp[i+1][j];
                int iRight = dp[i][j-1];
                val = max(iLeft,iRight);
            }

            dp[i][j] = val;
        }
    }

        
    return dp[0][NCol-1]; //OBSERVE3: this time our ans is not at NRow-1,NCol-1
}
int main()
{  

    return 0;
}


    int findLongestPalindromeSubseqSplitInBetween(int l, int r, string s1)
    {
        if(l==r)
            return 1;
        if(l>r)
            return 0;
        
        for(int i=l;i<r;i++)
        {
            int lHalf = findLongestPalindromeSubseqSplitInBetween(l,i,s1);
            int rHalf = findLongestPalindromeSubseqSplitInBetween(i+1,r,s1);
            
            printf("(%d-%d) = %d, (%d-%d) = %d\n",l,i,lHalf,i+1,r,rHalf);
            return lHalf + rHalf; //can we combine??? ==> i think no
        }
        
        return 0;
    }