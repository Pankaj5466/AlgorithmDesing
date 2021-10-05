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

    listNode* reverseStartEnd(listNode* start, listNode* end)
    {
        listNode* cur{}, * prev{}, * nt{};
        cur = start;

        while (end != nullptr && cur->next != end->next)
        {
            nt = cur->next;
            cur->next = prev;

            prev = cur;
            cur = nt;
        }

        return prev;
    }

    listNode* reverseKGroupIterative(listNode* head, int k)
    {
        if (head == nullptr)
            return head;

       
        listNode* crawl = head;
        int count = 1;

        listNode* prev{};
        while (crawl != nullptr)
        {
            if (count % k == 0)//extract list of size k
            {
                listNode* next_ofrHead = crawl->next;
                listNode *rHead = reverseStartEnd(head, crawl); //[1,2,3,4, .. ] => [3,2,1,4,..] rHead = 1
               
                prev->next = crawl;
                head->next = crawl->next;

                crawl = next_ofrHead;
            }
            else
            {
                crawl = crawl->next;
                count++;
            }
        }

        return crawl;
    }
};


// { Driver Code Starts.

/* Drier program to test above function*/
int main(void)
{
   // freopen("sample_input.txt", "r+", stdin);

    int t = 1;
  //  cin >> t;

    while (t--)
    {
        struct node* head = NULL;
        struct node* temp = NULL;
        int n;
    //    cin >> n;
        int arr[] = { 1,2,3,4,5,6,7,8 };
        n = sizeof(arr) / sizeof(arr[0]);
        int k = 3;

        for (int i = 0; i < n; i++)
        {
            int value = arr[i];
            //cin >> value;
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

      //  int k;
     //   cin >> k;


        Solution ob;
       // head = ob.reverseKGroupLogicMojo(head, k);
        head = ob.reverseKGroupIterative(head, k);
        printList(head);
    }

    return(0);
}

// } Driver Code Ends