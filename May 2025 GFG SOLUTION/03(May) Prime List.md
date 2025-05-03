# *3. Prime List*

The problem can be found at the following link: 🔗 [Question Link](https://www.geeksforgeeks.org/problems/prime-list--170646/1)

## **🧩 Problem Description**

You are given the head of a singly linked list. Your task is to replace the value of each node with the nearest prime number.

If multiple prime numbers are equidistant from the current value, choose the smaller one. Return the head of the updated linked list.

### 📘 Examples

#### **Example 1:**

**Input:**
`head = 2 → 6 → 10`

**Output:**
`2 → 5 → 11`

<img src="https://github.com/user-attachments/assets/fa6c7455-87cd-4c0c-8625-aeb522276732" width="30%">

**Explanation:**

* 2 is already prime.
* 6 has nearest primes 5 and 7 → choose 5.
* 10 has nearest primes 7 and 11 → choose 11.


#### **Example 2:**

**Input:**
`head = 1 → 15 → 20`

**Output:**
`2 → 13 → 19`

<img src="https://github.com/user-attachments/assets/94642319-e200-4d3e-8311-d7b8ee975a14" width="30%">

**Explanation:**

* Nearest prime to 1 is 2.
* 15 → nearest primes: 13 and 17 → choose 13.
* 20 → nearest primes: 19 and 23 → choose 19.


## 🔒 Constraints

* \$1 \leq \text{Number of nodes} \leq 10^4\$
* \$1 \leq \text{Node.val} \leq 10^4\$

## **✅ My Approach**

### **Sieve of Eratosthenes + Two-pointer Prime Search**

### **Core Idea:**

Precompute all prime numbers up to twice the maximum value in the list using the **Sieve of Eratosthenes**. Then, for each node, scan outwards from its value to find the closest prime (checking both left and right directions simultaneously). This guarantees optimal lookup and replacement for large datasets.

### **Algorithm Steps:**

1. Traverse the list once to find the maximum value `m`.
2. Build a sieve array of size `2*m+1` to mark prime numbers.
3. Traverse the list again:

   * For each node, search outward from `node.val` until a prime is found (prefer the smaller one if both directions are valid).
   * Replace the value in the node.
4. Return the updated head.


## 🧮 Time and Auxiliary Space Complexity

* **Expected Time Complexity:** O(n + m·loglogm), where `n` is the number of nodes and `m` is the maximum value. Sieve is built once, and each node is updated in amortized constant time.
* **Expected Auxiliary Space Complexity:** O(m), to store the sieve of prime numbers.


## **🧠 Code (C++)**

```cpp
class Solution {
public:
    Node* primeList(Node* h) {
        int m = 0;
        for (auto p = h; p; p = p->next) m = max(m, p->val);
        vector<char> s(2*m+1, 1);
        s[0] = s[1] = 0;
        for (int i = 2; i*i <= 2*m; ++i)
            if (s[i])
                for (int j = i*i; j <= 2*m; j += i)
                    s[j] = 0;
        for (auto p = h; p; p = p->next) {
            int x = p->val, d = 0;
            while (1) {
                if (x-d > 1 && s[x-d]) { p->val = x-d; break; }
                if (x+d <= 2*m && s[x+d]) { p->val = x+d; break; }
                ++d;
            }
        }
        return h;
    }
};
```


<details>
<summary><h2 align="center">⚡ Alternative Approaches</h2></summary>

## 📊 **1️⃣ Brute Force (Per Node Prime Search)**

### **Algorithm Steps:**

1. For each node value `x`, check decreasing and increasing values (`x-1, x+1, x-2, x+2...`) until a prime is found.
2. Replace the node’s value with the nearest prime.

```cpp
bool isPrime(int n) {
    if (n < 2) return false;
    for (int i = 2; i*i <= n; ++i)
        if (n % i == 0) return false;
    return true;
}

class Solution {
public:
    Node* primeList(Node* h) {
        for (auto p = h; p; p = p->next) {
            int x = p->val, d = 0;
            while (true) {
                if (x-d > 1 && isPrime(x-d)) { p->val = x-d; break; }
                if (isPrime(x+d)) { p->val = x+d; break; }
                ++d;
            }
        }
        return h;
    }
};
```

### ✅ **Why This Approach?**

* Simpler to implement without preprocessing.
* Doesn’t use extra memory.

#### 📝 **Complexity Analysis:**

* **Time:** O(n√m) – for `n` nodes and value up to `m`.
* **Auxiliary Space:** O(1)


## 🆚 **Comparison of Approaches**

| **Approach**               | ⏱️ **Time**         | 🗂️ **Space** | ✅ **Pros**                                 | ⚠️ **Cons**                 |
| -------------------------- | ------------------- | ------------- | ------------------------------------------ | --------------------------- |
| Sieve + Search (Optimal)   | 🟢 O(n + m loglogm) | 🔸 O(m)       | Fast, efficient lookup, handles large data | Needs extra space for sieve |
| Brute Force Prime Checking | 🟡 O(n√m)           | 🟢 O(1)       | Simple, no extra memory                    | Slower on large inputs      |


### ✅ **Best Choice?**

| **Scenario**                           | **Recommended Approach**      |
| -------------------------------------- | ----------------------------- |
| Large datasets with frequent queries   | 🥇 Sieve + outward prime scan |
| Small lists or memory-restricted cases | 🥈 Brute force prime checking |

</details>

## **🧑‍💻 Code (Java)**

```java
class Solution {
    Node primeList(Node h) {
        int m = 0;
        for (Node p = h; p != null; p = p.next) m = Math.max(m, p.val);
        boolean[] s = new boolean[2*m+1];
        Arrays.fill(s, true);
        s[0] = s[1] = false;
        for (int i = 2; i*i <= 2*m; i++)
            if (s[i])
                for (int j = i*i; j <= 2*m; j += i) s[j] = false;
        for (Node p = h; p != null; p = p.next) {
            int x = p.val, d = 0;
            while (true) {
                if (x-d > 1 && s[x-d]) { p.val = x-d; break; }
                if (x+d <= 2*m && s[x+d]) { p.val = x+d; break; }
                d++;
            }
        }
        return h;
    }
}
```


## **🐍 Code (Python)**

```python
class Solution:
    def primeList(self, h):
        m = 0; p = h
        while p: m = max(m, p.val); p = p.next
        s = [1]*(2*m+1); s[0] = s[1] = 0
        for i in range(2, int((2*m)**0.5)+1):
            if s[i]: s[i*i:2*m+1:i] = [0]*len(range(i*i, 2*m+1, i))
        p = h
        while p:
            x, d = p.val, 0
            while 1:
                if x-d > 1 and s[x-d]: p.val = x-d; break
                if x+d <= 2*m and s[x+d]: p.val = x+d; break
                d += 1
            p = p.next
        return h
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
