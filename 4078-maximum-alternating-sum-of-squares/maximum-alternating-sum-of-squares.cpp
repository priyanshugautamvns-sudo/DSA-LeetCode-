class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n=nums.size();
        priority_queue<int>pq;
        for(int i=0;i<nums.size();i++)
        {
            pq.push(abs(nums[i]));
        }
        long long sum=0;
        if(n%2==0)
        {
            int j=n/2;
            while(j--)
            {
                int k=pq.top();
                sum+=k*k;
                pq.pop();
            }
        }
        else
        {
            int j=(n/2)+1;
            while(j--)
            {
                int k=pq.top();
                sum+=k*k;
                pq.pop();
            }
        }
        while(!pq.empty())
        {
            int k=pq.top();
            sum-=k*k;
            pq.pop();
        }
        return sum;
    }
};