class Solution {
public:
    int sumOfModes(vector<int>& arr, int k) {
        int n = arr.size(), sum = 0;
        unordered_map<int, int> freq;
        map<int, set<int>> buckets;
        
        for (int i = 0; i < k; i++) freq[arr[i]]++;
        for (auto& p : freq) buckets[p.second].insert(p.first);
        sum += *buckets.rbegin()->second.begin();
        
        for (int i = k; i < n; i++) {
            int out = arr[i - k], in = arr[i];
            
            buckets[freq[out]].erase(out);
            if (buckets[freq[out]].empty()) buckets.erase(freq[out]);
            if (--freq[out] > 0) buckets[freq[out]].insert(out);
            else freq.erase(out);
            
            if (freq[in] > 0) {
                buckets[freq[in]].erase(in);
                if (buckets[freq[in]].empty()) buckets.erase(freq[in]);
            }
            buckets[++freq[in]].insert(in);
            
            sum += *buckets.rbegin()->second.begin();
        }
        return sum;
    }
};

2)
class Solution {
public:
    int sumOfModes(vector<int>& arr, int k) {
        int n = arr.size(), sum = 0;
        unordered_map<int, int> freq;
        priority_queue<pair<int, int>> pq;
        
        for (int i = 0; i < k; i++) freq[arr[i]]++;
        for (auto& p : freq) pq.push({p.second, -p.first});
        
        auto getMode = [&]() {
            while (!pq.empty() && freq[-pq.top().second] != pq.top().first) pq.pop();
            return -pq.top().second;
        };
        
        sum += getMode();
        for (int i = k; i < n; i++) {
            int out = arr[i - k], in = arr[i];
            if (--freq[out] == 0) freq.erase(out);
            else pq.push({freq[out], -out});
            pq.push({++freq[in], -in});
            sum += getMode();
        }
        return sum;
    }
};

3)
class Solution {
public:
    int sumOfModes(vector<int>& arr, int k) {
        int n = arr.size(), sum = 0;
        unordered_map<int, int> freq;
        for (int i = 0; i < k; i++) freq[arr[i]]++;
        auto getMode = [&]() {
            int maxFreq = 0;
            for (auto& p : freq) maxFreq = max(maxFreq, p.second);
            int mode = INT_MAX;
            for (auto& p : freq) 
                if (p.second == maxFreq) mode = min(mode, p.first);
            return mode;
        };
        sum += getMode();
        for (int i = k; i < n; i++) {
            int out = arr[i - k], in = arr[i];
            if (--freq[out] == 0) freq.erase(out);
            freq[in]++;
            sum += getMode();
        }
        return sum;
    }
};

4)
class Solution {
public:
    int sumOfModes(vector<int>& arr, int k) {
        int n = arr.size(), sum = 0;
        unordered_map<int, int> freq;
        multiset<pair<int, int>> ms; 
        for (int i = 0; i < k; i++) freq[arr[i]]++;
        for (auto& p : freq) ms.insert({p.second, -p.first});
        sum += -ms.rbegin()->second;
        for (int i = k; i < n; i++) {
            int out = arr[i - k], in = arr[i];
            ms.erase(ms.find({freq[out], -out}));
            if (--freq[out] > 0) ms.insert({freq[out], -out});
            else freq.erase(out);
            if (freq[in] > 0) ms.erase(ms.find({freq[in], -in}));
            freq[in]++;
            ms.insert({freq[in], -in});
            
            sum += -ms.rbegin()->second;
        }
        return sum;
    }
};

5)
class Solution {
public:
    int sumOfModes(vector<int>& arr, int k) {
        int n = arr.size(), sum = 0;
        unordered_map<int, int> freq;
        priority_queue<pair<int, int>> pq;
        for (int i = 0; i < k; i++) freq[arr[i]]++;
        for (auto& p : freq) pq.push({p.second, -p.first});
        auto getMode = [&]() {
            while (!pq.empty() && freq[-pq.top().second] != pq.top().first) 
                pq.pop();
            return -pq.top().second;
        };
        sum += getMode();
        for (int i = k; i < n; i++) {
            int out = arr[i - k], in = arr[i];
            if (--freq[out] == 0) freq.erase(out);
            else pq.push({freq[out], -out});
            pq.push({++freq[in], -in});
            sum += getMode();
        }
        return sum;
    }
};
