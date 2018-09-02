class Solution {//h(n)=((4*n-2)/(n+1))*h(n-1);
public:
    int numTrees(int n) {
        long long int *dp = new long long int[n + 1];
        dp[0] = dp[1] = 1;
        for(int i = 2; i <= n; i++) 
            dp[i] = (4 * i - 2) * dp[i - 1] / (i + 1);
        return dp[n];
    }
};