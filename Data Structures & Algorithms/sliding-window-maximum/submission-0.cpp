class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> m;
        deque<int> dq;
        for(int r = 0 ; r < nums.size() ; r++){
            if(!dq.empty() && dq.front() == r-k){
                dq.pop_front();
            }
            while(!dq.empty() && nums[dq.back()] < nums[r]){
                dq.pop_back();
            }
            dq.push_back(r);
            if(r >= k-1){
                m.push_back(nums[dq.front()]);
            }
        }
        return m;
    }
};
