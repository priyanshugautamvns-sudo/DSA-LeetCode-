class Solution {
public:

    void dpp(vector<int>& nums,
             int i,
             int end,
             int sum,
             int cnt,
             vector<vector<int>>& dp)
    {
        if(i == end)
        {
            dp[cnt].push_back(sum);
            return;
        }

        // Don't take
        dpp(nums, i + 1, end, sum, cnt, dp);

        // Take
        dpp(nums, i + 1, end,
            sum + nums[i], cnt + 1, dp);
    }

    int minimumDifference(vector<int>& nums) {

        int n = nums.size();
        int total = 0;

        for(int x : nums)
            total += x;

        int mid = n / 2;

        vector<vector<int>> left(mid + 1);
        vector<vector<int>> right(mid + 1);

        // Generate all subset sums
        dpp(nums, 0, mid, 0, 0, left);
        dpp(nums, mid, n, 0, 0, right);

        // Sort right side
        for(int i = 0; i <= mid; i++)
        {
            sort(right[i].begin(), right[i].end());
        }

        int ans = INT_MAX;

        // k elements from left
        for(int k = 0; k <= mid; k++)
        {
            // Remaining elements from right
            int need = mid - k;

            for(int leftSum : left[k])
            {
                // We want:
                //
                // leftSum + rightSum ≈ total / 2

                double target =
                    (double)total / 2.0 - leftSum;

                auto it = lower_bound(
                    right[need].begin(),
                    right[need].end(),
                    target
                );

                // Candidate >= target
                if(it != right[need].end())
                {
                    int rightSum = *it;

                    int currentSum =
                        leftSum + rightSum;

                    ans = min(
                        ans,
                        abs(total - 2 * currentSum)
                    );
                }

                // Candidate < target
                if(it != right[need].begin())
                {
                    --it;

                    int rightSum = *it;

                    int currentSum =
                        leftSum + rightSum;

                    ans = min(
                        ans,
                        abs(total - 2 * currentSum)
                    );
                }
            }
        }

        return ans;
    }
};
