## 03. Largest Number formed from an Array

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/largest-number-formed-from-an-array1117/1)

### My Approach

To achieve our objective of forming the largest possible number by concatenating strings from an array, we follow these steps:

1. **Define a Custom Comparison Function**: We create a function, let's call it `compareStrings`, which compares two strings (`a` and `b`) based on their concatenation in different orders (`a + b` versus `b + a`). This function determines which combination results in a larger number.

2. **Sorting the Array**: Using the `sort` function, we arrange the strings in the array in descending order. This sorting is done based on our custom comparison function `compareStrings`. Consequently, the array is ordered in a way that ensures when the strings are concatenated, they form the largest possible number.

3. **Concatenation**: After sorting, we simply concatenate the strings in the sorted array to form the final result.

4. **Return Output**: The concatenated string is then returned as the output of our process.

### Time and Auxiliary Space Complexity

- **Time Complexity**: `O(NlogN)`, where N is the number of strings in the array.
- **Auxiliary Space Complexity**: `O(N)`, where N is the number of strings in the array.

### Code (C++)

```cpp
class Solution {
public:
 static bool comp(string a, string b){
     return a + b > b + a;
 }

 string printLargest(int n, vector<string> &arr) {
     sort(arr.begin(), arr.end(), comp);

     string ans;
     for(string i : arr)
         ans += i;

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
