class Solution {
public:
    // bool solve(int n, vector<int>& dp) {
    //     if (n == 0) return false;

    //     if (dp[n] != -1)
    //         return dp[n];

    //     for (int i = 1; i * i <= n; i++) {
    //         if (!solve(n - i * i, dp)) {
    //             return dp[n] = true;
    //         }
    //     }

    //     return dp[n] = false;
    // }

    bool winnerSquareGame(int n) {
        vector<int> dp(n + 1, -1);
        dp[0]=false;
        for(int j=1;j<=n;j++)
        {
            for (int i = 1; i * i <= j; i++) {
                if (!dp[j-i*i]) {
                    dp[j] = true;
                }
            }
            if(dp[j]==-1)
            {dp[j] = false;}
        }
        return dp[n];
    }
};