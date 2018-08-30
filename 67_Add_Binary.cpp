class Solution {
public:
    string addBinary(string a, string b) {
        int c = 0;
        string ret = "";
        for(int i = a.length() - 1, j = b.length() - 1; i >= 0 || j >= 0; i--, j--) {
            c += (i < 0 ? 0 : a[i] - '0') + (j < 0 ? 0 : b[j] - '0');
            ret = char(c % 2 + '0') + ret;
            c /= 2;
        }
        if(c) ret = "1" + ret;
        return ret;
    }
};