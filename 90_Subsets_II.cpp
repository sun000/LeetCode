class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector< vector<int> > ret;
        vector<int> tmp;
        
        ret.push_back(tmp);
        int pre = 0, size = 1;
        for(int i = 0; i < nums.size(); i++) {
            int s = 0;
            if(i > 0 && nums[i] == nums[i - 1]) 
                s = pre;
            for(int j = s; j < size; j++) {
                tmp = ret[j];
                tmp.push_back(nums[i]);
                ret.push_back(tmp);
            }
            pre = size;
            size = ret.size();
        }
        return ret;
    }
};