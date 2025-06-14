/*
class Node {
public:
    int data;
    Node *left, *right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/

class Solution {
 public:
    bool isSymmetric(Node* r){
        if(!r) return true;
        stack<Node*> s1,s2;
        s1.push(r->left);
        s2.push(r->right);
        while(!s1.empty()){
            Node* u=s1.top(); s1.pop();
            Node* v=s2.top(); s2.pop();
            if(!u&&!v) continue;
            if(!u||!v||u->data!=v->data) return false;
            s1.push(u->left);  s2.push(v->right);
            s1.push(u->right); s2.push(v->left);
        }
        return true;
    }
};


2)
class Solution {
  public:
    bool isSymmetric(Node* root) {
        if (!root) return true;
        stack<Node*> s1, s2;
        s1.push(root->left);
        s2.push(root->right);
        while (!s1.empty() && !s2.empty()) {
            Node* a = s1.top(); s1.pop();
            Node* b = s2.top(); s2.pop();
            if (!a && !b) continue;
            if (!a || !b || a->data != b->data) return false;
            s1.push(a->left); s2.push(b->right);
            s1.push(a->right); s2.push(b->left);
        }
        return s1.empty() && s2.empty();
    }
};


3)
class Solution {
  bool isSym(Node* a, Node* b){
    if(!a||!b) return a==b;
    if(a->data!=b->data) return false;
    return isSym(a->left,b->right)&&isSym(a->right,b->left);
  }
 public:
    bool isSymmetric(Node* r){
        return !r||isSym(r->left,r->right);
    }
};
