class Solution {
    vector<string> ret;
    
    void dfs(int k, int t, string tmp) { // 剩下没有匹配的左括号，还需要填几个字符
        if(t == 0) ret.push_back(tmp);
        else {
            if(k > 0) dfs(k - 1, t - 1, tmp + ')');
            if(k < t) dfs(k + 1, t - 1, tmp + '(');   
        }
    }
    
public:
    vector<string> generateParenthesis(int n) {
        dfs(0, 2 * n, "");
        return ret;
    }
};