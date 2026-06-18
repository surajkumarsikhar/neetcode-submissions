class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size()-1;
        int fast = nums[nums[0]];
        int slow = nums[0];
        while (slow != fast){
            fast = nums[fast];
            fast = nums[fast];
            slow = nums[slow];
        }
        slow = 0;
        while (slow != fast){
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
    }
};
