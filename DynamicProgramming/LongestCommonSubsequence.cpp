#include<iostream>
#include<algorithm>
#include<vector>
#include "LongestCommonSubsequencePrint.h"
using namespace std;

//Only Length of longest common substring
int findLCSRecursiveBottomUp(int m, int n, const string& s1, const string& s2)
{
	if (m >= s1.length() || n >= s2.length())
		return 0;

	if (s1[m] == s2[n])
	{
		return 1 + findLCSRecursiveBottomUp(m + 1, n + 1, s1, s2);
	}
	else
	{
		int val1 = findLCSRecursiveBottomUp(m+1, n, s1, s2);
		int val2 = findLCSRecursiveBottomUp(m , n+1, s1, s2);

		return max(val1, val2);
	}
}

int findLCSRecursiveTopDown(int m, int n, const string& s1, const string& s2)
{
	if (m < 0 || n<0)
		return 0;

	if (s1[m] == s2[n])
	{
		return 1 + findLCSRecursiveTopDown(m - 1, n - 1, s1, s2);
	}
	else
	{
		int val1 = findLCSRecursiveTopDown(m - 1, n, s1, s2);
		int val2 = findLCSRecursiveTopDown(m, n - 1, s1, s2);

		return max(val1, val2);
	}
}

void printMatrix(vector<vector<int> >& vec1);

int findLCSDP(string s1, string s2)
{
	if (s1.length() == 0 || s2.length() == 0)
		return 0;

	int NRow = s1.length();
	int NCol = s2.length();

	NRow++;
	NCol++;

	vector<vector<int> > dp(NRow, vector<int>(NCol, 0));

	for (int i = 0; i < NRow; i++)
		dp[i][0] = 0;
	for (int j = 0; j < NCol; j++)
		dp[0][j] = 0;

	for (int i = 1; i < NRow; i++)
	{
		for (int j = 1; j < NCol; j++)
		{
			int val = 0;
			printf("(%c,%c)\n", s1[i-1], s2[j-1]);
			if (s1[i-1] == s2[j-1])
				val = 1 + dp[i - 1][j - 1]; //following bottom up approach
			else
				val = max(dp[i - 1][j], dp[i][j - 1]);
			dp[i][j] = val;

		}
	}//for loop ends here

	printf("Matrix is\n");
	printMatrix(dp);

	printf("Common Substring is = %s\n",printLCS(s1,s2,dp).c_str());
	return dp[NRow - 1][NCol - 1];
}


int main()
{
	string s1 = "ABCDEF"; //"abc";
	string s2 = "AEDNEK"; //"def";

	int count1 = findLCSRecursiveBottomUp(0, 0, s1, s2);

	int count2 = findLCSRecursiveTopDown(s1.length()-1,s2.length()-1,s1, s2);

	int count3 = findLCSDP(s1, s2);
	printf("Bottom Up Recusion = %d, Top Down Recusiono = %d. DP Count  %d\n", count1, count2,count3);
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