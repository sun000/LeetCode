class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ret;
        if(!numRows) return ret;
        ret.push_back(vector<int>(1,1));
        for(int i = 1; i < numRows; i++) {
            vector<int> level;
            level.push_back(1);
            for(int j = 1; j <= i - 1; j++) 
                level.push_back(ret[i - 1][j] + ret[i - 1][j - 1]);
            level.push_back(1);
            ret.push_back(level);
        }
        return ret;
    }
};