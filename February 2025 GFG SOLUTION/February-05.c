//{ Driver Code Starts
// Initial Template for C
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* A binary tree node has data, pointer to left child
   and a pointer to right child */
typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;
} Node;

// Function to create a new node
Node *newNode(int x) {
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = x;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Function to create a queue
typedef struct QueueNode {
    Node *treeNode;
    struct QueueNode *next;
} QueueNode;

typedef struct Queue {
    QueueNode *front, *rear;
} Queue;

Queue *createQueue() {
    Queue *q = (Queue *)malloc(sizeof(Queue));
    q->front = q->rear = NULL;
    return q;
}

void enqueue(Queue *q, Node *node) {
    QueueNode *newNode = (QueueNode *)malloc(sizeof(QueueNode));
    newNode->treeNode = node;
    newNode->next = NULL;
    if (q->rear == NULL) {
        q->front = q->rear = newNode;
        return;
    }
    q->rear->next = newNode;
    q->rear = newNode;
}

Node *dequeue(Queue *q) {
    if (q->front == NULL)
        return NULL;
    QueueNode *temp = q->front;
    Node *node = temp->treeNode;
    q->front = q->front->next;
    if (q->front == NULL)
        q->rear = NULL;
    free(temp);
    return node;
}

int isQueueEmpty(Queue *q) {
    return q->front == NULL;
}

// Function to Build Tree
Node *buildTree(char *str) {
    // Corner Case
    if (strlen(str) == 0 || str[0] == 'N')
        return NULL;

    // Tokenize the input string
    char *token = strtok(str, " ");
    Node *root = newNode(atoi(token));

    Queue *q = createQueue();
    enqueue(q, root);

    while (!isQueueEmpty(q)) {
        Node *currNode = dequeue(q);

        // Left child
        token = strtok(NULL, " ");
        if (token == NULL)
            break;
        if (strcmp(token, "N") != 0) {
            currNode->left = newNode(atoi(token));
            enqueue(q, currNode->left);
        }

        // Right child
        token = strtok(NULL, " ");
        if (token == NULL)
            break;
        if (strcmp(token, "N") != 0) {
            currNode->right = newNode(atoi(token));
            enqueue(q, currNode->right);
        }
    }

    free(q);
    return root;
}

// Generate output as level order of tree
char *levelOrder(Node *root) {
    if (root == NULL)
        return strdup("N\n");

    char *str = (char *)malloc(2000000 * sizeof(char));
    str[0] = '\0';
    Queue *q = createQueue();
    enqueue(q, root);

    while (!isQueueEmpty(q)) {
        Node *curr = dequeue(q);

        if (curr == NULL) {
            strcat(str, "N ");
            continue;
        }

        char buffer[12];
        sprintf(buffer, "%d ", curr->data);
        strcat(str, buffer);

        enqueue(q, curr->left);
        enqueue(q, curr->right);
    }

    // Trim trailing non-numeric characters
    int len = strlen(str);
    while (len > 0 && !isdigit(str[len - 1])) {
        str[--len] = '\0';
    }

    free(q);
    return str;
}


// } Driver Code Ends
// User function Template for C
/*
typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;
} Node;

Node *newNode(int x) {
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = x;
    node->left = NULL;
    node->right = NULL;
    return node;
}
*/
void mirror(Node *n) {
    if (!n) return;
    mirror(n->left);
    mirror(n->right);
    Node* t = n->left;
    n->left = n->right;
    n->right = t;
}


//{ Driver Code Starts.

int main() {
    int tc;
    scanf("%d ", &tc);

    while (tc--) {
        char str[2000000];
        fgets(str, sizeof(str), stdin);
        str[strlen(str) - 1] = '\0';

        Node *root = buildTree(str);
        mirror(root);

        char *result = levelOrder(root);
        puts(result);
        // printf("\n");
        printf("~\n");

        free(result);
    }

    return 0;
}

// } Driver Code Ends
