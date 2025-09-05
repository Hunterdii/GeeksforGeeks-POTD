/* Node is defined as
  class Node {
  public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};
*/


class Solution {
public:
    Node* segregate(Node* head) {
        if (!head || !head->next) return head;
        
        Node* curr = head;
        int count0 = 0, count1 = 0, count2 = 0;
        
        while (curr) {
            if (curr->data == 0) count0++;
            else if (curr->data == 1) count1++;
            else count2++;
            curr = curr->next;
        }
        
        curr = head;
        while (count0 > 0) {
            curr->data = 0;
            curr = curr->next;
            count0--;
        }
        while (count1 > 0) {
            curr->data = 1;
            curr = curr->next;
            count1--;
        }
        while (count2 > 0) {
            curr->data = 2;
            curr = curr->next;
            count2--;
        }
        
        return head;
    }
};


2)
class Solution {
public:
    Node* segregate(Node* head) {
        vector<int> count(3, 0);
        for (Node* temp = head; temp; temp = temp->next)
            count[temp->data]++;
        
        Node* curr = head;
        for (int i = 0; i < 3; i++) {
            while (count[i]-- && curr) {
                curr->data = i;
                curr = curr->next;
            }
        }
        return head;
    }
};


3)
class Solution {
public:
    Node* segregate(Node* head) {
        Node *zHead = nullptr, *zTail = nullptr;
        Node *oHead = nullptr, *oTail = nullptr;
        Node *tHead = nullptr, *tTail = nullptr;
        
        while (head) {
            if (head->data == 0) {
                if (!zHead) zHead = zTail = head;
                else zTail->next = head, zTail = head;
            } else if (head->data == 1) {
                if (!oHead) oHead = oTail = head;
                else oTail->next = head, oTail = head;
            } else {
                if (!tHead) tHead = tTail = head;
                else tTail->next = head, tTail = head;
            }
            Node* temp = head->next;
            head->next = nullptr;
            head = temp;
        }
        
        if (zTail) zTail->next = oHead ? oHead : tHead;
        if (oTail) oTail->next = tHead;
        
        return zHead ? zHead : (oHead ? oHead : tHead);
    }
};


4)
class Solution {
    Node *zHead = nullptr, *oHead = nullptr, *tHead = nullptr;
    Node *zTail = nullptr, *oTail = nullptr, *tTail = nullptr;
    
    void processNode(Node* node) {
        if (!node) return;
        
        Node* next = node->next;
        node->next = nullptr;
        
        if (node->data == 0) {
            if (!zHead) zHead = zTail = node;
            else zTail->next = node, zTail = node;
        } else if (node->data == 1) {
            if (!oHead) oHead = oTail = node;
            else oTail->next = node, oTail = node;
        } else {
            if (!tHead) tHead = tTail = node;
            else tTail->next = node, tTail = node;
        }
        
        processNode(next);
    }
    
public:
    Node* segregate(Node* head) {
        zHead = oHead = tHead = zTail = oTail = tTail = nullptr;
        processNode(head);
        
        if (zTail) zTail->next = oHead ? oHead : tHead;
        if (oTail) oTail->next = tHead;
        
        return zHead ? zHead : (oHead ? oHead : tHead);
    }
};


5)
class Solution {
public:
    Node* segregate(Node* head) {
        if (!head || !head->next) return head;
        
        Node* curr = head;
        int count0 = 0, count1 = 0, count2 = 0;
        
        while (curr) {
            if (curr->data == 0) count0++;
            else if (curr->data == 1) count1++;
            else count2++;
            curr = curr->next;
        }
        
        curr = head;
        while (count0 > 0) {
            curr->data = 0;
            curr = curr->next;
            count0--;
        }
        while (count1 > 0) {
            curr->data = 1;
            curr = curr->next;
            count1--;
        }
        while (count2 > 0) {
            curr->data = 2;
            curr = curr->next;
            count2--;
        }
        
        return head;
    }
};
