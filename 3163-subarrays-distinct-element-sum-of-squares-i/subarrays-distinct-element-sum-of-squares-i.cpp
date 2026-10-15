class Solution {
public:
    int sumCounts(vector<int>& nums)
    {
        vector<int>lis;
        int sum=0;
        for(int j=0;j<nums.size();j++)
        {
            unordered_set<int>st;
            for(int i=j;i<nums.size();i++)
            {
                st.insert(nums[i]);
                sum+=st.size()*st.size();
            }
        }      
        return sum;  
    }
};