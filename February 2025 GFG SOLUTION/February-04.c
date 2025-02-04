//{ Driver Code Starts
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the Node structure
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* newNode(int val) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

// Function to build a binary tree from a string
struct Node* buildTree(char* str) {
    // Corner Case
    if (str == NULL || str[0] == 'N') {
        return NULL;
    }

    // Split the input string by space
    char** tokens = (char**)malloc(200000 * sizeof(char*));
    int count = 0;

    char* token = strtok(str, " ");
    while (token != NULL) {
        tokens[count++] = token;
        token = strtok(NULL, " ");
    }

    // Create the root of the tree
    struct Node* root = newNode(atoi(tokens[0]));

    // Dynamically allocate memory for queue
    struct Node** queue = (struct Node**)malloc(200000 * sizeof(struct Node*));
    int front = 0, rear = 0;

    // Push the root to the queue
    queue[rear++] = root;

    // Starting from the second element
    int i = 1;
    while (front < rear && i < count) {
        // Get and remove the front of the queue
        struct Node* currNode = queue[front++];

        // Get the current node's value from the string
        char* currVal = tokens[i];

        // If the left child is not null
        if (strcmp(currVal, "N") != 0) {
            // Create the left child for the current node
            currNode->left = newNode(atoi(currVal));

            // Push it to the queue
            queue[rear++] = currNode->left;
        }

        // For the right child
        i++;
        if (i >= count) {
            break;
        }
        currVal = tokens[i];

        // If the right child is not null
        if (strcmp(currVal, "N") != 0) {
            // Create the right child for the current node
            currNode->right = newNode(atoi(currVal));

            // Push it to the queue
            queue[rear++] = currNode->right;
        }
        i++;
    }

    // Free the tokens and queue memory
    free(tokens);
    free(queue);

    return root;
}


// } Driver Code Ends
/*
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* newNode(int val) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}
*/
struct Pair{int h,d;};
struct Pair f(struct Node* r){struct Pair p={0,0};if(!r)return p;struct Pair a=f(r->left),b=f(r->right);p.h=1+(a.h>b.h?a.h:b.h);int m=a.d>b.d?a.d:b.d, s=a.h+b.h; p.d=m>s?m:s; return p;}
int diameter(struct Node* root){return f(root).d;}

2)
int max(int a, int b){ return a > b ? a : b; }

struct Pair {
    int h, d;
};

struct Pair f(struct Node* r) {
    struct Pair p = {0, 0};
    if (!r) return p;
    struct Pair a = f(r->left), b = f(r->right);
    p.h = 1 + max(a.h, b.h);
    int m = a.d > b.d ? a.d : b.d;
    int s = a.h + b.h;
    p.d = m > s ? m : s;
    return p;
}

int diameter(struct Node* root) {
    return f(root).d;
}

//{ Driver Code Starts.

/* Driver program to test size function */
int main() {
    int t;
    scanf("%d\n", &t);
    while (t--) {
        char* s = (char*)malloc(2000000 * sizeof(char));
        fgets(s, 2000000, stdin);

        // Remove trailing newline if present
        size_t len = strlen(s);
        if (len > 0 && s[len - 1] == '\n') {
            s[len - 1] = '\0';
        }

        struct Node* root = buildTree(s);

        // Calculate and print the diameter of the tree
        printf("%d\n", diameter(root));
        printf("~\n");
        // Free the allocated memory for the string
        free(s);
    }
    return 0;
}

// } Driver Code Ends
