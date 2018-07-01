class Solution {
    struct node {   
        int idx, num;
        node(int mIdx = 0, int mNum = 0):idx(mIdx),num(mNum){}
        bool operator< (const node &s) const {
            return num < s.num;
        }
    };
    
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<node> v;
        vector<int> ret;
        for(int i = 0; i < nums.size(); i++) 
            v.push_back(node(i, nums[i]));
        sort(v.begin(), v.end());
        for(int l = 0, r = v.size() - 1; l < r; ) {
            if(v[l].num + v[r].num < target) l++;
            else if(v[l].num + v[r].num > target) r--;
            else {
                ret.push_back(v[l].idx);
                ret.push_back(v[r].idx);
                break;
            }
        }
        return ret;
    }
};