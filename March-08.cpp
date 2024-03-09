//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
  // Utility method to get index of character ch
  // in lower alphabet characters
  int getIdx(char ch)
  {
      return (ch - 'a');
  }
  // Returns true if all non-zero elements
  // values are same
  bool allSame(int freq[], int N)
  {
      int same;
   
      //  get first non-zero element
      int i;
      for (i = 0; i < N; i++)
      {
          if (freq[i] > 0)
          {
              same = freq[i];
              break;
          }
      }
   
      //  check equality of each element with variable same
      for (int j = i+1; j < N; j++)
          if (freq[j] > 0 && freq[j] != same)
              return false;
   
      return true;
  }
   
  // Returns true if we can make all character
  // frequencies same
  bool sameFreq(string str)
  {
      int M = 26; // size of hash map for all 26 letters
      int l = str.length();
   
      //  fill frequency array
      int freq[M] = {0};
      for (int i = 0; i < l; i++)
          freq[getIdx(str[i])]++;
   
      //  if all frequencies are same, then return true
      if (allSame(freq, M))
          return true;
   
      /*  Try decreasing frequency of all character
          by one and then check all equality of all
          non-zero frequencies */
      for (char c = 'a'; c <= 'z'; c++)
      {
          int i = getIdx(c);
   
          // Check character only if it occurs in str
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

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        Solution ob;
        cout<<ob.sameFreq(s)<<endl;
    }
}



// } Driver Code Ends
