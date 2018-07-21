class Solution {
public:
    int jump(vector<int>& nums) {
        if(nums.size() <= 1) return 0;
        queue<int> q;
        int ans = 0;
        int tmp_size = 1;
        int ms = 1;
        q.push(0);
        while(!q.empty()) {
            ans++;
            for(int j = 0; j < tmp_size; j++) {
                int f = q.front(); 
                q.pop();
                for(int i = max(1, ms - f); i <= nums[f]; i++) {
                    if(f + i >= nums.size() - 1) return ans;
                    else {
                        q.push(f + i);
                        ms = f + i;
                    }
                }
            }
           tmp_size = q.size();
        }
        return ans;
    }
};