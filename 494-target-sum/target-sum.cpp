class Solution {
public:
    int dpp(vector<int>& nums, int target,int i,vector<vector<int>>&dp,int n)
    {
        if(i>=nums.size())
        {
            if(target!=0)
            {
                return 0;
            }
            else return 1;
        }
        // if(target==0 && i==nums.size()-1)
        // {
        //     return 1;
        // }
        if(target < -n || target > n)
        {
            return 0;
        }

        if(dp[i][target+n]!=-1)
        {
            return dp[i][target+n];
        }
        int c2=dpp(nums,target-nums[i],i+1,dp,n);
        int c3=dpp(nums,target+nums[i],i+1,dp,n);
        return dp[i][target+n]=c2+c3;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum=0;
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
        }
        if(abs(target) > sum)
        {
            return 0;
        }
        vector<vector<int>>dp(nums.size(),vector<int>(2*sum+1,-1));
        return dpp(nums,target,0,dp,sum);
    }
};