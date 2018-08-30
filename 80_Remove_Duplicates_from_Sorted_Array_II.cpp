class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // vector<int>::iterator it;
        for(int i = 2; i < nums.size(); i++) {
            if(nums[i] == nums[i - 1] && nums[i] == nums[i - 2]) {
                nums.erase(nums.begin() + i);
                i--;
            }
        }
        return nums.size();
    }
};