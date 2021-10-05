#define _CRT_SECURE_NO_WARNINGS
// { Driver Code Starts
#include<vector>
#include<functional>
#include<cstring>
#include<string>
#include<queue>
#include<iostream>
#include<fstream>
using namespace std;


struct node
{
    int data;
    struct node* next;

    node(int x) {
        data = x;
        next = NULL;
    }

};

/* Function to print linked list */
void printList(struct node* node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}


typedef  node listNode;
class Solution
{
public:
    struct node* reverseKGroupLogicMojo(struct node* head, int k)
    {
        // Complete this method
        if (head == nullptr)
            return head;

        listNode* cur{}, *prev{}, *nt{};
        cur = head;

        int count = 0;
        while (cur != nullptr && count < k)
        {
            nt = cur->next;
            cur->next = prev;

            prev = cur;
            cur = nt;
            
            count++;
        }

        if (head != nullptr)
            head->next = reverseKGroupLogicMojo(cur, k);

        return prev;
    }
};


// { Driver Code Starts.

/* Drier program to test above function*/
int main(void)
{
   // freopen("sample_input.txt", "r+", stdin);

    int t;
    cin >> t;

    while (t--)
    {
        struct node* head = NULL;
        struct node* temp = NULL;
        int n;
        cin >> n;

        for (int i = 0; i < n; i++)
        {
            int value;
            cin >> value;
            if (i == 0)
            {
                head = new node(value);
                temp = head;
            }
            else
            {
                temp->next = new node(value);
                temp = temp->next;
            }
        }

        int k;
        cin >> k;


        Solution ob;
        head = ob.reverseKGroupLogicMojo(head, k);
        printList(head);
    }

    return(0);
}

// } Driver Code Ends