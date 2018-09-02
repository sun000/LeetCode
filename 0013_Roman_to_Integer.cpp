class Solution {
    int toNum(char c) {
        if(c == 'I') return 1;
        else if(c == 'X') return 10;
        else if(c == 'C') return 100;
        else if(c == 'M') return 1000;
        else if(c == 'V') return 5;
        else if(c == 'L') return 50;
        else if(c == 'D') return 500;
    }
    
    bool isSmall(char a, char b) {
        return toNum(a) < toNum(b);
    }
public:
    int romanToInt(string s) {
        int ans = 0;
        int flag = 1;
        for(int i = 0; i < s.length(); i++) {
            flag = 1;
            if(i + 1 < s.length() && isSmall(s[i], s[i + 1])) flag = -1;
            ans += flag * toNum(s[i]);
        }
        return ans;
    }
};