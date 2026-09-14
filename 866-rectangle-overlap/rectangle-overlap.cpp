class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        // int x1bl=rec1[0];
        // int y1bl=rec1[1];
        // int x1br=rec1[2];
        // int y1br=rec1[1];
        // int x1tl=rec1[0];
        // int y1tl=rec1[3];
        // int x1tr=rec1[2];
        // int y1tr=rec1[3];

        // int x2bl=rec2[0];
        // int y2bl=rec2[1];
        // int x2br=rec2[2];
        // int y2br=rec2[1];
        // int x2tl=rec2[0];
        // int y2tl=rec2[3];
        // int x2tr=rec2[2];
        // int y2tr=rec2[3];

        if(((rec2[0]>rec1[0] && rec2[0]<rec1[2]) || (rec1[0]>rec2[0] && rec1[0]<rec2[2])) && ((rec2[1]>rec1[1] && rec2[1]<rec1[3]) || (rec1[1]>rec2[1] && rec1[1]<rec2[3])))return true;
        else if(((rec2[0]>=rec1[0] && rec2[2]<=rec1[2]) || (rec1[0]>=rec2[0] && rec1[0]<=rec2[0])) && ((rec2[1]>rec1[1] && rec2[1]<rec1[3]) || (rec1[1]>rec2[1] && rec1[1]<rec2[3]))) return true;
        else if(((rec2[0]>rec1[0] && rec2[0]<rec1[2]) || (rec1[0]>rec2[0] && rec1[0]<rec2[2])) && ((rec2[1]>=rec1[1] && rec2[3]<=rec1[3]) || (rec1[1]>=rec2[1] && rec1[3]<=rec2[3]))) return true;
        else if((rec2[0]==rec1[0] && rec2[2]==rec1[2])&& (rec2[1]==rec1[1] && rec2[3]==rec1[3])) return true;
        return false;
    }
};