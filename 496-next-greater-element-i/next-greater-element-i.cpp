class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        vector<int>ans(n,-1);
        stack<int>st;
        unordered_map<int,int>mp;
        unordered_set<int>stt;
        for(int i=0;i<nums1.size();i++)
        {
            mp[nums1[i]]=i;
            stt.insert(nums1[i]);
        }
        for(int i=0;i<nums2.size();i++)
        {
            while(!st.empty() && nums2[st.top()]<nums2[i])
            {
                if(stt.count(nums2[st.top()])!=0)
                {
                    ans[mp[nums2[st.top()]]]=nums2[i];
                }
                st.pop();
            }
            st.push(i);
        }
        return ans;
    }
};