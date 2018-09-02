class Solution {
public:
    int mySqrt(int x) {
        int l = 0, r = INT_MAX;
        while(l < r - 1) {
            int m = (l + r) / 2;
            if(m <= x / m) l = m;
            else if(m > l / m) r = m;
        }
        return l;
    }
};