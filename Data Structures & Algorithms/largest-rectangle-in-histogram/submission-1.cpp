class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int maxArea = INT_MIN;
        int n = heights.size();
        vector<int> rg(n);
        vector<int> ls(n);
        stack<int> st;
        for(int i=n-1 ; i>=0 ; i--){
            while(!st.empty() && heights[st.top()] >= heights[i]){
                st.pop();
            }
            int ind = st.empty() ? n : st.top();
            rg[i]=ind;
            st.push(i);
        }
        while(!st.empty()){
            st.pop();
        }
        for(int i=0 ; i<n ; i++){
            while(!st.empty() && heights[st.top()] >= heights[i]){
                st.pop();
            }
            int ind = st.empty() ? -1 : st.top();
            ls[i]=ind;
            st.push(i);
        }
        for(int i=0;i<n;i++){
            int area = (rg[i]-ls[i]-1) * heights[i];
            maxArea = max(area,maxArea);
        }
        return maxArea;
    }
};
