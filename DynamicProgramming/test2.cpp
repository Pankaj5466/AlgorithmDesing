#include<iostream>
#include<vector>
#include<set>
using namespace std;

int main()
{
    vector<int> arr{1,2,4,4,4,7,7,7,9};
    set<int> s1(arr.begin(),arr.end());

    printf("Array is\n");
    for(int i=0;i<arr.size();i++)
        printf("%d(%d)  ",arr[i],i);
    printf("\n");

    for(auto k:s1)
    {
        int lb = lower_bound(arr.begin(),arr.end(),k) - arr.begin();
        int up = upper_bound(arr.begin(),arr.end(),k) - arr.begin();

        printf("%d:: LB(%d),UP(%d)\n",k,lb,up);
    }

    return {};
}