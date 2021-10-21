#include<iostream>
#include<vector>
using namespace std;
#define cc if(0)
void printMatrix(vector<vector<int> >& vec1);
const int INSERTION_COST = 1;
const int DEL_COST = 1;
const int REPLACE_COST = 1;

//s1->s2
int findEditDistanceCostRecursiveTopDown(int m, int n, string s1, string s2)
{
	if (m == 0 || n == 0)
	{
	cc	printf("\n");
		return  (max(m, n)) * INSERTION_COST;
	}

	int val = 0;
	if (s1[m-1] == s2[n-1])
	{
		val =  findEditDistanceCostRecursiveTopDown(m - 1, n - 1, s1, s2); //if char matches then {delete,replace or Insert non happen}
	}
	else
	{
		int iCost = INSERTION_COST + findEditDistanceCostRecursiveTopDown(m - 1, n, s1, s2);
		int dCost = DEL_COST + findEditDistanceCostRecursiveTopDown(m, n - 1, s1, s2);

		int rCost = REPLACE_COST + findEditDistanceCostRecursiveTopDown(m - 1, n - 1, s1, s2);
		val =  (min(iCost, min(dCost, rCost)));
	}
cc	printf("(%d,%d) = %d ", m, n, val);
	return val;
}

int findEditDistanceBottomUp(int m, int n, string s1, string s2)
{
	if(m == s1.length() ) //to convert larger s1 to smaller s2, we need to delete that amount
		return (s2.length()-n)*DEL_COST;
	if( n == s2.length()) //s1 i smaller, we need some inseration to make it s2
		return (s1.length()-m)*INSERTION_COST;

    int retVal = 0;
	if(s1[m] == s2[n])
	{
		retVal =  findEditDistanceBottomUp(m+1,n+1,s1,s2);
	}
	else //chars do not equal , we need to try all three opertion to find Min cost
	{
		//(m,n) => (m,n+1) ==> insert add new character to s1 i.e. m
		int iCost = INSERTION_COST * 1 + findEditDistanceBottomUp(m,n+1,s1,s2);

		int dCost = DEL_COST*1 + findEditDistanceBottomUp(m+1,n,s1,s2);
		int rCost = REPLACE_COST*1 + findEditDistanceBottomUp(m+1,n+1,s1,s2);

		retVal =  min(iCost,min(dCost,rCost));
	}
 //   printf("[%d] (%s->%s) :: %d\n",step,s1.substr(0,m+1).c_str(),s2.substr(0,n+1).c_str(),retVal);
    return retVal;
}
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
		cc	printf("(%s,%s) = %d ", a.c_str(), b.c_str(), val);
			dp[i][j] = val;
		}
		printf("\n");
	}//NRow for loop

	cc cout << "Matrix is\n";
	cc printMatrix(dp);

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

	printf("\findEditDistanceCostRecursiveTopDown = %d\n", findEditDistanceCostRecursiveTopDown(s1.length(),s2.length(), s1, s2));

	printf("\nfindEditDistanceBottomUp = %d\n",findEditDistanceBottomUp(0,0,s1,s2));
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