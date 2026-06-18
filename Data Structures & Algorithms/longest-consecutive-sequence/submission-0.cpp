class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st;

        for(int n : nums){
            st.insert(n);
        }
        int res = 0;
        for(int x : nums){
            if(st.count(x-1)) continue;
            else{
                int len = 1;
                int t = x;
                while(true){
                    if(st.count(++t)) len++;
                    else{
                        res = max(res, len);
                        break;
                    }
                }
            }
        }
        return res;
    }
};
