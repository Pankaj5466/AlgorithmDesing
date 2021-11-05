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
    void sortColors(vector<int>& arr)
    {
        
        int l=0,r=arr.size()-1;
        int k=0;
        //l = left, r = right, k  = mid
        
        while(k<=r)
        {   
     cc         printf("%d,%d(%d),%d\n",l,k,arr[k],r);
            if(arr[k] == 0) //swap from left //Current element is 0, as per question it need to be placed at left
            {
            cc    cout<<"Swap Left\n";
                swap(arr[k],arr[l]);
                l++; // <=l has all zero, so increment l
                k++;
            }  
            else if(arr[k] == 2) //swap from right
            {
         cc       cout<<"Swap Right\n";
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
    return 0;
}