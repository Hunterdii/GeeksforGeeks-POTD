class Solution {
  public:
    int kokoEat(vector<int>& arr, int k) {
        sort(arr.begin(), arr.end());
        int lo = 1, hi = arr.back();

        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            long hours = 0;
            bool valid = true;

            for (int pile : arr) {
                hours += (pile + mid - 1) / mid;
                if (hours > k) {
                    valid = false;
                    break; 
                }
            }

            if (valid)
                hi = mid;
            else
                lo = mid + 1;
        }
        return lo;
    }
};

2)
class Solution {
  public:
    bool canEat(vector<int>& arr, int speed, int k) {
        long hours = 0;
        for (int pile : arr) {
            hours += (pile + speed - 1) / speed;
            if (hours > k) return false;
        }
        return true;
    }

    int kokoEat(vector<int>& arr, int k) {
        int lo = 1, hi = *max_element(arr.begin(), arr.end());
        
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (canEat(arr, mid, k)) {
                hi = mid;
            } else {
                lo = mid + 1;
            }
        }
        return lo;
    }
};

3)
class Solution {
  public:
    int kokoEat(vector<int>& arr, int k) {
        int lo = 1, hi = *max_element(arr.begin(), arr.end());
        
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            int hours = 0;
            for (int pile : arr) {
                hours += (pile + mid - 1) / mid;
            }
            if (hours <= k)
                hi = mid;
            else
                lo = mid + 1;
        }
        return lo;
    }
};


4)
class Solution {
  public:
    int kokoEat(vector<int>& arr, int k) {
        sort(arr.begin(), arr.end());
        int lo = 1, hi = arr.back();
        
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            long hours = 0;
            bool canFinish = true;
            
            for (int pile : arr) {
                hours += (pile + mid - 1) / mid;
                if (hours > k) {
                    canFinish = false;
                    break;
                }
            }
            
            if (canFinish) hi = mid;
            else lo = mid + 1;
        }
        return lo;
    }
};

5)
class Solution {
  public:
    long calculateHours(vector<int>& arr, int speed) {
        long hours = 0;
        for (int pile : arr) {
            hours += (pile + speed - 1) / speed;
        }
        return hours;
    }
    
    int kokoEat(vector<int>& arr, int k) {
        int lo = 1, hi = *max_element(arr.begin(), arr.end());
        
        while (hi - lo > 2) {
            int m1 = lo + (hi - lo) / 3;
            int m2 = hi - (hi - lo) / 3;
            
            long h1 = calculateHours(arr, m1);
            long h2 = calculateHours(arr, m2);
            
            if (h1 <= k && h2 <= k) {
                hi = m1;
            } else if (h1 > k && h2 <= k) {
                lo = m1 + 1;
                hi = m2;
            } else {
                lo = m2 + 1;
            }
        }
        
        for (int speed = lo; speed <= hi; speed++) {
            if (calculateHours(arr, speed) <= k) return speed;
        }
        return hi;
    }
};


6)
class Solution {
  public:
    double calculateHours(vector<int>& arr, int speed) {
        double hours = 0;
        for (int pile : arr) {
            hours += (pile + speed - 1) / speed;
        }
        return hours;
    }
    
    int kokoEat(vector<int>& arr, int k) {
        double phi = (1 + sqrt(5)) / 2;
        double resphi = 2 - phi;
        
        double a = 1, b = *max_element(arr.begin(), arr.end());
        double tol = 1;
        
        double c = a + resphi * (b - a);
        double d = a + (1 - resphi) * (b - a);
        
        while (abs(b - a) > tol) {
            double fc = calculateHours(arr, (int)c);
            double fd = calculateHours(arr, (int)d);
            
            if ((fc <= k && fd > k) || (fc <= k && fd <= k && fc >= fd)) {
                b = d;
                d = c;
                c = a + resphi * (b - a);
            } else {
                a = c;
                c = d;
                d = a + (1 - resphi) * (b - a);
            }
        }
        
        int result = (int)((a + b) / 2);
        while (calculateHours(arr, result) > k) result++;
        return result;
    }
};
