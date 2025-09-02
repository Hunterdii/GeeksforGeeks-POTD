/*
class Node {
  public:
    int data;
    Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};
*/

class Solution {
public:
    Node* swapKth(Node* head, int k) {
        if (!head) return head;
        int n = 0;
        for (Node* t = head; t; t = t->next) n++;
        if (k > n || 2 * k - 1 == n) return head;
        
        Node *x = head, *y = head, *px = nullptr, *py = nullptr;
        for (int i = 1; i < k; i++) px = x, x = x->next;
        for (int i = 1; i < n - k + 1; i++) py = y, y = y->next;
        
        if (px) px->next = y; else head = y;
        if (py) py->next = x; else head = x;
        
        Node* temp = x->next;
        x->next = y->next;
        y->next = temp;
        
        return head;
    }
};

2)
class Solution {
public:
    Node* swapKth(Node* head, int k) {
        if (!head) return head;
        int n = getLength(head);
        if (k > n || 2 * k - 1 == n) return head;
        return swapNodes(head, k, n - k + 1, n);
    }
    
private:
    int getLength(Node* head) {
        return head ? 1 + getLength(head->next) : 0;
    }
    
    Node* swapNodes(Node* head, int pos1, int pos2, int n) {
        if (pos1 > pos2) swap(pos1, pos2);
        
        Node* prev1 = nullptr, *prev2 = nullptr;
        Node* curr = head;
        
        for (int i = 1; i < pos1; i++) prev1 = curr, curr = curr->next;
        Node* node1 = curr;
        
        curr = head;
        for (int i = 1; i < pos2; i++) prev2 = curr, curr = curr->next;
        Node* node2 = curr;
        
        if (prev1) prev1->next = node2;
        if (prev2) prev2->next = node1;
        
        swap(node1->next, node2->next);
        
        return (pos1 == 1) ? node2 : (pos2 == 1) ? node1 : head;
    }
};

3)
class Solution {
public:
    Node* swapKth(Node* head, int k) {
        if (!head || k <= 0) return head;
        
        Node* curr = head;
        int len = 0;
        while (curr) len++, curr = curr->next;
        
        if (k > len || 2 * k - 1 == len) return head;
        
        Node* first = head, *second = head;
        Node* prevFirst = nullptr, *prevSecond = nullptr;
        
        for (int i = 1; i < k; i++) prevFirst = first, first = first->next;
        for (int i = 1; i < len - k + 1; i++) prevSecond = second, second = second->next;
        
        if (prevFirst) prevFirst->next = second;
        if (prevSecond) prevSecond->next = first;
        
        Node* temp = first->next;
        first->next = second->next;
        second->next = temp;
        
        return (k == 1) ? second : (k == len) ? first : head;
    }
};


4)
class Solution {
public:
    Node* swapKth(Node* head, int k) {
        if (!head) return head;
        int n = getLength(head);
        if (k > n || 2 * k - 1 == n) return head;
        
        Node* first = nullptr, *second = nullptr;
        findNodes(head, k, n - k + 1, 1, first, second);
        
        if (first && second && first != second) {
            swapNodeData(first, second);
        }
        
        return head;
    }
    
private:
    int getLength(Node* head) {
        return head ? 1 + getLength(head->next) : 0;
    }
    
    void findNodes(Node* curr, int pos1, int pos2, int index, Node*& first, Node*& second) {
        if (!curr) return;
        if (index == pos1) first = curr;
        if (index == pos2) second = curr;
        findNodes(curr->next, pos1, pos2, index + 1, first, second);
    }
    
    void swapNodeData(Node* a, Node* b) {
        int temp = a->data;
        a->data = b->data;
        b->data = temp;
    }
};


5)
class Solution {
public:
    Node* swapKth(Node* head, int k) {
        if (!head) return head;
        
        vector<Node*> nodes;
        for (Node* curr = head; curr; curr = curr->next) 
            nodes.push_back(curr);
        
        int n = nodes.size();
        if (k > n || 2 * k - 1 == n) return head;
        
        int idx1 = k - 1, idx2 = n - k;
        Node* first = nodes[idx1], *second = nodes[idx2];
        
        Node* prevFirst = (idx1 > 0) ? nodes[idx1 - 1] : nullptr;
        Node* prevSecond = (idx2 > 0) ? nodes[idx2 - 1] : nullptr;
        
        if (prevFirst) prevFirst->next = second;
        if (prevSecond) prevSecond->next = first;
        
        Node* temp = first->next;
        first->next = second->next;
        second->next = temp;
        
        return (k == 1) ? second : (k == n) ? first : head;
    }
};
