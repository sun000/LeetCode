class Solution {
public:
    int maxArea(vector<int>& height) {
        int ans = 0, h;
        int l = 0, r = height.size() - 1;
        while(l < r) {
            h = min(height[l], height[r]);
            ans = max(ans, (r - l) * h);
            if(h == height[l]) l++;
            if(h == height[r]) r--;
        }
        return ans;
    }
};