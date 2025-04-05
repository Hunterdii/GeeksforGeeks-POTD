## 09. Find the N-th character

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/find-the-n-th-character5925/1)

### My Approach

1. **Initialization:**

   - Start by determining the length of the input string `s` and store it in a variable called `len`. This gives us the number of characters we need to manipulate.

2. **Iteration Process:**
   - Iterate `r` times, as specified, to apply the transformation on the string.
   - For each iteration:
3. **Temporary Storage:**

   - Create a temporary string `temp` and copy the content of the original string `s` into it. This preserves the original string for further iterations.

4. **Character Transformation:**

   - Traverse through each character of the original string `s`.
   - For each character at position `j`, apply the following transformation:
     - If the corresponding character in `temp` at position `j/2` is `'0'`, set `s[j]` to `'0' + (j % 2)`.
     - Otherwise, set `s[j]` to `'1' - (j % 2)`.

5. **Finalization:**
   - After completing all iterations, the desired character will be at index `n` in the final transformed string `s`.

This approach essentially iterates over the string `s` multiple times, adjusting characters based on their position and values in a calculated manner. By following this process, we ensure that the desired character is appropriately modified according to the specified logic after the defined number of iterations.

### Time and Auxiliary Space Complexity

- **Time Complexity** : `O(r*|s|)`, as there are two nested loops.
- **Auxiliary Space Complexity** : `O(|s|)`, as the temporary string temp is of the same length as the input string.

### Code (C++)

```cpp
class Solution{
  public:
    char nthCharacter(string s, int r, int n)
    {
        int len=s.length();
        for (int i=0;i<r;i++)
        {
            string temp=s;
            for (int j=0;j<len;j++)
            {
                if (temp[j/2]=='0')
                    s[j]='0'+(j%2);
                else s[j]='1'-(j%2);
            }
        }
        return s[n];
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
