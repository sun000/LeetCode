class Solution {
    vector<int> path;
    vector<vector<int>> ans;
    int vis[1000];
    
    void dfs(int n, int k) {
        if(!k) 
            ans.push_back(path);
        else {
            int s = 1;
            if(path.size() > 0) s = path[path.size() - 1] + 1; 
            for(int i = s; i <= n; i++) 
                if(!vis[i]) {
                    vis[i] = true;
                    path.push_back(i);
                    dfs(n, k - 1);
                    vis[i] = false;
                    path.pop_back();
                }
        }
    }
    
    
public:
    vector<vector<int>> combine(int n, int k) {
        memset(vis, false, sizeof vis);
        dfs(n, k);
        return ans;
    }
};