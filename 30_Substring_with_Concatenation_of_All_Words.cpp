class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ret;
        set<string> all_words;
        map<string, int> cnt, o;
        for(int i = 0; i < words.size(); i++) {
            all_words.insert(words[i]);
            o[words[i]]++;
        }
        int len = words.size() * words[0].length();
        int l = words[0].length();
        if(len > s.length()) return ret;
        string tmp;
        for(int st = 0; st < l; st++) {
            cnt.clear();
            int now = 0;
            for(int i = st; i < st + len; i += l) {
                tmp = s.substr(i, l);
                // cout << tmp << endl;
                if(all_words.count(tmp)) {
                    cnt[tmp]++;
                    if(cnt[tmp] == o[tmp])
                        now++;
                }
            }
            // printf("now = %d\n", now);
            if(now == all_words.size())
                ret.push_back(st);
            for(int i = st + len; i < s.length(); i += l) {
                tmp = s.substr(i, l);
                // cout << i << " in " << tmp << " " ;
                if(all_words.count(tmp)) {
                    cnt[tmp]++;
                    if(cnt[tmp] == o[tmp]) {
                        now++;
                        // printf("%d %d\n", i, now);
                    }
                }
                tmp = s.substr(i - len, l);
                // cout << " out " << tmp << endl;
                if(all_words.count(tmp)) {
                    cnt[tmp]--;
                    if(cnt[tmp] == o[tmp] - 1) {
                        now--;
                        // printf("%d %d\n", i, now);
                    }
                }
                if(now == all_words.size())
                    ret.push_back(i - len + l);
            }
        }
        sort(ret.begin(), ret.end());
        return ret;
    }
};