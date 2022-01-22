//Problem Link:https://practice.geeksforgeeks.org/problems/median-in-a-row-wise-sorted-matrix1527/1#
#include<iostream>
#include<vector>
using namespace std;


 // } Driver Code Ends
//User function template for C++

#define cc if(0)
class Solution{  
    //will not work 
    int linearFindMedian(vector<vector<int>> &mat, const int NRow, const int NCol)
    {
       printf("NRow = %d, NCol = %d\n",NCol,NCol);
       for(int i=0;i<NRow;i++)
       {
           for(int j=0;j<NCol;j++)
           {
               printf("%d ",mat[i][j]);
           }
           printf("\n");
       }
       printf("\n");
        
        int medianIdx = (NRow*NCol/2) + 1;
        printf("medianIdx = %d\n",medianIdx);

        for(int r=NRow-1,c=0 ; ;)
        {
            int cElementIndex = NCol*((r+1)-1) + c+1;
         //cc   printf("current element in sorted positon =%d\n",cElementIndex);
            
         cc   printf("(%d,%d) :: cElementIndex = %d , ME(%d)\n",r,c,cElementIndex,mat[r][c]);
            if(cElementIndex < medianIdx)
            {
                //we need to increase our element count
                printf("go RIGHT\n");
                c++;
            }
            else if(cElementIndex > medianIdx)
            {
                //need to decrease element count
                printf("go UP\n");
                r--;
            }
            else
            {
                //we are itself at median element
           cc     printf("at Median (%d,%d)\n",r,c);
                return mat[r][c];
            }
            printf("\n");
            
        }
        
        return -1; //unable to find
    }
    
    //NRow*Log(NCol)
    int binarySearchOnRow(vector<vector<int>> &mat, const int NRow,const int NCol)
    {
        int medianIdx = (NRow*NCol)/2 + 1;

        //get min and max from whole matrix
        int minElement = INT_MAX,maxElement = INT_MIN;
        for(int i=0;i<NRow;i++)
        {
            minElement = min(minElement,mat[i][0]) ;//as all row are sorted => for each row min will be on first, then max at the end
        }

        for(int i=0;i<NRow;i++)
        {
            maxElement  = max(maxElement,mat[i][NCol-1]);
        }

        //now keep shirnking min,and max as per condition of median
        //if both converge to same value => it has to be the median

        //initially these minelement and maxElement covers entire matrix
        //now shrink it
        while(minElement<maxElement)
        {
            int midElement = (minElement+maxElement)/2; //if these number are placed in sorted line, then it would be somethign like
            //me,me+1,me+2, .... ,mxe-1,mx => in no duplicate case median will lie at center index, which will also be equal to (me+mx)/2 (think it like shown Arithmetic Progression)
            //but in case of duplicate,although median will lie at center index, we do not know about its value(in current matrix). Hence, we will try to shirk mi and mx until our set contain only 1 element

            //count is number of element smaller than midElement in entire matrix <= here logn factory on row can be used, as row is sorted
            int count = 0;
            for(int i=0;i<NRow;i++)
            {
                count += upper_bound(mat[i].begin(),mat[i].end(),midElement) - mat[i].begin();
            }
            int &midElementIdx  = count; //a name alias (when flatted to single array, what is the position of midElement)
       cc    printf("mi = %d, mx = %d, mE(%d),mEI(%d)\n",minElement,maxElement,midElement, midElementIdx);

            // /... midElementIdx.....median..........
            if(midElementIdx < medianIdx) 
            {
                //go right
       cc       printf("increase minElement\n");
                minElement = midElement+1 ; //NOTE: minElement may not exist in the matrix
                //In upper_bound count, midElement count is also included.
                //What that means is, we guarnteed that count+1 element is strictely greator than count (when whole matrix is flatted to 1d sorted array)
                //and as we rule out that midElement is not our median , the next value to check is strictly greator than current value
            }
            else if(midElementIdx >= medianIdx)
            {
                //.........median.....midElementIdx.....
                //go left
                
       cc        printf("decrease mx\n");
                maxElement = midElement; //NOTE: maxElement may not exist in matrix
                //Query: why its not written like midElement-1 
                //Explanation1: => beause midElement will always be either less or equal than origianl max
                //ex : (3+3)/2 = 3 , (3+4)/2 = 3

                //Examplation2: as increment is already taken case in other case, just like all binary search, the else case need to take care of equality also. (so safely we can skip -1 in this)

                //Explanation3: (more easy to justify) => upper_bound guarntees that count+1 will be different, but count and count-1 can still be same element
                //Hence, we have not YET rule out the possibility that midElement is CANNOT be the median element 
            }
        }//while loop
        return minElement;
    }


public:
    int median(vector<vector<int>> &mat, int NRow, int NCol)
    {
        // code here 
   cc     printf("\n\n");
    #if 0
        printf("NRow = %d, NCol = %d\n",NCol,NCol);
       for(int i=0;i<NRow;i++)
       {
           for(int j=0;j<NCol;j++)
           {
               printf("%d ",mat[i][j]);
           }
           printf("\n");
       }
       printf("\n");
    #endif
       // int ans = linearFindMedian(mat,NRow,NCol);
        int ans = binarySearchOnRow(mat,NRow,NCol);
      cc  printf("ans = %d\n",ans);
        return ans;
    }
};

// { Driver Code Starts.

int main()
{
    freopen("sample_input.txt","r+",stdin);
    int t;
    cin>>t;
    while(t--)
    {
        int r, c;
        cin>>r>>c;
        vector<vector<int>> matrix(r, vector<int>(c));
        for(int i = 0; i < r; ++i)
            for(int j = 0;j < c; ++j)
                cin>>matrix[i][j];
        Solution obj;
        cout<<obj.median(matrix, r, c)<<endl;        
    }
    return 0;
}  // } Driver Code Ends

/* sample_input
3
3 3
1 3 5 2 6 9 3 6 9
3 3
1 3 4 2 6 9 3 6 9
9 11
1 3 4 9 11 11 11 11 12 13 18 7 7 8 8 8 9 10 13 14 14 16 2 3 4 6 7 10 13 13 16 16 18 3 6 7 9 9 13 13 14 15 15 18 2 6 7 10 10 13 14 16 19 20 20 2 6 8 11 13 14 16 19 19 20 20 1 8 11 11 11 13 14 16 17 20 20 2 4 5 6 7 7 8 9 14 17 20 3 4 5 9 11 11 12 13 14 17 20
11 9
2 2 6 11 11 11 14 19 19 2 8 12 13 14 15 16 17 19 1 2 5 6 12 13 18 20 20 5 5 10 11 12 15 17 17 20 4 5 6 9 9 11 12 17 17 2 4 6 10 12 14 18 18 19 3 3 8 8 11 13 14 15 18 4 7 10 15 16 17 18 19 20 1 1 2 10 11 12 16 17 19 1 1 2 5 9 10 12 16 18 4 6 7 8 13 14 15 15 18

Expected Output:
5
4
11
12
*/