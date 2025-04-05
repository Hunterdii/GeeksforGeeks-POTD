## 09. Divisor Game

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/divisor-game-1664432414/1)

### Problem Description

Alice and Bob take turns playing a game, with Alice starting first. Initially, there is a number \( n \) on the chalkboard. On each player's turn, that player makes a move consisting of:

- Choosing any \( x \) with \( 0 < x < n \) and \( n \% x == 0 \).
- Replacing the number \( n \) on the chalkboard with \( n - x \).
- If a player cannot make a move, they lose the game.

Return `true` if and only if Alice wins the game, assuming both players play optimally.

**Example:**

Input:

```
n = 2
```

Output:

```
True
```

Explanation:
Alice chooses 1, and Bob has no more moves.

Input:

```
n = 3
```

Output:

```
False
```

Explanation:
Alice chooses 1, Bob chooses 1, and Alice has no more moves.

### Approach

To solve this problem, we can observe that:

- If \( n \) is even, Alice can always choose \( x = 1 \) in her turn, which will make Bob left with \( n - 1 \), an odd number.
- If \( n \) is odd, there's no such \( x \) satisfying \( 0 < x < n \) and \( n \% x == 0 \), hence Alice will lose.

So, the strategy for Alice is to always play optimally and select \( x = 1 \) whenever she has the chance.

### Time and Auxiliary Space Complexity

- **Expected Time Complexity:** O(1), as we perform a constant number of operations regardless of the size of \( n \).
- **Expected Auxiliary Space Complexity:** O(1), as we only use a constant amount of additional space.

### Code (C++)

```cpp
class Solution {
public:
    bool divisorGame(int n) {
       return n % 2 == 0;
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
