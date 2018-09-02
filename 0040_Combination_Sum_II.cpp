class Solution {
    vector<vector<int>> ret;
    vector<int> tmp;
    void dfs(vector<int>& candidates, int target, int now) {
        if(!target) ret.push_back(tmp);
        else {
            for(int i = now; i < candidates.size(); i++) {
                if(i > now && candidates[i] == candidates[i - 1]) continue;
                if(candidates[i] <= target) {
                    tmp.push_back(candidates[i]);
                    dfs(candidates, target - candidates[i], i + 1);
                    tmp.pop_back();
                }
            }
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        dfs(candidates, target, 0);
        return ret;
    }
}; 