class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(!nums.size()) return -1; 
        int l = 0, r = nums.size();
        while(l < r - 1) {
            int m = (l + r) / 2;
            if(nums[m] > nums[l]) l = m;
            else r = m;
        }
        int mm = l;
        // printf("mm + 1 = %d\n", mm + 1);
        l = 0, r = mm + 1;
        while(l < r - 1) {
            int m = (l + r) / 2;
            if(nums[m] <= target) l = m;
            else r = m;
        }
        if(l < mm + 1 && nums[l] == target) return l;
        l = mm + 1, r = nums.size();
        while(l < r - 1) {
            int m = (l + r) / 2;
            if(nums[m] <= target) l = m;
            else r = m;
        }
        if(l < nums.size() && nums[l] == target) return l;
        return -1;
    }
};