# *Next Greater Element using Stack*

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/next-greater-element/)

## **Problem Description**

Given an array **arr[]** of integers, the task is to find the **next greater element** for each element of the array in order of their appearance. 

The **next greater element** of an element in the array is the nearest element **on the right** which is **greater** than the current element.

If there is no greater element, return **-1**.

## **Examples**

### **Example 1:**
#### **Input:**
```
arr = [1, 3, 2, 4]
```
#### **Output:**
```
[3, 4, 4, -1]
```
#### **Explanation:**
- The next greater element for `1` is `3`
- The next greater element for `3` is `4`
- The next greater element for `2` is `4`
- `4` has no greater element, so `-1`

### **Example 2:**
#### **Input:**
```
arr = [6, 8, 0, 1, 3]
```
#### **Output:**
```
[8, -1, 1, 3, -1]
```
#### **Explanation:**
- The next greater element for `6` is `8`
- `8` has no greater element
- The next greater element for `0` is `1`
- The next greater element for `1` is `3`
- `3` has no greater element, so `-1`

### **Example 3:**
#### **Input:**
```
arr = [10, 20, 30, 50]
```
#### **Output:**
```
[20, 30, 50, -1]
```
#### **Explanation:**
- For a sorted array, the next element is the next greater element except for the last element.

### **Example 4:**
#### **Input:**
```
arr = [50, 40, 30, 10]
```
#### **Output:**
```
[-1, -1, -1, -1]
```
#### **Explanation:**
- There is no greater element for any of the elements in the array, so all are `-1`.

## **Constraints**
- $1 \leq arr.length \leq 10^6$
- $1 \leq arr[i] \leq 10^9$

## **Approach**

### **Stack-Based Approach (O(N) Time, O(N) Space)**
1. **Use a stack to track elements** whose next greater element hasn't been found.
2. **Traverse the array from right to left**:
   - If the stack is **not empty** and the top of the stack is **less than or equal to the current element**, pop the stack.
   - The next greater element for the current element is the **top of the stack**.
   - If the stack is empty, assign `-1`.
   - Push the current element onto the stack.

### **Algorithm Steps**
1. Initialize an empty **stack**.
2. Traverse **arr** from right to left:
   - While stack is **not empty** and `stack.peek() <= arr[i]`, pop elements.
   - If stack is empty, `result[i] = -1`, else `result[i] = stack.peek()`.
   - Push `arr[i]` onto the stack.
3. Return `result`.

## **Time and Space Complexity**
- **Time Complexity:** **O(N)** (Each element is pushed and popped once)
- **Space Complexity:** **O(N)** (For storing elements in the stack)
- ## **Code (c++)**
```c++
vector<int> nextLargerElement(vector<int> &arr) {
    int n = arr.size();
    vector<int> result(n, -1);
    stack<int> st;

    for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && st.top() <= arr[i]) {
            st.pop();
        }
        if (!st.empty()) {
            result[i] = st.top();
        }
        st.push(arr[i]);
    }
    return result;
}

```
## **Code (Java)**
```java
import java.util.*;

class Solution {
    // Function to find the next greater element for each element of the array.
    public static ArrayList<Integer> nextLargerElement(int[] arr) {
       int n = arr.length;
        ArrayList<Integer> result = new ArrayList<>(n);
        Stack<Integer> stack = new Stack<>();

        // Initialize result list with -1 (default value)
        for (int i = 0; i < n; i++) {
            result.add(-1);
        }

        for (int i = n - 1; i >= 0; i--) {
            while (!stack.isEmpty() && stack.peek() <= arr[i]) {
                stack.pop();
            }
            if (!stack.isEmpty()) {
                result.set(i, stack.peek());
            }
            stack.push(arr[i]);
        }

        return result;
    }

    // Driver code to test the function
    public static void main(String[] args) {
        int[] arr = {1, 3, 2, 4};
        System.out.println(nextLargerElement(arr)); // Output: [3, 4, 4, -1]
    }
}
```

## **Code (Python)**
```python
def nextLargerElement(arr):
    n = len(arr)
    result = [-1] * n
    stack = []

    for i in range(n - 1, -1, -1):
        while stack and stack[-1] <= arr[i]:
            stack.pop()
        if stack:
            result[i] = stack[-1]
        stack.append(arr[i])

    return result

# Driver code to test the function
arr = [1, 3, 2, 4]
print(nextLargerElement(arr)) # Output: [3, 4, 4, -1]
```

## **Alternative Approaches**
### **1️⃣ Brute Force Approach (O(N²) Time, O(1) Space)**
- Use a nested loop to compare each element with elements on the right.
- This approach is inefficient for large inputs.

```java
class Solution {
    public static ArrayList<Integer> nextLargerElement(int[] arr) {
        int n = arr.length;
        ArrayList<Integer> result = new ArrayList<>(Collections.nCopies(n, -1));

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (arr[j] > arr[i]) {
                    result.set(i, arr[j]);
                    break;
                }
            }
        }
        return result;
    }
}
```

🔹 **Pros:** Simple to understand  
🔹 **Cons:** **O(N²)** time complexity makes it slow for large arrays  

---

## **Comparison of Approaches**
| **Approach**            | **Time Complexity** | **Space Complexity** | **Pros**                          | **Cons** |
|-------------------------|--------------------|----------------------|-----------------------------------|----------|
| **Stack Approach**      | `O(N)`             | `O(N)`               | Efficient and optimal solution   | Uses extra space for stack |
| **Brute Force Approach** | `O(N²)`            | `O(1)`               | Easy to understand               | Too slow for large inputs |

---

## **Conclusion**
- ✅ The **Stack-based approach** is the most **efficient** solution.
- ❌ The **Brute-force approach** is too slow for large inputs.
- **Use the Stack approach** when solving Next Greater Element problems in competitive programming or interviews.

⭐ **If you find this helpful, please star this repository!** ⭐
