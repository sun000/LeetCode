class Solution {
    vector<string> ret;
    vector<int> dev;
    
    void add(string s) {
        int cnt = 0;
        string str = "";
        for(int i = 0; i < 4; i++) {
            int now = 0;
            string tmp = "";
            for(int j = 0; j < dev[i]; j++, cnt++) {
                now = now * 10 + s[cnt] - '0';
                tmp = tmp + s[cnt];
                if((now == 0 && dev[i] > 1)|| now > 255) return;
            }
            if(i > 0) str = str + ".";
            str = str + tmp;
        }
        ret.push_back(str);
    }
    
    void dfs(string s, int len) {
        if(dev.size() == 4) {
            if(len == 0)
                add(s);
            return;
        }
        for(int i = 1; i < 4 && i <= len; i++) {
            dev.push_back(i);
            dfs(s, len - i);
            dev.pop_back();
        }
    }
public:
    vector<string> restoreIpAddresses(string s) {
        dfs(s, s.length());
        return ret;
    }   
};