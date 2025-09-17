class Solution {
    static String decodeString(String s) {
        Stack<StringBuilder> stStr = new Stack<>();
        Stack<Integer> stNum = new Stack<>();
        StringBuilder curr = new StringBuilder();
        int num = 0;
        
        for (char c : s.toCharArray()) {
            if (Character.isDigit(c)) {
                num = num * 10 + (c - '0');
            } else if (c == '[') {
                stStr.push(curr);
                stNum.push(num);
                curr = new StringBuilder();
                num = 0;
            } else if (c == ']') {
                StringBuilder temp = curr;
                curr = stStr.pop();
                int cnt = stNum.pop();
                while (cnt-- > 0) curr.append(temp);
            } else {
                curr.append(c);
            }
        }
        return curr.toString();
    }
}
