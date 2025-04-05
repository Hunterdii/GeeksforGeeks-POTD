## 01. Peak element

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/peak-element/1)

### My Approach

To find the peak element within a sequence, we employ a binary search method, leveraging the characteristic pattern where the sequence ascends and then descends.

- Initially, we establish two pointers, `left` and `right`, delineating the array's start and end, respectively.
- Next, we iterate through a loop to determine the middle index.
- If the value at the middle index is lower than its right adjacent element, it indicates the peak is positioned towards the right. Consequently, we shift `left` to `mid + 1`.
- Conversely, if the middle value is greater than or equal to its adjacent element to the right, it implies the peak lies towards the left or could be the middle value itself. Hence, we adjust `right` to `mid`.
- This iterative process continues until `left` is less than `right`, signifying that `left` denotes the peak element within the sequence.

### Time and Auxiliary Space Complexity

- **Time Complexity**: The time complexity of the binary search approach is `O(log n)`, where n is the number of elements in the array.
- **Auxiliary Space Complexity**: The space complexity is `O(1)` as we are using only a constant amount of extra space.

### Code (C++)

```cpp
class Solution
{
    public:
    int peakElement(int arr[], int n)
    {
       int ans=0;
       for(int i=0;i<n;i++){
           if(arr[i]>arr[i+1]){
              ans=i;
              break;
           }
          else if(arr[i]>arr[i-1]){
              ans=i;
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
