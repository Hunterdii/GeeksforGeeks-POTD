# _28. Remove Duplicates in Array_

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/remove-duplicates-in-small-prime-array/1)

### Problem Description

Given an array `arr` consisting of positive integer numbers, remove all duplicate numbers. The modified array should contain only unique elements.

**Example:**

Input:

```
arr[] = [2, 2, 3, 3, 7, 5]
```

Output:

```
[2, 3, 7, 5]
```

Explanation: After removing the duplicates 2 and 3, we get the array `[2, 3, 7, 5]`.

Input:

```
arr[] = [2, 2, 5, 5, 7, 7]
```

Output:

```
[2, 5, 7]
```

Input:

```
arr[] = [8, 7]
```

Output:

```
[8, 7]
```

**Constraints:**

- 1 ≤ arr.size() ≤ 10^6
- 2 ≤ arr[i] ≤ 100

## My Approach

1. **Using a Set for Uniqueness:**

   - Utilize a set to keep track of the unique elements encountered while iterating through the array. Sets automatically handle duplicates for us.

2. **Building the Result:**
   - Iterate through the array, adding elements to the set. If an element is already present in the set, it is ignored.
   - Finally, convert the set back to a vector or array for the result.

## Time and Auxiliary Space Complexity

- **Expected Time Complexity:** O(n), where n is the length of the input array. Each element is processed once.
- **Expected Auxiliary Space Complexity:** O(n), as we use a set to store the unique elements.

## Code (C++)

```cpp
class Solution {
public:
    vector<int> removeDuplicate(vector<int>& arr) {
        vector<int> result;
        unordered_set<int> seen;

        for (int num : arr) {
            if (seen.insert(num).second) {
                result.push_back(num);
            }
        }
        return result;
    }
};
```

## Code (Java)

```java
class Solution {
    ArrayList<Integer> removeDuplicate(int arr[]) {
        ArrayList<Integer> result = new ArrayList<>();
        HashSet<Integer> seen = new HashSet<>();

        for (int num : arr) {
            if (seen.add(num)) {
                result.add(num);
            }
        }
        return result;
    }
}
```

## Code (Python)

```python
class Solution:
    def removeDuplicates(self, arr):
        seen = set()
        result = []
        for num in arr:
            if num not in seen:
                result.append(num)
                seen.add(num)
        return result
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
