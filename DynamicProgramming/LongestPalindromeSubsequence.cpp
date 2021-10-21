#include<iostream>
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