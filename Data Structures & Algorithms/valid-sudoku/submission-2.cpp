class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<int, unordered_set<char>> row, col, box;
        for(int i = 0 ; i < board.size() ; i++){
            for(int j = 0 ; j < board[0].size() ; j++){
                if(board[i][j] == '.') continue;

                char c = board[i][j];
                int b = (i/3)*3 + (j/3);

                if(row[i].count(c) || col[j].count(c) || box[b].count(c)) return false;

                row[i].insert(c);
                col[j].insert(c);
                box[b].insert(c);
            }
        }
        return true;
    }
};
