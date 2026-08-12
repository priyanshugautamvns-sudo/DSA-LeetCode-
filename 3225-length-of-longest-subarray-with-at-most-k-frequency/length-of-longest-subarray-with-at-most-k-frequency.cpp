class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        map<int,int>mp;
        int max_size=0;
        int i=0;
        int j=0;
        while(j<nums.size())
        {
            if(mp[nums[j]]<k)
            {
                mp[nums[j]]++;
                                j++;

                max_size=max(max_size,j-i);
            }
            else
            {
                mp[nums[i]]--;
                i++;
            }
        }
        return max_size;
    }
};