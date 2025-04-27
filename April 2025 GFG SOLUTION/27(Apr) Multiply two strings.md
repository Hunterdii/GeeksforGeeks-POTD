# *27. Multiply Two Strings*

The problem can be found at the following link: 🔗 [Question Link](https://www.geeksforgeeks.org/problems/multiply-two-strings/1)

## **🧩 Problem Description**

Given two numbers as strings `s1` and `s2`, calculate their **product** without using built-in big integer libraries or converting the entire strings to integers directly.  
Handle cases like negative numbers and leading zeros properly.

You don't need to explicitly show the '+' sign for positive numbers.

## **📘 Examples**

### **Example 1:**

#### **Input:**
`s1 = "0033", s2 = "2"`

#### **Output:**
`66`

#### **Explanation:**
After removing leading zeros, we have 33 × 2 = 66.


### **Example 2:**

#### **Input:**
`s1 = "11", s2 = "23"`

#### **Output:**
`253`

#### **Explanation:**
11 × 23 = 253.


### **Example 3:**

#### **Input:**
`s1 = "123", s2 = "0"`

#### **Output:**
`0`

#### **Explanation:**
Any number multiplied by 0 results in 0.


## **🔒 Constraints**

- $\( 1 \leq \text{s1.size()} \leq 10^3 \)$  
- $\( 1 \leq \text{s2.size()} \leq 10^3 \)$  


## **✅ My Approach:**

### **Manual Digit-by-Digit Multiplication**

### **Algorithm Steps:**
Since direct integer conversion is not allowed, we simulate multiplication the way we do it by hand:

1. Determine the overall **sign** of the result based on the signs of `s1` and `s2`.
2. Remove any leading zeros.
3. Initialize an array to store the intermediate multiplication results.
4. Multiply every digit of `s1` with every digit of `s2` and store results appropriately.
5. Handle carryovers properly.
6. Construct the final answer string from the result array.
7. Add a negative sign if required.



## **🧮 Time and Auxiliary Space Complexity**

- **Expected Time Complexity:** O(n × m), where `n` and `m` are the lengths of `s1` and `s2`, since we multiply every digit of one number with every digit of the other.
- **Expected Auxiliary Space Complexity:** O(n + m), for storing the result of the multiplication as an array of digits.


## **🧠 Code (C++)**

```cpp
class Solution {
  public:
    string multiplyStrings(string num1, string num2) {
        int sign=1;
        if(num1[0]=='-') sign*=-1,num1=num1.substr(1);
        if(num2[0]=='-') sign*=-1,num2=num2.substr(1);
        int n=num1.size(),m=num2.size();
        if(n==0||m==0) return "0";
        vector<int> res(n+m,0);
        for(int i=n-1;i>=0;i--)
            for(int j=m-1;j>=0;j--)
                res[i+j+1]+=(num1[i]-'0')*(num2[j]-'0');
        for(int i=n+m-1;i>0;i--){
            res[i-1]+=res[i]/10;
            res[i]%=10;
        }
        string ans;
        int i=0;
        while(i<res.size()&&res[i]==0) i++;
        for(;i<res.size();i++) ans+=res[i]+'0';
        if(ans.empty()) return "0";
        return sign==-1?"-"+ans:ans;
    }
};
```

## **🧑‍💻 Code (Java)**

```java
class Solution {
    public String multiplyStrings(String s1, String s2) {
        int sign=(s1.charAt(0)=='-'^s2.charAt(0)=='-')?-1:1;
        if(s1.charAt(0)=='-') s1=s1.substring(1);
        if(s2.charAt(0)=='-') s2=s2.substring(1);
        s1=s1.replaceFirst("^0+",""); if(s1.isEmpty()) return "0";
        s2=s2.replaceFirst("^0+",""); if(s2.isEmpty()) return "0";
        int n=s1.length(), m=s2.length(), L=n+m;
        int[] r=new int[L];
        for(int i=n-1;i>=0;i--) for(int j=m-1;j>=0;j--) r[i+j+1]+=(s1.charAt(i)-'0')*(s2.charAt(j)-'0');
        for(int i=L-1;i>0;i--){ r[i-1]+=r[i]/10; r[i]%=10; }
        int i=0; while(i<L&&r[i]==0) i++;
        StringBuilder a=new StringBuilder();
        for(;i<L;i++) a.append(r[i]);
        String ans=a.toString();
        return sign<0?"-"+ans:ans;
    }
}
```


## **🐍 Code (Python)**

```python
class Solution:
    def multiplyStrings(self, s1, s2):
        sign=-1 if (s1[0]=='-')^(s2[0]=='-') else 1
        if s1[0]=='-': s1=s1[1:]
        if s2[0]=='-': s2=s2[1:]
        s1=s1.lstrip('0'); s2=s2.lstrip('0')
        if not s1 or not s2: return "0"
        n,m=len(s1),len(s2); r=[0]*(n+m)
        for i in range(n-1,-1,-1):
            for j in range(m-1,-1,-1):
                r[i+j+1]+=int(s1[i])*int(s2[j])
        for i in range(n+m-1,0,-1):
            r[i-1]+=r[i]//10; r[i]%=10
        i=0
        while i<len(r) and r[i]==0: i+=1
        ans=''.join(str(x) for x in r[i:])
        return "-"+ans if sign<0 else ans
```

## 🧠 Contribution and Support

For discussions, questions, or doubts related to this solution, feel free to connect on LinkedIn: [📬 Any Questions?](https://www.linkedin.com/in/patel-hetkumar-sandipbhai-8b110525a/). Let’s make this learning journey more collaborative!

⭐ **If you find this helpful, please give this repository a star!** ⭐

--- 

<div align="center">
  <h3><b>📍Visitor Count</b></h3>
</div>

<p align="center">
  <img src="https://profile-counter.glitch.me/Hunterdii/count.svg" />
</p>
