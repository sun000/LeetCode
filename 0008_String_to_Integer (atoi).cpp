class Solution {
public:
    bool isNum(char c) {
        return '0' <= c && c <= '9';
    }
    
    int myAtoi(string str) {
        long long int ret = 0;
        int i = 0;
        int flag = 0;
        while(i < str.length() && str[i] == ' ') i++;
        if(i ==str.length()) return 0;
        if(str[i] == '-') flag = -1;
        else if(isNum(str[i])) {
            ret = str[i] -  '0';
            flag = 1;
        }  else if(str[i] == '+') {
            flag = 1;
        } else return 0;
        
        i++;
        for(; i < str.length(); i++) {
            if(isNum(str[i])) ret = ret * 10 + str[i] - '0';
            else break;
            
            if(ret * flag < -2147483648) return -2147483648;
            else if(ret * flag > 2147483647) return 2147483647;
        }
        return ret * flag;
    }
};