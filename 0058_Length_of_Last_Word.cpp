class Solution {
public:
    int lengthOfLastWord(string s) {
        int ans = 0, i = s.length() - 1;
        for(;i >= 0 && s[i] == ' '; i--);
        for(; i >= 0 && s[i] != ' '; i--, ans++);
        return ans;
    }
};