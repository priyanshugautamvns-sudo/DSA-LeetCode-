class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>mp;
        vector<int>ans;  
        for(int i=0;i<nums.size();i++)
        {
            int fin=target-nums[i];
            if(mp.find(fin)!=mp.end())
            {
                if(mp[fin]!=i) return {i,mp[fin]};
            }
            mp[nums[i]]=i;
        }
        return {};
    }
};