#include<iostream>
#include<vector>

using namespace std;
#define cc if(0)
#define INF LLONG_MAX

typedef  long long int lli;

class Solution{
    
    lli merge(lli l,lli mid, lli r, vector<lli>&arr)
    {
        lli lSize = mid-l + 1; //end - start + 1 (for 1st half of array)
        lli rSize = r-(mid+1) +1; //end - start + 1 (for 2nd half of array)
        lli left[lSize+1];
        lli right[rSize+1];
        
        lli i=l,j=mid+1;
     //   printf("%lld-%lld-%lld, (%lld,%lld)\n",l,mid,r,lSize,rSize);
       // return 0;
        
        for(i=0;i<lSize;i++)
            left[i] = arr[i+l]; //start of 1st array is l
        for( j=0;j<rSize;j++)
            right[j] =arr[j+mid+1]; //start of 2nd array is (mid+1)
            
        left[i] = INF; //sentinel node <=1st Issue should have used Unsinged-long-long-int-max
        right[j]= INF; //sentinel node
#if 0     
        cout<<"Left and right is\n";
        for(int i=0;i<lSize;i++)
            cout<<left[i]<<" ";
        cout<<endl;
        for(int i=0;i<rSize;i++)
            cout<<right[i]<<" ";
        cout<<endl;
#endif
        lli count = 0;
        i=0;
        j=0;
        for(lli k=l;k<=r;)
        {
         //   printf("k = %lld, left[i] = %lld, right[j] = %lld ",k,left[i],right[j]);

            if(left[i] <= right[j])
            {
                arr[k++] = left[i++]; //already at correct place
            }
            else
            {
                arr[k++] = right[j++];
                if(left[i] != INF) 
                    count += (mid+1)-(l+i);
            }
       //     printf(" count = %lld\n",count);
        }
     //   printf("\n");

        return count;
            
    }
public:
    void printVector(const vector<lli>&arr)
    {
        for(auto k:arr)
            cout<<k<<" ";
        cout<<endl;
    }
 public:   
    lli mergeSortInversionCount(lli l, lli r, vector<lli>& arr)
    {
        if(l>=r) return 0;
       // lli mid =  l +(r-l)/2;
        lli mid = (l+r)>>1;
        lli count = 0;
        
     //   printf("mid = %d\n",mid);
        count += mergeSortInversionCount(l,mid,arr);
        count += mergeSortInversionCount(mid+1,r,arr);
        
        count += merge(l,mid,r,arr);
   cc     printf("%lld<%lld>%lld = %lld\n",l,mid,r,count);
   cc     printVector(arr);
    cc    printf("\n");
        
        return count;
        
        
    }
    
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    long long int inversionCount(long long a[], long long N)
    {
        vector<lli> arr(a,a+N);
        lli ans = mergeSortInversionCount(0,arr.size()-1,arr);
        
        return ans;
    }

};

int main()
{
    freopen("../DynamicProgramming/sample_input.txt","r+",stdin);
    lli size = 0;
    cin>>size;

    vector<lli> arr;
    for(lli i=0;i<size;i++)
    {
        lli t;
        cin>>t;
        arr.push_back(t);
    }
   // vector<lli> arr{10, 10, 10};// arr{2, 3, 4, 5, 6}; //arr{2,4,1,3,5};
    Solution s = Solution();

    // printf("Aray input is\n");
    // for(auto k:arr)
    //     cout<<k<<" ";
    // cout<<endl;

    lli ans = s.mergeSortInversionCount(0,arr.size()-1,arr);

    printf("Ans = %lld\n",ans);
    // cout<<"After sorting\n";
    // s.printVector(arr);

    return 0;
};
/* Failed at 100th TC
//code: 60659061037
//correct:  62346309089
*/