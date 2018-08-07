class Solution {
    int d[4][2] = {0,1,1,0,0,-1,-1,0};
    vector<vector<bool>> vis;
    int m, n;
    bool check(int x, int y) {
        if(x < 0 || y < 0) return false;
        if(x >= m || y >= n) return false;
        return !vis[x][y];
    }
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ret;
        int to = 0;
        m = matrix.size();
        if(m == 0) return ret;
        n = matrix[0].size();
        vis = vector<vector<bool>> (m, vector<bool> (n, false)); 
        int x = 0, y = 0;
        ret.push_back(matrix[x][y]);
        vis[x][y] = true;
        while(ret.size() < m * n) {
            int nx = x + d[to][0], ny = y + d[to][1];
            if(check(nx, ny)) {    
                x = nx, y = ny;     
                ret.push_back(matrix[x][y]);
                vis[x][y] = true;
            } 
            else 
                to = (to + 1) % 4;
        }
        return ret;
    }
};