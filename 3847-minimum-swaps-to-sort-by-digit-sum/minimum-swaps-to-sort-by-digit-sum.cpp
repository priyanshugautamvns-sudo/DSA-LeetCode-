
class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();

        vector<array<int, 3>> arr;

        for (int i = 0; i < n; i++) {
            int x = nums[i];
            int sum = 0;

            while (x > 0) {
                sum += x % 10;
                x /= 10;
            }

            arr.push_back({sum, nums[i], i});
        }

        sort(arr.begin(), arr.end());

        vector<bool> vis(n, false);
        int cnt = 0;

        for (int i = 0; i < n; i++) {
            if (vis[i] || arr[i][2] == i)
                continue;

            int cycle = 0;
            int j = i;

            while (!vis[j]) {
                vis[j] = true;
                j = arr[j][2];
                cycle++;
            }

            if (cycle > 1)
                cnt += cycle - 1;
        }

        return cnt;
    }
};
