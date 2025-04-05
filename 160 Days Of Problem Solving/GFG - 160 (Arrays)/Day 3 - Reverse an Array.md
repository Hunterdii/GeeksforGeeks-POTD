---
Difficulty: Easy
Source: 160 Days of Problem Solving
Tags:
  - Arrays
---

# 🚀 _Day 3. Reverse an Array_ 🧠

The problem can be found at the following link: [Problem Link](https://www.geeksforgeeks.org/batch/gfg-160-problems/track/arrays-gfg-160/problem/reverse-an-array)

## 💡 **Problem Description:**

You are given an array of integers `arr[]`. Your task is to reverse the given array.

## 🔍 **Example Walkthrough:**

**Input:**  
`arr = [1, 4, 3, 2, 6, 5]`  
**Output:**  
`[5, 6, 2, 3, 4, 1]`

**Explanation:**  
The elements of the array are `1 4 3 2 6 5`. After reversing the array, the first element goes to the last position, the second element goes to the second-last position, and so on. Hence, the answer is `[5, 6, 2, 3, 4, 1]`.

**Input:**  
`arr = [4, 5, 2]`  
**Output:**  
`[2, 5, 4]`

**Explanation:**  
The elements of the array are `4 5 2`. The reversed array will be `[2, 5, 4]`.

**Input:**  
`arr = [1]`  
**Output:**  
`[1]`

**Explanation:**  
The array has only a single element, hence the reversed array is the same as the original.

### Constraints:

- $`1 <= arr.size() <= 10^5`$
- $`0 <= arr[i] <= 10^5`$

## 🎯 **My Approach:**

1. **Reversal Process:**

   - The main idea is to reverse the array in-place by swapping elements from both ends.
   - We initialize two pointers: `left` at the beginning of the array and `right` at the end.
   - We swap `arr[left]` and `arr[right]`, then move `left` forward and `right` backward until they cross each other.
   - This process effectively reverses the array.

2. **Alternative Approaches:**
   - **XOR Swap Method:** You can swap elements using XOR to avoid a temporary variable.
   - **Using List Reverse:** In some languages, you can simply call the reverse function on the array.

## 🕒 **Time and Auxiliary Space Complexity**📝

- **Expected Time Complexity:** O(n), where `n` is the number of elements in the array. We perform one pass through the array, swapping elements in place.
- **Expected Auxiliary Space Complexity:** O(1), as we only use a constant amount of additional space to track the left and right pointers.

## 📝 **Solution Code**

## Code (C)

```c
void reverseArray(int arr[], int n) {
    int left = 0, right = n - 1;

    while (left < right) {
        arr[left] ^= arr[right];
        arr[right] ^= arr[left];
        arr[left] ^= arr[right];
        left++;
        right--;
    }
}
```

<details>
  <summary><h2 align='center'>👨‍💻 Alternative Approaches</h2></summary>

### Alternative Approach (Using Temporary Variable)

```c
void reverseArray(int arr[], int n) {
    int left = 0, right = n - 1;

    while (left < right) {
        int temp = arr[left];
        arr[left] = arr[right];
        arr[right] = temp;
        left++;
        right--;
    }
}
```

</details>

## Code (CPP)

```cpp
class Solution {
public:
    void reverseArray(std::vector<int>& arr) {
        std::reverse(arr.begin(), arr.end());
    }
};
```

<details>
  <summary><h2 align='center'>👨‍💻 Alternative Approaches</h2></summary>

### Alternative Approach (Using `std::swap`)

```cpp
class Solution {
public:
    void reverseArray(std::vector<int>& arr) {
        int left = 0, right = arr.size() - 1;

        while (left < right) {
            std::swap(arr[left], arr[right]);
            left++;
            right--;
        }
    }
};
```

### Alternative Approach (Using `XOR Swap`)

```cpp
class Solution {
public:
    void reverseArray(std::vector<int>& arr) {
        int left = 0, right = arr.size() - 1;

        while (left < right) {
            arr[left] ^= arr[right];
            arr[right] ^= arr[left];
            arr[left] ^= arr[right];
            left++;
            right--;
        }
    }
};
```

</details>

## Code (Java)

```java
class Solution {
    public void reverseArray(int[] arr) {
        Integer[] boxedArray = Arrays.stream(arr).boxed().toArray(Integer[]::new);
        List<Integer> list = Arrays.asList(boxedArray);
        Collections.reverse(list);
        for (int i = 0; i < arr.length; i++) {
            arr[i] = list.get(i);
        }
    }
}
```

<details>
  <summary><h2 align='center'>👨‍💻 Alternative Approaches</h2></summary>

### Alternative Approach (Using XOR Swap)

```java
class Solution {
    public void reverseArray(int[] arr) {
        int left = 0, right = arr.length - 1;

        while (left < right) {
            arr[left] = arr[left] ^ arr[right];
            arr[right] = arr[left] ^ arr[right];
            arr[left] = arr[left] ^ arr[right];
            left++;
            right--;
        }
    }
}
```

</details>

## Code (Python)

```python
class Solution:
    def reverseArray(self, arr):
        arr.reverse()
```

<details>
  <summary><h2 align='center'>👨‍💻 Alternative Approaches</h2></summary>

### Alternative Approach (Using Swapping)

```python
class Solution:
    def reverseArray(self, arr):
        left, right = 0, len(arr) - 1

        while left < right:
            arr[left], arr[right] = arr[right], arr[left]
            left += 1
            right -= 1
```

</details>

# 🎯 **Contribution and Support:**

For discussions, questions, or doubts related to this solution, feel free to connect on LinkedIn: [Any Questions](https://www.linkedin.com/in/patel-hetkumar-sandipbhai-8b110525a/). Let’s make this learning journey more collaborative!

⭐ If you find this helpful, please give this repository a star! ⭐

---

<div align="center">
  <h3><b>📍Visitor Count</b></h3>
</div>

<p align="center">
  <img src="https://profile-counter.glitch.me/Hunterdii/count.svg" />
</p>
