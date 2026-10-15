class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>mp;
        unordered_set<int>st;
        vector<int>ans;  
        for(int i=0;i<nums.size();i++)
        {
            int fin=target-nums[i];
            if(st.count(fin)!=0)
            {
                if(mp[fin]!=i) return {i,mp[fin]};
            }
            st.insert(nums[i]);
            mp[nums[i]]=i;
        }
        return {};
    }
};