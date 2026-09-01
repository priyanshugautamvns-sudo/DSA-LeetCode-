class Solution {
public:
    int stoneGameVI(vector<int>& aliceValues, vector<int>& bobValues) {
        priority_queue<pair<int,int>>pq;
        for(int i=0;i<bobValues.size();i++)
        {
            pq.push({aliceValues[i]+bobValues[i],i});
        }
        int a=0;
        int b=0;
        int ptr=0;
    while(!pq.empty())
        {
            if(ptr==0)
            {
                a+=aliceValues[pq.top().second];
                pq.pop();
                ptr=1;
            }
            else
            {
                b+=bobValues[pq.top().second];
                pq.pop();
                ptr=0;
            }

        }
        if(a==b) return 0;
        else if(a>b) return 1;
        else return -1;
    }
};