class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        vector<int>dp(n,1);
        vector<int>hash;
        for(int i=0;i<n;i++)
        {
            hash.push_back(i);
        }
        int li=0;
        int maxi=1;
        vector<int>ans;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(nums[i]%nums[j]==0 && dp[j]+1>dp[i])
                {
                    dp[i]=dp[j]+1;
                    hash[i]=j;
                }
            }
            if(maxi<dp[i])
            {
                maxi=dp[i];
                li=i;
            }
        }
        while(li!=hash[li])
        {
            ans.push_back(nums[li]);
            li=hash[li];
        }
        ans.push_back(nums[li]);
        reverse(ans.begin(),ans.end());
        return ans;
    }
};