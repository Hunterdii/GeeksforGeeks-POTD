class Solution {
public:
    int countBalanced(vector<string>& arr) {
        int res = 0, sum = 0;
        unordered_map<int, int> mp{{0, 1}};
        for (string& s : arr) {
            int score = 0;
            for (char c : s) score += (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') ? 1 : -1;
            res += mp[sum += score]++;
        }
        return res;
    }
};

2)
class Solution {
public:
    int countBalanced(vector<string>& arr) {
        int vowels = (1 << ('a' - 'a')) | (1 << ('e' - 'a')) | (1 << ('i' - 'a')) | (1 << ('o' - 'a')) | (1 << ('u' - 'a'));
        int res = 0, sum = 0;
        unordered_map<int, int> mp{{0, 1}};
        for (auto& s : arr) {
            for (char c : s) sum += (vowels & (1 << (c - 'a'))) ? 1 : -1;
            res += mp[sum]++;
        }
        return res;
    }
};


3)
class Solution {
public:
    int countBalanced(vector<string>& arr) {
        vector<int> freq(200001, 0);
        int offset = 100000, res = 0, sum = offset;
        freq[offset] = 1;
        for (auto& s : arr) {
            for (char c : s) sum += (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') ? 1 : -1;
            res += freq[sum]++;
        }
        return res;
    }
};


4)
class Solution {
public:
    int countBalanced(vector<string>& arr) {
        auto isVowel = [](char c) { return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'; };
        unordered_map<int, int> mp{{0, 1}};
        int res = 0, sum = 0;
        for (auto& s : arr) {
            for (char c : s) sum += isVowel(c) ? 1 : -1;
            res += mp[sum]++;
        }
        return res;
    }
};

5)
class Solution {
public:
    int countBalanced(vector<string>& arr) {
        string vowels = "aeiou";
        unordered_map<int, int> mp{{0, 1}};
        int res = 0, sum = 0;
        for (auto& s : arr) {
            for (char c : s) sum += (vowels.find(c) != string::npos) ? 1 : -1;
            res += mp[sum]++;
        }
        return res;
    }
};
