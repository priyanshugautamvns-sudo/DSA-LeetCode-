class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        int k=k1+k2;
        // priority_queue<long long>pq;
        // for(int i=0;i<nums1.size();i++)
        // {
        //     pq.push(abs((nums1[i]-nums2[i])));
        // }
        // while(k>0 && pq.top()>0)
        // {
        //     long long ni=pq.top();
        //     pq.pop();
        //     pq.push(ni-1);
        //     k--;
        // }
        // long long sum=0;
        // while(!pq.empty())
        // {
        //     long long ni=pq.top();
        //     pq.pop();
        //     sum+=ni*ni;
        // }
        // return sum;
        vector<int>mp(100001,0);
        int maxi=0;
        for(int i=0;i<nums2.size();i++)
        {
            mp[abs(nums2[i]-nums1[i])]++;
            maxi=max(maxi,abs(nums2[i]-nums1[i]));
        }
        for(int i=maxi;i>0;i--)
        {
            if(k==0) break;
            int f=mp[i];
            if(k>=f)
            {
                mp[i]=0;
                mp[i-1]+=f;
                k-=f;
            }
            else
            {
                mp[i]=f-k;
                mp[i-1]+=k;
                k=0;
            }
        }
        long long sum=0;
        for(int i=1;i<=maxi;i++)
        {
            int freq=mp[i];
            sum+=1LL*freq*pow(i,2);
        }
        return sum;
    }
};