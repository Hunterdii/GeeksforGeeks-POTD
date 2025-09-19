class Solution {
public:
    int minParentheses(string& s) {
        int open = 0, close = 0;
        for (char c : s) {
            if (c == '(') open++;
            else if (c == ')') open > 0 ? open-- : close++;
        }
        return open + close;
    }
};


2)
class Solution {
public:
    int minParentheses(string& s) {
        int balance = 0, additions = 0;
        for (char c : s) {
            balance += (c == '(') ? 1 : (c == ')') ? -1 : 0;
            if (balance < 0) additions++, balance = 0;
        }
        return balance + additions;
    }
};


3)
class Solution {
public:
    int minParentheses(string& s) {
        int stack_size = 0, unmatched = 0;
        for (char& c : s) {
            if (c == '(') stack_size++;
            else if (c == ')') {
                stack_size ? stack_size-- : unmatched++;
            }
        }
        return stack_size + unmatched;
    }
};


4)
class Solution {
public:
    int minParentheses(string& s) {
        int open = 0, close = 0;
        for (unsigned char c : s) {
            open += (c == 40);
            close += (c == 41) & (open == 0);
            open -= (c == 41) & (open > 0);
        }
        return open + close;
    }
};
