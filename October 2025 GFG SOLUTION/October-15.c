int kthSmallest(struct Node* root, int k) {
    int s[100000], t = 0, c = 0;
    struct Node* n = root;
    while (n || t) {
        while (n) s[t++] = (long)n, n = n->left;
        n = (struct Node*)s[--t];
        if (++c == k) return n->data;
        n = n->right;
    }
    return -1;
}
