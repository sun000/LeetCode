class Solution {
    int fac[10];
    vector<int> v;
    void init() {
        fac[0] = 1;
        for(int i = 1; i < 10; i++) {
            v.push_back(i);
            fac[i] = i * fac[i - 1];
        }
    }
public:
    string getPermutation(int n, int m) {
        --m;
        init();
        string ret = "";
        for(int i = n - 1; i > 0; i--) {
            int k = m / fac[i];
            ret = ret + char(v[k] + '0');
            v.erase(v.begin() + k);
            m %= fac[i];
        }
        ret = ret + char(v[0] + '0');
        return ret;
    }
};