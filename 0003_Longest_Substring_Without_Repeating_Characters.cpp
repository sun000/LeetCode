class Solution {
    bool vis[256];
public:
    int lengthOfLongestSubstring(string s) {
        memset(vis, false, sizeof(vis));
        int ans = 0, l, r;
        for(l = 0, r = 0; r < s.length(); ) {
            if(vis[s[r]]) {
                ans = max(ans, r - l);
                while(vis[s[r]]) {
                    vis[s[l++]] = false;
                }
            } 
            vis[s[r++]] = true;
        }
        return max(ans, r - l);
    }
};