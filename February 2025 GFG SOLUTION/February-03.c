//{ Driver Code Starts
// Initial Template for C

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Tree Node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// A structure to represent a queue
struct Queue {
    int front, rear, size;
    unsigned capacity;
    struct Node** array;
};

// function to create a queue of given capacity.
// It initializes size of queue as 0
struct Queue* createQueue(unsigned capacity) {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->capacity = capacity;
    queue->front = queue->size = 0;

    // This is important, see the enqueue
    queue->rear = capacity - 1;
    queue->array = (struct Node**)malloc(queue->capacity * sizeof(struct Node**));
    return queue;
}

// Queue is full when size becomes
// equal to the capacity
int isFull(struct Queue* queue) {
    return (queue->size == queue->capacity);
}

// Queue is empty when size is 0
int isEmpty(struct Queue* queue) {
    return (queue->size == 0);
}

// Function to add an item to the queue.
void enqueue(struct Queue* queue, struct Node* item) {
    if (isFull(queue))
        return;
    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->array[queue->rear] = item;
    queue->size = queue->size + 1;
}

// Function to remove an item from queue.
void dequeue(struct Queue* queue) {
    if (isEmpty(queue))
        return;
    struct Node* item = queue->array[queue->front];
    queue->front = (queue->front + 1) % queue->capacity;
    queue->size = queue->size - 1;
}

// Function to get front of queue
struct Node* front(struct Queue* queue) {
    if (isEmpty(queue))
        return NULL;
    return queue->array[queue->front];
}

// Function to get size of queue
int size(struct Queue* queue) {
    return queue->size;
}

// Utility function to create a new Tree Node
struct Node* newNode(int val) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node*));
    ;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

// Function to Build Tree
struct Node* buildTree(char str[]) {
    // Corner Case
    if (strlen(str) == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    char* token = strtok(str, " ");
    int cnt = 0;
    char* ip[100000];

    // Keep printing tokens while one of the
    // delimiters present in str[].
    while (token != NULL) {
        ip[cnt++] = token;
        token = strtok(NULL, " ");
    }

    // Create the root of the tree
    struct Node* root = newNode(atoi(ip[0]));

    // Push the root to the queue
    struct Queue* queue = createQueue(cnt);
    enqueue(queue, root);

    // Starting from the second element
    int i = 1;
    while (!isEmpty(queue) && i < cnt) {

        // Get and remove the front of the queue
        struct Node* currNode = front(queue);
        dequeue(queue);
        // Get the current node's value from the string
        char* currVal = ip[i];

        // If the left child is not null
        if (strcmp(currVal, "N") != 0) {

            // Create the left child for the current node
            currNode->left = newNode(atoi(currVal));

            // Push it to the queue
            enqueue(queue, currNode->left);
        }

        // For the right child
        i++;
        if (i >= cnt)
            break;
        currVal = ip[i];

        // If the right child is not null
        if (strcmp(currVal, "N") != 0) {

            // Create the right child for the current node
            currNode->right = newNode(atoi(currVal));

            // Push it to the queue
            enqueue(queue, currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
// User function Template for C

/*
// Tree Node
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
};

// Utility function to create a new Tree Node
struct Node* newNode(int val)
{
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node*));;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}
*/

// Function to find the height of a binary tree.
int max(int a,int b){return a>b?a:b;}
int height(struct Node* node){return node?1+max(height(node->left),height(node->right)):-1;}

//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {
        char str[100000];
        scanf("%[^\n]%*c", str);
        struct Node* root = buildTree(str);
        printf("%d\n", height(root));

        printf("~%s", "\n");
    }
    return 0;
}
// } Driver Code Ends
