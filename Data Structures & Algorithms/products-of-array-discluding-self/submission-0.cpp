class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int mul = 1;
        int mulwo = 1;
        int zeronos = size(nums);
        for(int i = 0 ;i < size(nums) ; i++){
            mul*=nums[i];
            if(nums[i] != 0){
                zeronos--;
                mulwo*=nums[i];
            }
        }
        vector<int> res;
        for(int x : nums){
            if(x == 0 && zeronos == 1){
                res.push_back(mulwo);
            } else if(zeronos >1){
                res.push_back(0);
            }else{
                res.push_back(mul/x);
            }
        }
        return res;
    }
};
