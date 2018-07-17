class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool v1[9][9], v2[9][9], v3[9][9];
        memset(v1, false, sizeof v1);
        memset(v2, false, sizeof v2);
        memset(v3, false, sizeof v3);
        for(int i = 0; i < 9; i++) {
            for(int j = 0; j < 9; j++) {
                if(board[i][j] == '.') continue;
                int num = board[i][j] - '1';
                if(v1[i][num] || v2[j][num] || v3[i / 3 * 3 + j / 3][num]) return false;
                v1[i][num] = v2[j][num] = v3[i / 3 * 3 + j / 3][num] = true;
            }
        }
        return true;
    }
};