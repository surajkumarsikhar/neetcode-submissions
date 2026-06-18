class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int i = 0;
        int j = 1; 
        int maxProfit = INT_MIN;
        int prof = 0;
        int minPrice = INT_MAX;
        while(i<j && j!=prices.size()){
            minPrice = min(minPrice,prices[i]);
            prof = prices[j] - minPrice;
            maxProfit = max(prof,maxProfit);
            j++;
            i++;
        }
        return maxProfit >= 0 ? maxProfit : 0;
    }
};
