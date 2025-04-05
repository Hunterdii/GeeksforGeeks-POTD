## 21. K Closest Elements

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/k-closest-elements3619/1)

### Problem Description

Given an array `arr[]` of size `n` integers and a value `x`, find the `k` closest elements to `x` in `arr[]`.

**Example:**

Input:

```
n = 13
arr[] = {12, 16, 22, 30, 35, 39, 42, 45, 48, 50, 53, 55, 56}
k = 4, x = 35
```

Output:

```
39 30 42 45
```

Explanation:
The first closest element to 35 is 39, the second is 30, the third is 42, and the fourth is 45.

### My Approach

1. **Finding the Cross-Over Point:**

- Implement a binary search to find the index `l` such that `arr[l]` is the largest element smaller than or equal to `x`.
- This step helps in determining the elements closest to `x`.

2. **Finding K Closest Elements:**

- Initialize two pointers `l` and `r` to the indices found in the previous step.
- Compare the absolute differences of `x` with elements at `l` and `r`.
- Move the pointers accordingly to find the `k` closest elements.

3. **Return:**

- Return an array containing the `k` closest elements found.

### Time and Auxiliary Space Complexity

- **Expected Time Complexity:** O(log n + k), where log n is for binary search and k is for finding the closest elements.
- **Expected Auxiliary Space Complexity:** O(k), as we use an array to store the `k` closest elements.

### Code

#### Java

```java
class Solution {
    private int findCrossOver(int[] arr, int low, int high, int x) {
        if (arr[high] <= x) {
            return high;
        }
        if (arr[low] > x) {
            return low;
        }
        int mid = (low + high) / 2;
        if (arr[mid] <= x && arr[mid + 1] > x) {
            return mid;
        } else if (arr[mid] < x) {
            return findCrossOver(arr, mid + 1, high, x);
        }
        return findCrossOver(arr, low, mid - 1, x);
    }

    int[] printKClosest(int[] arr, int n, int k, int x) {

        int[] result = new int[k];
        List<Integer> closest = new ArrayList<>();


        int l = findCrossOver(arr, 0, n - 1, x);

        int r = l + 1;
        int count = 0;

        if (arr[l] == x) {
            l--;
        }


        while (l >= 0 && r < n && count < k) {
            if (x - arr[l] < arr[r] - x) {
                closest.add(arr[l]);
                l--;
            } else {
                closest.add(arr[r]);
                r++;
            }
            count++;
        }


        while (count < k && l >= 0) {
            closest.add(arr[l]);
            l--;
            count++;
        }


        while (count < k && r < n) {
            closest.add(arr[r]);
            r++;
            count++;
        }


        for (int i = 0; i < k; i++) {
            result[i] = closest.get(i);
        }

        return result;
    }
}
```

#### Python

```python
class Solution:
    def printKClosest(self, arr, n, k, x):

        def findCrossOver(arr, low, high, x):
            if arr[high] <= x:
                return high
            if arr[low] > x:
                return low
            mid = (low + high) // 2
            if arr[mid] <= x and arr[mid + 1] > x:
                return mid
            elif arr[mid] < x:
                return findCrossOver(arr, mid + 1, high, x)
            return findCrossOver(arr, low, mid - 1, x)

        result = []
        closest = []

        l = findCrossOver(arr, 0, n - 1, x)
        r = l + 1
        count = 0

        if arr[l] == x:
            l -= 1


        while l >= 0 and r < n and count < k:
            if (x - arr[l] < arr[r] - x):
                closest.append(arr[l])
                l -= 1
            else:
                closest.append(arr[r])
                r += 1
            count += 1


        while (count < k and l >= 0):
            closest.append(arr[l])
            l -= 1
            count += 1


        while (count < k and r < n):
            closest.append(arr[r])
            r += 1
            count += 1

        return closest
```

#### CPP

```cpp
class Solution {
  public:
       int findCrossOver(std::vector<int>& arr, int low, int high, int x) {

        if (arr[high] <= x) return high;
        if (arr[low] > x) return low;

        int mid = (low + high) / 2;


        if (arr[mid] <= x && arr[mid + 1] > x) return mid;
        else if (arr[mid] < x) return findCrossOver(arr, mid + 1, high, x);
        return findCrossOver(arr, low, mid - 1, x);
    }

    std::vector<int> printKClosest(std::vector<int>& arr, int n, int k, int x) {

        int id1 = findCrossOver(arr, 0, n - 1, x);


        int id2 = id1 + 1;


        if (id1 >= 0 && arr[id1] == x) id1--;

        std::vector<int> ans;
        for (int i = 0; i < k; i++) {

            if (id1 >= 0 && id2 < n) {
                int val1 = x - arr[id1];
                int val2 = arr[id2] - x;

                if (val1 < val2) {
                    ans.push_back(arr[id1]);
                    id1--;
                } else {
                    ans.push_back(arr[id2]);
                    id2++;
                }
            } else if (id1 >= 0) {
                ans.push_back(arr[id1]);
                id1--;
            } else {
                ans.push_back(arr[id2]);
                id2++;
            }
        }

        return ans;
    }
};

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
