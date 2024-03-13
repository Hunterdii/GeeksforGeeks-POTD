## 02. First element to occur k times
The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/print-matrix-in-diagonal-pattern/1)

### My Approach

1. *Initialization:*
   - Initialize an empty vector res to store pairs of coordinates and values.
   - Initialize variables n to store the size of the matrix.

2. *Iterating through the Matrix:*
   - Iterate through the matrix using nested loops.
   - For each element, determine its diagonal order:
     - If the sum of row index and column index is even, the order is row-first.
     - If the sum is odd, the order is column-first.
   - Store the pair of coordinates and value in res.

3. *Sorting:*
   - Sort the vector res based on the sum of row and column indices.
   - If the sums are equal, prioritize the pair with a smaller column index.

4. *Extracting Diagonal Order:*
   - Iterate through the sorted vector and extract the values, storing them in a separate vector diagonalOrder.

5. *Return Diagonal Order:*
   - Return the diagonalOrder vector representing the matrix elements in diagonal order.

### Time and Auxiliary Space Complexity

- *Time Complexity*: O(n^2), where n is the size of the matrix.
- *Auxiliary Space Complexity*: O(n^2), since the vector res stores pairs for all elements of the matrix.

### Code (C++)
```cpp
class Solution{
public:
    static bool compare(pair<pair<int, int>, int>& a, pair<pair<int, int>, int>& b) {
        if (a.first.first == b.first.first) {
            return a.first.second < b.first.second;
        }
        return a.first.first < b.first.first;
    }
    
    vector<int> matrixDiagonally(vector<vector<int>>& mat) {
        vector<pair<pair<int, int>, int>> res;
        int n = mat.size();
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if ((i + j) % 2 == 0) {
                    res.push_back({{i + j, j}, mat[i][j]});
                } else {
                    res.push_back({{i + j, i}, mat[i][j]});
                }
            }
        }
        
        sort(res.begin(), res.end(), compare);
        
        vector<int> diagonalOrder;
        for (auto& elem : res) {
            diagonalOrder.push_back(elem.second);
        }
        
        return diagonalOrder;
    }
};
```

### Contribution and Support

For discussions, questions, or doubts related to this solution, please visit my LinkedIn:- [Any Questions](https://www.linkedin.com/in/het-patel-8b110525a/). 
Thank you for your input; together, we strive to create a space where learning is a collaborative endeavor.

⭐ Star this repository if you find it helpful or intriguing! ⭐
