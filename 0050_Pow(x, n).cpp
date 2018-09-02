class Solution {
public:
    double myPow(double x, int n) {
        if(n < 0) x = 1.0 / x;
        double ans = 1.0, tmp = x;
        while(n != 0) {
            if(n % 2 != 0) ans *= tmp;
            tmp *= tmp;
            n /= 2;
        }
        return ans;
    }
};