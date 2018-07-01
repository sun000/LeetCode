class Solution { //可以优化掉一维的时间复杂度
public:
    bool dp[2000][2000];
   
    bool isMatch(string s, string p) {
        int l1 = s.length(), l2 = p.length();
        memset(dp, false, sizeof dp);
        dp[0][0] = true;
        for(int j = 1; j <= l2; j++) 
            if(p[j - 1] == '*')
                dp[0][j] |= dp[0][j - 2];
        for(int i = 1; i <= l1; i++) { //dp的下标从1开始，要平移1位
            for(int j = 1; j <= l2; j++) {
                if(s[i - 1] == p[j - 1] || p[j - 1] == '.') 
                    dp[i][j] |= dp[i - 1][j - 1];
                else if(p[j - 1] == '*') {
                    dp[i][j] |= dp[i][j - 2];//删除之前的一个char
                    if(p[j - 2] == '.' && dp[i][j - 1]) {
                        for(int k = i; k <= l1; k++) dp[k][j] = true;
                    }else if(s[i - 1] == p[j - 2]) 
                        dp[i][j] |= dp[i - 1][j - 1] | dp[i][j - 1];
                }
            }
        }
        return dp[l1][l2];
    }
};