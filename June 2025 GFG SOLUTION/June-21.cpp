class Solution {
public:
    int catchThieves(vector<char> &arr, int k) {
        int n = arr.size(), i = 0, j = 0, c = 0;
        while (i < n && j < n) {
            while (i < n && arr[i] != 'P') i++;
            while (j < n && arr[j] != 'T') j++;
            if (i < n && j < n && abs(i - j) <= k) i++, j++, c++;
            else if (j < i) j++;
            else i++;
        }
        return c;
    }
};

2)
class Solution {
public:
    int catchThieves(vector<char> &arr, int k) {
        queue<int> police, thief;
        int count = 0;
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] == 'P') police.push(i);
            else if (arr[i] == 'T') thief.push(i);
        }
        while (!police.empty() && !thief.empty()) {
            int p = police.front(), t = thief.front();
            if (abs(p - t) <= k) {
                count++;
                police.pop();
                thief.pop();
            } else if (t < p) thief.pop();
            else police.pop();
        }
        return count;
    }
};

3)
class Solution {
public:
    int catchThieves(vector<char> &arr, int k) {
        vector<int> police, thieves;
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] == 'P') police.push_back(i);
            else if (arr[i] == 'T') thieves.push_back(i);
        }
        int i = 0, j = 0, count = 0;
        while (i < police.size() && j < thieves.size()) {
            if (abs(police[i] - thieves[j]) <= k) {
                count++;
                i++;
                j++;
            } else if (police[i] < thieves[j]) {
                i++;
            } else {
                j++;
            }
        }
        return count;
    }
};


4)
class Solution {
public:
    int catchThieves(vector<char> &arr, int k) {
        vector<int> thieves;
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] == 'T') thieves.push_back(i);
        }
        set<int> available(thieves.begin(), thieves.end());
        int count = 0;
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] == 'P') {
                auto it = available.lower_bound(i - k);
                if (it != available.end() && *it <= i + k) {
                    available.erase(it);
                    count++;
                }
            }
        }
        return count;
    }
};
