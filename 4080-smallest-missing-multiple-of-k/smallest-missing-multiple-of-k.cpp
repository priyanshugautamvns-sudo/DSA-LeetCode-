class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        map<int,int>mp;
       for(int i=0;i<nums.size();i++){
        if(nums[i]%k==0) mp[nums[i]]++;
       } 
       int ans=-1;
       for(int i=k; ;i=i+k)
       {
         if(mp[i]==0) return i;

       }
       return 0;
    }
};