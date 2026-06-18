class Solution {
public:
    string minWindow(string s, string t) {
        map<char,int> tmap;
        for(char c : t) tmap[c]++;
        int minLength = INT_MAX;
        int start;
        int requiredCount = t.length();
        int l = 0;
        for(int r = 0 ; r < s.length() ; r++){
            if(tmap[s[r]]>0)requiredCount--;
            tmap[s[r]]--;
            while(requiredCount<=0){
                if(r-l+1 < minLength){
                    minLength = r-l+1;
                    start = l;
                }
                tmap[s[l]]++;
                if(tmap[s[l]]>0){
                    requiredCount++;
                }
                l++;
            }
        }
        if(minLength == INT_MAX) return "";
        return s.substr(start,minLength);
    }
};
