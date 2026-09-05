class Solution {
public:
    int jump(vector<int>& nums) {
        vector<int> dp(nums.size(), -1);
        return minjumps(nums, 0, dp);
    }

    int minjumps(vector<int>& nums, int position, vector<int>& dp) {

        if(position >= nums.size()-1)
            return 0;

        if(nums[position] == 0)
            return INT_MAX;

        if(dp[position] != -1)
            return dp[position];

        int minstep = INT_MAX;

        for(int jump = 1; jump <= nums[position]; jump++) {

            int subresult = minjumps(nums, position+jump, dp);

            if(subresult != INT_MAX)
                minstep = min(minstep, 1 + subresult);
        }

        return dp[position] = minstep;
    }
};