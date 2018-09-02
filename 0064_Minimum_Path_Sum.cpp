class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> dp(n + 1, INT_MAX);
        dp[1] = 0;
        for(int i = 0; i < m; i++) 
            for(int j = 1; j <= n; j++) 
               dp[j] = min(dp[j], dp[j - 1]) + grid[i][j - 1]; 
        return dp[n];
            
    }
};