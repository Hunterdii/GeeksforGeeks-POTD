class Solution {
public:
    void rotateDeque(deque<int>& dq, int type, int k) {
        int n = dq.size();
        if (n == 0 || (k %= n) == 0) return;
        
        if (type == 1) {
            for (int i = 0; i < k; i++) {
                dq.push_front(dq.back());
                dq.pop_back();
            }
        } else {
            for (int i = 0; i < k; i++) {
                dq.push_back(dq.front());
                dq.pop_front();
            }
        }
    }
};

2)
class Solution {
public:
    void rotateDeque(deque<int>& dq, int type, int k) {
        int n = dq.size();
        if (n == 0 || (k %= n) == 0) return;
        
        if (type == 1) 
            rotate(dq.begin(), dq.end() - k, dq.end());
        else 
            rotate(dq.begin(), dq.begin() + k, dq.end());
    }
};

3)
class Solution {
public:
    void rotateDeque(deque<int>& dq, int type, int k) {
        int n = dq.size();
        if (n == 0 || (k %= n) == 0) return;
        
        if (type == 1) k = n - k;
        
        list<int> temp(dq.begin(), dq.end());
        auto it = temp.begin();
        advance(it, k);
        temp.splice(temp.end(), temp, temp.begin(), it);
        dq.assign(temp.begin(), temp.end());
    }
};

4)
class Solution {
public:
    void reverseDeque(deque<int>& dq, int start, int end) {
        while (start < end) {
            swap(dq[start], dq[end]);
            start++;
            end--;
        }
    }
    
    void rotateDeque(deque<int>& dq, int type, int k) {
        int n = dq.size();
        if (n == 0 || (k %= n) == 0) return;
        
        if (type == 1) {
            reverseDeque(dq, 0, n - 1);
            reverseDeque(dq, 0, k - 1);
            reverseDeque(dq, k, n - 1);
        } else {
            reverseDeque(dq, 0, k - 1);
            reverseDeque(dq, k, n - 1);
            reverseDeque(dq, 0, n - 1);
        }
    }
};

5)
class Solution {
public:
    void rotateDeque(deque<int>& dq, int type, int k) {
        int n = dq.size();
        if (n == 0 || (k %= n) == 0) return;
        
        vector<int> temp(dq.begin(), dq.end());
        dq.clear();
        
        if (type == 1) {
            for (int i = n - k; i < n; i++) dq.push_back(temp[i]);
            for (int i = 0; i < n - k; i++) dq.push_back(temp[i]);
        } else {
            for (int i = k; i < n; i++) dq.push_back(temp[i]);
            for (int i = 0; i < k; i++) dq.push_back(temp[i]);
        }
    }
};
