class Solution {
public:
    void func(vector<int>& nums,vector<int>&lis,int i,int j,unordered_set<int>&st)
    {
        if(i==nums.size()) return;
        st.insert(nums[i]);
        lis.push_back(st.size());
        func(nums,lis,i+1,j,st);
    }
    int sumCounts(vector<int>& nums) {
        vector<int>lis;
        for(int j=0;j<nums.size();j++) {
            unordered_set<int>st;
            func(nums,lis,j,j,st);
        }        
        int sum=0;
        for(int i=0;i<lis.size();i++)
        {
            sum+=lis[i]*lis[i];
        }
        return sum;
    }
};