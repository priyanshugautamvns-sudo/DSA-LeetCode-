class Solution {
public:

    int dpp(int left, int right, vector<int>& psum,
            vector<vector<int>>& dp) {

        if(left == right)
            return 0;

        if(dp[left][right] != -1)
            return dp[left][right];

        int ans = 0;

        for(int mid = left; mid < right; mid++) {

            int leftSum = psum[mid + 1] - psum[left];

            int rightSum = psum[right + 1] - psum[mid + 1];

            if(leftSum < rightSum) {

                ans = max(ans,
                          leftSum + dpp(left, mid, psum, dp));
            }

            else if(leftSum > rightSum) {

                ans = max(ans,
                          rightSum + dpp(mid + 1, right, psum, dp));
            }

            else {

                ans = max(ans,
                          leftSum + dpp(left, mid, psum, dp));

                ans = max(ans,
                          rightSum + dpp(mid + 1, right, psum, dp));
            }
        }

        return dp[left][right] = ans;
    }


    int stoneGameV(vector<int>& stoneValue) {

        int n = stoneValue.size();

        vector<int> psum(n + 1, 0);

        for(int i = 0; i < n; i++) {
            psum[i + 1] = psum[i] + stoneValue[i];
        }

        vector<vector<int>> dp(
            n,
            vector<int>(n, -1)
        );

        return dpp(0, n - 1, psum, dp);
    }
};