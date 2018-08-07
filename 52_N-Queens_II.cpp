class Solution {
    int ret;
    vector<bool> vis1, vis2, vis3;
    void dfs(int now, int n) {
        if(now == n) {
            ret++;
            return;
        } else {
            for(int i = 0; i < n; i++) {
                if(!vis1[i] && !vis2[now + i] && !vis3[n + now - i]) {
                    vis1[i] = vis2[now + i] = vis3[n + now - i] = true;
                    dfs(now + 1, n);
                    vis1[i] = vis2[now + i] = vis3[n + now - i] = false;
                }
             }   
        }
    }
public:
   int totalNQueens(int n) {
        vis1 = vector<bool> (n, false);
        vis2 = vis3 = vector<bool> (2 * n, false);
        ret = 0;
        dfs(0, n);
        return ret;
    }
};