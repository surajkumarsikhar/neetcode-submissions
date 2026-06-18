class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size() == 0) return 0;
        int j=0;
        int maxString = INT_MIN;
        unordered_map<char,int> m;
        for(int i=0;i<s.size();i++){
            char c = s[i];
            if(m.count(c)){
                j = max(j,m[c]+1);
            }
            m[c] = i;
            maxString = max(maxString,(i-j+1));
        }
        return maxString;
    }
};
