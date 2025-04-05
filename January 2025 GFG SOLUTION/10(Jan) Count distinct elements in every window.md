# _10. Count Distinct Elements in Every Window_

The problem can be found at the following link: [Problem Link](https://www.geeksforgeeks.org/problems/count-distinct-elements-in-every-window/1)

## **Problem Description**

Given an integer array `arr[]` and a number `k`, find the count of distinct elements in every window of size `k` in the array.

## **Examples**

**Input:**  
`arr[] = [1, 2, 1, 3, 4, 2, 3], k = 4`  
**Output:**  
`[3, 4, 4, 3]`

**Explanation:**

- Window 1: `[1, 2, 1, 3]` → 3 distinct elements (`1, 2, 3`)
- Window 2: `[2, 1, 3, 4]` → 4 distinct elements (`1, 2, 3, 4`)
- Window 3: `[1, 3, 4, 2]` → 4 distinct elements (`1, 2, 3, 4`)
- Window 4: `[3, 4, 2, 3]` → 3 distinct elements (`2, 3, 4`)

**Input:**  
`arr[] = [4, 1, 1], k = 2`  
**Output:**  
`[2, 1]`

**Explanation:**

- Window 1: `[4, 1]` → 2 distinct elements (`4, 1`)
- Window 2: `[1, 1]` → 1 distinct element (`1`)

**Input:**  
`arr[] = [1, 1, 1, 1, 1], k = 3`  
**Output:**  
`[1, 1, 1]`

**Explanation:**

- Each window has only `1` distinct element (`1`) as all values in `arr` are identical.

### **Constraints**

- $\( 1 \leq k \leq \text{arr.size()} \leq 10^5 \) $
- $\( 1 \leq \text{arr}[i] \leq 10^5 \) $

## **My Approach**

1. **Sliding Window with Frequency Map:**

   - Use an unordered map (or dictionary) to keep track of the frequency of elements in the current window.
   - Iterate over the array while maintaining the size of the window as `k`.

2. **Steps:**

   - Add the current element to the frequency map and increment its count.
   - If the current index exceeds `k - 1`, count the distinct elements by checking the size of the map.
   - Remove the element that is sliding out of the window by decrementing its count. If its count becomes `0`, remove it from the map.

3. **Edge Cases:**
   - If $\( k = 1 \)$, each element is its own window, so the count of distinct elements is $\( n \)$.
   - If $\( n \leq k \)$, handle the window size appropriately without exceeding bounds.

## **Time and Auxiliary Space Complexity**

**Expected Time Complexity:** $\( O(n) \)$, where $\( n \)$ is the size of the array. Each element is added to and removed from the map at most once.

**Expected Auxiliary Space Complexity:** $\( O(n) \)$, as the size of the frequency map is proportional to the size of the window.

## Code (C++)

```cpp
class Solution {
public:
    vector<int> countDistinct(vector<int> &arr, int k) {
        unordered_map<int, int> freq;
        vector<int> res;
        for (int i = 0; i < arr.size(); i++) {
            freq[arr[i]]++;
            if (i >= k - 1) {
                res.push_back(freq.size());
                if (--freq[arr[i - k + 1]] == 0) freq.erase(arr[i - k + 1]);
            }
        }
        return res;
    }
};
```

## Code (Java)

```java
class Solution {
    ArrayList<Integer> countDistinct(int arr[], int k) {
        HashMap<Integer, Integer> freq = new HashMap<>();
        ArrayList<Integer> res = new ArrayList<>();
        for (int i = 0; i < arr.length; i++) {
            freq.put(arr[i], freq.getOrDefault(arr[i], 0) + 1);
            if (i >= k - 1) {
                res.add(freq.size());
                freq.put(arr[i - k + 1], freq.get(arr[i - k + 1]) - 1);
                if (freq.get(arr[i - k + 1]) == 0) freq.remove(arr[i - k + 1]);
            }
        }
        return res;
    }
}
```

## Code (Python)

```python
class Solution:
    def countDistinct(self, arr, k):
        freq = {}
        res = []
        for i in range(len(arr)):
            freq[arr[i]] = freq.get(arr[i], 0) + 1
            if i >= k - 1:
                res.append(len(freq))
                freq[arr[i - k + 1]] -= 1
                if freq[arr[i - k + 1]] == 0:
                    del freq[arr[i - k + 1]]
        return res
```

## **Contribution and Support**

For discussions, questions, or doubts related to this solution, feel free to connect on LinkedIn: [Any Questions](https://www.linkedin.com/in/patel-hetkumar-sandipbhai-8b110525a/). Let’s make this learning journey more collaborative!

⭐ If you find this helpful, please give this repository a star! ⭐

---

<div align="center">
  <h3><b>📍Visitor Count</b></h3>
</div>

<p align="center">
  <img src="https://profile-counter.glitch.me/Hunterdii/count.svg" />
</p>
