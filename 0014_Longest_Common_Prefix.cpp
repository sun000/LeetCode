class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size() == 0) return "";
        string ans = "";
        bool flag = true;
        for(int i = 0; flag; i++) {
            for(int j = 0; j < strs.size(); j++) {
                if(strs[j].length() == i || strs[j][i] != strs[0][i]) {
                    flag = false;
                    break;
                }
            }
            if(flag) ans = ans + strs[0][i];
        }
        return ans;
    }
};