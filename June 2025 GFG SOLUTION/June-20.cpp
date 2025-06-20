class Solution {
public:
    bool validgroup(vector<int> &arr, int k) {
        map<int, int> m;
        for (int x : arr) m[x]++;
        for (auto& p : m) {
            int v = p.first, f = p.second;
            if (f == 0) continue;
            for (int i = 1; i < k; i++) {
                if (m[v + i] < f) return false;
                m[v + i] -= f;
            }
        }
        return true;
    }
};


2)
class Solution {
public:
    bool validgroup(vector<int> &arr, int k) {
        map<int, int> freq;
        for (int val : arr) freq[val]++;
        
        auto it = freq.begin();
        while (it != freq.end()) {
            if (it->second == 0) {
                ++it;
                continue;
            }
            int start = it->first, count = it->second;
            for (int i = 0; i < k; i++) {
                if (freq[start + i] < count) return false;
                freq[start + i] -= count;
            }
            ++it;
        }
        return true;
    }
};


3)
class Solution {
public:
    bool validgroup(vector<int> &arr, int k) {
        int minVal = *min_element(arr.begin(), arr.end());
        int maxVal = *max_element(arr.begin(), arr.end());
        vector<int> freq(maxVal - minVal + 1, 0);
        
        for (int val : arr) freq[val - minVal]++;
        
        for (int i = 0; i < freq.size(); i++) {
            if (freq[i] == 0) continue;
            int count = freq[i];
            for (int j = 1; j < k; j++) {
                if (i + j >= freq.size() || freq[i + j] < count) 
                    return false;
                freq[i + j] -= count;
            }
        }
        return true;
    }
};


4)
class Solution {
public:
    bool validgroup(vector<int> &arr, int k) {
        sort(arr.begin(), arr.end());
        unordered_map<int, int> freq;
        for (int x : arr) freq[x]++;
        
        for (int x : arr) {
            if (freq[x] == 0) continue;
            int count = freq[x];
            for (int i = 0; i < k; i++) {
                if (freq[x + i] < count) return false;
                freq[x + i] -= count;
            }
        }
        return true;
    }
};



