class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int ans = nums[0] + nums[1] + nums[2];
        for(int i = 0; i < nums.size(); i++) {
            for(int j = i + 1, k = nums.size() - 1; j < k; ) {
                int tmp = nums[i] + nums[j] + nums[k];
                if(abs(target - tmp) < abs(target - ans)) ans = tmp;
                
                if(nums[i] + nums[j] + nums[k] > target)  k--;
                else if(nums[i] + nums[j] + nums[k] < target) j++;
                else return target;
            }
        }
        return ans;
    }
};