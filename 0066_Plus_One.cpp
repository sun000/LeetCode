class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        digits[digits.size() - 1] += 1;
        int c = 0;
        for(int i = digits.size() - 1; i >= 0 && (c || i == digits.size() - 1); i--) {
            digits[i] += c;
            c = digits[i] / 10;
            digits[i] %= 10;
        }
        if(c) {
            auto it = digits.begin();
            digits.insert(it, c);
        }
        return digits;
    }
};