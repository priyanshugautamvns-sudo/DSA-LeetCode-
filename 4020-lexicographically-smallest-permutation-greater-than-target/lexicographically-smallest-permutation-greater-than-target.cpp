class Solution {
public:
    string dpp(int j, vector<int>& alpha, string& target, string& res)
    {
        if (j == target.size())
            return "";

        int need = target[j] - 'a';

        if (alpha[need] > 0)
        {
            alpha[need]--;
            res.push_back(target[j]);

            string ans = dpp(j + 1, alpha, target, res);

            if (ans != "")
                return ans;

            res.pop_back();
            alpha[need]++;
        }

        for (int c = need + 1; c < 26; c++)
        {
            if (alpha[c] > 0)
            {
                string ans = res;
                ans.push_back(char('a' + c));

                alpha[c]--;

                for (int x = 0; x < 26; x++)
                {
                    while (alpha[x] > 0)
                    {
                        ans.push_back(char('a' + x));
                        alpha[x]--;
                    }
                }

                return ans;
            }
        }

        return "";
    }

    string lexGreaterPermutation(string s, string target)
    {
        vector<int> alpha(26, 0);

        for (char ch : s)
            alpha[ch - 'a']++;

        string res = "";

        return dpp(0, alpha, target, res);
    }
};