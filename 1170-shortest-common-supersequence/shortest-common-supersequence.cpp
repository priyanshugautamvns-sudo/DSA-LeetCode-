class Solution {
public:
    int dpp(string &str1, string &str2, int i, int j,
            vector<vector<int>>& dp)
    {
        if(i == str1.size())
        {
            return str2.size() - j;
        }

        if(j == str2.size())
        {
            return str1.size() - i;
        }

        if(dp[i][j] != -1)
            return dp[i][j];

        if(str1[i] == str2[j])
        {
            dp[i][j] = 1 + dpp(str1, str2, i+1, j+1, dp);
        }
        else
        {
            dp[i][j] = 1 + min(
                dpp(str1, str2, i+1, j, dp),
                dpp(str1, str2, i, j+1, dp)
            );
        }

        return dp[i][j];
    }

    string shortestCommonSupersequence(string str1, string str2)
    {
        int n = str1.size();
        int m = str2.size();

        vector<vector<int>> dp(n, vector<int>(m, -1));

        // Fill memoization table
        dpp(str1, str2, 0, 0, dp);

        string ans = "";

        int i = 0;
        int j = 0;

        // Construct answer
        while(i < n && j < m)
        {
            if(str1[i] == str2[j])
            {
                ans += str1[i];
                i++;
                j++;
            }
            else
            {
                int deleteFromStr1 = dpp(str1, str2, i+1, j, dp);
                int deleteFromStr2 = dpp(str1, str2, i, j+1, dp);

                if(deleteFromStr1 < deleteFromStr2)
                {
                    ans += str1[i];
                    i++;
                }
                else
                {
                    ans += str2[j];
                    j++;
                }
            }
        }

        // Remaining characters
        while(i < n)
        {
            ans += str1[i];
            i++;
        }

        while(j < m)
        {
            ans += str2[j];
            j++;
        }

        return ans;
    }
};