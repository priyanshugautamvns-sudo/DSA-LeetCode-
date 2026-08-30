class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int mini=INT_MAX;
        int n=nums.size();
        int maxi=INT_MIN;
        int mini_ind;
        int maxi_ind;
        for(int i=0;i<n;i++)
        {
            if(nums[i]>maxi)
            {
                maxi=nums[i];
                maxi_ind=i;
            }
            if(nums[i]<mini)
            {
                mini=nums[i];
                mini_ind=i;
            }
        }
        int k1;
        int k2;
        if(mini_ind>maxi_ind)
        {
            k1=maxi_ind+1;
            k2=n-mini_ind;
        }
        else
        {
            k1=mini_ind+1;
            k2=n-maxi_ind;
        }
        
        int ans;
        ans=min(k1,k2);
        if(ans==k2)
        {
            ans+=min(k1,n-k2+1-k1);
        }
        else
        {
            ans+=min(k2,n-k1+1-k2);
        }
        return ans;
    }
};