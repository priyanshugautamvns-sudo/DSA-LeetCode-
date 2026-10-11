class Solution {
public:
    bool canJump(vector<int>& nums) {
        int k;
        for(int i=0;i<nums.size();i=k)
        {
            int maxi=0;
            k=i+nums[i];
            int j=k;
            while(j<nums.size() && j>i)
            {
                int maxa=j+nums[j];
                if(maxi<maxa)
                {
                    maxi=maxa;
                    k=j;
                }
                j--;
            }
            if(k>=nums.size()-1 || j>=nums.size()-1) return true;
            if(k==i) return false;
        }
        if(nums.size()<=1) return true;
        return false;
    }
};