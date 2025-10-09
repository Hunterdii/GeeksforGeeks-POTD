/*
    struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};
*/

#define MAX_SIZE 100000

int* postOrder(struct Node* root, int* size) {
    int* res = (int*)malloc(MAX_SIZE * sizeof(int));
    *size = 0;
    struct Node* curr = root;
    while (curr) {
        if (!curr->right) {
            res[(*size)++] = curr->data;
            curr = curr->left;
        } else {
            struct Node* pred = curr->right;
            while (pred->left && pred->left != curr) pred = pred->left;
            if (!pred->left) {
                res[(*size)++] = curr->data;
                pred->left = curr;
                curr = curr->right;
            } else {
                pred->left = NULL;
                curr = curr->left;
            }
        }
    }
    for (int i = 0, j = *size - 1; i < j; i++, j--) {
        int temp = res[i];
        res[i] = res[j];
        res[j] = temp;
    }
    return res;
}
