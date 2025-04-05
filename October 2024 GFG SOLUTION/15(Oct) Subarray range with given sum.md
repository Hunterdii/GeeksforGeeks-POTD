# _15. Subarray Range with Given Sum_

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/subarray-range-with-given-sum0128/1)

### **Problem Description**

Given an unsorted array of integers `arr[]`, and a target sum `tar`, determine the number of subarrays whose elements sum up to the target value.

**Example:**

Input:  
arr[] = [10, 2, -2, -20, 10]  
tar = -10

Output:  
3

Explanation:  
Subarrays with sum -10 are:

- [10, 2, -2, -20]
- [2, -2, -20, 10]
- [-20, 10]

**Constraints:**

- 1 <= arr.size() <= 10^6
- -10^5 <= arr[i] <= 10^5
- -10^5 <= tar <= 10^5

---

### **My Approach**

1. **Prefix Sum and Hashmap:**

   - The core idea is to use a prefix sum array and a hashmap (or dictionary) to store the frequency of sums encountered so far.
   - Iterate through the array, calculating the cumulative sum as we go, and check if there is a prefix sum that, when subtracted from the current cumulative sum, equals the target `tar`.
   - If a valid prefix sum is found, it indicates a subarray that sums to the target, so we increment the count.

2. **Hashmap Optimization:**

   - The hashmap stores the frequency of each prefix sum encountered.
   - For each element in the array, we check if the difference between the current sum and the target sum exists in the hashmap.
   - If it does, the value in the hashmap indicates how many subarrays with the target sum can be formed up to this point.

3. **Time and Space Efficiency:**
   - This approach ensures we only traverse the array once, maintaining a time complexity of O(n).
   - The auxiliary space is O(n) due to the hashmap storing the prefix sums.

---

### **Time and Auxiliary Space Complexity**

- **Expected Time Complexity:** O(n), as we traverse the array once and perform constant-time operations (hashmap lookups and updates) for each element.
- **Expected Auxiliary Space Complexity:** O(n), due to the storage of the prefix sum frequencies in a hashmap.

---

### **Code (C++)**

```cpp
class Solution {
  public:
    int subArraySum(vector<int>& arr, int tar) {
        unordered_map<int, int> map;
        int curr_sum = 0, count = 0;

        for (int i = 0; i < arr.size(); i++) {
            curr_sum += arr[i];
            if (curr_sum == tar) {
                count++;
            }
            if (map.find(curr_sum - tar) != map.end()) {
                count += map[curr_sum - tar];
            }
            map[curr_sum]++;
        }

        return count;
    }
};
```

---

### **Code (Java)**

```java
class Solution {
    static int subArraySum(int[] arr, int target) {
        HashMap<Integer, Integer> prefixSumMap = new HashMap<>();
        int curr_sum = 0;
        int count = 0;

        prefixSumMap.put(0, 1);

        for (int num : arr) {
            curr_sum += num;
            if (prefixSumMap.containsKey(curr_sum - target)) {
                count += prefixSumMap.get(curr_sum - target);
            }
            prefixSumMap.put(curr_sum, prefixSumMap.getOrDefault(curr_sum, 0) + 1);
        }

        return count;
    }
}
```

---

### **Code (Python)**

```python
class Solution:
    def subArraySum(self, arr, target):
        prefixSumMap = {0: 1}
        curr_sum = 0
        count = 0

        for num in arr:
            curr_sum += num
            if (curr_sum - target) in prefixSumMap:
                count += prefixSumMap[curr_sum - target]
            prefixSumMap[curr_sum] = prefixSumMap.get(curr_sum, 0) + 1

        return count
```

---

## Contribution and Support

For discussions, questions, or doubts related to this solution, please visit my LinkedIn:- [Any Questions](https://www.linkedin.com/in/patel-hetkumar-sandipbhai-8b110525a/). Thank you for your input; together, we strive to create a space where learning is a collaborative endeavor.

⭐ Star this repository if you find it helpful or intriguing! ⭐

---

<div align=center>
  <h3><b>📍Visitor Count</b></h3>
</div>

<p align="center" >   
  <img src="https://profile-counter.glitch.me/Hunterdii/count.svg" />  
</p>
