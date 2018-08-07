class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ret(n, vector<int>(n, 0));
        int cnt = 0, tmp = 1;
        while(tmp <= n * n) {
            for(int i = 0; i < n - cnt * 2 && tmp <= n * n; i++) 
                ret[cnt][cnt + i] = tmp++;
            for(int i = 0; i < n - cnt * 2 - 1 && tmp <= n * n; i++) 
                ret[cnt + 1 + i][n - 1 - cnt] = tmp++;
            for(int i = 0; i < n - cnt * 2 - 1 && tmp <= n * n; i++) 
                ret[n - 1 - cnt][n - 2 - cnt - i] = tmp++;
            for(int i = 0; i < n - cnt * 2 - 2 && tmp <= n * n; i++) 
                ret[n - 2 - cnt - i][cnt] = tmp++;
            cnt++;
        }
        return ret;
    }
};