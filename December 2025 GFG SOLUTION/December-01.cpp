class Solution {
public:
    class T {
    public:
        T* c[2];
        int n;
        T() { c[0] = c[1] = NULL; n = 0; }
    };
    void add(T* r, int v) {
        for (int i = 31; i >= 0; i--) {
            int b = (v >> i) & 1;
            if (!r->c[b]) r->c[b] = new T();
            r->c[b]->n++;
            r = r->c[b];
        }
    }
    int cnt(T* r, int v, int k) {
        int res = 0;
        for (int i = 31; i >= 0 && r; i--) {
            int bv = (v >> i) & 1, bk = (k >> i) & 1;
            if (bk) {
                if (r->c[bv]) res += r->c[bv]->n;
                r = r->c[1 - bv];
            } else r = r->c[bv];
        }
        return res;
    }
    int cntPairs(vector<int>& a, int k) {
        T* r = new T();
        int ans = 0;
        for (int x : a) {
            ans += cnt(r, x, k);
            add(r, x);
        }
        return ans;
    }
};

2)
class Solution {
public:
    struct Node {
        Node* ch[2] = {};
        int freq = 0;
    };
    void insert(Node* root, int val) {
        for (int i = 31; i >= 0; i--) {
            int bit = (val >> i) & 1;
            if (!root->ch[bit]) root->ch[bit] = new Node();
            root->ch[bit]->freq++;
            root = root->ch[bit];
        }
    }
    int query(Node* root, int val, int k) {
        int count = 0;
        for (int i = 31; i >= 0 && root; i--) {
            int vb = (val >> i) & 1, kb = (k >> i) & 1;
            if (kb) {
                if (root->ch[vb]) count += root->ch[vb]->freq;
                root = root->ch[!vb];
            } else {
                root = root->ch[vb];
            }
        }
        return count;
    }
    int cntPairs(vector<int>& a, int k) {
        Node* root = new Node();
        int result = 0;
        for (int x : a) {
            result += query(root, x, k);
            insert(root, x);
        }
        return result;
    }
};

3)
class Solution {
public:
    int cntPairs(vector<int>& a, int k) {
        int ans = 0, n = a.size();
        for (int i = 0; i < n; i++)
            for (int j = i + 1; j < n; j++)
                if ((a[i] ^ a[j]) < k) ans++;
        return ans;
    }
};

4)
class Solution {
public:
    int cntPairs(vector<int>& a, int k) {
        unordered_map<int, int> m;
        int ans = 0;
        for (int x : a) {
            for (auto& p : m) 
                if ((x ^ p.first) < k) ans += p.second;
            m[x]++;
        }
        return ans;
    }
};
