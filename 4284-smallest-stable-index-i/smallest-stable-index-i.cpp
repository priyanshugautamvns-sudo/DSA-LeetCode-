class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>maxi(n,0);
        vector<int>mini(n,0);
        int mina=INT_MAX;
        int maxa=INT_MIN;
        for(int i=0;i<n;i++)
        {
            mina=min(mina,nums[n-1-i]);
            maxa=max(maxa,nums[i]);
            mini[n-1-i]=mina;
            maxi[i]=maxa;
        }
        for(int i=0;i<n;i++)
        {
            if(maxi[i]-mini[i]<=k)
            {
                return i;
            }
        }
        return -1;
    }
};