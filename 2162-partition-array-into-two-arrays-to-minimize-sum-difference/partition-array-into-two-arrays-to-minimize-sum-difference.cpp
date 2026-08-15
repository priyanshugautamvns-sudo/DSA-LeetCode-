class Solution {
public:

    void generate(vector<int>& nums,
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
        generate(nums, i + 1, end, sum, cnt, dp);

        // Take
        generate(nums, i + 1, end,
                 sum + nums[i], cnt + 1, dp);
    }

    int minimumDifference(vector<int>& nums)
    {
        int n = nums.size();

        int total = 0;

        for(int x : nums)
            total += x;

        int mid = n / 2;

        vector<vector<int>> left(mid + 1);
        vector<vector<int>> right(n - mid + 1);

        // Generate all subset sums
        generate(nums, 0, mid, 0, 0, left);

        generate(nums, mid, n, 0, 0, right);

        // Sort right sums for binary search
        for(int i = 0; i < right.size(); i++)
        {
            sort(right[i].begin(), right[i].end());
        }

        int ans = INT_MAX;

        // Choose k elements from left
        for(int k = 0; k <= mid; k++)
        {
            // Need mid-k elements from right
            int need = mid - k;

            for(int L : left[k])
            {
                // We want:
                //
                // L + R ≈ total/2
                //
                // Therefore:
                //
                // R ≈ total/2 - L

                double target = (double)total / 2.0 - L;

                auto it = lower_bound(
                    right[need].begin(),
                    right[need].end(),
                    target
                );

                // Candidate 1
                if(it != right[need].end())
                {
                    int R = *it;

                    int sum = L + R;

                    ans = min(
                        ans,
                        abs(total - 2 * sum)
                    );
                }

                // Candidate 2: previous element
                if(it != right[need].begin())
                {
                    --it;

                    int R = *it;

                    int sum = L + R;

                    ans = min(
                        ans,
                        abs(total - 2 * sum)
                    );
                }
            }
        }

        return ans;
    }
};