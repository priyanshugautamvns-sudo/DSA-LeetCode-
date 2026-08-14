class Solution {
public:
    // bool dpp(vector<int>&nums,int target,vector<vector<int>>&dp,int i,int n)
    // {
    //     if(target==0)
    //     {
    //         return true;
    //     }
    //     else if(i>=n)
    //     {
    //         return false;
    //     }
    //     if(dp[i][target]!=-1)
    //     {
    //         return dp[i][target];
    //     }
    //     bool c1=false;
    //     bool c2=false;
    //     if(i<n && nums[i]<=target)
    //     {
    //         c1=dpp(nums,target-nums[i],dp,i+1,n);
    //         c2=dpp(nums,target,dp,i+1,n);
    //     }
    //     else if(nums[i]>target)
    //     {
    //         c2=dpp(nums,target,dp,i+1,n);
    //     }
    //     return dp[i][target]=c1||c2;
    // }
    bool canPartition(vector<int>& nums) {
        int sum=0;
        int target;
        int n=nums.size();
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
        }
        if(sum%2!=0) return false;
        else target=sum/2;
        vector<vector<int>>dp(n+1,vector<int>(target+1,false));
        for(int i=0;i<dp.size();i++)
        {
            dp[i][0]=true;
        }
        for(int i=n-1;i>=0;i--)
        {
            for(int j=1;j<=target;j++)
            {
                bool c1=false;
                bool c2=dp[i+1][j];
                if(nums[i]<=j)
                {
                    c1=dp[i+1][j-nums[i]];
                }
                dp[i][j]=c1||c2;
            }
        }
        return dp[0][target];
    }
};