class Solution {
public:
    vector<vector<int>>rns;
    void lkj(vector<int> &nums,int i,vector<int> &ans)
    {
        if(i==nums.size()) return;
        if(i==0)
        {
            rns.push_back(ans);
            ans.push_back(nums[i]);
            rns.push_back(ans);
        }
        else
        {
            int n=rns.size();
            for(int j=0;j<n;j++)
            {
                ans=rns[j];
                ans.push_back(nums[i]);
                rns.push_back(ans);
                ans.pop_back();
            }
        }
        lkj(nums,i+1,ans);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>ans={};
        lkj(nums,0,ans);
        return rns;
    }
};