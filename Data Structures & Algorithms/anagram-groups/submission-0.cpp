#include <array>
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<array<int,26>,vector<string>> mp;
        for(auto &s : strs){
            array<int,26> freq{};

            for(char c : s){
                freq[c-'a']++;
            }

            mp[freq].push_back(s);
        }

        vector<vector<string>> vec;
        for(auto it : mp){
            vec.push_back(it.second);
        }

        return vec;
    }
};
