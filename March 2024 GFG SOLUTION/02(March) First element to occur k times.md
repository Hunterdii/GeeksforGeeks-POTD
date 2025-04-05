## 02. First element to occur k times

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/first-element-to-occur-k-times5150/1)

### My Approach

1. We'll utilize an unordered map to keep track of how many times each element appears in the array.
2. While traversing through the array:
   - If the frequency of the current element reaches k, we'll immediately return that element.
   - If we don't find any element with a frequency of k, we'll return -1.

### Time and Auxiliary Space Complexity

- **Time Complexity**: O(n) - We iterate through the array once.
- **Auxiliary Space Complexity**: O(n) - We use an unordered map to store the frequency of elements.

### Code (C++)

```cpp
class Solution{
    public:
    int firstElementKTime(int n, int k, int a[])
    {
        std::unordered_map<int, int> map;
        for(int i=0; i<n; i++){
            map[a[i]]++;
            if(map[a[i]] == k)
                return a[i];
        }
        return -1;
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
