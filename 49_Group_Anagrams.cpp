class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int prime[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103};
        vector<vector<string>> ret;
        map<long long int, int> cnt;
        int m = 0;
        for(int i = 0; i < strs.size(); i++) {
            long long int tmp = 1;
            for(int j = 0; j < strs[i].length(); j++)
                tmp *= prime[strs[i][j] - 'a'];
            if(cnt.find(tmp) == cnt.end()) {
                cnt[tmp] = m++;
                vector<string> v;
                v.push_back(strs[i]);
                ret.push_back(v);
            }
            else {
                ret[cnt[tmp]].push_back(strs[i]);
            }
        }
        return ret;
    }
};