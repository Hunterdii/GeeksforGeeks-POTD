# *18. Implement Trie*  

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/trie-insert-and-search0651/1)  

## **Problem Description**  

Implement the Trie data structure. You are given queries of the following three types:
- **Type 1**: Insert a word into the Trie.
- **Type 2**: Search whether a word exists in the Trie.
- **Type 3**: Check whether a word is a prefix of any word stored in the Trie.

> 📅 Note: Sorry for uploading late, my Final Sem exam is going on.


## **Examples**

### **Example 1:**  
#### **Input:**  
`[[1, "abcd"], [1, "abc"], [1, "bcd"], [2, "bc"], [3, "bc"], [2, "abc"]]`  
#### **Output:**  
`[false, true, true]`  
#### **Explanation:**  
- "bc" does not exist as a word  
- "bc" exists as prefix of "bcd"  
- "abc" exists  


### **Example 2:**  
#### **Input:**  
`[[1, "gfg"], [1, "geeks"], [3, "fg"], [3, "geek"], [2, "for"]]`  
#### **Output:**  
`[false, true, false]`  
#### **Explanation:**  
- "fg" is not a prefix  
- "geek" is a prefix of "geeks"  
- "for" not in Trie  


### **Constraints:**  
- $1 \leq \text{query.size()} \leq 10^4$  
- $1 \leq \text{word.size()} \leq 10^3$  


## **My Approach**

### **Fixed-Size Trie Using 26 Pointers**  

### **Algorithm Steps:**

We create a class Trie, with a nested structure (Node) that stores a boolean flag for end of word and a fixed array of 26 pointers (one for each lowercase letter).  
- **Insert:** Walk through characters, initialize child if needed.  
- **Search:** Check for existence and end-of-word.  
- **Prefix:** Just ensure prefix exists in Trie.


## **Time and Auxiliary Space Complexity**

- **Expected Time Complexity:** O(L), where L = length of the word  
- **Expected Auxiliary Space Complexity:** O(1), as each function uses constant extra space aside from Trie structure itself  


## **Code (C++)**

```cpp
// ✅ Fixed‐Array Trie (26 pointers per node)
class Trie {
    struct N { N* c[26] = {}; bool e = 0; }*r = new N;
public:
    void insert(string &w) {
        auto n = r;
        for (char ch : w) n = n->c[ch - 'a'] ?: (n->c[ch - 'a'] = new N);
        n->e = 1;
    }
    bool search(string &w) {
        auto n = r;
        for (char ch : w) if (!(n = n->c[ch - 'a'])) return 0;
        return n->e;
    }
    bool isPrefix(string &w) {
        auto n = r;
        for (char ch : w) if (!(n = n->c[ch - 'a'])) return 0;
        return 1;
    }
};
```

<details>
<summary><h2 align="center">⚡ Alternative Approaches</h2></summary>


## 📊 **2️⃣ Map‐Based Trie (unordered_map children)**

#### **Algorithm Steps:**
1. Each node stores an `unordered_map<char, N*>` instead of a fixed array.
2. Insert/search/prefix each walk the map—only existing edges consume memory.

```cpp
struct Node {
    std::unordered_map<char, Node*> m;
    bool e = false;
};

class Trie {
    Node* root = new Node;
public:
    void insert(const string &w) {
        Node* p = root;
        for (char c : w)
            p = p->m.count(c) ? p->m[c] : (p->m[c] = new Node);
        p->e = true;
    }
    bool search(const string &w) {
        Node* p = root;
        for (char c : w)
            if (!p->m.count(c)) return false;
            else p = p->m[c];
        return p->e;
    }
    bool isPrefix(const string &w) {
        Node* p = root;
        for (char c : w)
            if (!p->m.count(c)) return false;
            else p = p->m[c];
        return true;
    }
};
```

#### 📝 **Complexity Analysis:**
- **Time Complexity:** O(L) average per operation (L = word length)  
- **Space Complexity:** O(total characters stored), only allocates for existing edges



### 🆚 **Comparison of Approaches**

| **Approach**              | ⏱️ **Time Complexity** | 🗂️ **Space Complexity** | ✅ **Pros**                    | ⚠️ **Cons**           |
|-----------------------------|-----------------|-------------------------|------------------------------------------|-----------------------------------------------|
| Fixed‐Array (26 pointers)   | 🟢 O(L)            | 🟢 O(26 × nodes)           | Fast, constant‑time child access         | Wastes memory for sparse alphabets            |
| Map‐Based (unordered_map)   | 🟢 O(L) avg        | 🟡 O(children × nodes)     | Space‑efficient when sparse              | Hash overhead, slower than array lookup       |

</details>


## **Code (Java)**

```java
class Trie {
    class N { N[] c = new N[26]; boolean e; }
    N r = new N();
    public void insert(String w) {
        N n = r;
        for (char ch : w.toCharArray())
            n = n.c[ch - 'a'] != null ? n.c[ch - 'a'] : (n.c[ch - 'a'] = new N());
        n.e = true;
    }
    public boolean search(String w) {
        N n = r;
        for (char ch : w.toCharArray())
            if ((n = n.c[ch - 'a']) == null) return false;
        return n.e;
    }
    public boolean isPrefix(String w) {
        N n = r;
        for (char ch : w.toCharArray())
            if ((n = n.c[ch - 'a']) == null) return false;
        return true;
    }
}
```


## **Code (Python)**

```python
class Trie:
    class N:
        def __init__(self): self.c, self.e = [None]*26, 0
    def __init__(self): self.r = self.N()
    def insert(self, w):
        n = self.r
        for ch in w:
            i = ord(ch)-97
            n.c[i] = n.c[i] or self.N()
            n = n.c[i]
        n.e = 1
    def search(self, w):
        n = self.r
        for ch in w:
            i = ord(ch)-97
            if not n.c[i]: return 0
            n = n.c[i]
        return n.e
    def isPrefix(self, w):
        n = self.r
        for ch in w:
            i = ord(ch)-97
            if not n.c[i]: return 0
            n = n.c[i]
        return 1
```

## **Contribution and Support:**

For discussions, questions, or doubts related to this solution, feel free to connect on LinkedIn: [Any Questions](https://www.linkedin.com/in/patel-hetkumar-sandipbhai-8b110525a/). Let’s make this learning journey more collaborative!

⭐ **If you find this helpful, please give this repository a star!** ⭐

---

<div align="center">
  <h3><b>📍Visitor Count</b></h3>
</div>

<p align="center">
  <img src="https://profile-counter.glitch.me/Hunterdii/count.svg" />
</p>
