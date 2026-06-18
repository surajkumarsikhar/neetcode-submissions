class Solution {
public:

    string encode(vector<string>& strs) {
        string res = "";
        for(auto &s : strs){
            string n = to_string(s.length());
            res = res + n + "#" + s;
        }
        return res;
    }

    vector<string> decode(string s) {
        vector<string> op;
        int position = 0;
        while(position<s.length()){
            int len = 0;
            while (s[position] != '#') {
                len = len * 10 + (s[position] - '0');
                position++;
            }
            position++;
            string word =  s.substr(position, len);
            op.push_back(word);
            position = position+len;
        }
        return op;
    }
};
