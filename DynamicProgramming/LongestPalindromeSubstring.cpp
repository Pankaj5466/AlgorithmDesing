#include<iostream>
using namespace std;

//TO-DO: Not yet verfied by submitting to any onine judge, as questin can not be found
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

int longestPalindromeRecursive(int l, int r, string s1)
{
    if(l>r)
        return 0;
    if(l==r) //All single string length are palindrome of length 1
        return 1;
    
    if(s1[l] == s1[r])
    {
        return 2+ longestPalindromeRecursive(l+1,r-1,s1);
    }
    else
    {
        int iLeft = longestPalindromeRecursive(l+1,r,s1); //ignore left
        int iRight = longestPalindromeRecursive(l,r-1,s1); //ignore right
        return max(iLeft,iRight);
    }

}
int main()
{

    return 0;
}