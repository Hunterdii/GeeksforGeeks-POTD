---
Difficulty: Easy  
Source: 160 Days of Problem Solving  
Tags:
  - Sorting
  - two-pointer-algorithm
  - Arrays
  - Hash
---

# 🚀 _Day 4. Intersection of Two arrays with Duplicate Elements_ 🧠


The problem can be found at the following link: [Problem Link](https://www.geeksforgeeks.org/batch/gfg-160-problems/track/hashing-gfg-160/problem/intersection-of-two-arrays-with-duplicate-elements)



## 💡 **Problem Description:**

You are given two integer arrays `a[]` and `b[]`. Your task is to find the intersection of the two arrays, which includes the elements that are common in both arrays. The intersection should not contain duplicate elements, and the result can be in any order.  

## 🔍 **Example Walkthrough:**

**Input:**  
`a[] = [1, 2, 1, 3, 1], b[] = [3, 1, 3, 4, 1]`  
**Output:**  
`[1, 3]`  
**Explanation:**  
1 and 3 are the only common elements, and only one occurrence of each is included in the result.

**Input:**  
`a[] = [1, 1, 1], b[] = [1, 1, 1, 1, 1]`  
**Output:**  
`[1]`  
**Explanation:**  
1 is the only common element present in both arrays.

**Input:**  
`a[] = [1, 2, 3], b[] = [4, 5, 6]`  
**Output:**  
`[]`  
**Explanation:**  
No common elements exist in both arrays.



### **Constraints**

- $\( 1 \leq \text{size of } a, b \leq 10^5 \)$  
- $\( 1 \leq a[i], b[i] \leq 10^5 \)$  



## 🎯 **My Approach:**

### **Optimized Intersection with Hashing**  

1. **Use of Hash Set:**  
   - We utilize a hash set to store the elements of the first array `a[]`. This allows for efficient lookups to check if an element from the second array `b[]` is present in `a[]`.  

2. **Steps to Solve the Problem:**  
   - Insert all elements of `a[]` into a hash set `setA`.
   - Iterate through `b[]`. For each element in `b[]`, check if it exists in `setA`:
     - If yes, add the element to the result and remove it from `setA` to ensure duplicates are avoided.
   - Return the resulting list of common elements.  

3. **Why Efficient?**  
   - Hash sets allow O(1) average time complexity for both insertion and lookup.  
   - This approach minimizes unnecessary comparisons, making it suitable for large arrays.


## 🕒 **Time and Auxiliary Space Complexity** 

**Expected Time Complexity:**  
- $\( O(n + m) \)$, where $\( n \)$ is the size of array `a` and $\( m \)$ is the size of array `b`.  
- Constructing the hash set takes $\( O(n) \)$, and traversing array `b` takes $\( O(m) \)$.

**Expected Auxiliary Space Complexity:**  
- $\( O(\min(n, m)) \)$, as the hash set stores at most the unique elements from the smaller array.



## 📝 **Solution Code**

## Code (C++)

```cpp
class Solution {
public:
    vector<int> intersectionWithDuplicates(vector<int>& a, vector<int>& b) {
        unordered_set<int> sa(a.begin(), a.end());
        unordered_set<int> res_set;
        for (int num : b) {
            if (sa.erase(num)) {  
                res_set.insert(num);
            }
        }
        return vector<int>(res_set.begin(), res_set.end());
    }
};
```



## Code (Java)

```java
class Solution {
    public ArrayList<Integer> intersectionWithDuplicates(int[] a, int[] b) {
        HashSet<Integer> setA = new HashSet<>();
        ArrayList<Integer> result = new ArrayList<>();
        
        for (int num : a) setA.add(num);
        
        for (int num : b) {
            if (setA.remove(num)) result.add(num); 
        }
        
        return result;
    }
}
```



## Code (Python)

```python
class Solution:
    def intersectionWithDuplicates(self, a, b):
        set_a = set(a)
        result = []
        
        for num in b:
            if num in set_a:
                result.append(num)
                set_a.remove(num) 
        
        return result
```



## 🎯 **Contribution and Support:**

For discussions, questions, or doubts related to this solution, feel free to connect on LinkedIn: [Any Questions](https://www.linkedin.com/in/het-patel-8b110525a/). Let’s make this learning journey more collaborative!

⭐ If you find this helpful, please give this repository a star! ⭐

---

<div align="center">
  <h3><b>📍Visitor Count</b></h3>
</div>

<p align="center">
  <img src="https://profile-counter.glitch.me/Hunterdii/count.svg" />
</p> 
