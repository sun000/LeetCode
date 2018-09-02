static int x = []() { 
    std::ios::sync_with_stdio(false); 
    cin.tie(NULL);  
    return 0; 
}();

class Solution {
public:
    bool isPalindrome(int x) {
        if(x >= 0 && x / 10 == 0) return true;
        if(x < 0 || x % 10 == 0) return false;
        int tmp = 0;
        while(tmp < x) {
            tmp = tmp * 10 + x % 10;
            if(tmp == x) return true;
            x /= 10;
            if(tmp == x) return true;
        }
        return false;
    }
};