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
    int lengthOfLoop(Node* head) {
        Node *s = head, *f = head;
        while (f && f->next) {
            s = s->next;
            f = f->next->next;
            if (s == f) {
                int len = 0;
                do {
                    f = f->next;
                    len++;
                } while (s != f);
                return len;
            }
        }
        return 0;
    }
};


2)
class Solution {
public:
    int lengthOfLoop(Node* head) {
        Node *p1 = head, *p2 = head;
        do {
            if (!p2 || !p2->next) return 0;
            p1 = p1->next;
            p2 = p2->next->next;
        } while (p1 != p2);
        
        int length = 1;
        while (p1->next != p2) {
            p1 = p1->next;
            length++;
        }
        return length;
    }
};


3)
class Solution {
public:
    int lengthOfLoop(Node* head) {
        unordered_map<Node*, int> pos;
        Node* curr = head;
        int idx = 0;
        while (curr) {
            if (pos.count(curr)) return idx - pos[curr];
            pos[curr] = idx++;
            curr = curr->next;
        }
        return 0;
    }
};


4)
class Solution {
public:
    int lengthOfLoop(Node* head) {
        Node *s = head, *f = head;
        while (f && f->next) {
            s = s->next;
            f = f->next->next;
            if (s == f) {
                int cnt = 1;
                while (s->next != f) s = s->next, cnt++;
                return cnt;
            }
        }
        return 0;
    }
};


5)
class Solution {
public:
    int lengthOfLoop(Node* head) {
        unordered_set<Node*> visited;
        Node* curr = head;
        while (curr) {
            if (visited.count(curr)) {
                int len = 1;
                Node* start = curr->next;
                while (start != curr) start = start->next, len++;
                return len;
            }
            visited.insert(curr);
            curr = curr->next;
        }
        return 0;
    }
};


6)
class Solution {
public:
    int lengthOfLoop(Node* head) {
        Node *slow = head, *fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) break;
        }
        if (!fast || !fast->next) return 0;
        
        fast = head;
        while (slow != fast) slow = slow->next, fast = fast->next;
        
        int length = 1;
        fast = slow->next;
        while (fast != slow) fast = fast->next, length++;
        return length;
    }
};


7)
class Solution {
public:
    int lengthOfLoop(Node* head) {
        if (!head || !head->next) return 0;
        
        Node *slow = head->next, *fast = head->next->next;
        while (fast && fast->next && slow != fast) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        if (!fast || !fast->next) return 0;
        
        int count = 1;
        fast = slow->next;
        while (fast != slow) {
            fast = fast->next;
            count++;
        }
        return count;
    }
};
