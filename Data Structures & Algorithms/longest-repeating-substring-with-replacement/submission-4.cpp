class Solution {
public:
    int characterReplacement(string s, int k) {
        int j = 0;
        map<char,int> mp;
        int maxString = 0;
        int maxFreq = 0;
        for(int i = 0 ; i < s.length() ; i++){
            mp[s[i]]++;
            maxFreq = max(maxFreq,mp[s[i]]);
            int replace = (i-j+1) - maxFreq;
            if(replace<=k){
                maxString = max(maxString,(i-j+1));
            }
            else{
                while((i-j+1)-maxFreq > k){
                    mp[s[j]]--;
                    j++;
                }
            }
        }
        return maxString;
        
    }
};
