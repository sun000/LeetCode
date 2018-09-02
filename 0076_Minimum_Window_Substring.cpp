class Solution {
    map<char, int> target, m;
    void initTarget(string s) {
        for(int i = 0; i < s.length(); i++)
            target[s[i]]++;
    }
    
public:
    string minWindow(string s, string t) {
        initTarget(t);
        int tot = target.size();
        printf("%d %d %d\n", target['A'], target['B'], target['C']);
        int b = 0, g = 0xffff, len, cnt = 0;
        int l, r;
        for(l = 0, r = 0; r < s.length(); r++) {
            m[s[r]]++; 
            if(m[s[r]] == target[s[r]])
                cnt++;
            if(cnt == tot) {
                while(cnt >= tot) {
                    if(m[s[l]] == target[s[l]])
                        cnt--;
                    m[s[l++]]--;  
                }
                if(g > r - (l - 1) + 1) {
                    g = r - (l - 1) + 1;
                    b = l - 1;
                }
            }
        }
        if(cnt == tot) {
            while(cnt >= tot) {
                if(m[s[l]] == target[s[l]])
                    cnt--;
                m[s[l++]]--;  
            }
            if(g < r - (l - 1) + 1) {
                g = r - (l - 1) + 1;
                b = l - 1;
            }
        }
        if(g < 0xffff) return s.substr(b, g);
        return "";
    }
};