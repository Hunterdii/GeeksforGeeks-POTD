class SpecialQueue {
    queue<int> q;
    deque<int> mn, mx;
public:
    void enqueue(int x) {
        q.push(x);
        while (!mn.empty() && mn.back() > x) mn.pop_back();
        mn.push_back(x);
        while (!mx.empty() && mx.back() < x) mx.pop_back();
        mx.push_back(x);
    }
    void dequeue() {
        int f = q.front(); q.pop();
        if (f == mn.front()) mn.pop_front();
        if (f == mx.front()) mx.pop_front();
    }
    int getFront() { return q.front(); }
    int getMin() { return mn.front(); }
    int getMax() { return mx.front(); }
};

2)
class SpecialQueue {
    stack<int> in, out, minIn, maxIn, minOut, maxOut;
    void transfer() {
        while (!in.empty()) {
            int x = in.top(); in.pop();
            out.push(x);
            minOut.push(minOut.empty() ? x : min(x, minOut.top()));
            maxOut.push(maxOut.empty() ? x : max(x, maxOut.top()));
        }
        while (!minIn.empty()) minIn.pop();
        while (!maxIn.empty()) maxIn.pop();
    }
public:
    void enqueue(int x) {
        in.push(x);
        minIn.push(minIn.empty() ? x : min(x, minIn.top()));
        maxIn.push(maxIn.empty() ? x : max(x, maxIn.top()));
    }
    void dequeue() {
        if (out.empty()) transfer();
        out.pop(); minOut.pop(); maxOut.pop();
    }
    int getFront() {
        if (out.empty()) transfer();
        return out.top();
    }
    int getMin() {
        int mn = INT_MAX;
        if (!minIn.empty()) mn = min(mn, minIn.top());
        if (!minOut.empty()) mn = min(mn, minOut.top());
        return mn;
    }
    int getMax() {
        int mx = INT_MIN;
        if (!maxIn.empty()) mx = max(mx, maxIn.top());
        if (!maxOut.empty()) mx = max(mx, maxOut.top());
        return mx;
    }
};



3)
class SpecialQueue {
    queue<pair<int,int>> q;
    deque<pair<int,int>> minQ, maxQ;
    int timestamp;
public:
    SpecialQueue() : timestamp(0) {}
    
    void enqueue(int x) {
        q.push({x, timestamp});
        while (!minQ.empty() && minQ.back().first > x) minQ.pop_back();
        minQ.push_back({x, timestamp});
        while (!maxQ.empty() && maxQ.back().first < x) maxQ.pop_back();
        maxQ.push_back({x, timestamp});
        timestamp++;
    }
    
    void dequeue() {
        auto front = q.front(); q.pop();
        if (minQ.front().second == front.second) minQ.pop_front();
        if (maxQ.front().second == front.second) maxQ.pop_front();
    }
    
    int getFront() { return q.front().first; }
    int getMin() { return minQ.front().first; }
    int getMax() { return maxQ.front().first; }
};
