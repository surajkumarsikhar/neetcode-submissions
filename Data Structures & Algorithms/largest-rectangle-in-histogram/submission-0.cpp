class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int maxArea = INT_MIN;
        for(int i = 0 ; i < heights.size() ; i++){
            int lp = i;
            int rp = i;
            int rw,lw;
            while(lp>=0 && heights[lp]>=heights[i]){
                lw=lp;
                lp--;
            } 
            // cout<<"================>"<<endl;
            while(rp<heights.size() && heights[rp]>=heights[i]){
                rw=rp;
                rp++;
            }
            // cout<<"--------------->"<<endl;
            cout<<lw<<endl;
            cout<<rw<<endl;
            maxArea = max(maxArea, ((rw-lw+1) * heights[i]));

        }
        return maxArea;
    }
};
