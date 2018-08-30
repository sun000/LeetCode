class Solution {
    vector<vector<int>> ans;
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        for(int s = 0; s < (1 << nums.size()); s++) {
            int t = s;
            int g = 0;
            vector<int> tmp;
            while(t) {
                if(t & 1) 
                    tmp.push_back(nums[g]);
                t >>= 1;
                g++;
            }
            ans.push_back(tmp);
        }
        return ans;
    }
};