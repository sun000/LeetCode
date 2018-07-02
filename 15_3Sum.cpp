class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>> ret;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size(); i++) {
            if(i > 0 && nums[i] == nums[i - 1]) continue;
            for(int j = i + 1, k = nums.size() - 1; j < k; ) {
                if(nums[i] + nums[j] + nums[k] < 0) j++;
                else if(nums[i] + nums[j] + nums[k] > 0) k--;
                else {
                    vector<int> tmp;
                    tmp.push_back(nums[i]);
                    tmp.push_back(nums[j]);
                    tmp.push_back(nums[k]);
                    ret.insert(tmp);
                    j++,k--;
                }
            } 
        }
        return vector<vector<int>> (ret.begin(), ret.end());
    }
};