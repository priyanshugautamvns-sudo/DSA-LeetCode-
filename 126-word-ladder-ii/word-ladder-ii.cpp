class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string>st;

        for(int i=0;i<wordList.size();i++)
        {
            st.insert(wordList[i]);
        }

        if(st.count(endWord)==0) return {};

        queue<string>q;
        q.push(beginWord);
        st.erase(beginWord);

        unordered_map<string,vector<string>>mp;
        bool f=false;

        while(!q.empty() && !f)
        {
            int sz=q.size();
            unordered_set<string>used;

            while(sz--)
            {
                string f1=q.front();
                q.pop();

                for(int i=0;i<endWord.size();i++)
                {
                    for(int j=0;j<26;j++)
                    {
                        string f2=f1;
                        f2[i]='a'+j;

                        if(st.count(f2))
                        {
                            // f1 is a parent of f2
                            mp[f2].push_back(f1);
                            used.insert(f2);

                            if(f2==endWord)
                                f=true;
                        }
                    }
                }
            }

            // erase only after complete level
            for(auto x:used)
            {
                st.erase(x);
                q.push(x);
            }
        }

        vector<vector<string>>ans;
        vector<string>temp={endWord};

        function<void(string)> dfs = [&](string f1)
        {
            if(f1==beginWord)
            {
                vector<string>v=temp;
                reverse(v.begin(),v.end());
                ans.push_back(v);
                return;
            }

            for(auto x:mp[f1])
            {
                temp.push_back(x);
                dfs(x);
                temp.pop_back();
            }
        };

        dfs(endWord);

        return ans;
    }
};