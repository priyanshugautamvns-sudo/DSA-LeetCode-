class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>maxarr(n,0);
        vector<int>minarr(n,0);
        int mini=INT_MAX;
        int maxi=INT_MIN;
        for(int i=0;i<n;i++)
        {
            maxi=max(maxi,nums[i]);
            mini=min(mini,nums[n-i-1]);
            minarr[n-i-1]=mini;
            maxarr[i]=maxi;
        }
        for(int i=0;i<n;i++)
        {
            if(maxarr[i]-minarr[i]<=k) return i;
        }
        return -1;
    }
};