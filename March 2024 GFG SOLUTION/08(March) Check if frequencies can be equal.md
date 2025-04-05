## 08. Check if frequencies can be equal

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/check-frequencies4211/1)

### My Approach:

1. **Character Frequency Counting:** First, I go through the provided string and tally up how often each character appears, using a map-like structure.

2. **Finding Extremes:** I then identify the least and most frequent characters among all.

3. **Checking Feasibility:** If the gap between the most and least frequent characters is greater than one, it means there's no way to equalize frequencies, so I return false (0).

4. **Counting Characters:** Next, I calculate how many characters have the least frequency.

5. **Feasibility Check:** Finally, I assess whether it's possible to make all characters appear with the same frequency. If the difference between the total unique characters and those with the least frequency is at most one, it means we can adjust frequencies to make them equal. Hence, I return true (1).

### Time and Auxiliary Space Complexity

- **Time Complexity** : O`(N)`, where N is the length of the input string.
- **Auxiliary Space Complexity** : At most, 26 unique characters can be used, resulting in a time complexity of `O(26)`

### Code (C++)

```cpp
class Solution{
public:
  int getIdx(char ch)
  {
      return (ch - 'a');
  }
  bool allSame(int freq[], int N)
  {
      int same;

      int i;
      for (i = 0; i < N; i++)
      {
          if (freq[i] > 0)
          {
              same = freq[i];
              break;
          }
      }

      for (int j = i+1; j < N; j++)
          if (freq[j] > 0 && freq[j] != same)
              return false;

      return true;
  }

  bool sameFreq(string str)
  {
      int M = 26;
      int l = str.length();

      int freq[M] = {0};
      for (int i = 0; i < l; i++)
          freq[getIdx(str[i])]++;

      if (allSame(freq, M))
          return true;

      for (char c = 'a'; c <= 'z'; c++)
      {
          int i = getIdx(c);

          if (freq[i] > 0)
          {
              freq[i]--;

              if (allSame(freq, M))
                  return true;
              freq[i]++;
          }
      }
      return false;
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
