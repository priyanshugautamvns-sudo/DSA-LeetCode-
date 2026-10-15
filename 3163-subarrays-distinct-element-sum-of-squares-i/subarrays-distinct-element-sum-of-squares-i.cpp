class Solution {
public:
    int sumCounts(vector<int>& nums)
    {
        vector<int>lis;
        for(int j=0;j<nums.size();j++)
        {
            unordered_set<int>st;
            for(int i=j;i<nums.size();i++)
            {
                st.insert(nums[i]);
                lis.push_back(st.size());
            }
        }        
        int sum=0;
        for(int i=0;i<lis.size();i++)
        {
            sum+=lis[i]*lis[i];
        }
        return sum;
    }
};