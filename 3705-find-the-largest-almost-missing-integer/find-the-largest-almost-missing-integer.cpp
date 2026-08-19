class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        for(int i=0,j=i+k-1;j<nums.size();i++,j++)
        {
            set<int>st;
            for(int l=i;l<=j;l++)
            {
                if(st.count(nums[l])==0)
                {
                    mp[nums[l]]++;
                    st.insert(nums[l]);
                }
            }
        }
        int ans=-1;
        for(auto it:mp)
        {
            if(it.second==1)
            {
                ans=max(ans,it.first);
            }
        }
        return ans;
    }
};