class Solution {
  public:

    int maxOccured(int n, int l[], int r[], int maxx) {
    vector<int> freq(maxx + 2, 0);

    for (int i = 0; i < n; ++i) {
        freq[l[i]] += 1;
        if (r[i] + 1 <= maxx) {
            freq[r[i] + 1] -= 1;
        }
    }

    int maxFreq = 0;
    int result = 0;
    int currentFreq = 0;

    for (int i = 0; i <= maxx; ++i) {
        currentFreq += freq[i];
        if (currentFreq > maxFreq) {
            maxFreq = currentFreq;
            result = i;
        }
    }

    return result;
    }
};
