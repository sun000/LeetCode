class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.size() == 0) return vector<int>(2, -1);
        vector<int> ret;
        int l = 0, r = nums.size();
        while(l < r - 1) {
            int m = (l + r) / 2;
            if(nums[m - 1] >= target) r = m;
            else l = m;
        }
        if(nums[r - 1] == target) ret.push_back(r - 1);
        l = 0, r = nums.size();
        while(l < r - 1) {
            int m = (l + r) / 2;
            if(nums[m] <= target) l = m;
            else r = m;
        }
        if(nums[l] == target) ret.push_back(l);
        if(ret.size() == 2) return ret;
        ret.push_back(-1); ret.push_back(-1);
        return ret; 
    }
};