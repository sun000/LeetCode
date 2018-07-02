class Solution {
public:
    vector<string> letterCombinations(string digits) {
        queue<string> Q;
        Q.push("");
        int d;
        for(int i = 0; i < digits.length(); i++) {
            int cnt = Q.size();
            d = digits[i] - '2';
            for(int j = 0; j < cnt; j++) {
                string f = Q.front();
                Q.pop();
                if(d == 5) 
                    for(int k = 0; k < 4; k++) 
                        Q.push(f + char('a' + 3 * d + k));
                else if(d == 6) 
                    for(int k = 0; k < 3; k++) 
                        Q.push(f + char('a' + 3 * d + k + 1));
                else if(d == 7) 
                    for(int k = 0; k < 4; k++) 
                        Q.push(f + char('a' + 3 * d + k + 1));
                else
                    for(int k = 0; k < 3; k++) 
                        Q.push(f + char('a' + 3 * d + k));
            }
        }
        vector<string> ans;
        if(Q.size() > 1) {
            while(!Q.empty()) {
                ans.push_back(Q.front());
                Q.pop();
            }
        }
        return ans;
    }
};