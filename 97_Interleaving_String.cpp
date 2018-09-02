class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.length() + s2.length() != s3.length()) return false;
        bool ** dp = new bool* [s1.length() + 1];  
        for(int i = 0; i < s1.length() + 1; i++)
            dp[i] = new bool[s2.length() + 1];
        dp[0][0] = true;
        for(int len = 1; len <= s3.length(); len++) {
            for(int l1 = max(0, len - (int)s2.length()); l1 <= len && l1 <= s1.length(); l1++) {
                int l2 = len - l1;    
                dp[l1][l2] = false;
                if(l1 && s1[l1 - 1] == s3[len - 1])
                    dp[l1][l2] |= dp[l1 - 1][l2];
                if(l2 && s2[l2 - 1] == s3[len - 1])
                    dp[l1][l2] |= dp[l1][l2 - 1];
            }
        }
        return dp[s1.length()][s2.length()];
    }
};