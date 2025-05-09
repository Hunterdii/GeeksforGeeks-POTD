# *9. Largest Number in K Swaps*

The problem can be found at the following link: 🔗 [Question Link](https://www.geeksforgeeks.org/problems/largest-number-in-k-swaps-1587115620/1)

## **🧩 Problem Description**

Given a string `s` representing a positive integer and an integer `k`, you may perform at most `k` swap operations on the digits of `s`. Each swap exchanges two digits at different positions. Return the lexicographically largest number (as a string) achievable under these operations.

## **📘 Examples**

### **Example 1:**

#### **Input:**

`s = "1234567"`, `k = 4`

#### **Output:**

`"7654321"`

#### **Explanation:**

Swap 1↔7 → `7234561`, then 2↔6 → `7634521`, then 3↔5 → `7654321`. Only three swaps needed, within limit `k=4`.

### **Example 2:**

#### **Input:**

`s = "3435335"`, `k = 3`

#### **Output:**

`"5543333"`

#### **Explanation:**

Swap 3↔5 → `5433335`, then 4↔5 → `5533334`, then 4↔3 → `5543333`.

### **Example 3:**

#### **Input:**

`s = "1034"`, `k = 2`

#### **Output:**

`"4301"`

#### **Explanation:**

Swap 1↔4 → `4031`, then 0↔3 → `4301`.

## **🔒 Constraints**

* `1 ≤ s.size() ≤ 15`
* `1 ≤ k ≤ 7`

## **✅ My Approach**

### **Backtracking with Pruning**

We explore swap operations recursively, always targeting the maximum digit available from the current index to the end. When the maximum digit at or after the current position differs from the digit at the current index, we perform a swap (consuming one of the `k` swaps), update the answer if it improves, and recurse to the next index. After recursion, we undo the swap to restore state. If the current digit is already the maximum, we skip consuming `k` and recurse directly.

### **Algorithm Steps:**

1. Initialize global `ans = s`.
2. Define recursive function `dfs(array a, int k, int i)`:

   * If `k == 0` or `i == a.length`, return.
   * Find `m = max(a[i..end])`.
   * If `m != a[i]`, for each position `j` from end to `i` where `a[j] == m`:

     1. Swap `a[i]` and `a[j]`, decrement `k` by 1.
     2. Update `ans = max(ans, string(a))`.
     3. Recurse `dfs(a, k, i+1)`.
     4. Undo swap and restore `k`.
   * Else, recurse `dfs(a, k, i+1)` without using `k`.
3. Convert `s` to array and call `dfs(a, k, 0)`.
4. Return `ans`.

## **🧮 Time and Auxiliary Space Complexity**

* **Expected Time Complexity:** $O(N! / (N-K)!)$ in the worst case, where N = length of `s` and K = number of allowed swaps. We prune branches when no beneficial swap exists, greatly reducing the practical search space for small N ≤ 15 and K ≤ 7.
* **Expected Auxiliary Space Complexity:** O(N + K), due to recursion depth up to `min(N, K)` and storing the character array of size N.

## **🧠 Code (C++)**

```cpp
class Solution {
  public:
    string ans;
    void solve(string &s, int k, int idx) {
        if (k == 0) return;
        char mx = *max_element(s.begin() + idx, s.end());
        if (mx != s[idx]) k--;
        for (int i = s.size() - 1; i >= idx; i--) {
            if (s[i] == mx) {
                swap(s[i], s[idx]);
                if (s > ans) ans = s;
                solve(s, k, idx + 1);
                swap(s[i], s[idx]);
            }
        }
    }
    string findMaximumNum(string& s, int k) {
        ans = s;
        solve(s, k, 0);
        return ans;
    }
};
```

## **🧑‍💻 Code (Java)**

```java
class Solution {
    String ans;
    void r(char[] a, int k, int i) {
        if (k == 0 || i == a.length) return;
        char m = a[i];
        for (int j = i + 1; j < a.length; j++) if (a[j] > m) m = a[j];
        if (m != a[i]) {
            for (int j = a.length - 1; j >= i; j--) if (a[j] == m) {
                char t = a[i]; a[i] = a[j]; a[j] = t;
                String cur = new String(a);
                if (cur.compareTo(ans) > 0) ans = cur;
                r(a, k - 1, i + 1);
                a[j] = a[i]; a[i] = t;
            }
        } else r(a, k, i + 1);
    }
    public String findMaximumNum(String s, int k) {
        ans = s;
        r(s.toCharArray(), k, 0);
        return ans;
    }
}
```

## **🐍 Code (Python)**

```python
class Solution:
    def findMaximumNum(self, s, k):
        ans = [s]
        def r(a, k, i):
            if k == 0 or i == len(a): return
            m = max(a[i:])
            if m != a[i]:
                for j in range(len(a)-1, i-1, -1):
                    if a[j] == m:
                        a[i], a[j] = a[j], a[i]
                        cur = ''.join(a)
                        if cur > ans[0]: ans[0] = cur
                        r(a, k-1, i+1)
                        a[i], a[j] = a[j], a[i]
            else:
                r(a, k, i+1)
        r(list(s), k, 0)
        return ans[0]
```

## 🧠 Contribution and Support

For discussions, questions, or doubts related to this solution, feel free to connect on LinkedIn: [📬 Any Questions?](https://www.linkedin.com/in/patel-hetkumar-sandipbhai-8b110525a/). Let’s make this learning journey more collaborative!

⭐ **If you find this helpful, please give this repository a star!** ⭐

--- 

<div align="center">
  <h3><b>📍Visitor Count</b></h3>
</div>

<p align="center">
  <img src="https://profile-counter.glitch.me/Hunterdii/count.svg" />
</p>
