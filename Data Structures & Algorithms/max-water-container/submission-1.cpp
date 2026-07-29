class Solution {
public:
    int maxArea(vector<int>& heights) {
        int l = 0, r = heights.size() - 1;
        int maxArea = INT_MIN;
        int maxLeft = 0, maxRight = 0;
        while(l<r){
            // maxLeft = max(maxLeft, height[l]);
            // maxRight = max(maxRight, height[r]);
            int area = min(heights[l], heights[r]) * (r-l);
            maxArea = max(area, maxArea);
            if(heights[l] < heights[r]) l++;
            else r--;
        }
        return maxArea;
    }
};
