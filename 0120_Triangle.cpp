class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        if(!triangle.size()) return 0;
        vector<vector<int>> dp;
        dp.push_back(triangle[0]);
        
        for(int i = 1; i < triangle.size(); i++) {
            vector<int> level;
            level.push_back(dp[i - 1][0] + triangle[i][0]);
            for(int j = 1; j < triangle[i].size() - 1; j++) 
                level.push_back(min(dp[i - 1][j - 1], dp[i - 1][j]) + triangle[i][j]);
            level.push_back(dp[i - 1][i - 1] + triangle[i][i]);
            dp.push_back(level);
        }
        int ans = dp.back()[0];
        for(int i = 1; i < dp.back().size(); i++)
            ans = min(ans, dp.back()[i]);
        return ans;
    }
};