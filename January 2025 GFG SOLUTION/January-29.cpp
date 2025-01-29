//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
public:
    double power(double b, int e) {
        if (e == 0) return 1.0;
        double half = power(b, e / 2);
        return e % 2 == 0 ? half * half : (e > 0 ? b * half * half : (1.0 / b) * half * half);
    }
};

2)
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

3)
class Solution {
public:
    double power(double b, int e, double result = 1.0) {
        if (e == 0) return result;
        if (e < 0) return power(1.0 / b, -e, result);
        return e % 2 == 0 ? power(b * b, e / 2, result) : power(b * b, e / 2, result * b);
    }
};

4)
// #include <cmath> 
class Solution {
public:
    double power(double b, int e) {
        return std::pow(b, e);
    }
};

5)
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

//{ Driver Code Starts.

int main() {
    cout << fixed << setprecision(5);
    int t;
    cin >> t;
    while (t--) {
        double b;
        cin >> b;
        int e;
        cin >> e;
        Solution ob;
        cout << ob.power(b, e) << endl;
        cout << "~" << endl;
    }

    return 0;
}
// } Driver Code Ends
