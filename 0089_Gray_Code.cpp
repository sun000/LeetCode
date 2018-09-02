class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> ret;
        ret.push_back(0);
        if(!n) return ret;
        
        ret.push_back(1);
        
        for(int s = 1; s < n; s++)
            for(int j = 0; j < (1 << s); j++) 
                ret.push_back(ret[(1 << s) - j - 1] + (1 << s));
        return ret;
    }
};