class Solution {
public:
    int numDecodings(string s) {
        int * dp = new int[s.length() + 1];
        dp[0] = 1;
        int pre = 0;
        for(int i = 0; i < s.length(); i++) {
            int now = pre * 10 + s[i] - '0'; 
            if(s[i] - '0' == 0) {
                if(now > 26 || now <= 0) return 0;
                dp[i + 1] = dp[i - 1];
            }
            else if(now <= 26 && now >= 10) dp[i + 1] = dp[i - 1] + dp[i];
            else dp[i + 1] = dp[i];
            pre = s[i] - '0';
        }
        return dp[s.length()];
    }
};