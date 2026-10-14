class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n=nums.size();
        int i=0;
        stack<int>st;
        vector<int>ans(n,-1);
        int cnt=0;
        while(cnt<2*n)
        {
            if(i==n) i=0;
            while(!st.empty() && nums[i]>nums[st.top()])
            {
                ans[st.top()]=nums[i];
                st.pop();
            }
            st.push(i);
            i++;
            cnt++;
        }
        return ans;
    }
};