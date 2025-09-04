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
    Node* reverseKGroup(Node* head, int k) {
        int len = 0;
        for (Node* p = head; p; p = p->next) len++;
        
        Node dummy(0);
        dummy.next = head;
        Node* prev = &dummy;
        
        for (int i = 0; i <= len / k; i++) {
            int size = (i < len / k) ? k : len % k;
            if (size == 0) break;
            
            Node* start = prev->next;
            Node* end = start;
            for (int j = 1; j < size; j++) end = end->next;
            
            Node* next = end->next;
            end->next = nullptr;
            prev->next = reverse(start);
            start->next = next;
            prev = start;
        }
        
        return dummy.next;
    }
    
private:
    Node* reverse(Node* head) {
        Node* prev = nullptr;
        while (head) {
            Node* next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }
        return prev;
    }
};


2)
class Solution {
public:
    Node* reverseKGroup(Node* head, int k) {
        Node* node = head;
        for (int i = 0; i < k; i++) {
            if (!node) return reverseAll(head);
            node = node->next;
        }
        
        Node* prev = reverseKGroup(node, k);
        while (k--) {
            Node* next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }
        return prev;
    }
    
private:
    Node* reverseAll(Node* head) {
        Node* prev = nullptr;
        while (head) {
            Node* next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }
        return prev;
    }
};


3)
class Solution {
public:
    Node* reverseKGroup(Node* head, int k) {
        stack<Node*> st;
        Node dummy(0);
        Node* tail = &dummy;
        Node* cur = head;
        
        while (cur) {
            int count = 0;
            Node* temp = cur;
                while (temp && count < k) {
                st.push(temp);
                temp = temp->next;
                count++;
            }
                while (!st.empty()) {
                tail->next = st.top();
                tail = tail->next;
                st.pop();
            }
            tail->next = nullptr;
            cur = temp;
        }
        
        return dummy.next;
    }
};


4)
class Solution {
public:
    Node* reverseKGroup(Node* head, int k) {
        Node* cur = head; int cnt = 0;
        while (cur && cnt < k) { cur = cur->next; cnt++; }
        if (cnt < k) {
            Node* prev = nullptr;
            while (head) {
                Node* nxt = head->next; head->next = prev; prev = head; head = nxt;
            }
            return prev;
        }
        cur = reverseKGroup(cur, k);
        while (cnt--) {
            Node* nxt = head->next; head->next = cur; cur = head; head = nxt;
        }
        return cur;
    }
};
