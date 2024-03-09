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

### Contribution and Support

For discussions, questions, or doubts related to this solution, please visit my LinkedIn:- [Any Questions](https://www.linkedin.com/in/het-patel-8b110525a/). 
Thank you for your input; together, we strive to create a space where learning is a collaborative endeavor.

⭐ Star this repository if you find it helpful or intriguing! ⭐
