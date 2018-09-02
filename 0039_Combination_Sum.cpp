class Solution {
    vector<vector<int>> ret;
    vector<int> tmp;
    void dfs(vector<int>& candidates, int target, int now) {
        if(!target) ret.push_back(tmp);
        else {
            for(int i = now; i < candidates.size(); i++) {
                if(candidates[i] <= target) {
                    tmp.push_back(candidates[i]);
                    dfs(candidates, target - candidates[i], i);
                    tmp.pop_back();
                }
            }
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        dfs(candidates, target, 0);
        return ret;
    }
};