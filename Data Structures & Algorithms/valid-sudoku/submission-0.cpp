class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        set<string> st;
        for(int i = 0 ; i < board.size() ; i++){
            for(int j = 0 ; j < board[0].size() ; j++){
                if(board[i][j] == '.') continue;
                string val(1, board[i][j]);
                string istr = val + "--> i=" + to_string(i);
                string jstr = val + "--> j=" + to_string(j);
                string ijstr = val + "--> ij=" + to_string(i/3) + "," + to_string(j/3);
                bool ibool = st.find(istr) != st.end();
                bool jbool = st.find(jstr) != st.end();
                bool ijbool = st.find(ijstr) != st.end();
                if(ibool || jbool || ijbool) return false;
                st.insert(istr);
                st.insert(jstr);
                st.insert(ijstr);
            }
        }
        return true;
    }
};
