class Solution {
public:
    int numDistinct(string s, string t) {
        int* dp = new int[t.length() + 1]();
        dp[0] = 1;
        
        for(int i = 0; i < s.length(); i++) 
            for(int j = t.length() - 1; j >= 0; j--) 
                if(s[i] == t[j]) 
                    dp[j + 1] += dp[j];

        return dp[t.length()];
    }
};