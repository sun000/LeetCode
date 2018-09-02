class Solution {
    bool flag;
    bool v1[9][9], v2[9][9], v3[9][9];
    void init(vector<vector<char>> board) {
        flag = false;
        memset(v1, false, sizeof v1);
        memset(v2, false, sizeof v2);
        memset(v3, false, sizeof v3);
        for(int i = 0; i < 9; i++) 
            for(int j = 0; j < 9; j++) {
                if(board[i][j] == '.') continue;
                int num = board[i][j] - '1';
                v1[i][num] = v2[j][num] = v3[i / 3 * 3 + j / 3][num] = true;
            }
    }
    
    bool check(int x, int y, int num) {
        if(v1[x][num - 1] || v2[y][num - 1] || v3[x / 3 * 3 + y / 3][num - 1]) return false;
        return true;
    }
    
    void dfs(vector<vector<char>>& board, int now) {
        if(now == 81 || flag) {
            flag = true;
            return;
        }
        int x = now / 9, y = now % 9;
        if(board[x][y] == '.') {
            for(int num = 1; num <= 9; num++) {
                if(check(x, y, num)) {
                    v1[x][num - 1] = v2[y][num - 1] = v3[x / 3 * 3 + y / 3][num - 1] = true;
                    board[x][y] = '0' + num;
                    dfs(board, now + 1);
                    if(flag) return;
                    v1[x][num - 1] = v2[y][num - 1] = v3[x / 3 * 3 + y / 3][num - 1] = false;
                    board[x][y] = '.';
                }
            }   
        }
        else 
            dfs(board, now + 1);
    }
public:
    void solveSudoku(vector<vector<char>>& board) {
        init(board);
        dfs(board, 0);
    }
};