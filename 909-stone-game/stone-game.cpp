class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int i=0;
        int j=piles.size()-1;
        int alice=0;
        int bob=0;
        int cnt=0;
        while(i<j)
        {
            if(cnt%2==0)
            {
                if(piles[i]>=piles[j])
                {
                    alice+=piles[i];
                    i++;
                }
                else
                {
                    alice+=piles[j];
                    j--;
                }
            }
            else
            {
                if(piles[i]>=piles[j])
                {
                    bob+=piles[i];
                    i++;
                }
                else
                {
                    bob+=piles[j];
                    j--;
                }
            }
        }
        return alice>bob;
    }
};