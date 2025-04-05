---
Difficulty: Medium
Source: 160 Days of Problem Solving
Tags:
  - Recursion
  - Backtracking
---

# 🚀 _Day 2. Implement Pow_ 🧠

The problem can be found at the following link: [Problem Link](https://www.geeksforgeeks.org/batch/gfg-160-problems/track/recursion-and-backtracking-gfg-160/problem/powx-n)

## 💡 **Problem Description:**

You are given a floating point number `b` and an integer `e`, and your task is to calculate \( b^e \) (b raised to the power of e).

## 🔍 **Example Walkthrough:**

**Input:**  
`b = 3.00000`, `e = 5`  
**Output:**  
`243.00000`

**Input:**  
`b = 0.55000`, `e = 3`  
**Output:**  
`0.16638`

**Input:**  
`b = -0.67000`, `e = -7`  
**Output:**  
`-16.49971`

### Constraints:

- -100.0 < b < 100.0
- -109 <= e <= $10^9$
- Either b is not zero or e > 0.
- -104 <= be <= $10^4$

## 🎯 **My Approach:**

1. **Optimized Binary Exponentiation:**  
   The problem can be efficiently solved using the binary exponentiation approach (also known as exponentiation by squaring). This method reduces the number of multiplications required to compute \( b^e \) by breaking the problem down recursively.

2. **Steps:**

   - If `e == 0`, return 1, as any number raised to the power of 0 is 1.
   - If `e` is negative, calculate the result using $\( \frac{1}{b^e} \)$.
   - For positive `e`, repeatedly divide `e` by 2, multiplying `b` by itself for each halving of `e`.
   - The result is obtained by squaring the value of `b` for each step and multiplying it with the current result when necessary.

3. **Optimization:**  
   Using a while loop or recursion, the approach reduces the time complexity from O(e) (in the naive approach) to O(log e) , which is significantly faster for large values of `e`.

## 🕒 **Time and Auxiliary Space Complexity**

- **Expected Time Complexity:** $O(log |e|)$, where $(e)$ is the exponent. The exponent is reduced by half in each iteration.
- **Expected Auxiliary Space Complexity:** $O(1)$, as we only use a constant amount of additional space.

## 📝 **Solution Code**

## Code (C++)

```cpp
class Solution {
public:
    double power(double b, int e) {
        if (e == 0) return 1.0;
        double half = power(b, e / 2);
        return e % 2 == 0 ? half * half : (e > 0 ? b * half * half : (1.0 / b) * half * half);
    }
};
```

<details>
  <summary><h2 align='center'>👨‍💻 Alternative Approaches</h2></summary>

## **1. Iterative Method (Binary Exponentiation)**

```cpp
class Solution {
public:
    double power(double b, int e) {
        double result = 1.0;
        long long exp = abs((long long)e);
        while (exp > 0) {
            if (exp % 2 == 1) result *= b;
            b *= b;
            exp /= 2;
        }
        return e < 0 ? 1.0 / result : result;
    }
};
```

- **Optimization:** No recursion, reduced overhead.
- **Time Complexity:** $\( O(\log e) \)$
- **Space Complexity:** $\( O(1) \)$

## **2. Tail-Recursive Method**

```cpp
class Solution {
public:
    double power(double b, int e, double result = 1.0) {
        if (e == 0) return result;
        if (e < 0) return power(1.0 / b, -e, result);
        return e % 2 == 0 ? power(b * b, e / 2, result) : power(b * b, e / 2, result * b);
    }
};
```

- **Optimization:** Tail recursion ensures no stack buildup in compilers with tail-call optimization.
- **Time Complexity:** $\( O(\log e) \)$
- **Space Complexity:** $\( O(\log e) \)$ (if no tail-call optimization)

## **3. Using Built-in Function**

```cpp
// #include <cmath>
class Solution {
public:
    double power(double b, int e) {
        return std::pow(b, e);
    }
};
```

- **Optimization:** Leverages highly optimized library implementation.
- **Time Complexity:** $\( O(1) \)$ (Library-optimized)
- **Space Complexity:** $\( O(1) \)$

## **4. Modified Iterative Approach (Handling Edge Cases)**

```cpp
class Solution {
public:
    double power(double b, int e) {
        long long exp = e;
        double result = 1.0;
        if (exp < 0) { b = 1.0 / b; exp = -exp; }
        while (exp) {
            if (exp & 1) result *= b;
            b *= b;
            exp >>= 1;
        }
        return result;
    }
};
```

- **Optimization:** Uses bitwise operations and handles edge cases like negative exponents directly.
- **Time Complexity:** $\( O(\log e) \)$
- **Space Complexity:** $\( O(1) \)$

### Summary of Approaches:

| Approaches              | Time Complexity | Space Complexity | Notes                     |
| ----------------------- | --------------- | ---------------- | ------------------------- |
| Recursive               | $O(\log e)$     | $O(\log e)$      | Simple, uses recursion.   |
| Iterative (Binary Exp.) | $O(\log e) $    | $O(1)$           | Most efficient approach.  |
| Tail-Recursive          | $O(\log e) $    | $O(\log e)$      | Requires tail-call opt.   |
| Built-in `std::pow`     | $O(1) $         | $O(1)$           | Leveraging library power. |
| Modified Iterative      | $O(\log e) $    | $O(1)$           | Handles edge cases well.  |

The **iterative binary exponentiation** is typically the best choice for performance-critical scenarios.

</details>

## Code (Java)

```java
class Solution {
    public double power(double b, int e) {
        if (e == 0) return 1.0;
        double half = power(b, e / 2);
        return e % 2 == 0 ? half * half : (e > 0 ? b * half * half : (1.0 / b) * half * half);
    }
}
```

## Code (Python)

```python
class Solution:
    def power(self, b: float, e: int) -> float:
        result = 1.0
        exp = abs(e)
        while exp > 0:
            if exp % 2 == 1:
                result *= b
            b *= b
            exp //= 2
        return result if e >= 0 else 1.0 / result
```

## 🎯 **Contribution and Support:**

For discussions, questions, or doubts related to this solution, feel free to connect on LinkedIn: [Any Questions](https://www.linkedin.com/in/patel-hetkumar-sandipbhai-8b110525a/). Let’s make this learning journey more collaborative!

⭐ If you find this helpful, please give this repository a star! ⭐

---

<div align="center">
  <h3><b>📍Visitor Count</b></h3>
</div>

<p align="center">
  <img src="https://profile-counter.glitch.me/Hunterdii/count.svg" />
</p>
