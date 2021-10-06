
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<stack>
using namespace std;

class Solution
{
public:
    //Function to calculate the span of stockâ€™s price for all n days.
    vector <int> calculateSpan(vector<int> price, int n)
    {
#if 1
        stack<int> st;
        vector<int> ans;
        int count = 1;

        st.push(0); //stack will hold index
        ans.push_back(1);

        for (int i = 1; i < n;i++)
        {
            while (st.empty() == false && price[st.top()] <= price[i]) //OBSERVE the pattern
                st.pop();

            int span = (st.empty() == true) ? (i + 1) : (i - st.top()); //OBSERVE that if stack is empty, then all elemtn before this are samller
            
            ans.push_back(span);
            st.push(i);

        }//iteam for loop
#endif
        return ans;

    }
};



// { Driver Code Starts.

int main()
{
    freopen("sample_input.txt", "r", stdin);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int i;
        vector<int>a(n);
        for (i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        Solution obj;
        vector <int> s = obj.calculateSpan(a, n);

        printf("ans.size()  %d\n", s.size());
        for (i = 0; i < s.size(); i++)
        {
            cout << s[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends