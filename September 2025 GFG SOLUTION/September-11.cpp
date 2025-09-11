class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        if (n <= 1) return 0;
        
        int jumps = 0, currentEnd = 0, farthest = 0;
        for (int i = 0; i < n - 1; i++) {
            farthest = max(farthest, i + arr[i]);
            if (i == currentEnd) {
                jumps++;
                currentEnd = farthest;
            }
        }
        return currentEnd >= n - 1 ? jumps : -1;
    }
};

2)
class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        if (n == 1) return 0;
        int jumps = 0, reach = 0, farthest = 0;
        for (int i = 0; i < n - 1; i++) {
            farthest = max(farthest, i + arr[i]);
            if (i == reach) {
                jumps++;
                reach = farthest;
                if (reach >= n - 1) return jumps;
            }
        }
        return -1;
    }
};

3)
class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size(), jumps = 0, far = 0, end = 0;
        for (int i = 0; i < n - 1; i++) {
            far = max(far, i + arr[i]);
            if (i == end) jumps++, end = far;
            if (end >= n - 1) return jumps;
        }
        return -1;
    }
};

4)
class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size(), near = 0, far = 0, jumps = 0;
        while (far < n - 1) {
            int temp = far;
            for (int i = near; i <= far; i++) {
                temp = max(temp, i + arr[i]);
            }
            if (temp == far) return -1;
            near = far + 1;
            far = temp;
            jumps++;
        }
        return jumps;
    }
};

5)
class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        if (n <= 1) return 0;
        
        int level = 0, currentMax = 0, nextMax = 0;
        
        for (int i = 0; i < n - 1; i++) {
            nextMax = max(nextMax, i + arr[i]);
            
            if (i == currentMax) {
                level++;
                currentMax = nextMax;
                
                if (currentMax >= n - 1) return level;
                if (currentMax <= i) return -1;
            }
        }
        
        return -1;
    }
};

6)
class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        if (n <= 1) return 0;
        if (arr[0] == 0) return -1;
        
        int jumps = 0, current_end = 0, farthest = 0;
        
        for (int i = 0; i < n - 1; i++) {
            farthest = max(farthest, i + arr[i]);
            
            if (i == current_end) {
                jumps++;
                current_end = farthest;
                
                if (current_end >= n - 1) break;
                if (current_end <= i) return -1;
            }
        }
        
        return jumps;
    }
};
