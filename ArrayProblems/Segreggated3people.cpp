//problem Practice link : https://leetcode.com/problems/sort-colors/
//Intution: logicmojo

#include<iostream>
#include<vector>
using namespace std;
void swap(int &a,int &b)
{
    int t = a;
    a = b;
    b =t;
}
void printVector(const vector<int>& vec)
{
    for(auto k:vec)
        cout<<k<<" ";
     cout<<endl;
}
#define cc  if(0)
class Solution {
public:
    void stableSeggrete(vector<int>& arr)
    {
        cout<<"Before Segrreation\n";
        for(auto k:arr)
            cout<<k<<" ";
        cout<<endl;

        int size = arr.size();
        int l=0,r;
        int k=0;

        int t=0; //total count of all positive and nonzero intergers
        for(auto p:arr)
            if(p>0)
                t++;
        r = size-t; //Reserve Space from end for all non zero & positive integer
        while(k<=size-t-1 || r<size-1)
        {
            printf("\n\t::%d,%d,%d\n\t",l,k,r);
            for(auto t:arr)
                cout<<t<<" ";
            cout<<endl;

            if(arr[k] < 0)
            {
                printf("Swap l,k\n");
                swap(arr[l],arr[k]);
                l++;
                k++;
            }
            else if(arr[k] == 0)
            {
                printf("increment k\n");
                k++;
            }
            else if(arr[k] > 0)
            {
                if(arr[r] > 0)
                {
                    r++;
                    continue;
                }
                printf("Decrement r\n");
                swap(arr[r], arr[k]);
                r++;
            }


        }

        printf("After Segrettion , elements are\n");
        for(auto k:arr)
            cout<<k<<" ";
        cout<<endl;

    }

public:
    void sortColors(vector<int>& arr)
    {
        
        int l=0,r=arr.size()-1;
        int k=0;
        //l = left, r = right, k  = mid
        
        while(k<=r)
        {   
     cc     printf("%d,%d(%d),%d\n",l,k,arr[k],r);
            if(arr[k] == 0) //swap from left //Current element is 0, as per question it need to be placed at left
            {
            cc    cout<<"Swap Left\n";
                swap(arr[k],arr[l]);
                l++; // <=l has all zero, so increment l
                k++;
            }  
            else if(arr[k] == 2) //swap from right
            {
         cc     cout<<"Swap Right\n";
                swap(arr[k],arr[r]); 
                r--;
                //OBSERVE: no k++, as arr[r] might have 1, which is placed at k now. Will be handled in next iteration
            }
            else //arr[k] is '1'
            { 
     cc           cout<<"No Swap\n";
                  k++;
            }
          
 cc           printVector(arr);
  cc          cout<<endl;
        }//segretted
    }
};

int main()
{
    //vector<int> vec{-1,-2,89,90,12,38,-99,0,0,0,1,2,3,4};
    vector<int> vec{89,34,23,0,0,0,-9,34,12,665,-1,-2,89,90,12,38,-99,0,0,0,1,2,3,4};
    // vector<int> vec;
    // while(1)
    // {
    //     int t;
    //     cin>>t;
    //     if(t==-99) break;
    //     vec.push_back(t);
    // }
    Solution s;

    s.stableSeggrete(vec);

    return 0;
}