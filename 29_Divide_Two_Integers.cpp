Divide Two Integersclass Solution {
    const int MIN_INT = -2147483648;
    const int MAX_INT = 2147483647;
    
public:
    int divide(int dividend, int divisor) {
        if(dividend == 0) return 0;
        if((dividend == MIN_INT && divisor == -1) || divisor == 0) return MAX_INT;
        return dividend / divisor;
    }
};