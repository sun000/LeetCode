class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if(nums.size() < 2) return;
        for(int i = nums.size() - 2; i >= 0; i--) {
            if(nums[i] < nums[i + 1]) {
                int l = i + 1, r = nums.size();
                while(l < r - 1) {
                    int m = (l + r) / 2;
                    if(nums[m] > nums[i]) l = m;
                    else r = m;
                }
                swap(nums[l], nums[i]);
                sort(nums.begin() + i + 1, nums.end());
                return;
            }
        }
        for(int l = 0, r = nums.size() - 1; l < r; l++, r--)
            swap(nums[l], nums[r]);
    }
};