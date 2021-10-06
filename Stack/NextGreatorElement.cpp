#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<stack>
using namespace std;

typedef long long int lli;
class Solution
{
public:
    //Function to find the next greater element for each element of the array.
	//NOTE: this question is same as StockSpan but in reverse order
    vector<long long> nextLargerElement(vector<long long> arr, int n) 
    {
        stack<int> st;
        vector<lli> ans;

        ans.push_back(-1);
        st.push(n - 1);

        for (int i = n - 2; i >= 0; i--)
        {
            while (st.empty() == false && arr[st.top()] < arr[i])
                st.pop();

            lli lE = (st.empty() == true) ? -1 : arr[st.top()];
           
            ans.push_back(lE);
            st.push(i);
        }
       
        reverse(ans.begin(), ans.end());
        return ans;
    }
};



int main()
{
    freopen("sample_input.txt", "r", stdin);
    int t;
    cin >> t;
    while (t--)
    {

        int n;
        cin >> n;
        vector<long long> arr(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];

        Solution obj;
        vector <long long> res = obj.nextLargerElement(arr, n);
        for (long long i : res) cout << i << " ";
        cout << endl;
    }
    return 0;
}  