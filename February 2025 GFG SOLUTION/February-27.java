//{ Driver Code Starts
import java.util.*;

class Get_Min_From_Stack {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        int T = sc.nextInt(); // Number of test cases

        while (T-- > 0) {
            int q = sc.nextInt(); // Number of queries
            Solution g = new Solution();

            while (q-- > 0) {
                int qt = sc.nextInt();

                if (qt == 1) {
                    int att = sc.nextInt();
                    g.push(att);
                } else if (qt == 2) {
                    g.pop(); // Just call pop(), do not print anything
                } else if (qt == 3) {
                    System.out.print(g.peek() + " "); // Print top element
                } else if (qt == 4) {
                    System.out.print(g.getMin() + " "); // Print minimum element
                }
            }
            System.out.println("\n~");
        }
        sc.close();
    }
}

// } Driver Code Ends


class Solution {
    Stack<Integer> s = new Stack<>(), m = new Stack<>();

    void push(int x) { s.push(x); m.push(m.isEmpty() ? x : Math.min(x, m.peek())); }
    void pop() { if (!s.isEmpty()) { s.pop(); m.pop(); } }
    int peek() { return s.isEmpty() ? -1 : s.peek(); }
    int getMin() { return m.isEmpty() ? -1 : m.peek(); }
}

2)
class Solution {
    private Stack<Integer> s = new Stack<>();
    private Stack<Integer> minStack = new Stack<>();
    public void push(int x) {
        s.push(x);
        if (minStack.isEmpty() || x <= minStack.peek()) {
            minStack.push(x);
        }
    }
    public void pop() {
        if (!s.isEmpty()) {
            if (s.peek().equals(minStack.peek())) {
                minStack.pop();
            }
            s.pop();
        }
    }
    public int peek() {
        return s.isEmpty() ? -1 : s.peek();
    }
    public int getMin() {
        return minStack.isEmpty() ? -1 : minStack.peek();
    }
}

