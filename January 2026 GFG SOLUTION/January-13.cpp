class Solution {
public:
    bool canServe(vector<int>& arr) {
        int f = 0, t = 0;
        for (int x : arr) {
            if (x == 5) f++;
            else if (x == 10) {
                if (!f) return false;
                f--; t++;
            } else {
                if (t && f) { t--; f--; }
                else if (f >= 3) f -= 3;
                else return false;
            }
        }
        return true;
    }
};

2)
class Solution {
public:
    bool canServe(vector<int>& arr) {
        int c5 = 0, c10 = 0;
        for (int bill : arr) {
            if (bill == 5) c5++;
            else if (bill == 10 && c5) { c5--; c10++; }
            else if (bill == 20 && c10 && c5) { c10--; c5--; }
            else if (bill == 20 && c5 >= 3) c5 -= 3;
            else return false;
        }
        return true;
    }
};

3)
class Solution {
public:
    bool canServe(vector<int>& arr) {
        int notes[2] = {0};
        for (int payment : arr) {
            switch(payment) {
                case 5: notes[0]++; break;
                case 10: if (!notes[0]--) return false; notes[1]++; break;
                default: 
                    if (notes[1] && notes[0]) { notes[1]--; notes[0]--; }
                    else if (notes[0] >= 3) notes[0] -= 3;
                    else return false;
            }
        }
        return true;
    }
};

4)
class Solution {
public:
    bool canServe(vector<int>& arr) {
        int state = 0;
        for (int x : arr) {
            int f = state & 0xFFFF, t = state >> 16;
            if (x == 5) f++;
            else if (x == 10) { if (!f) return false; f--; t++; }
            else { 
                if (t && f) { t--; f--; } 
                else if (f >= 3) f -= 3; 
                else return false; 
            }
            state = (t << 16) | f;
        }
        return true;
    }
};
