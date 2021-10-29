//Problem Practice Link: https://leetcode.com/problems/shortest-common-supersequence/
#include<iostream>
#include<string>
#include<vector>
using namespace std;
void printMatrix(vector<vector<int> >& vec1);
#define cc if(0)
string printLCS(string s1, string s2, const vector<vector<int>>& dp)
{

    int NRow = dp.size();
    int NCol = dp[0].size();

    string aS;
    int i = NRow-1,j = NCol-1;
    while(i>=1 && j>=1 )//s2 //OBSERVE condition check for s1 ===i, s2 ===j
        {
    cc        printf("(%d,%d)\n",i,j);
          //  if(dp[i-1][j-1] +1 == dp[i][j])
            if(s1[i-1]  == s2[j-1])
             {
                aS += s1[i-1];
                i--;
                j--;
             }
            else
            {
                if(dp[i-1][j] > dp[i][j-1]) //Determine from where it came from
                //an alternate in this case would be dp[i-1][j] > dp[i][j-1]
                 {
                     aS += s1[i-1];
                     i--;
                 }  
                else
                {
                    aS += s2[j-1];
                    j--;
                }
            }
    }//outer for loop
    //if either one is not emoty, then incldue all remainine 

cc    printf("\n\t(%d,%d) aS = %s\n",i,j,aS.c_str());
#if 1
    while(i>=1)
     {   aS = aS + s1[i-1];  i--; }
    while(j>=1)
     {   aS = aS + s2[j-1];  j--; }
#endif
 cc   printf("aS = %s\n",aS.c_str());
   reverse(aS.begin(),aS.end());
   return aS;
}

string findLCSDP(string s1, string s2)
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
	//		printf("(%c,%c)\n", s1[i-1], s2[j-1]);
			if (s1[i-1] == s2[j-1])
				val = 1 + dp[i - 1][j - 1]; //following bottom up approach
			else
				val = max(dp[i - 1][j], dp[i][j - 1]);
			dp[i][j] = val;

		}
	}//for loop ends here
#if 0
	printf("Matrix is\n");
	printMatrix(dp);
#endif
    string ans = printLCS(s1,s2,dp);
cc	printf("Common Substring is = %s\n",ans.c_str());
//	return dp[NRow - 1][NCol - 1];
    return ans;
}

int main()
{
    string s1 = "abac";
    string s2 = "cab";

    findLCSDP(s1,s2);

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