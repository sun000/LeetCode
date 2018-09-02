class Solution { // 借鉴了一下大佬的代码。。。
public:
    bool isScramble(string s1, string s2) {
        if(s1.size() != s2.size()) return false;
        if(s1.size() == 0) return true;
        int n = s1.size();
        bool dp[n][n][n+1];
        for(int l = 1 ; l <= n ; l++) 
            for(int i = 0 ; i < n-l+1; i++) 
                for(int j = 0 ; j < n-l+1 ; j++) {
                    if(l == 1) {
                        if(s1[i] == s2[j]) dp[i][j][l] = true;
                        else dp[i][j][l] = false;
                        continue;
                    }
                    
                    dp[i][j][l] = false;
                    for(int k = 1; k <= l-1; k++) {
                        if( (dp[i][j][k] && dp[i+k][j+k][l-k]) || (dp[i][j+l-k][k] && dp[i+k][j][l-k])  ) {
                            dp[i][j][l] = true;
                            break;
                        }
                    }
                }

        return dp[0][0][n];
    }
};