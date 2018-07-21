class Solution {
public:
     int trap(vector<int>& height) {
        if(height.size() < 3) return 0;
        vector<long long int> preSum;
        long long int tmpSum = 0;
        for(int i = 0; i < height.size(); i++) {
            tmpSum += 1LL * height[i];
            preSum.push_back(tmpSum);
        }
        stack<int> s;
        vector<int> t1(height.size(), -1), t2(height.size(), -1);
        for(int i = 0; i < height.size(); i++) {
            while(!s.empty() && height[i] >= height[s.top()]) {
                t1[s.top()] = i;
                s.pop();
            }
            s.push(i);
        }
        while(!s.empty()) s.pop();
        for(int i = height.size() - 1; i >= 0; i--) {
            while(!s.empty() && height[i] >= height[s.top()]) {
                t2[s.top()] = i;
                s.pop();
            }
            s.push(i);
        }
        long long int ans = 0;
        int mm;
        for(int i = 0; t1[i] != -1;mm = i = t1[i]) 
            ans += 1LL * (t1[i] - i - 1) * height[i] - preSum[t1[i] - 1] + preSum[i]; 
        for(int i = height.size() - 1; t2[i] != -1 && i != mm; i = t2[i]) 
            ans += 1LL * (i - t2[i] - 1) * height[i] - preSum[i - 1] + preSum[t2[i]];
        return ans;
    }
};