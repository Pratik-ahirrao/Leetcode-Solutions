class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        int x1 = rec1[0];
        int y1 = rec1[1];
        int x2 = rec1[2];
        int y2 = rec1[3];
        
        int x3 = rec2[0];
        int y3 = rec2[1];
        int x4 = rec2[2];
        int y4 = rec2[3];
        
        bool xoverlap = false;
        bool yoverlap = false;
        
        if(max(x1, x3) < min(x2, x4))
            xoverlap = true;
        
        if(max(y1, y3) < min(y2, y4))
            yoverlap = true;
        
        return xoverlap && yoverlap;
    }
};