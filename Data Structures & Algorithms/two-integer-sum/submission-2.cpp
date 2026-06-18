class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> m;
        for(int i=0;i<size(nums);i++){
            int diff = target - nums[i];
            auto it = m.find(diff);
            if(it != m.end()){
                return {m[diff],i};
            }
            m[nums[i]] = i;
        }
    }
};
