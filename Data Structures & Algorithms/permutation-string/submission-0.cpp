class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> freq(26,0);
        vector<int> freq2(26,0);
        int len = s1.length();
        int len2 = s2.length();
        if(len>len2) return false;
        for(int i=0;i<len;i++){
            freq[s1[i]-'a']++;
            freq2[s2[i]-'a']++;
        }
        if(freq == freq2) return true;
        int left = 0;
        for(int right = len ; right<len2 ; right++){
            char c = s2[right];
            char c2 = s2[left];
            freq2[c2-'a']--;
            freq2[c-'a']++;
            if(freq == freq2){
                return true;
            }
            left++;
        }
        return false;
    }
};
