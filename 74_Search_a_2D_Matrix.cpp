class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        for(int i = 0; i < matrix.size(); i++) {
            auto it = binary_search(matrix[i].begin(), matrix[i].end(), target);
            if(it) return true;
        }
        return false;
    }
};