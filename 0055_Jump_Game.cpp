class Solution {
public:
    bool canJump(vector<int>& nums) {
        int m = 0;
        for(int i = 0; i < nums.size() && i <= m; i++) {
            m = max(m, i + nums[i]);
            if(m >= nums.size() - 1) return true;
        }
        return false;
    }
};