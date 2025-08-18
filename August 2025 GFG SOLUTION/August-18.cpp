class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        vector<int> bucket(n + 1, 0);
        
        for (int c : citations) bucket[min(c, n)]++;
        
        int count = 0;
        for (int i = n; i >= 0; i--) {
            count += bucket[i];
            if (count >= i) return i;
        }
        return 0;
    }
};

2)
class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.rbegin(), citations.rend());
        int h = 0;
        for (int i = 0; i < citations.size() && citations[i] > h; i++) h++;
        return h;
    }
};

3)
class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size(), left = 0, right = n;
        while (left < right) {
            int mid = left + (right - left + 1) / 2;
            int count = 0;
            for (int c : citations) if (c >= mid) count++;
            if (count >= mid) left = mid;
            else right = mid - 1;
        }
        return left;
    }
};

4)
class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        vector<int> papers(n + 1);
        for (int c : citations) papers[min(c, n)]++;
        
        int k = n;
        for (int s = papers[n]; k > s; s += papers[--k]);
        return k;
    }
};
