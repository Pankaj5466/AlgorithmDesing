//https://practice.geeksforgeeks.org/problems/boolean-parenthesization5610/1

#include<iostream>
using namespace std;

int calculate(int lT,int lF,int rT,int rF, int op,int target)
{
    int trueWay = 0,falseWay = 0;

    switch(op)
    {
        case '|':
            trueWay += lF*rT;
            trueWay += lT*rF;
            trueWay += lT*rT;

            falseWay += lF * rF;
            break;
        case '&':
            trueWay  += lT *rT;
            
            falseWay += lF*rF + lF*rT + lT*rF;
            break;

        case '^':
            trueWay += lF*rT + lT*rF;

            falseWay += lF*rF + lT*rT;
            break;
    }

    return (target == true) ? trueWay : falseWay;
}
const int MAX_ARR_SIZE = 100;
int mem[MAX_ARR_SIZE][MAX_ARR_SIZE][2];
int evaluate(int l,int r, string& s1, bool target)
{
    if(l==r) //single expression (we will make sure it shold not be called on operator )
    {
        bool a = (s1[l] == 'T') ? true : false;
        return a == target; //if its same as target, then 1 way, else ZERO way
    }

    if(mem[l][r][target] != -1)
        return mem[l][r][target];

    int trueWay = 0, falseWay = 0;

    for(int k=l+1; k<r; k = k+2)
    {
        int lT = evaluate(l,k-1,s1,true);
        int lF = evaluate(l,k-1,s1,false);

        int rT = evaluate(k+1,r,s1,true);
        int rF = evaluate(k+1,r,s1,false);

        int op = s1[k];
        printf("(%c,%c):: %c\n",s1[l],s1[r],s1[k]);
        trueWay = trueWay + calculate(lT,lF,rT,rF,op,true);
        falseWay = falseWay + calculate(lT,lF,rT,rF,op,false);

       
    }

    int rVal =  (target == true) ? trueWay : falseWay;
    mem[l][r][target] = rVal;

    return rVal;
}

int main()
{
    string s1 = "T|T&F^T";
    s1 = "T^F|F";
    s1 = "T|F^F&T|F^F^F^T|T&T^T|F^T^F&F^T|T^F";

    memset(mem,-1,sizeof(int)*MAX_ARR_SIZE*MAX_ARR_SIZE*2);
    int ans = evaluate(0,s1.length()-1,s1,true);

    printf("ans = %d\n",ans);
    return 0;
}

/*
Input:

35
T|F^F&T|F^F^F^T|T&T^T|F^T^F&F^T|T^F



Its Correct output is:

638



And Your Code's output is:

99632640*/
