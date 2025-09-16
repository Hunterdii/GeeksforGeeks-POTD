class Solution {
public:
    int evaluatePostfix(vector<string>& arr) {
        stack<int> st;
        for (const auto& t : arr) {
            if (t.size() == 1 && strchr("+-*/^", t[0])) {
                int b = st.top(); st.pop();
                int a = st.top(); st.pop();
                if (t[0] == '/') st.push((a < 0) ^ (b < 0) && a % b ? a / b - 1 : a / b);
                else st.push(t[0] == '+' ? a + b : t[0] == '-' ? a - b : 
                          t[0] == '*' ? a * b : pow(a, b));
            } else st.push(stoi(t));
        }
        return st.top();
    }
};

2)
class Solution {
public:
    int evaluatePostfix(vector<string>& arr) {
        int stack[arr.size()], top = -1;
        for (const string& t : arr) {
            if (t.size() == 1) {
                switch (t[0]) {
                    case '+': { int b = stack[top--], a = stack[top--]; stack[++top] = a + b; break; }
                    case '-': { int b = stack[top--], a = stack[top--]; stack[++top] = a - b; break; }
                    case '*': { int b = stack[top--], a = stack[top--]; stack[++top] = a * b; break; }
                    case '/': { int b = stack[top--], a = stack[top--]; 
                              stack[++top] = (a < 0) ^ (b < 0) && a % b ? a / b - 1 : a / b; break; }
                    case '^': { int b = stack[top--], a = stack[top--]; stack[++top] = pow(a, b); break; }
                    default: stack[++top] = stoi(t); break;
                }
            } else stack[++top] = stoi(t);
        }
        return stack[top];
    }
};

3)
class Solution {
public:
    int evaluatePostfix(vector<string>& arr) {
        int idx = arr.size() - 1;
        return helper(arr, idx);
    }
    
private:
    int helper(vector<string>& arr, int& idx) {
        string t = arr[idx--];
        if (t.size() == 1 && strchr("+-*/^", t[0])) {
            int right = helper(arr, idx);
            int left = helper(arr, idx);
            if (t[0] == '/') return (left < 0) ^ (right < 0) && left % right ? left / right - 1 : left / right;
            return t[0] == '+' ? left + right : t[0] == '-' ? left - right :
                  t[0] == '*' ? left * right : pow(left, right);
        }
        return stoi(t);
    }
};

4)
class Solution {
public:
    int evaluatePostfix(vector<string>& arr) {
        vector<int> st;
        st.reserve(arr.size());
        for (auto& t : arr) {
            if (t == "+") { int b = st.back(); st.pop_back(); st.back() += b; }
            else if (t == "-") { int b = st.back(); st.pop_back(); st.back() -= b; }
            else if (t == "*") { int b = st.back(); st.pop_back(); st.back() *= b; }
            else if (t == "/") { int b = st.back(); st.pop_back(); int a = st.back(); 
                                st.back() = (a < 0) ^ (b < 0) && a % b ? a / b - 1 : a / b; }
            else if (t == "^") { int b = st.back(); st.pop_back(); st.back() = pow(st.back(), b); }
            else st.push_back(stoi(t));
        }
        return st.back();
    }
};
