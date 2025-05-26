/* structure for a node
class Node {
 public:
  int data;
  Node *next;

  Node(int x){
      data = x;
      next = NULL;
  }
}; */

class Solution {
  public:
    Node* sortedInsert(Node* head, int data) {
        Node* n = new Node(data);
        if (!head) {
            n->next = n;
            return n;
        }
        Node* cur = head;
        while (true) {
            Node* nxt = cur->next;
            if ((cur->data <= data && data <= nxt->data) ||
                (cur->data > nxt->data && (data >= cur->data || data <= nxt->data)) ||
                nxt == head) {
                cur->next = n;
                n->next = nxt;
                if (data < head->data) head = n;
                break;
            }
            cur = nxt;
        }
        return head;
    }
};

2)
class Solution {
  public:
    Node* sortedInsert(Node* head, int data) {
        Node* n = new Node(data);
        if (!head) {
            n->next = n;
            return n;
        }
        Node* cur = head;
        do {
            Node* nxt = cur->next;
            if ((cur->data <= data && data <= nxt->data) ||
                (cur->data > nxt->data && (data >= cur->data || data <= nxt->data))) {
                cur->next = n;
                n->next = nxt;
                if (data < head->data) head = n;
                break;
            }
            cur = nxt;
        } while (cur != head);
        return head;
    }
};

3)
class Solution {
  public:
    Node* sortedInsert(Node* head, int data) {
        Node* n = new Node(data);
        if (!head) { n->next = n; return n; }
        Node* maxNode = head;
        while (maxNode->next != head && maxNode->data <= maxNode->next->data)
            maxNode = maxNode->next;
        Node* cur = maxNode->next;
        while (cur != maxNode && !(cur->data <= data && data <= cur->next->data))
            cur = cur->next;
        if (cur == maxNode && !(cur->data <= data && data <= cur->next->data))
            cur = maxNode;
        n->next = cur->next;
        cur->next = n;
        if (data < head->data) head = n;
        return head;
    }
};

4)
class Solution {
  public:
    Node* sortedInsert(Node* head, int data) {
        Node* n = new Node(data);
        if (!head) { n->next = n; return n; }
        Node* tail = head;
        while (tail->next != head) tail = tail->next;
        tail->next = nullptr;

        if (data < head->data) {
            n->next = head;
            head = n;
        } else {
            Node* cur = head;
            while (cur->next && cur->next->data < data) cur = cur->next;
            n->next = cur->next;
            cur->next = n;
        }

        tail = head;
        while (tail->next) tail = tail->next;
        tail->next = head;
        return head;
    }
};
