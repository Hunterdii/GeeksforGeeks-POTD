# **28. Sorting Elements of an Array by Frequency**

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/sorting-elements-of-an-array-by-frequency-1587115621/1)

**Note:** Sorry for uploading late, my exam is going on.

### Problem Description

Given an array of integers `arr`, the task is to sort the array according to the frequency of elements, i.e., elements that have a higher frequency come first. If the frequencies of two elements are the same, then the smaller number comes first.

**Examples:**

Input:

```
arr[] = [5, 5, 4, 6, 4]
```

Output:

```
[4, 4, 5, 5, 6]
```

Explanation: Both `5` and `4` have a frequency of `2`. Since `4` is smaller, it comes before `5`. `6` has a frequency of `1`, so it comes last.

### My Approach

1. **Frequency Count:**

   - Use a hash map to count the frequency of each element in the array.

2. **Sorting:**

   - Convert the frequency map into a list of pairs `(element, frequency)`.
   - Sort this list first by frequency in descending order. If two elements have the same frequency, sort them by the element value in ascending order.

3. **Reconstruct the Array:**
   - Iterate through the sorted list and reconstruct the array based on the frequency of each element.

### Time and Auxiliary Space Complexity

- **Expected Time Complexity:** O(n log n), where `n` is the size of the array. This is due to the sorting step, which dominates the time complexity.
- **Expected Auxiliary Space Complexity:** O(n), for the hash map storing the frequency of each element and the list used for sorting.

### Code (C++)

```cpp
class Solution {
public:
    vector<int> sortByFreq(vector<int>& arr) {
        unordered_map<int, int> freqMap;
        vector<pair<int, int>> freqVec;
        for (int num : arr) {
            freqMap[num]++;
        }
        for (const auto& entry : freqMap) {
            freqVec.emplace_back(entry.first, entry.second);
        }
        sort(freqVec.begin(), freqVec.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
            return a.second > b.second || (a.second == b.second && a.first < b.first);
        });
        vector<int> result;
        for (const auto& entry : freqVec) {
            result.insert(result.end(), entry.second, entry.first);
        }

        return result;
    }
};
```

### Code (Java)

```java
class Solution {
    public ArrayList<Integer> sortByFreq(int arr[]) {
        HashMap<Integer, Integer> freqMap = new HashMap<>();
        for (int num : arr) {
            freqMap.put(num, freqMap.getOrDefault(num, 0) + 1);
        }
        List<Map.Entry<Integer, Integer>> freqList = new ArrayList<>(freqMap.entrySet());
        freqList.sort((a, b) -> {
            if (a.getValue().equals(b.getValue())) {
                return a.getKey() - b.getKey();
            }
            return b.getValue() - a.getValue();
        });
        ArrayList<Integer> result = new ArrayList<>();
        for (Map.Entry<Integer, Integer> entry : freqList) {
            for (int i = 0; i < entry.getValue(); i++) {
                result.add(entry.getKey());
            }
        }

        return result;
    }
}
```

### Code (Python)

```python
class Solution:
    def sortByFreq(self, arr):
        freq_map = {}
        for num in arr:
            freq_map[num] = freq_map.get(num, 0) + 1
        sorted_items = sorted(freq_map.items(), key=lambda x: (-x[1], x[0]))
        result = []
        for num, freq in sorted_items:
            result.extend([num] * freq)

        return result
```

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
