//{ Driver Code Starts
// Initial Template for C
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure for linked list nodes
struct Node {
    int data;
    struct Node *next;
};

// Function to create a new node
struct Node *newNode(int data) {
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    return node;
}

// Function to print the linked list
void printList(struct Node *head) {
    struct Node *temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n~\n");
}

// Function to insert a node in a sorted manner
struct Node *insertSorted(struct Node *head, int data) {
    struct Node *new_node = newNode(data);
    if (!head || head->data >= data) {
        new_node->next = head;
        return new_node;
    }

    struct Node *current = head;
    while (current->next && current->next->data < data) {
        current = current->next;
    }
    new_node->next = current->next;
    current->next = new_node;
    return head;
}


// } Driver Code Ends
// User function Template for C
struct Node* sortedMerge(struct Node* head1, struct Node* head2) {
    struct Node dummy = {0, NULL}, *tail = &dummy;
    while (head1 && head2) {
        if (head1->data <= head2->data) {
            tail->next = head1;
            head1 = head1->next;
        } else {
            tail->next = head2;
            head2 = head2->next;
        }
        tail = tail->next;
    }
    tail->next = head1 ? head1 : head2;
    return dummy.next;
}

//{ Driver Code Starts.

// Driver program to test the above functions
int main() {
    int T;
    scanf("%d", &T);
    getchar(); // To consume newline after reading T
    while (T--) {
        int n1, n2, tmp;
        struct Node *head1 = NULL, *head2 = NULL;
        char input1[100001], input2[100001];

        fgets(input1, 100001, stdin); // Read the entire line for the LL1 elements
        char *token = strtok(input1, " ");
        while (token) {
            sscanf(token, "%d", &tmp);
            head1 = insertSorted(head1, tmp);
            token = strtok(NULL, " ");
        }

        fgets(input2, 100001, stdin); // Read the entire line for the LL2 elements
        token = strtok(input2, " ");
        while (token) {
            sscanf(token, "%d", &tmp);
            head2 = insertSorted(head2, tmp);
            token = strtok(NULL, " ");
        }

        struct Node *head = sortedMerge(head1, head2);
        printList(head);
    }
    return 0;
}

// } Driver Code Ends
