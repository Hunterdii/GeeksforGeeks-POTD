## 19. Count Smaller Elements

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/count-smaller-elements2214/1)

### Problem Description

Given an array `arr` containing positive integers, count and return an array `ans` where `ans[i]` denotes the number of smaller elements on the right side of `arr[i]`.

**Example:**

Input:

```
arr = [12, 1, 2, 3, 0, 11, 4]
```

Output:

```
6 1 1 1 0 1 0
```

Explanation:
There are 6 smaller elements right after 12. There is 1 smaller element right after 1. And so on.

Input:

```
arr = [1, 2, 3, 4, 5]
```

Output:

```
0 0 0 0 0
```

Explanation:
There are 0 smaller elements right after 1. There are 0 smaller elements right after 2. And so on.

### My Approach

1. **Initialization:**

- Create a vector `ans` to store the count of smaller elements to the right for each element in the array.
- Create a Binary Indexed Tree (BIT) `bit` to help in efficiently querying and updating the frequency of elements.

2. **Rank Compression:**

- Sort the elements with their original indices.
- Assign ranks to the elements based on their sorted order to handle the large range of values.

3. **BIT Update and Query:**

- Traverse the array from right to left.
- For each element, get the count of elements smaller than the current element using the BIT.
- Update the BIT with the current element's rank to maintain the frequency of seen elements.

4. **Return:**

- Return the vector `ans` containing the count of smaller elements to the right for each element in the array.

### Time and Auxiliary Space Complexity

- **Expected Time Complexity:** O(n \* log n), as we perform log n operations for each of the n elements.
- **Expected Auxiliary Space Complexity:** O(n), as we use additional space for the BIT and other auxiliary structures.

### Code (C++)

```cpp
class Solution {
public:
    vector<int> constructLowerArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> bit(n + 1, 0);
        vector<int> ans(n, 0);

        auto update = [&](int index, int value) {
            for (; index <= n; index += index & (-index)) {
                bit[index] += value;
            }
        };

        auto get = [&](int index) {
            int sum = 0;
            for (; index > 0; index -= index & (-index)) {
                sum += bit[index];
            }
            return sum;
        };

        vector<pair<int, int>> value_index_pairs;
        for (int i = 0; i < n; ++i) {
            value_index_pairs.push_back({nums[i], i});
        }

        sort(value_index_pairs.begin(), value_index_pairs.end());

        unordered_map<int, int> rank;
        for (int i = 0; i < n; ++i) {
            rank[value_index_pairs[i].first] = i + 1;
        }

        for (int i = n - 1; i >= 0; --i) {
            int index = rank[nums[i]];
            ans[i] = get(index - 1);
            update(index, 1);
        }

        return ans;
    }
};
```

### Code (Java)

```java
class Solution {
    private int[] bit;

    private void update(int index, int value, int n) {
        for (; index <= n; index += index & (-index)) {
            bit[index] += value;
        }
    }

    private int get(int index) {
        int sum = 0;
        for (; index > 0; index -= index & (-index)) {
            sum += bit[index];
        }
        return sum;
    }

    public int[] constructLowerArray(int[] nums) {
        int n = nums.length;
        bit = new int[n + 1];
        int[] ans = new int[n];

        List<int[]> valueIndexPairs = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            valueIndexPairs.add(new int[]{nums[i], i});
        }

        Collections.sort(valueIndexPairs, Comparator.comparingInt(a -> a[0]));

        Map<Integer, Integer> rank = new HashMap<>();
        for (int i = 0; i < n; i++) {
            rank.put(valueIndexPairs.get(i)[0], i + 1);
        }

        for (int i = n - 1; i >= 0; i--) {
            int index = rank.get(nums[i]);
            ans[i] = get(index - 1);
            update(index, 1, n);
        }

        return ans;
    }
}
```

### Code (Python)

```python
class Solution:
    def constructLowerArray(self, arr):
        n = len(arr)
        bit = [0] * (n + 1)
        ans = [0] * n

        def update(index, value):
            while index <= n:
                bit[index] += value
                index += index & -index

        def get(index):
            sum = 0
            while index > 0:
                sum += bit[index]
                index -= index & -index
            return sum

        value_index_pairs = [(arr[i], i) for i in range(n)]
        value_index_pairs.sort()

        rank = {value_index_pairs[i][0]: i + 1 for i in range(n)}

        for i in range(n - 1, -1, -1):
            index = rank[arr[i]]
            ans[i] = get(index - 1)
            update(index, 1)

        return ans
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
