class Solution {
public:
    int findLength(vector<int>& color, vector<int>& radius) {
        int n = color.size();
        stack<int> st;
        for (int i = 0; i < n; ++i)
            if (!st.empty() && color[i] == color[st.top()] && radius[i] == radius[st.top()])
                st.pop();
            else
                st.push(i);
        return st.size();
    }
};


2)
class Solution {
public:
    int findLength(vector<int>& color, vector<int>& radius) {
        int n = color.size(), j = -1;
        for (int i = 0; i < n; ++i) {
            if (j >= 0 && color[i] == color[j] && radius[i] == radius[j])
                --j;
            else {
                ++j;
                color[j] = color[i];
                radius[j] = radius[i];
            }
        }
        return j + 1;
    }
};
