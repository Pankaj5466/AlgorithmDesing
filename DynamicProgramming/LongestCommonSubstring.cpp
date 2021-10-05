#include<iostream>
#include<vector>
#include<string>
using namespace std;
void printMatrix(vector<vector<int> >& vec1);

//will be called as m = 0, n =0
int maxVal = 0;
int findLCSRecursiveTopDown(int m, int n, const string& s1, const string& s2)
{
	if (m >= s1.length() || n >= s2.length())
		return 0;

	if (s1[m] == s2[n])
	{
		int t = 1 + findLCSRecursiveTopDown(m + 1, n + 1, s1, s2);
		maxVal = max(maxVal, t);
		return t;
	}
	else
	{
		int val1 = findLCSRecursiveTopDown(m + 1, n, s1, s2); //just call to find LCS for subsequence and update maxVal
		int val2 = findLCSRecursiveTopDown(m, n + 1, s1, s2);

		return 0; //if string do not match. then LCSubstring is '0' for this m,n
	}

}

int findLCSubstringDP(string s1, string s2)
{
	if (s1.length() == 0 || s2.length() == 0)
		return 0;

	int NRow = s1.length();
	int NCol = s2.length();
	NRow++;
	NCol++;

	vector<vector<int> > dp(NRow, vector<int>(NCol, 0));
	
	for (int i = 0; i < NRow; i++)
	{
		for (int j = 0; j < NCol; j++)
		{
			if (i == 0 || j == 0)
			{
				dp[i][j] = 0;
				continue;
			}

			int t = 0;
			if (s1[i - 1] == s2[j - 1])
				t = 1 + dp[i - 1][j - 1];
			else
				t = 0;

			dp[i][j] = t;
		}
	}

	cout << "DP matrix is\n";
	printMatrix(dp);

	int ans = 0;
	for (auto v : dp)
	{
		for (auto k : v)
			ans = max(ans, k);
	}

	return ans;
}
int main()
{
	//string s1 = "ABABC";
	//string s2  = "BABCA";
	string s1 = "ABAB";
	string s2 = "BABA";

	maxVal = 0;
	findLCSRecursiveTopDown(0, 0, s1, s2);

	printf("TopDown Recursive = %d\n", maxVal);

	printf("DPSubstring Max = %d\n", findLCSubstringDP(s1, s2));

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