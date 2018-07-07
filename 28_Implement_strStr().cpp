class Solution {
    int *f;
    void getFail(string T, string P)
    {
        int m = P.length();
        f = new int[m + 5];
        f[0] = 0;
        f[1] = 0;
        for(int i = 1; i < m; i++)
        {
            int j = f[i];
            while(j && P[i] != P[j])
                j = f[j];
            if(P[i] == P[j])
                f[i + 1] = j + 1;
            else 
                f[i + 1] = 0;
        }
    }

    int find(string T, string P)
    {
        int n = T.length(), m = P.length();
        getFail(T, P);
        for(int i = 0, j = 0; i < n; i++)
        {
            while(j && T[i] != P[j])
                j = f[j];
            if(T[i] == P[j])
                j++;
            if(j == m)
                return i - m + 1;
        }
        return -1;
    }

public:
    int strStr(string T, string P) {
        if(P == "" ) return 0;
        if(T == "") return -1;
        delete f;
        return find(T, P);
    }
};