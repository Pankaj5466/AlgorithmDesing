#include<iostream>
#include<vector>
using namespace std;
void printMatrix(vector<vector<int> >& vec1);

int findEditDistanceCostRecursiveTopDown(int m, int n, string s1, string s2)
{
	if (s1.length() == s1.length() || s2.length() == n)
		return 0;

	if (s1[m] == s2[n])
	{
		return findEditDistanceCostRecursiveTopDown(m + 1, n + 1, s1, s2); //if char matches then {delete,replace or Insert non happen}
	}
	


}

const int INSERTION_COST = 1;
const int DEL_COST = 1;
const int REPLACE_COST = 1;
int findEditDistanceDP(string s1, string s2)
{
	if (s1.length() == 0 || s2.length() == 0)
		return max(s1.length(),s2.length()); //OBSERVE

	int NRow = s1.length();
	int NCol = s2.length();

	NRow++;
	NCol++;

	vector<vector<int>> dp(NRow, vector<int>(NCol, 0));
	
	for (int i = 1; i < NRow; i++)
		dp[i][0] = i;

	for (int j = 0; j < NCol; j++)
		dp[0][j] = j;
	

	for (int i = 1; i < NRow; i++)
	{
		string a = s1.substr(0, i);
		for (int j = 1; j < NCol; j++)
		{
			int val = 0;

			string b = s2.substr(0, j);

			if (s1[i-1] == s2[j-1])
				val = dp[i-1][j-1];
			else
			{
				//OBSERVE Different Cost
				int nCost = INSERTION_COST + dp[i][j - 1];
				int dCost = DEL_COST + dp[i - 1][j];
				int rCost = REPLACE_COST + dp[i - 1][j - 1];

				val = min(nCost, min(dCost, rCost));
			}
			printf("(%s,%s) = %d ", a.c_str(), b.c_str(), val);
			dp[i][j] = val;
		}
		printf("\n");
	}//NRow for loop

	cout << "Matrix is\n";
	printMatrix(dp);

	return dp[NRow - 1][NCol - 1];
}

int main()
{
	string s1 = "horse"; // "sunday";
	string s2 = "rose";// "saturday";

//	string s1 = "sunday";
//	string s2 = "saturday";

	int ans = findEditDistanceDP(s1, s2);
	printf("EditDP = %d\n", ans);

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