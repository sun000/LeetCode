class Solution { //这个算法很低效，由于整理的时候已经写了很久了，具体原因再看
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ret;
        set<pair<int, int>> tmp;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size(); i++) {
            for(int j = i + 1; j < nums.size(); j++) {
                if(tmp.count(make_pair(nums[i], nums[j]))) continue;
                tmp.insert(make_pair(nums[i], nums[j]));
                for(int k = j + 1, t = nums.size() - 1; k < t; ) {
                    if(nums[i] + nums[j] + nums[k] + nums[t] == target) {
                        vector<int> h;
                        h.push_back(nums[i]);
                        h.push_back(nums[j]);
                        h.push_back(nums[k]);
                        h.push_back(nums[t]);
                        ret.push_back(h);
                        while(nums[k] == h[2]) k++;
                        while(nums[t] == h[3]) t--;
                    } 
                    else if(nums[i] + nums[j] + nums[k] + nums[t] <= target)  { 
                        k++; while(k < t && nums[k] == nums[k - 1]) k++;
                    }
                    else { 
                       t--; while(t > k && nums[t] == nums[t + 1]) t--;
                    }
                }
            }
        }
        return ret;
    }
};