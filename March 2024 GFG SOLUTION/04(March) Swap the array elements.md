## 04. Swap the array elements
The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/need-some-change/1)

### My Approach

1. **Iteration**: Start from the beginning of the array and move towards the second-to-last element (index `n - 2`). This is because you're swapping elements at index `i` with the element at index `i + 2`, and you don't want to go beyond the array boundary.

2. **Swapping with Bitwise XOR**: At each step, swap the element at index `i` with the element at index `i + 2` using bitwise XOR operation. This operation allows you to swap elements without using a temporary variable.

3. **Repeat Until the End**: Keep repeating this process until you reach the end of the array.

### Time and Auxiliary Space Complexity

- **Time Complexity**: `O(n)`, where n is the size of the array.
- **Auxiliary Space Complexity**: `O(1)`, as no extra space is used.

### Code (C++)
```cpp
class Solution{
public:
    void swapElements(int arr[], int n){
        for(int i = 0; i < n-2; i++){
            swap(arr[i], arr[i+2]);
        }
    }
};
```

### Contribution and Support

For discussions, questions, or doubts related to this solution, please visit my LinkedIn:- [Any Questions](https://www.linkedin.com/in/het-patel-8b110525a/). 
Thank you for your input; together, we strive to create a space where learning is a collaborative endeavor.

⭐ Star this repository if you find it helpful or intriguing! ⭐
