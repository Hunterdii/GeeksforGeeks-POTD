class Solution {
public:
    void reverseQueue(queue<int>& q) {
        if (q.empty()) return;
        int x = q.front();
        q.pop();
        reverseQueue(q);
        q.push(x);
    }
};

2)
class Solution {
public:
    void reverseQueue(queue<int>& q) {
        stack<int> s;
        while (!q.empty()) s.push(q.front()), q.pop();
        while (!s.empty()) q.push(s.top()), s.pop();
    }
};

3)
class Solution {
public:
    void reverseQueue(queue<int>& q) {
        vector<int> v;
        while (!q.empty()) v.push_back(q.front()), q.pop();
        for (auto it = v.rbegin(); it != v.rend(); ++it) q.push(*it);
    }
};

4)
class Solution {
public:
    void reverseQueue(queue<int>& q) {
        int n = q.size(), arr[n], i = 0;
        while (!q.empty()) arr[i++] = q.front(), q.pop();
        while (--i >= 0) q.push(arr[i]);
    }
};

5)
class Solution {
public:
    void reverseQueue(queue<int>& q) {
        deque<int> dq;
        while (!q.empty()) {
            dq.push_back(q.front());
            q.pop();
        }
        while (!dq.empty()) {
            q.push(dq.back());
            dq.pop_back();
        }
    }
};
