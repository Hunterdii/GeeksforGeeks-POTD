# _10. Union of Two Sorted Arrays with Distinct Elements_

The problem can be found at the following link: [Problem Link](https://www.geeksforgeeks.org/problems/union-of-two-sorted-arrays-with-distinct-elements/1)

## Problem Description

Given two sorted arrays `a[]` and `b[]`, where each array contains distinct elements, the task is to return a sorted array containing the union of the two arrays with distinct elements only. The union of two arrays is defined as the set containing all distinct elements present in either of the arrays.

### Examples:

**Input:**

```
a[] = [1, 2, 3, 4, 5]
b[] = [1, 2, 3, 6, 7]
```

**Output:**

```
1 2 3 4 5 6 7
```

**Explanation:** The distinct elements in both arrays are: 1, 2, 3, 4, 5, 6, 7.

**Input:**

```
a[] = [2, 3, 4, 5]
b[] = [1, 2, 3, 4]
```

**Output:**

```
1 2 3 4 5
```

**Explanation:** The distinct elements in both arrays are: 1, 2, 3, 4, 5.

**Input:**

```
a[] = [1]
b[] = [2]
```

**Output:**

```
1 2
```

**Explanation:** The distinct elements in both arrays are: 1, 2.

## My Approach

1. **Two-pointer Technique:**
   - We use two pointers, `i` and `j`, starting at the beginning of arrays `a` and `b` respectively.
   - Compare elements at `a[i]` and `b[j]`. Add the smaller element to the result and move the pointer. If both elements are equal, add one to the result and move both pointers.
   - After finishing the comparison, if there are remaining elements in either array, add them to the result (skipping duplicates).
2. **Edge Cases:**
   - If either array is empty, return the other array.
   - Handle duplicates by checking adjacent elements before adding them to the result array.

## Time and Auxiliary Space Complexity

- **Expected Time Complexity:** O(n + m), where `n` and `m` are the lengths of arrays `a` and `b`, as each element is processed once.
- **Expected Auxiliary Space Complexity:** O(n + m), to store the result array containing the union of both input arrays.

## Code (C++)

```cpp
#include <vector>
using namespace std;

class Solution {
  public:
    vector<int> findUnion(vector<int> &a, vector<int> &b) {
        vector<int> res;
        int n = a.size();
        int m = b.size();
        int i = 0, j = 0;

        while (i < n && j < m) {
            while (i > 0 && i < n && a[i] == a[i - 1]) i++;
            while (j > 0 && j < m && b[j] == b[j - 1]) j++;

            if (i < n && j < m) {
                if (a[i] < b[j]) {
                    res.push_back(a[i++]);
                } else if (a[i] > b[j]) {
                    res.push_back(b[j++]);
                } else {
                    res.push_back(a[i]);
                    i++;
                    j++;
                }
            }
        }
        while (i < n) {
            if (i == 0 || a[i] != a[i - 1]) {
                res.push_back(a[i]);
            }
            i++;
        }
        while (j < m) {
            if (j == 0 || b[j] != b[j - 1]) {
                res.push_back(b[j]);
            }
            j++;
        }

        return res;
    }
};
```

<details>
  <summary><h2 align='center'>👨‍💻 Alternative Approaches</h2></summary>

1. **Using a Set for Distinct Elements:**
   - Insert all elements from both arrays into a set to automatically handle duplicates, then return the sorted values.

```cpp
#include <vector>
#include <set>
using namespace std;

class Solution {
  public:
    vector<int> findUnion(vector<int> &a, vector<int> &b) {
        set<int> s;
        s.insert(a.begin(), a.end());
        s.insert(b.begin(), b.end());
        return vector<int>(s.begin(), s.end());
    }
};
```

</details>

## Code (Java)

```java
class Solution {
    public static ArrayList<Integer> findUnion(int[] a, int[] b) {
        ArrayList<Integer> res = new ArrayList<>();
        int i = 0, j = 0;
        int n = a.length, m = b.length;
        int lastAdded = Integer.MIN_VALUE;

        while (i < n && j < m) {
            int val;
            if (a[i] < b[j]) {
                val = a[i++];
            } else if (a[i] > b[j]) {
                val = b[j++];
            } else {
                val = a[i];
                i++;
                j++;
            }
            if (val != lastAdded) {
                res.add(val);
                lastAdded = val;
            }
        }
        while (i < n) {
            if (a[i] != lastAdded) {
                res.add(a[i]);
                lastAdded = a[i];
            }
            i++;
        }
        while (j < m) {
            if (b[j] != lastAdded) {
                res.add(b[j]);
                lastAdded = b[j];
            }
            j++;
        }

        return res;
    }
}
```

## Code (Python)

```python
class Solution:
    def findUnion(self, a, b):
        res = []
        i, j = 0, 0
        n, m = len(a), len(b)

        while i < n and j < m:
            if a[i] < b[j]:
                res.append(a[i])
                i += 1
            elif a[i] > b[j]:
                res.append(b[j])
                j += 1
            else:
                res.append(a[i])
                i += 1
                j += 1
        while i < n:
            res.append(a[i])
            i += 1
        while j < m:
            res.append(b[j])
            j += 1

        return res
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
