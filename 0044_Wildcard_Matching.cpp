class Solution { //效率太低了
    bool dp[2000][2000];
public:
    bool isMatch(string s, string p) {
        memset(dp, false, sizeof dp);
        dp[0][0] = true;
        for(int i = 1; i <= p.length() && p[i - 1] == '*'; i++)
            dp[0][i] = true;
        for(int i = 1; i <= s.length(); i++) {
            for(int j = 1; j <= p.length(); j++) {
                if(p[j - 1] == '?') {
                    dp[i][j] |= dp[i - 1][j - 1];
                } else if(p[j - 1] == '*') {
                    dp[i][j] |= dp[i][j - 1];
                    if(dp[i - 1][j - 1])
                        for(int k = i; k <= s.length(); k++)
                            dp[k][j] = true;
                }
                else {
                    dp[i][j] |= dp[i - 1][j - 1] & (s[i - 1] == p[j - 1]);
                }
            }
        }
        return dp[s.length()][p.length()];
    }
};