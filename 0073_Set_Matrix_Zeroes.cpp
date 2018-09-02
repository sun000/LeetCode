class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<bool> x(matrix.size(), false), y(matrix[0].size(), false);
        for(int i = 0; i < matrix.size(); i++) {
            for(int j = 0; j < matrix[0].size(); j++) {
                if(!matrix[i][j]) {
                    x[i] = true;
                    y[j] = true;
                }
            }
        }
         for(int i = 0; i < matrix.size(); i++) {
            for(int j = 0; j < matrix[0].size(); j++) {
                if( x[i] || y[j]) {
                   matrix[i][j] = 0;
                }
            }
        }
    }
};