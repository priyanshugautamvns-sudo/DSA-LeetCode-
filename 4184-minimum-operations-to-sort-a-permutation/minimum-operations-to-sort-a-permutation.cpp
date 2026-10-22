class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return 0;

        int ind = -1; // 0 ki pos
        int isr = -1; // 0 inc, 1 dec
        int flg = 0;

        for(int i=0;i<n;i++) if(nums[i]==0) ind=i;
        if(ind==-1) return -1;

        // check circular
        int inc = 1, dec = 1;
        for(int i=1;i<n;i++){
            if(nums[i] != (nums[i-1]+1)%n) inc = 0;
            if(nums[i] != (nums[i-1]-1+n)%n) dec = 0;
        }
        if(!inc && !dec) return -1;

        if(inc){
            isr = 0; flg = 1;
            // [1,2,3,4,0] -> ind=4
            // left: 4, right via rev: n-ind+2 = 3
            int left = ind;
            int right = n - ind + 2;
            if(ind==0) right = n+5; // already sorted
            return min(left, right);
        } else {
            isr = 1; flg = 1;
            // dec: [0,2,1] -> ind=0 -> min(n-ind=3, ind+2=2) =2
            // [1,2,3,4,0] is inc, not dec, so yaha nahi ayega
            int op1 = n - ind;     // reverse + k right
            int op2 = ind + 2;     // k right + reverse
            if(ind==n-1) op2 = 1; // [2,1,0] -> 1 reverse
            return min(op1, op2);
        }
    }
};