class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string>st1;
        for(int i=0;i<wordList.size();i++)
        {
            st1.insert(wordList[i]);
        }
        if(st1.count(endWord)==0) return 0;
        queue<string>q;
        unordered_set<string>st2;
        q.push(beginWord);
        st2.insert(beginWord);
        int cnt1=1;
        while(!q.empty())
        {
            int sz=q.size();
            while(sz--)
            {
                string f1=q.front();
                q.pop();
                for(int i=0;i<beginWord.size();i++)
                {
                    string f2=f1;
                    for(int j=0;j<26;j++)
                    {
                        f2[i]='a'+j;
                        if(st1.count(f2)!=0 && st2.count(f2)==0)
                        {
                            if(f2==endWord) return cnt1+1;
                            q.push(f2);
                            st2.insert(f2);
                        }
                    }
                }
            }
            cnt1++;
        }
        return 0;
    }
};