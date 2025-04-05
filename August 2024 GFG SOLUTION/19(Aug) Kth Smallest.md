# **19. Kth Smallest Element**

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/kth-smallest-element5635/1)

### **Problem Description**

Given an array `arr[]` and an integer `k` where `k` is smaller than the size of the array, the task is to find the `k`th smallest element in the given array. It is given that all array elements are distinct.

**Examples:**

**Input:**

```
arr[] = [7, 10, 4, 3, 20, 15], k = 3
```

**Output:**

```
7
```

**Explanation:** The 3rd smallest element in the given array is 7.

**Input:**

```
arr[] = [7, 10, 4, 20, 15], k = 4
```

**Output:**

```
15
```

**Explanation:** The 4th smallest element in the given array is 15.

### **Approach**

1. **Initial Setup:**

   - Determine the minimum and maximum elements in the array. These values help define the range of the array elements.
   - Calculate the `range` of elements in the array as `max_element - min_element + 1`.

2. **Frequency Array:**

   - Create a frequency array of size `range` to store the count of each element in the array.
   - Populate this frequency array by iterating through the input array and incrementing the count at the index corresponding to each element.

3. **Finding the Kth Smallest Element:**
   - Iterate through the frequency array, maintaining a running count of elements encountered.
   - Once the running count reaches or exceeds `k`, the current index in the frequency array corresponds to the `k`th smallest element in the original array.

### **Time and Auxiliary Space Complexity**

- **Expected Time Complexity:** O(n + max_element), as we first scan the array to populate the frequency array, and then scan the frequency array to determine the `k`th smallest element.
- **Expected Auxiliary Space Complexity:** O(max_element), since we use a frequency array with a size based on the range of array elements.

### **Code (C++)**

```cpp
class Solution {
public:
    int kthSmallest(std::vector<int> &arr, int k) {
        int min_element = *std::min_element(arr.begin(), arr.end());
        int max_element = *std::max_element(arr.begin(), arr.end());
        int range = max_element - min_element + 1;

        std::vector<int> freq(range, 0);
        for (int i = 0; i < arr.size(); i++) {
            freq[arr[i] - min_element]++;
        }

        int count = 0;
        for (int i = 0; i < range; i++) {
            count += freq[i];
            if (count >= k) {
                return i + min_element;
            }
        }

        return -1;
    }
};
```

### **Code (Java)**

```java
class Solution {
    public static int kthSmallest(int[] arr, int k) {
        int minElement = Integer.MAX_VALUE;
        int maxElement = Integer.MIN_VALUE;

        for (int num : arr) {
            if (num < minElement) {
                minElement = num;
            }
            if (num > maxElement) {
                maxElement = num;
            }
        }

        int range = maxElement - minElement + 1;
        int[] freq = new int[range];

        for (int num : arr) {
            freq[num - minElement]++;
        }

        int count = 0;
        for (int i = 0; i < range; i++) {
            count += freq[i];
            if (count >= k) {
                return i + minElement;
            }
        }

        return -1;
    }
}
```

### **Code (Python)**

```python
class Solution:

    def kthSmallest(self, arr, k):
        min_element = min(arr)
        max_element = max(arr)
        range_size = max_element - min_element + 1

        freq = [0] * range_size

        for num in arr:
            freq[num - min_element] += 1

        count = 0
        for i in range(range_size):
            count += freq[i]
            if count >= k:
                return i + min_element

        return -1
```

## Contribution and Support

For discussions, questions, or doubts related to this solution, feel free to connect on LinkedIn: [Any Questions](https://www.linkedin.com/in/patel-hetkumar-sandipbhai-8b110525a/). Let’s make this learning journey more collaborative!

⭐ If you find this helpful, please give this repository a star! ⭐

---

<div align="center">
  <h3><b>📍Visitor Count</b></h3>
</div>

<p align="center">
  <img src="https://profile-counter.glitch.me/Hunterdii/count.svg" />
</p>
