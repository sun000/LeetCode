class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        for(auto it = nums.begin(); it != nums.end(); ) {
            if(*it == val) nums.erase(it);
            else it++;
        }
        return nums.size();
    }
};