class Solution {
public:
    bool isValid(string s) {
        stack<char> ss;
        for(int i = 0; i < s.length(); i++) {
            if(s[i] == ')') {
                if(!ss.empty() && ss.top() == '(') ss.pop();
                else return false;
            } else if(!ss.empty() && s[i] == ']') {
                if(ss.top() == '[') ss.pop();
                else return false;
            } else if(!ss.empty() && s[i] == '}') {
                if(ss.top() == '{') ss.pop();
                else return false;
            } else ss.push(s[i]);
        }
        return ss.empty();
    }
};