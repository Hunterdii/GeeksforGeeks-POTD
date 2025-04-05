## 05. Maximum Index

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/maximum-index-1587115620/1)

### My Approach

1. **Initialization**: Begin by setting ans to -1 to signify that the maximum difference of indices is yet to be determined.
2. **Compute Left Minima (lmin)**: For each element, calculate the minimum value on its left side and store it in the lmin array.

3. **Compute Right Maxima (rmax)**: Similarly, for each element, calculate the maximum value on its right side and store it in the rmax array.

4. **Iterate and Compare**: Utilize two pointers, i and j, to traverse through the arrays. While both pointers are within the array bounds:
   - Compare the minimum on the left (lmin[i]) with the maximum on the right (rmax[j]).
   - If the minimum on the left is less than the maximum on the right, update the answer (ans) with the maximum difference of indices (j - i) and increment j.
   - Otherwise, increment i.
5. **Return Answer**: Once the iteration is complete, return the final answer, which represents the maximum difference of indices satisfying the condition.

By following these steps, you can effectively find the maximum difference of indices based on the given conditions.

### Time and Auxiliary Space Complexity

- **Time Complexity**: `O(N)`, where N is the size of the array.
- **Auxiliary Space Complexity**: `O(N)`, two additional arrays of size N (lmin and rmax) are used.

### Code (C++)

```cpp
class Solution{
    public:
    int maxIndexDiff(int a[], int n)
    {
       int i=0,j=n-1;
       int ans = 0;

       while(i <= j){
           if(a[i]<=a[j]){
               ans = max(ans,j-i);
               i++;
               j = n-1;
           }
           else{
               j--;
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
