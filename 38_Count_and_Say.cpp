class Solution {
    string toS(int n) {
        string ret = "";
        while(n) {
            ret = char(n % 10 + '0') + ret;
            n /= 10;
        }
        return ret;
    }
public:
    string countAndSay(int n) {
        string ans[] = {"1", "1"};
        int cur = 0;
        for(int i = 0; i < n; i++, cur ^= 1) {
            ans[cur ^ 1] = "";
            char now = ans[cur][0], tmp = 1;
            for(int j = 1; j < ans[cur].length(); j++) {
                if(ans[cur][j] == ans[cur][j - 1]) tmp++;
                else {
                    ans[cur ^ 1] = ans[cur ^ 1] + toS(tmp) + now;
                    now = ans[cur][j];
                    tmp = 1;
                }
            }
            ans[cur ^ 1] = ans[cur ^ 1] + char(tmp + '0') + now;
        }
        return ans[cur ^ 1];
    }
};