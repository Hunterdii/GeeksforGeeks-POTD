//{ Driver Code Starts
// C program to find n'th Node in linked list
#include <stdio.h>
#include <stdlib.h>
#include<iostream>
using namespace std;
/* Link list Node */
struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};


void append(struct Node** head_ref, struct Node **tail_ref, int new_data)
{
    struct Node* new_node = new Node(new_data);
    
    if (*head_ref == NULL)
       *head_ref = new_node;
    else
       (*tail_ref)->next = new_node;
    
    *tail_ref = new_node;
}


// } Driver Code Ends
/* Link list Node 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};
*/

/*You are required to complete this method*/

/* Function to get the middle of the linked list*/
/*K will always be in range */

class Solution {
public:
    Node* deleteK(Node* head, int K) {
        if (head == nullptr || K <= 0)
            return head;
        
        if (K == 1) {
            // Deleting entire list
            while (head) {
                Node* temp = head;
                head = head->next;
                delete temp;
            }
            return nullptr;
        }

        Node dummy(0);
        dummy.next = head;
        Node* prev = &dummy;
        Node* curr = head;
        int index = 1;

        while (curr) {
            if (index == K) {
                prev->next = curr->next;
                delete curr;
                curr = prev->next;
                index = 1;
            } else {
                index++;
                prev = curr;
                curr = curr->next;
            }
        }

        return dummy.next;
    }
};

//{ Driver Code Starts.

/* Driver program to test above function*/
int main()
{
  int T,i,n,l;
    cin>>T;
    while(T--){
    struct Node *head = NULL,  *tail = NULL;
        cin>>n;
        for(i=1;i<=n;i++)
        {
            cin>>l;
            append(&head, &tail, l);
        }
        int K;
        cin>>K;
        Solution obj;
        Node *res = obj.deleteK(head,K);
        Node *temp = res;
        while(temp!=NULL)
        {
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }
    return 0;
}

// } Driver Code Ends
