class Solution {
public:
    int longestValidParentheses(string s) {
        vector<bool> flag(s.length(), false);
        stack<int> st;
        for(int i = 0; i < s.length(); i++) {
            if(s[i] == '(') st.push(i);
            else {
                if(!st.empty()) {
                    flag[st.top()] = flag[i] = true;
                    st.pop();
                }
            }
        }
        int ans = 0, ret = 0;
        for(int i = 0; i < flag.size(); i++) {
            if(flag[i]) ret++;
            else {
                ans = max(ans, ret);
                ret = 0;
            }
        }
        ans = max(ans, ret);
        return ans;
    }
};