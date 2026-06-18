class Solution {
public:
    int characterReplacement(string s, int k) {
        int j = 0;
        map<char,int> mp;
        int maxString = 0;
        for(int i = 0 ; i < s.length() ; i++){
            mp[s[i]]++;
            int maxFreq = 0;
            for(auto c : mp){
                maxFreq = max(maxFreq,c.second);
            }
            int replace = (i-j+1) - maxFreq;
            if(replace<=k){
                maxString = max(maxString,(i-j+1));
                
            }
            else{
                while(replace>k){
                    mp[s[j]]--;
                    j++;
                    for(auto c : mp){
                        maxFreq = max(maxFreq,c.second);
                    }
                    replace = (j-i+1) - maxFreq;
                }
            }
        }
        return maxString;
        
    }
};
