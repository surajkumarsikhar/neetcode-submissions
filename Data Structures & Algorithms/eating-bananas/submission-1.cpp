class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int maxE = *max_element(piles.begin(),piles.end());
        int low = 1;
        int high = maxE;
        while(low<=high){
            int mid = low + (high-low)/2;
            int totalHours = 0;
            for(int x : piles){
                totalHours+=(x + mid - 1) / mid;
            }
            if(totalHours<=h){
                high = mid-1;
            } else{
                low = mid+1;
            }
        }
        return low;
    }
};
