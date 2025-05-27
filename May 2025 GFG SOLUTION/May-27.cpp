class Solution {
  public:
    vector<int> leafNodes(vector<int>& p) {
        stack<int> s;
        vector<int> r;
        for (int i = 0, j = 1; j < p.size(); i++, j++) {
            bool f = 0;
            if (p[i] > p[j]) s.push(p[i]);
            else while (!s.empty() && p[j] > s.top()) s.pop(), f = 1;
            if (f) r.push_back(p[i]);
        }
        r.push_back(p.back());
        return r;
    }
};


2)
class Solution {
  public:
    struct Node { int v; Node *l,*r; Node(int x):v(x),l(0),r(0){} };
    Node* build(vector<int>& P, int& i, int UB) {
        if (i==P.size()||P[i]>UB) return nullptr;
        Node* n=new Node(P[i++]);
        n->l=build(P,i,n->v);
        n->r=build(P,i,UB);
        return n;
    }
    void dfs(Node* u, vector<int>& L) {
        if(!u) return;
        if(!u->l&&!u->r) L.push_back(u->v);
        dfs(u->l,L); dfs(u->r,L);
    }
    vector<int> leafNodes(vector<int>& P) {
        int i=0; auto root=build(P,i,INT_MAX);
        vector<int> L; dfs(root,L);
        return L;
    }
};


3)
class Solution {
  public:
    void dc(int l, int r, vector<int>& P, vector<int>& L) {
        if (l>r) return;
        if (l==r) { L.push_back(P[l]); return; }
        int m = l+1;
        while (m<=r && P[m]<P[l]) ++m;
        dc(l+1,m-1,P,L);
        dc(m,r,P,L);
    }
    vector<int> leafNodes(vector<int>& P) {
        vector<int> L;
        dc(0,P.size()-1,P,L);
        return L;
    }
};


