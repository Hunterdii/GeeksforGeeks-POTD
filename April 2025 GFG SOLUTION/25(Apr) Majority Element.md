# *25. Majority Element*

The problem can be found at the following link: 🔗 [Question Link](https://www.geeksforgeeks.org/problems/majority-element-1587115620/1)


## **🧩 Problem Description**

Given an array `arr[]`, find the **majority element** in the array. A majority element is an element that appears **strictly more than** `arr.size() / 2` times.

If no such element exists, return `-1`.


## **📘 Examples**

### **Example 1:**

#### **Input:**
`arr[] = [1, 1, 2, 1, 3, 5, 1]`

#### **Output:**
`1`

#### **Explanation:**
`1` appears 4 times out of 7, which is more than 7/2. Hence, it is the majority element.


### **Example 2:**

#### **Input:**
`arr[] = [7]`

#### **Output:**
`7`

#### **Explanation:**
The only element `7` appears once, which is more than 1/2. Hence, it is the majority element.


### **Example 3:**

#### **Input:**
`arr[] = [2, 13]`

#### **Output:**
`-1`

#### **Explanation:**
No element occurs more than 2/2 times. Hence, no majority element.


### **🔒 Constraints**

- $1 \leq \text{arr.size()} \leq 10^5$
- $0 \leq \text{arr[i]} \leq 10^5$


## **✅ My Approach:**

### **Boyer-Moore Voting Algorithm**

This algorithm is optimal in both time and space. It works in two phases:
1. **Candidate Selection** — Identify a potential majority candidate.
2. **Validation Pass** — Count its frequency to confirm majority.


### **Algorithm Steps:**

1. Initialize `count = 0` and `candidate = -1`.
2. Traverse the array:
   - If `count == 0`, set `candidate = current element`.
   - If current element equals `candidate`, increment `count`.
   - Else, decrement `count`.
3. After traversal, validate whether `candidate` actually occurs more than `n/2` times.
4. If yes, return `candidate`; else return `-1`.


## **🧮 Time and Auxiliary Space Complexity**

- **Expected Time Complexity:** O(n), as we traverse the array twice — once to find candidate and once to validate.
- **Expected Auxiliary Space Complexity:** O(1), as we only use a constant number of variables.


## **💡 Code (C)**

```c
int majorityElement(int arr[], int n) {
    int count=0,cand;
    for(int i=0;i<n;i++){
        if(!count) cand=arr[i];
        count += arr[i]==cand ? 1 : -1;
    }
    count=0;
    for(int i=0;i<n;i++) if(arr[i]==cand) count++;
    return count>n/2 ? cand : -1;
}
```


## **🧠 Code (C++)**

```cpp
class Solution {
  public:
    int majorityElement(vector<int>& arr) {
        int count = 0, candidate;
        for (int num : arr) {
            if (count == 0) candidate = num;
            count += (num == candidate) ? 1 : -1;
        }
        count = 0;
        for (int num : arr) if (num == candidate) count++;
        return count > arr.size() / 2 ? candidate : -1;
    }
};
```

<details>
<summary><h2 align="center">⚡ Alternative Approaches</h2></summary>


## 📊 **2️⃣ Hash Map Frequency Count**

### **Algorithm Steps:**
1. Traverse the array and store the count of each element using a hash map.
2. Iterate through the map and return the element with frequency > n/2.

```cpp
class Solution {
  public:
    int majorityElement(vector<int>& arr) {
        unordered_map<int, int> freq;
        for (int x : arr) freq[x]++;
        for (auto &p : freq)
            if (p.second > arr.size() / 2)
                return p.first;
        return -1;
    }
};
```

#### 📝 **Complexity Analysis:**
- **Expected Time Complexity:** O(n), as we iterate over the array and map once.
- **Expected Auxiliary Space Complexity:** O(n), due to extra space for frequency map.


## 📊 **3️⃣ Sorting + Middle Element**

### **Algorithm Steps:**
1. Sort the array.
2. Pick the middle element at index `n/2` as the candidate.
3. Count its frequency to validate.

```cpp
class Solution {
  public:
    int majorityElement(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int candidate = arr[arr.size() / 2];
        int count = count_if(arr.begin(), arr.end(), [&](int x){ return x == candidate; });
        return count > arr.size() / 2 ? candidate : -1;
    }
};
```

#### 📝 **Complexity Analysis:**
- **Expected Time Complexity:** O(n log n), due to sorting.
- **Expected Auxiliary Space Complexity:** O(1), assuming in-place sort.


## 📊 **4️⃣ Bit Manipulation**

### **Algorithm Steps:**
1. For each bit (0–31), count the number of times it is set across all elements.
2. If a bit is set in more than n/2 elements, include it in the result.
3. Finally, validate the constructed number.

```cpp
class Solution {
  public:
    int majorityElement(vector<int>& arr) {
        int n = arr.size(), result = 0;
        for (int i = 0; i < 32; i++) {
            int bitCount = 0;
            for (int num : arr)
                if ((num >> i) & 1) bitCount++;
            if (bitCount > n / 2) result |= (1 << i);
        }
        int count = count_if(arr.begin(), arr.end(), [&](int x){ return x == result; });
        return count > n / 2 ? result : -1;
    }
};
```

#### 📝 **Complexity Analysis:**
- **Expected Time Complexity:** O(n), as we check all bits over all elements.
- **Expected Auxiliary Space Complexity:** O(1), using only fixed variables.


### 🆚 **Comparison of Approaches**

| **Approach**                 | ⏱️ **Time**      | 🗂️ **Space** | ✅ **Pros**                         | ⚠️ **Cons**                    |
|-----------------------------|------------------|--------------|-------------------------------------|--------------------------------|
| **Boyer-Moore Voting**      | 🟢 O(n)           | 🟢 O(1)       | Optimal time and space             | Requires verification pass     |
| **Hash Map Frequency**      | 🟢 O(n)           | 🔴 O(n)       | Very easy to code                  | Extra memory usage             |
| **Sorting + Middle Element**| 🔴 O(n log n)     | 🟢 O(1)       | Simple logic after sort            | Sorting overhead               |
| **Bit Manipulation**        | 🟢 O(n)           | 🟢 O(1)       | Efficient, constant space          | Bit logic slightly tricky      |


### ✅ **Best Choice?**

| **Scenario**                                         | **Recommended Approach**        |
|------------------------------------------------------|---------------------------------|
| ✅ Space and speed optimized                          | 🥇 Boyer-Moore Voting           |
| ✅ Quick implementation with clarity                  | 🥈 Hash Map Frequency           |
| ✅ Sorting already needed or acceptable               | 🥉 Sorting + Middle Element     |
| ✅ Exploring bit-level ideas                          | 🤓 Bit Manipulation             |

</details>


## **🧑‍💻 Code (Java)**

```java
class Solution {
    static int majorityElement(int[] a) {
        int cand=0, count=0;
        for (int v : a) {
            if (count == 0) cand = v;
            count += v == cand ? 1 : -1;
        }
        count = 0;
        for (int v : a) if (v == cand) count++;
        return count > a.length / 2 ? cand : -1;
    }
}
```


## **🐍 Code (Python)**

```python
class Solution:
    def majorityElement(self, a):
        count = cand = 0
        for v in a:
            if not count:
                cand = v
            count += 1 if v == cand else -1
        return cand if sum(1 for v in a if v == cand) > len(a)//2 else -1
```


## 🧠 Contribution and Support

For discussions, questions, or doubts related to this solution, feel free to connect on LinkedIn: [📬 Any Questions?](https://www.linkedin.com/in/patel-hetkumar-sandipbhai-8b110525a/) — Let’s learn and grow together!

⭐ **If this helped you, don't forget to star the repository!** ⭐

---

<div align="center">
  <h3><b>📍Visitor Count</b></h3>
</div>

<p align="center">
  <img src="https://profile-counter.glitch.me/Hunterdii/count.svg" />
</p>
