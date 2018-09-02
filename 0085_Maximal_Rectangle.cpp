class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.size() == 0) return 0;
        vector<vector<int>> l(matrix.size() + 1, vector<int>(matrix[0].size() + 2, 0));
        vector<vector<int>> r(matrix.size() + 1, vector<int>(matrix[0].size() + 2, 0));
        vector<vector<int>> t(matrix.size() + 1, vector<int>(matrix[0].size() + 2, 0));
        
        for(int i = 1; i <= matrix.size(); i++) {
            for(int j = 1; j <= matrix[i - 1].size(); j++)
                if(matrix[i - 1][j - 1] == '1') {
                    l[i][j] = l[i][j - 1] + 1;
                    t[i][j] = t[i - 1][j] + 1;
                }
            for(int j = matrix[i - 1].size(); j > 0 ; j--) 
                if(matrix[i - 1][j - 1] == '1') 
                    r[i][j] = r[i][j + 1] + 1;
        }
        
        int ans = 0;
        for(int i = 1; i <= matrix.size(); i++) {
            for(int j = 1; j <= matrix[i - 1].size(); j++) {
                if(t[i - 1][j]) {
                    l[i][j] = min(l[i][j], l[i - 1][j]);
                    r[i][j] = min(r[i][j], r[i - 1][j]);    
                }
                ans = max(ans, (l[i][j] + r[i][j] - 1) * t[i][j]);
            }
        }
        return ans;
    }
};

//   ["1","0","1","0","0"],
//   ["1","0","1","1","1"],
//   ["1","1","1","1","1"],
//   ["1","0","0","1","0"]