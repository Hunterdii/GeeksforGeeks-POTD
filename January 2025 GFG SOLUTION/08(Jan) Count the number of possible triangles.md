# _08. Count the number of possible triangles_

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/count-possible-triangles-1587115620/1)

## Problem Description

Given an integer array `arr[]`, find the number of triangles that can be formed with three different array elements as the lengths of three sides of the triangle.

A triangle with three given sides is only possible if the sum of any two sides is always greater than the third side.

**Example:**

Input:

```
arr[] = [4, 6, 3, 7]
```

Output:

```
3
```

Explanation: There are three triangles possible: [3, 4, 6], [4, 6, 7], and [3, 6, 7]. Note that [3, 4, 7] is not a possible triangle.

Input:

```
arr[] = [10, 21, 22, 100, 101, 200, 300]
```

Output:

```
6
```

Explanation: There can be 6 possible triangles: [10, 21, 22], [21, 100, 101], [22, 100, 101], [10, 100, 101], [100, 101, 200], and [101, 200, 300].

Input:

```
arr[] = [1, 2, 3]
```

Output:

```
0
```

Explanation: No triangles are possible.

## My Approach

1. **Sorting the Array:**

   - Sort the array to make it easier to check if any three sides can form a valid triangle. Sorting ensures that we can always check for a valid triangle using the largest side as the third side.

2. **Iterating through the Array:**
   - After sorting the array, iterate over it in reverse order to check each possible triplet `(arr[i], arr[l], arr[r])` (with `l` and `r` starting from 0 and `i-1`, respectively).
3. **Checking Triangle Validity:**

   - For each triplet, if `arr[l] + arr[r] > arr[i]`, then the triplet can form a valid triangle. If this condition holds, increment the count of possible triangles.

4. **Returning the Result:**
   - The result is the final count of all valid triplets that form a triangle.

## Time and Auxiliary Space Complexity

- **Expected Time Complexity:** O(n^2), where `n` is the length of the array, as we iterate over the array and check pairs of elements for each element.
- **Expected Auxiliary Space Complexity:** O(1), since we only use a constant amount of additional space for counters and temporary variables.

## Code (C)

```c
int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int countTriangles(int arr[], int n) {
    qsort(arr, n, sizeof(int), compare);
    int count = 0;
    for (int i = n - 1; i >= 2; --i) {
        int l = 0, r = i - 1;
        while (l < r) {
            if (arr[l] + arr[r] > arr[i]) count += (r-- - l);
            else ++l;
        }
    }
    return count;
}
```

## Code (C++)

```cpp
class Solution {
public:
    int countTriangles(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int cnt = 0;
        for (int i = arr.size() - 1; i >= 2; --i)
            for (int l = 0, r = i - 1; l < r; arr[l] + arr[r] > arr[i] ? cnt += r-- - l : ++l);
        return cnt;
    }
};
```

## Code (Java)

```java
class Solution {
    static int countTriangles(int[] arr) {
        Arrays.sort(arr);
        int count = 0, n = arr.length;
        for (int i = n - 1; i >= 2; --i) {
            int l = 0, r = i - 1;
            while (l < r) {
                if (arr[l] + arr[r] > arr[i]) count += (r-- - l);
                else ++l;
            }
        }
        return count;
    }
}
```

## Code (Python)

```python
class Solution:
    def countTriangles(self, arr):
        arr.sort()
        n, count = len(arr), 0
        for i in range(n - 1, 1, -1):
            l, r = 0, i - 1
            while l < r:
                if arr[l] + arr[r] > arr[i]:
                    count += r - l
                    r -= 1
                else:
                    l += 1
        return count
```

## Contribution and Support

For discussions, questions, or doubts related to this solution, please visit my LinkedIn: [Any Questions](https://www.linkedin.com/in/patel-hetkumar-sandipbhai-8b110525a/). Thank you for your input; together, we strive to create a space where learning is a collaborative endeavor.

⭐ Star this repository if you find it helpful or intriguing! ⭐

---

<div align=center>
  <h3><b>📍Visitor Count</b></h3>
</div>

<p align="center" >   
  <img src="https://profile-counter.glitch.me/Hunterdii/count.svg" />  
</p>
