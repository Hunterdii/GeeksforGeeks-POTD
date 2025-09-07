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
    Node* mergeKLists(vector<Node*>& arr) {
        auto cmp = [](Node* a, Node* b) { return a->data > b->data; };
        priority_queue<Node*, vector<Node*>, decltype(cmp)> pq(cmp);
        
        for (Node* head : arr) if (head) pq.push(head);
        
        Node dummy(-1), *tail = &dummy;
        while (!pq.empty()) {
            Node* node = pq.top(); pq.pop();
            tail->next = node; tail = node;
            if (node->next) pq.push(node->next);
        }
        return dummy.next;
    }
};


2)
class Solution {
public:
    Node* mergeKLists(vector<Node*>& arr) {
        if (arr.empty()) return nullptr;
        while (arr.size() > 1) {
            vector<Node*> temp;
            for (int i = 0; i < arr.size(); i += 2) {
                Node* l1 = arr[i];
                Node* l2 = (i + 1 < arr.size()) ? arr[i + 1] : nullptr;
                temp.push_back(merge2Lists(l1, l2));
            }
            arr = temp;
        }
        return arr[0];
    }
    
private:
    Node* merge2Lists(Node* l1, Node* l2) {
        Node dummy(-1), *tail = &dummy;
        while (l1 && l2) {
            if (l1->data <= l2->data) {
                tail->next = l1; l1 = l1->next;
            } else {
                tail->next = l2; l2 = l2->next;
            }
            tail = tail->next;
        }
        tail->next = l1 ? l1 : l2;
        return dummy.next;
    }
};


3)
class Solution {
public:
    Node* mergeKLists(vector<Node*>& arr) {
        vector<int> values;
        for (Node* head : arr) {
            while (head) {
                values.push_back(head->data);
                head = head->next;
            }
        }
        sort(values.begin(), values.end());
        
        Node dummy(-1), *tail = &dummy;
        for (int val : values) {
            tail->next = new Node(val);
            tail = tail->next;
        }
        return dummy.next;
    }
};


4)
class Solution {
public:
    Node* mergeKLists(vector<Node*>& arr) {
        if (arr.empty()) return nullptr;
        Node* result = arr[0];
        for (int i = 1; i < arr.size(); i++) {
            result = merge2Lists(result, arr[i]);
        }
        return result;
    }
    
private:
    Node* merge2Lists(Node* l1, Node* l2) {
        Node dummy(-1), *tail = &dummy;
        while (l1 && l2) {
            if (l1->data <= l2->data) {
                tail->next = l1; l1 = l1->next;
            } else {
                tail->next = l2; l2 = l2->next;
            }
            tail = tail->next;
        }
        tail->next = l1 ? l1 : l2;
        return dummy.next;
    }
};
