class Solution {
public:
    string simplifyPath(string path) {
        path = path  + '/';
        stack<string> s;
        int pre = -1;
        for(int i = 0; i < path.length(); i++) {
            if(path[i] == '/') {
                if(i > pre + 1) {
                    string p = path.substr(pre + 1, i - pre - 1);
                    if(p == ".." && !s.empty())
                        s.pop();
                    else if(p != "." && p != "..") 
                        s.push(p);
                } 
                pre = i;
            }
        }
        string ans = "";
        if(s.empty()) ans = "/";
        while(!s.empty()) {
            ans = "/" + s.top() + ans;
            s.pop();
        }
        return ans;
    }
};