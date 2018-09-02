class Solution {
    vector<vector<string>> ret;
    vector<bool> vis1, vis2, vis3;
    vector<int> tmp;
    void dfs(int now, int n) {
        if(now == n) {
            // for(int i = 0; i < n; i++) 
            //     printf("%d ", tmp[i]);
            // printf("\n");
            vector<string> ss;
            for(int i = 0; i < n; i++) {
                string s = "";
                for(int j = 0; j < n; j++) {
                    if(j == tmp[i]) s = s + "Q";
                    else s = s + ".";
                }
                ss.push_back(s);
            }
            ret.push_back(ss);
            return;
        } else {
            for(int i = 0; i < n; i++) {
                if(!vis1[i] && !vis2[now + i] && !vis3[n + now - i]) {
                    vis1[i] = vis2[now + i] = vis3[n + now - i] = true;
                    tmp[now] = i;
                    dfs(now + 1, n);
                    vis1[i] = vis2[now + i] = vis3[n + now - i] = false;
                }
             }   
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vis1 = vector<bool> (n, false);
        vis2 = vis3 = vector<bool> (2 * n, false);
        tmp = vector<int> (n, 0);
        dfs(0, n);
        return ret;
    }
};