## 06. Search Pattern (Rabin-Karp Algorithm)

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/search-pattern-rabin-karp-algorithm--141631/1)

### My Approach

Rabin-Karp Algorithm: [Rabin-Karp](https://www.programiz.com/dsa/rabin-karp-algorithm).

### Time and Auxiliary Space Complexity

- **Time Complexity**: Due to the use of hashing, the average time complexity is `O(n + m)`.
- **Auxiliary Space Complexity**: The auxiliary space complexity is `O(1)` since we only use a constant amount of extra space for storing variables and data structures.

### Code (C++)

```cpp
class Solution
{
    public:
        vector <int> search(string pattern, string text)
        {
            //code here.
            int n = text.size();
            int m = pattern.size();
            vector<int> ans;

            for(int i = 0; i<n-m+1; i++){
                //check if first and last character match then only check whole string to reduce time complexity
                if(pattern[0]==text[i] && pattern[m-1]==text[i+m-1]){

                    if(pattern==text.substr(i,m)){
                        ans.push_back(i+1);
                    }
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
