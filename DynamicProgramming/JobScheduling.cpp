//leetcode problem link: https://leetcode.com/problems/maximum-profit-in-job-scheduling/submissions/
/*
Solution1: logicmojo O(n*n) dp[] solution
 - Should be optmized for starting from end of array

Solution2: instead of traversing whole O..k, we find the target index via binary search
(Leetcode Official Solution gives hint to do BinarySearch)
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct dataNode
{
    int sTime,eTime,profit;
};


//return position in nums, which is either equal to OR just smaller than target
//EX: [1,1.5,3,3,3,4,5,7,8,8]
//f(2) => return index of 1.5
//f(3) => return index of 1st 3
//f(3.5) => Return index of last 3
//f(4) => Return index of 4

//f(9) ==> index of last 8
//f(<1) => -1
int lower_bound(vector<int>& nums, int target) {
    int l = 0, r = nums.size()-1;
    if(target < nums[0])
        return -1;
    while (l <= r) {
        int mid = (r-l)/2+l;
        if (nums[mid] < target)
            l = mid+1;
        else
            r = mid-1;
    }

    return (nums[l] == target)?l:l-1;;
}
int findSortedEqualOrPrevious(const vector<int>&vec,int target)
{   
    if(target < vec[0])
        return -1;
    int l=0,r=vec.size()-1;
    
    while(l<=r)
    {
        int mid = (l+r)/2;
   //     printf("arr[l] =%d, arr[mid] = %d, arr[r] = %d\n",vec[l],vec[mid],vec[r]);
        if(target < vec[mid] )
            r = mid-1;
        else if (target > vec[mid])
            l = mid+1;
       else
           return mid;
    }
    
    return l;
    
}
//#define DEBUG
class Solution {
    
    //O(nlog + n*n)
    int jobSchedulingDP( vector<dataNode>& data)
    {
     
        int size = data.size();
        vector<int> mProfit(size);
        for(int i=0;i<size;i++)
            mProfit[i] = data[i].profit;
        
        for(int i =1;i<size;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(data[j].eTime <= data[i].sTime)//Non Overlapping condition
                {
                    int nProfit = data[i].profit + mProfit[j]; //cProfit = profit is task i MUST be completed + Other profit that can be added(profit till j)
                    mProfit[i] = max(mProfit[i] , nProfit);
                }
                else
                {
                    break; //OBSERVE (i,j) are overlapping ==> any j+1 will also be overlapping, as they are sorted in increasing order of their end time
                }
            }//sub loop for i
        }//main loop for i
#ifdef DEBUG        
        cout<<"The mPrfit Vector is\n";
        for(auto k:mProfit)
            cout<<k<<" ";
        cout<<endl;
#endif      
        int ans = *max_element(mProfit.begin(),mProfit.end());
        
        return ans;
    }
    
    //O(nlogn) 
    //data is sorted w.r.t their end time
    int jobSchedulingDPAndBinarySearch(vector<dataNode> &data)
    {
        
        int size = data.size();
        vector<int> sArray(size);
        
        vector<int> mProfit(size);
        for(int i=0;i<size;i++)
        {
            mProfit[i] = data[i].profit;
            sArray[i] = data[i].eTime;
        } 
        vector<int>& dp = mProfit; //name alias
#ifdef DEBUG        
        cout<<"End time are\n";
        for(auto k:sArray)
            cout<<k<<" ";
        cout<<endl;
#endif
        
        
        mProfit[0] = data[0].profit; //base case
        for(int i=1;i<size;i++)
        {
            //since end time are sorted, we will find last endtime which is less than or equal to current job (ith job) start time.
            //if we found such ==> this will be the last job (0..k) which can be combines.
            //So instead of for loop for(0..k) we will just take dp[k] 
            
            
            int k =lower_bound(sArray,data[i].sTime);
  #ifdef DEBUG         
            printf("EqualOrprevious of %d = %d \n",data[i].sTime,(k==-1)?-1:data[k].eTime);
   #endif    
            dp[i] = max(dp[i-1],dp[i]);
            while(k != -1 && k<i && data[k].eTime <=data[i].sTime) //OBSERVE1
            {
                int val = (k != -1) ? data[i].profit + dp[k] : 0;
             
            
                dp[i] = max(dp[i] , val);
                k++;
            }
#ifdef DEBUG
  //        printf("%d :: dp[i-1] = %d, dp[i] = %d, ar[k] = %d,val = %d, k =%d\n",sArray[i], dp[i-1],dp[i],(k==-1)?-1:sArray[k],val,k);
#endif
            
        }
        
#ifdef DEBUG
        cout<<"dp is\n";
        for(auto k:dp)
            cout<<k<<" ";
        cout<<endl;
        
#endif
        return dp[size-1];
    }
public:
    
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) 
    {
        int size = startTime.size();
        vector<dataNode> data(size);
        
        for(int i=0;i<size;i++)
        {
            data[i] = {startTime[i],endTime[i],profit[i]};
        }
        
        sort(data.begin(),data.end(),
            [](dataNode const& d1, dataNode const& d2)
             {
                 if(d1.eTime <= d2.eTime)
                     return true;
                 #if 0 //OBSERVE2
                 if(d1.eTime == d2.eTime && d1.sTime > d2.sTime)
                     return true;
                 #endif
                 return false;
             });

        #ifdef DEBUG
        cout<<"Sorted Timing are\n";
        for(auto k:data)
            printf("%d,%d,%d -> ",k.sTime,k.eTime,k.profit);
        cout<<endl<<endl;
        #endif  
      //  int ans = jobSchedulingDP(data);
        int ans = jobSchedulingDPAndBinarySearch(data);
        
        return ans;
    }
};

int  main()
{
    return 0;
}
/*
[1,2,4,5,6,7]
[4,6,7,10,8,10]
[3,200,5,7,11,13]
*/
/*
[24,27,43,14,12]
[27,46,46,24,27]
[4,12,3,9,8]
*/

/*
OBSERVE1 + OBSERVE2 :: for cases like above. in which during binary search we encounter element having starting time as same!!
In those cases, as each event can have its own profit. We need to check for all thse cases. (in which kth JOB END time is same, and is less than start time of ith JOB )

if you do not want to use while loop, please enable if statement at other observation. I cant explain, but i feel it may fail at some case
*/