# _20. Facing the Sun_

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/facing-the-sun2126/1)

### Problem Description

Given an array of integers `height` representing the heights of buildings, count the number of buildings that can see the sunrise. Assume the sun rises from the side of the array's starting point. A building can see the sunrise if its height is strictly greater than all buildings to its left.

<p align="center">
  <img src="https://github.com/user-attachments/assets/2d56e23b-1c9b-4ec2-9f2c-29acf2dea91c" alt="Image" width="370" />
</p>

**Examples:**

Input:  
`height = [7, 4, 8, 2, 9]`  
Output:  
`3`  
Explanation:

- Building 7 can see the sunrise.
- Building 4 cannot see the sunrise because building 7 blocks it.
- Building 8 can see the sunrise.
- Building 2 cannot see the sunrise because building 8 blocks it.
- Building 9 can see the sunrise.

### My Approach

1. **Tracking Maximum Height:**  
   We iterate through the array while maintaining the maximum height encountered so far. For each building, we compare its height with the maximum height. If the current building is taller, it can see the sunrise, and we increment the count. We also update the maximum height to the current building's height.

2. **Single Pass Solution:**  
   By iterating over the array once and using constant space, we can efficiently solve this problem in linear time.

### Time and Auxiliary Space Complexity

- **Expected Time Complexity:** O(n), where n is the number of buildings, as we iterate through the entire array once.
- **Expected Auxiliary Space Complexity:** O(1), as we only use a few variables to store intermediate values like `max_height` and `count`.

### Code (C++)

```cpp
class Solution {
  public:
    int countBuildings(const vector<int>& height) {
        int count = 0;
        int max_height = INT_MIN;

        for (int h : height) {
            if (h > max_height) {
                count++;
                max_height = h;
            }
        }
        return count;
    }
};
```

### Code (Java)

```java
class Solution {
    public int countBuildings(int[] height) {
        int count = 0;
        int max_height = Integer.MIN_VALUE;

        for (int h : height) {
            if (h > max_height) {
                count++;
                max_height = h;
            }
        }
        return count;
    }
}
```

### Code (Python)

```python
class Solution:
    def countBuildings(self, height):
        count = 0
        max_height = float('-inf')

        for h in height:
            if h > max_height:
                count += 1
                max_height = h

        return count
```

## Contribution and Support

For discussions, questions, or doubts related to this solution, please visit my LinkedIn: [Any Questions](https://www.linkedin.com/in/patel-hetkumar-sandipbhai-8b110525a/). Your input is valuable for improving the content, and together we can foster a community of learning.

⭐ Star this repository if you find it helpful or intriguing! ⭐

---

<div align=center>
  <h3><b>📍Visitor Count</b></h3>
</div>

<p align="center" >   
  <img src="https://profile-counter.glitch.me/Hunterdii/count.svg" />  
</p>
