class Solution {
public:
    int bSearch(vector<int> &divN, int high, int low,int target){
        while(high>=low){
            int mid = low + (high-low)/2;
            if(divN[mid] == target){
                return mid;
            } else if(divN[mid] > target){
                high = mid - 1;
            } else{
                low = mid + 1;
            }
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size() -1;
        while(low<high){
            int mid = low + (high-low)/2;
            if(nums[mid] > nums[high]){
                low = mid + 1;
            } else if(nums[mid] < nums[high]){
                high = mid;
            }
        }
        int ind = max(bSearch(nums,(low-1),0,target),bSearch(nums,(nums.size()-1),low,target));
        return ind;
    }
};
