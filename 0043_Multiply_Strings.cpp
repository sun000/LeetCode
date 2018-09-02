class Solution { //没有进制压缩，所以效率低
    string add[10];
    void init(string num) {
        add[0] = "0"; add[1] = num;
        for(int i = 2; i < 10; i++) {
            int c = 0;
            for(int j = num.length() - 1; j >= 0; j--) {
                c += (num[j] - '0') * i;
                add[i] = char(c % 10 + '0') + add[i];
                c /= 10;
            }
            while(c) {
                add[i] = char(c % 10 + '0') + add[i];
                c /= 10;
            }
        }
    }
    string addTo(string a, string b, int c) {
        string ret = "";
        for(int i = 0; i < c; i++) {
            if(i >= a.length()) ret = "0" + ret;
            ret = a[a.length() - 1 - i] + ret;
        }
        int ta, tb, tc = 0;
        for(int i = a.length() - 1 - c, j = b.length() - 1; i >= 0 || j >= 0; i--, j--) {
            ta = tb = 0;
            if(i >= 0) ta = a[i] - '0';
            if(j >= 0) tb = b[j] - '0';
            tc += ta + tb;
            ret = char(tc % 10 + '0') + ret;
            tc /= 10;
        }
        while(tc) {
            ret = char(tc % 10 + '0') + ret;
            tc /= 10;
        }
        return ret;
    }
public:
    string multiply(string num1, string num2) {
        string ret = "0";
        if(num1 == "0" || num2 == "0") return ret;
        init(num1);
        for(int i = num2.length() - 1; i >= 0; i--) 
            ret = addTo(ret, add[num2[i] - '0'], num2.length() - 1 - i);
        return ret;
    }
};