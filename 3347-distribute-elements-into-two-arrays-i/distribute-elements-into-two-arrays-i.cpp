class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        vector<int>arr1;
        vector<int>arr2;
        arr1.push_back(nums[0]);
        arr2.push_back(nums[1]);
        for(int i=2;i<nums.size();i++)
        {
            if(arr1[arr1.size()-1]>arr2[arr2.size()-1])
            {
                arr1.push_back(nums[i]);
            }
            else
            {
                arr2.push_back(nums[i]);
            }
        }
        vector<int>res;
        for(int j=0;j<arr1.size();j++)
        {
            res.push_back(arr1[j]);
        }
        for(int j=0;j<arr2.size();j++)
        {
            res.push_back(arr2[j]);
        }
        return res;
    }
};
