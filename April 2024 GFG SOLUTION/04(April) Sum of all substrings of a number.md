## 04. Sum of All Substrings of a Number

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/sum-of-all-substrings-of-a-number-1587115621/1)

### Problem Description

Given an integer \( s \) represented as a string, the task is to get the sum of all possible sub-strings of this string.
As the answer will be large, return answer modulo \( 10^9 + 7 \).

**Example:**

Input:

```
s = "1234"
```

Output:

```
1670
```

Explanation:
Sum = 1 + 2 + 3 + 4 + 12 + 23 + 34 + 123 + 234 + 1234 = 1670

**Your Task:**

You only need to complete the function `sumSubstrings` that takes `s` as an argument and returns the answer modulo \( 10^9 + 7 \).

**Constraints:**

- \( 1 \leq |s| \leq 10^5 \)

### My Approach 1

1. **Initialization:**
   - Initialize variables `mod` to \( 10^9 + 7 \), `r` to 1, and `res` to 0.
2. **Iterative Calculation:**
   - Iterate from \( i = \text{size of } s - 1 \) to 0.
   - Within each iteration:
     - Update `res` as \( (res + ((s[i] - '0') \times (i + 1) \times r) \% \text{mod}) \% \text{mod} \).
     - Update `r` as \( (r \times 10 + 1) \% \text{mod} \).
3. **Return:**
   - Return `res`.

### Time and Auxiliary Space Complexity

- **Expected Time Complexity:** \( O(|s|) \), as we iterate through the string `s` once.
- **Expected Auxiliary Space Complexity:** \( O(1) \), as we only use a constant amount of additional space.

### Code 1 (C++)

```cpp
class Solution {
public:
    long long sumSubstrings(string s) {
        long long mod = 1e9 + 7;
        long long r = 1, res = 0;
        for (int i = s.size() - 1; i >= 0; i--) {
            res = (res + ((s[i] - '0') * (i + 1) * r) % mod) % mod;
            r = (r * 10 + 1) % mod;
        }
        return res;
    }
};
```

### My Approach 2

1. **Initialization:**
   - Initialize variables `mod` to \( 10^9 + 7 \), `r` to 1, and `res` to 0.
2. **Iterative Calculation:**
   - Iterate from \( i = \text{size of } s - 1 \) to 0.
   - Within each iteration:
     - Update `res` as \( (res + ((s[i] - '0') \times (i + 1) \times r) \% \text{mod}) \% \text{mod} \).
     - Update `r` as \( (r \times 10 + 1) \% \text{mod} \).
3. **Return:**
   - Return `res`.

### Time and Auxiliary Space Complexity

- **Expected Time Complexity:** \( O(|s|) \), as we iterate through the string `s` once.
- **Expected Auxiliary Space Complexity:** \( O(1) \), as we only use a constant amount of additional space.

### Code 2 (C++)

```cpp
class Solution {
public:
    long long sumSubstrings(string s) {
        int mod = pow(10, 9) + 7; // Calculate modulo value dynamically
        long long int r = 1, res = 0;
        for (int i = s.size() - 1; i >= 0; i--) {
            res = (res + ((s[i] - '0') * (i + 1) * r) % mod) % mod;
            r = (r * 10 + 1) % mod;
        }
        return res;
    }
};
```

### My Approach 3

1. **Initialization:**
   - Initialize variables `mod` to \( 10^9 + 7 \), `result` to 0, `multiplier` to 1, and `positionSum` to 0.
2. **Iterative Calculation:**
   - Iterate from \( i = \text{size of } s - 1 \) to 0.
   - Within each iteration:
     - Update `positionSum` as \( (positionSum + (s[i] - '0') \times \text{multiplier}) \% \text{mod} \).
     - Update `result` as \( (result + \text{positionSum}) \% \text{mod} \).
     - Update `multiplier` as \( (multiplier \times 10 + 1) \% \text{mod} \).
3. **Return:**
   - Return `result`.

### Time and Auxiliary Space Complexity

- **Expected Time Complexity:** \( O(|s|) \), as we iterate through the string `s` once.
- **Expected Auxiliary Space Complexity:** \( O(1) \), as we only use a constant amount of additional space.

### Code 3 (C++)

```cpp
class Solution {
public:
    long long sumSubstrings(string s) {
        long long mod = 1e9 + 7;
        long long result = 0;
        long long multiplier = 1;
        long long positionSum = 0;

        for (int i = s.size() - 1; i >= 0; i--) {
            positionSum = (positionSum + (s[i] - '0') * multiplier) % mod;
            result = (result + positionSum) % mod;
            multiplier = (multiplier * 10 + 1) % mod;
        }

        return result;
    }
};
```

### My Approach 4

1. **Initialization:**
   - Initialize variables `mod` to \( 10^9 + 7 \), `r` to 1, and `res` to 0.
2. **Iterative Calculation:**
   - Iterate from \( i = \text{size of } s - 1 \) to 0.
   - Within each iteration:
     - Update `res` as \( (res + ((s[i] - '0') \times (i + 1) \times r) \% \text{mod}) \% \text{mod} \).
     - Update `r` as \( (r \times 10 + 1) \% \text{mod} \).
3. **Return:**
   - Return `res`.

### Time and Auxiliary Space Complexity

- **Expected Time Complexity:** \( O(|

s|) \), as we iterate through the string `s` once.

- **Expected Auxiliary Space Complexity:** \( O(1) \), as we only use a constant amount of additional space.

### Code 4 (C++)

```cpp
class Solution
{
    public:
    //Function to find sum of all possible substrings of the given string.
    long long sumSubstrings(string s){

       long long int mod=1e9+7;
        long long int r=1,res=0;
            for(int i=s.size()-1;i>=0;i--){
            // long long int
            res=(res+((s[i]-'0')*(i+1)*r)%mod)%mod;
            res%=mod;
            r=(r*10+1)%mod;
            r%=mod;

        }
        return(res);
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
