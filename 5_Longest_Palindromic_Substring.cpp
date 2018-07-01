class Solution { //这道题目应该用manacher算法写，先挂个暴力，以后补上
public: 
    string longestPalindrome(string s) {
        int ans = 0;
        int ss = 0, ee = 0;
        for(int i = 0; i < s.length(); i++) {
            for(int j = 0; j <= i; j++) {
                bool flag = true;
                for(int l = j, r = i; l < r; l++, r--) {
                    if(s[l] != s[r]) {
                        flag = false;
                        break;
                    }
                }
                if(flag && i - j + 1 > ans) {
                    ans = i - j + 1;
                    ss = j, ee = i;
                } 
            }
        }
        return s.substr(ss, ans);
    }
};