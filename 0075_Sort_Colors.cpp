class Solution {
public:
    void sortColors(vector<int>& nums) {
        int c[3] = {0, 0, 0};
        for(int i = 0; i < nums.size(); i++) c[nums[i]]++;
        int p = 0;
        for(int i = 0; i < 3; p += c[i++]) {
            for(int j = 0; j < c[i]; j++)
                nums[p + j] = i;
        }
    }
};