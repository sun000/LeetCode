class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> ret;
        ret.push_back(1);
        for(int i = 0; i < rowIndex; i++) {
            ret.push_back(1);
            for(int i = ret.size() - 2; i > 0; i--)
                ret[i] += ret[i - 1];
        }
        return ret;
    }
};