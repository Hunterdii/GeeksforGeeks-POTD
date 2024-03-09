## 09. Find the N-th character
The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/find-the-n-th-character5925/1)

### My Approach
- Initialize a variable len to store the length of the input string s.
- Use a loop to iterate r times for the specified number of iterations.
- In each iteration : 
  - Create a temporary string temp and copy the content of the original string s.
  - Use another loop to traverse each character in the original string s.
  - Update each character based on the following logic :
    - If the corresponding character in temp at position j/2 is '0', set s[j] to '0' + (j % 2).
    - Otherwise, set s[j] to '1' - (j % 2).
- After completing all iterations, the desired character is at index n in the final string s.

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

For discussions, questions, or doubts related to this solution, please visit our [discussion section](https://github.com/getlost01/gfg-potd/discussions). We welcome your input and aim to foster a collaborative learning environment.

⭐ Star this repository if you find it helpful or intriguing! ⭐
