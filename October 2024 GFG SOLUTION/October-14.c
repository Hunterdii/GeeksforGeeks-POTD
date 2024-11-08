//{ Driver Code Starts
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definition for singly-linked list node
struct Node {
    int data;
    struct Node* next;
};


// } Driver Code Ends
// Solution code: function to get the count of nodes
int getCount(struct Node* head) {
    if (head == NULL) {
        return 0;
    }
    return 1 + getCount(head->next);
}



//{ Driver Code Starts.
//  Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) { // Check for memory allocation failure
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to create a linked list from an array of integers
struct Node* createLinkedList(int arr[], int n) {
    if (n == 0)
        return NULL;

    struct Node* head = createNode(arr[0]);
    struct Node* tail = head;

    for (int i = 1; i < n; i++) {
        tail->next = createNode(arr[i]);
        tail = tail->next;
    }

    return head;
}

// Trim trailing newline from fgets input
void trimNewline(char* str) {
    size_t length = strlen(str);
    if (length > 0 && str[length - 1] == '\n') {
        str[length - 1] = '\0';
    }
}

int main() {
    int t;
    scanf("%d\n", &t); // Read number of test cases

    while (t--) {
        size_t buffer_size = 1000000; // Allocate a large buffer size for input
        char* input = (char*)malloc(buffer_size * sizeof(char));

        if (input == NULL) { // Check if memory allocation for input fails
            printf("Memory allocation failed\n");
            exit(1);
        }

        fgets(input, buffer_size, stdin); // Read input as a string

        // Trim any trailing newline from the input
        trimNewline(input);

        // Parse the input string into an array of integers
        int arr[100000], n = 0; // Increased size to handle large inputs
        char* token = strtok(input, " ");
        while (token != NULL) {
            arr[n++] = atoi(token);
            token = strtok(NULL, " ");
        }

        // Create the linked list from the array
        struct Node* head = createLinkedList(arr, n);

        // Call the getCount function and print the result
        printf("%d\n", getCount(head));

        // Free the allocated memory for the linked list
        struct Node* temp;
        while (head != NULL) {
            temp = head;
            head = head->next;
            free(temp);
        }

        // Free the allocated memory for input string
        free(input);
    }

    return 0;
}

// } Driver Code Ends
