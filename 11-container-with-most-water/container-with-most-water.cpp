class Solution {
public:
    int maxArea(vector<int>& height) {
        int mvol=INT_MIN;
        int i=0;
        int j=height.size()-1;
        while(i<j)
        {
            int vol=(j-i)*min(height[i],height[j]);
            mvol=max(vol,mvol);
            if(height[i]<height[j])
            {
                i++;
            }
            else
            {
                j--;
            }
        }
        return mvol;
    }
};