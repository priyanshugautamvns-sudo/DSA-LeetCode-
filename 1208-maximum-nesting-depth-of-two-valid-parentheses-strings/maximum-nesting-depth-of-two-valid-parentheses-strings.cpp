class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        vector<int>ans;
        ans.push_back(1);
        for(int i=1;i<seq.size();i++)
        {
            if(seq[i]==seq[i-1])
            {
                ans.push_back(1-ans[ans.size()-1]);
            }
            else
            {
                ans.push_back(ans[ans.size()-1]);
            }
        }
        return ans;
    }
};