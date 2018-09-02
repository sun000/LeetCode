class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> ret;
        int pre = 0, len = 0, cnt = 0;
        for(int i = 0; i < words.size(); i++) {
            if(cnt == 0) len += words[i].length();
            else len +=  words[i].length() + 1;
            cnt++;
            
            if(len > maxWidth) {
                len -= (words[i].length() + 1);
                cnt--;
                
                if(cnt == 1) {
                    string str = words[pre];
                    for(int j = 0; j < maxWidth - len; j++) 
                        str = str + " ";
                    ret.push_back(str);
                }
                
                else {
                    int u = (maxWidth - len) / (cnt - 1);
                    int m = (maxWidth - len) % (cnt - 1);
                    string str = words[pre];
                    for(int j = 1; j < cnt; j++, m--) {
                        if(m > 0) {
                            for(int k = 0; k < u + 1; k++)
                                str = str + " ";
                        }
                        else {
                            for(int k = 0; k < u; k++)
                                str = str + " ";
                        }
                        str = str + " " + words[pre + j];
                    }
                    ret.push_back(str);
                }   
                pre = i--;
                len = cnt = 0;
            }
        }
        if(cnt) {
            string str = words[pre];
            for(int j = 1; j < cnt; j++)
                str = str + " " + words[pre + j];
            for(int j = 0; j < maxWidth - len; j++)
                str = str + " ";
            ret.push_back(str);
        }
        return ret;
    }
};