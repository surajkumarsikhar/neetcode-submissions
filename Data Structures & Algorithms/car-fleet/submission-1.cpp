class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        stack<float> st;
        vector<pair<int,int>> vec;
        int k = 0;
        for(int j=0;j<position.size();j++){
            vec.push_back({(target - position[j]), speed[j]});
        }
        sort(vec.begin(),vec.end());
        for(auto x : vec){
            float s = (float(x.first))/float(x.second);
            if(st.empty()){
                st.push(s);
                k++;
            }
            else{
                if(st.top()>=s) continue;
                else{
                    st.push(s);
                    k++;
                }
            }
        }
        return k;
    }
};
