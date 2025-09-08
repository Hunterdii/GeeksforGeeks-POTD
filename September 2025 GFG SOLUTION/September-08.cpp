/*
class Node {
public:
    int data;
    Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};
*/

class Solution {
public:
    Node *mergeSort(Node *h) {
        if (!h || !h->next) return h;
        Node *s = h, *f = h->next;
        while (f && f->next) s = s->next, f = f->next->next;
        Node *r = s->next;
        s->next = nullptr;
        return merge(mergeSort(h), mergeSort(r));
    }
    
    Node *merge(Node *a, Node *b) {
        if (!a) return b;
        if (!b) return a;
        if (a->data <= b->data) {
            a->next = merge(a->next, b);
            return a;
        }
        b->next = merge(a, b->next);
        return b;
    }
};


2)
class Solution {
public:
    Node *mergeSort(Node *head) {
        if (!head || !head->next) return head;
        int len = getLength(head);
        Node dummy(0);
        dummy.next = head;
        
        for (int sz = 1; sz < len; sz *= 2) {
            Node *prev = &dummy;
            Node *curr = dummy.next;
            while (curr) {
                Node *left = curr;
                Node *right = split(left, sz);
                curr = split(right, sz);
                prev->next = merge(left, right);
                while (prev->next) prev = prev->next;
            }
        }
        return dummy.next;
    }

private:
    int getLength(Node *head) {
        int len = 0;
        while (head) {
            len++;
            head = head->next;
        }
        return len;
    }
    
    Node *split(Node *head, int n) {
        while (--n && head) head = head->next;
        Node *rest = head ? head->next : nullptr;
        if (head) head->next = nullptr;
        return rest;
    }
    
    Node *merge(Node *a, Node *b) {
        Node dummy(0);
        Node *tail = &dummy;
        while (a && b) {
            if (a->data <= b->data) {
                tail->next = a;
                a = a->next;
            } else {
                tail->next = b;
                b = b->next;
            }
            tail = tail->next;
        }
        tail->next = a ? a : b;
        return dummy.next;
    }
};

3)
class Solution {
public:
    Node *mergeSort(Node *head) {
        if (!head || !head->next) return head;
        vector<int> vals;
        Node *curr = head;
        while (curr) {
            vals.push_back(curr->data);
            curr = curr->next;
        }
        sort(vals.begin(), vals.end());
        curr = head;
        for (int val : vals) {
            curr->data = val;
            curr = curr->next;
        }
        return head;
    }
};

4)
class Solution {
public:
    Node *mergeSort(Node *head) {
        if (!head || !head->next) return head;
        if (!head->next->next) {
            if (head->data > head->next->data) {
                swap(head->data, head->next->data);
            }
            return head;
        }
        
        Node *mid1, *mid2;
        split3(head, &mid1, &mid2);
        head = mergeSort(head);
        mid1 = mergeSort(mid1);
        mid2 = mergeSort(mid2);
        return merge3(head, mid1, mid2);
    }

private:
    void split3(Node *head, Node **mid1, Node **mid2) {
        Node *slow = head, *fast = head;
        Node *prev = nullptr;
        
        while (fast && fast->next && fast->next->next) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next->next;
        } 
        *mid1 = slow->next;
        if (*mid1) {
            *mid2 = (*mid1)->next;
            if (*mid2) (*mid1)->next = nullptr;
        }
        slow->next = nullptr;
    }
    
    Node *merge3(Node *a, Node *b, Node *c) {
        return merge(merge(a, b), c);
    }
    
    Node *merge(Node *a, Node *b) {
        if (!a) return b;
        if (!b) return a;
        if (a->data <= b->data) {
            a->next = merge(a->next, b);
            return a;
        }
        b->next = merge(a, b->next);
        return b;
    }
};
