/*
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
public:
    int ans;
    pair<int,int> dfs(Node* r,int t){
        if(!r) return {0,-1};
        auto l=dfs(r->left,t), ri=dfs(r->right,t);
        int h=max(l.first,ri.first)+1, d=-1;
        if(r->data==t) d=0, ans=max(ans,h-1);
        else if(l.second>=0) d=l.second+1, ans=max(ans,ri.first+d);
        else if(ri.second>=0) d=ri.second+1, ans=max(ans,l.first+d);
        return {h,d};
    }
    int minTime(Node* root,int target){
        ans=0;
        dfs(root,target);
        return ans;
    }
};

2)
class Solution {
  void mapParents(Node* root, unordered_map<Node*, Node*>& par) {
    queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
      Node* cur = q.front(); q.pop();
      if (cur->left) par[cur->left] = cur, q.push(cur->left);
      if (cur->right) par[cur->right] = cur, q.push(cur->right);
    }
  }

  Node* findTarget(Node* root, int target) {
    if (!root) return nullptr;
    if (root->data == target) return root;
    Node* l = findTarget(root->left, target);
    if (l) return l;
    return findTarget(root->right, target);
  }

public:
  int minTime(Node* root, int target) {
    unordered_map<Node*, Node*> par;
    mapParents(root, par);
    Node* start = findTarget(root, target);
    
    unordered_set<Node*> vis;
    queue<Node*> q;
    q.push(start);
    vis.insert(start);

    int time = -1;
    while (!q.empty()) {
      int sz = q.size();
      time++;
      for (int i = 0; i < sz; ++i) {
        Node* cur = q.front(); q.pop();
        if (cur->left && !vis.count(cur->left)) vis.insert(cur->left), q.push(cur->left);
        if (cur->right && !vis.count(cur->right)) vis.insert(cur->right), q.push(cur->right);
        if (par[cur] && !vis.count(par[cur])) vis.insert(par[cur]), q.push(par[cur]);
      }
    }
    return time;
  }
};

3)
class Solution {
  int ans = 0;

  int dfs(Node* root, int target, int& dist) {
    if (!root) return 0;
    
    if (root->data == target) {
      dist = 0;
      int l = dfs(root->left, target, dist), r = dfs(root->right, target, dist);
      ans = max(ans, max(l, r));
      return max(l, r) + 1;
    }

    int ldist = -1, rdist = -1;
    int lh = dfs(root->left, target, ldist);
    int rh = dfs(root->right, target, rdist);

    if (ldist != -1) {
      dist = ldist + 1;
      ans = max(ans, dist + rh);
    } else if (rdist != -1) {
      dist = rdist + 1;
      ans = max(ans, dist + lh);
    }

    return max(lh, rh) + 1;
  }

public:
  int minTime(Node* root, int target) {
    int dist = -1;
    dfs(root, target, dist);
    return ans;
  }
};

