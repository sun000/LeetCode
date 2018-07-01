class Solution { //string拼接操作太多，导致效率低
public:
    string convert(string s, int numRows) {
        if(numRows == 1) return s;
        string ret;
        for(int i = 0; i < s.length(); i += 2 * (numRows - 1))
            ret = ret + s[i];
        for(int i = 1; i < numRows - 1; i++) {
            for(int j = 0; ; j++) {
                int tmp;
                tmp = (2 * j + 1) * (numRows - 1);
                int a = tmp - (numRows - 1) + i, b = tmp + (numRows - 1) - i;
                if(a < s.length()) ret = ret + s[a];
                else break;
                if(b < s.length()) ret = ret + s[b];
                else break;
            }
        }
        for(int i = numRows - 1; i < s.length(); i += 2 * (numRows - 1))
            ret = ret + s[i];
        return ret;
    }
};