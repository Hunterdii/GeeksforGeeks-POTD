//{ Driver Code Starts
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 100005

struct ListNode {
    int data;
    struct ListNode *next;
};

struct graph {
    struct ListNode *head[N];
};

// Edge struct
struct edges {
    int src, dest;
};

// Adjacency list construction
struct graph *create_graph(struct edges arr_edges[], int n, int m) {
    struct graph *g = (struct graph *)malloc(sizeof(struct graph));

    for (int i = 0; i < n; i++) {
        g->head[i] = NULL;
    }

    for (int i = m - 1; i >= 0; i--) {
        int u = arr_edges[i].src, v = arr_edges[i].dest;

        struct ListNode *newNode = (struct ListNode *)malloc(sizeof(struct ListNode));
        newNode->data = v;
        newNode->next = g->head[u];
        g->head[u] = newNode;
    }

    return g;
}


// } Driver Code Ends

// User function Template for C

bool isCycle(struct graph *g, int n, int m) {
    int in[N] = {}, q[N], f = 0, r = 0, c = 0;
    for (int i = 0; i < n; i++)
        for (struct ListNode *p = g->head[i]; p; p = p->next)
            in[p->data]++;
    for (int i = 0; i < n; i++) if (!in[i]) q[r++] = i;
    while (f < r) {
        int u = q[f++];
        c++;
        for (struct ListNode *p = g->head[u]; p; p = p->next)
            if (--in[p->data] == 0) q[r++] = p->data;
    }
    return c != n;
}

//{ Driver Code Starts.

int main() {
    int t = 1;

    while (t--) {
        int queries;
        scanf("%d", &queries);

        while (queries--) {
            int n, m;
            scanf("%d", &n);
            scanf("%d", &m);

            struct edges arr_edges[m];
            for (int i = 0; i < m; i++) {
                int u, v;
                scanf("%d %d", &u, &v);
                arr_edges[i].src = u;
                arr_edges[i].dest = v;
            }

            struct graph *g = create_graph(arr_edges, n, m);

            bool ans = isCycle(g, n, m);
            if (ans) {
                printf("true\n");
            } else {
                printf("false\n");
            }
        }
    }
    return 0;
}

// } Driver Code Ends
