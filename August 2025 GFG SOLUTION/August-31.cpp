class Solution {
public:
    int maxWater(vector<int>& h) {
        int l = 0, r = h.size() - 1, ans = 0;
        while (l < r) {
            ans = max(ans, min(h[l], h[r]) * (r - l));
            h[l] < h[r] ? ++l : --r;
        }
        return ans;
    }
};

2)
class Solution {
public:
    int maxWater(vector<int>& h) {
        int l = 0, r = h.size() - 1, maxArea = 0;
        while (l < r) {
            int width = r - l;
            if (h[l] < h[r]) {
                maxArea = max(maxArea, h[l] * width);
                ++l;
            } else {
                maxArea = max(maxArea, h[r] * width);
                --r;
            }
        }
        return maxArea;
    }
};

3)
class Solution {
public:
    int maxWater(vector<int>& h) {
        int l = 0, r = h.size() - 1, area = 0;
        while (l < r) {
            area = max(area, (r - l) * (h[l] < h[r] ? h[l++] : h[r--]));
        }
        return area;
    }
};

4)
class Solution {
public:
    int maxWater(vector<int>& h) {
        int n = h.size();
        int maxHeight = *max_element(h.begin(), h.end());
        int l = 0, r = n - 1, maxArea = 0;
        while (l < r) {
            int currentArea = min(h[l], h[r]) * (r - l);
            maxArea = max(maxArea, currentArea);
            if ((r - l - 1) * maxHeight <= maxArea) break;
            
            h[l] < h[r] ? ++l : --r;
        }
        return maxArea;
    }
};

5)
class Solution {
public:
    int maxWater(vector<int>& h) {
        int n = h.size(), maxArea = 0;
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                maxArea = max(maxArea, min(h[i], h[j]) * (j - i));
            }
        }
        return maxArea;
    }
};
