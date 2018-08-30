class Solution {
    int to[4][2] = {0,1,0,-1,-1,0,1,0};
    bool flag = false;
    bool vis[2000][2000];
    
    void check(vector<vector<char>>& board, string &word, int x, int y, int idx) {
        if(flag) return;
        if(idx == word.length()) {
            flag = true;
            return;
        }
        for(int i = 0; i < 4; i++) {
            int nx = x + to[i][0];
            int ny = y + to[i][1];
            if(nx >= 0 && nx < board.size() && ny >= 0 && ny < board[nx].size() && !vis[nx][ny] && board[nx][ny] == word[idx]) {
                vis[nx][ny] = true;
                check(board, word, nx, ny, idx + 1);
                vis[nx][ny] = false;
            }
        }
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        memset(vis, false, sizeof vis);
        for(int i = 0; i < board.size(); i++) {
            for(int j = 0; j < board[i].size(); j++) {
                if(board[i][j] == word[0]) {
                    vis[i][j] = true;
                    check(board, word, i, j, 1);
                    vis[i][j] = false;
                    if(flag) return true;
                }
            }
        }
        return false;
    }
};