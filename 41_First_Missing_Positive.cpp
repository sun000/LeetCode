class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        vector<bool> vis(nums.size() + 2, false);
        int ans = 2147483647;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] <= 0) continue;
            if(nums[i] <= nums.size()) vis[nums[i]] = true;
        }
        for(int i = 1; i <= nums.size() + 1; i++)
            if(!vis[i]) return i;
        return -1;
    }
};