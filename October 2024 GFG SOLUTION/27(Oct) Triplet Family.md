# _27. Triplet Family_

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/triplet-family/1)

_Note: My externals exams are currently ongoing, which is the reason for the delayed upload **Sorry** ._

## Problem Description

Given an array `arr` of integers, find whether there exist three numbers such that the sum of two elements equals the third element.

_Example:_

Input:

```
arr[] = [1, 2, 3, 4, 5]
```

Output:

```
true
```

Explanation: The pair (1, 2) sums to 3.

Input:

```
arr[] = [5, 3, 4]
```

Output:

```
false
```

Explanation: No triplets satisfy the condition.

## My Approach

1. **Sorting the Array:**

   - First, sort the array to allow for efficient searching of pairs.

2. **Iterating Through the Array:**

   - Loop through the array from the last element to the third element, treating the current element as the target.

3. **Two-Pointer Technique:**

   - For each target, use a two-pointer approach to find if there exist two numbers in the sorted array that sum up to the target:
     - Set one pointer at the start of the array and the other just before the target.
     - If the sum of the two pointers equals the target, return true.
     - If the sum is less than the target, move the left pointer to the right.
     - If the sum is greater than the target, move the right pointer to the left.

4. **Final Answer:**
   - If no such triplet is found by the end of the iterations, return false.

## Time and Auxiliary Space Complexity

- **Expected Time Complexity:** O(n^2), where n is the length of the array, as we perform two nested loops—one for iterating through the target and the other for the two-pointer search.
- **Expected Auxiliary Space Complexity:** O(1), as we use a constant amount of additional space.

## Code (C++)

```cpp
class Solution {
public:
    bool findTriplet(vector<int>& arr) {
        int n = arr.size();
        if (n < 3) return false;

        sort(arr.begin(), arr.end());

        for (int i = n - 1; i >= 2; --i) {
            int target = arr[i];
            int left = 0, right = i - 1;

            while (left < right) {
                int sum = arr[left] + arr[right];

                if (sum == target) return true;
                if (sum < target)
                    ++left;
                else
                    --right;
            }
        }
        return false;
    }
};
```

## Code (Java)

```java
class Solution {
    public boolean findTriplet(int[] arr) {
        int n = arr.length;
        if (n < 3) return false;

        Arrays.sort(arr); // Sort array

        for (int i = n - 1; i >= 2; i--) {
            int target = arr[i];
            int left = 0, right = i - 1;

            while (left < right) {
                int sum = arr[left] + arr[right];

                if (sum == target) return true;
                if (sum < target) {
                    left++;
                } else {
                    right--;
                }
            }
        }
        return false;
    }
}
```

## Code (Python)

```python
class Solution:
    def findTriplet(self, arr):
        n = len(arr)
        if n < 3:
            return False

        arr.sort()  # Sort array

        for i in range(n - 1, 1, -1):
            target = arr[i]
            left, right = 0, i - 1

            while left < right:
                sum_ = arr[left] + arr[right]

                if sum_ == target:
                    return True
                elif sum_ < target:
                    left += 1
                else:
                    right -= 1

        return False
```

## Contribution and Support

For discussions, questions, or doubts related to this solution, please visit my LinkedIn: [Any Questions](https://www.linkedin.com/in/patel-hetkumar-sandipbhai-8b110525a/). Thank you for your input; together, we strive to create a space where learning is a collaborative endeavor.

⭐ Star this repository if you find it helpful or intriguing! ⭐

<div align=center>
  <h3><b>📍Visitor Count</b></h3>
</div>

<p align="center" >   
  <img src="https://profile-counter.glitch.me/Hunterdii/count.svg" />  
</p>
