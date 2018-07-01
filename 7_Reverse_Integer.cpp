static int x = []() { 
    std::ios::sync_with_stdio(false); 
    cin.tie(NULL);  
    return 0; 
}(); //读入骚操作

class Solution {
public:
    int reverse(int x) {
        long long int ans = 0;
        int flag = 1;
        if(x < 0) x = -x, flag = -1;
        while(x) {
            ans = ans * 10 + x % 10;
            x /= 10;
        }
        ans = ans * flag;
        if(ans > 2147483647 || ans < -2147483648) ans = 0;
        return (int)ans;
    }
};