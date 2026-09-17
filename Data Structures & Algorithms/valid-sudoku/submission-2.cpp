class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        array<bool,9> chk = {false};
        for (int i=0; i<9; i++) {
            // row
            chk.fill(false);
            for (int j=0; j<9; j++) {
                if (board[i][j] == '.') continue;
                int num = board[i][j]-'0';
                if (chk[num-1]) {
                    cout << "row check [i,j] = [" << i << "," << j << "]" << "\n";
                    return false;
                }
                else chk[num-1] = true;
            }
        }

        for (int j=0; j<9; j++) {
            // col
            chk.fill(false);
            for (int i=0; i<9; i++) {
                if (board[i][j] == '.') continue;
                int num = board[i][j]-'0';
                if (chk[num-1]) {
                    cout << "col check [i,j] = [" << i << "," << j << "]" << "\n";
                    return false;
                }
                else chk[num-1] = true;
            }
        }

        for (int sgl=0; sgl<9; sgl+=3) {
            for (int sgr=0; sgr<9; sgr+=3) {
                chk.fill(false);
                for (int i=sgl; i<sgl+3; i++) {
                    for (int j=sgr; j<sgr+3; j++) {
                        if (board[i][j] == '.') continue;
                        int num = board[i][j]-'0';
                        if (chk[num-1]) {
                            cout << "sub grid check [i,j] = [" << i << "," << j << "]" << "\n";
                            return false;
                        }
                        else chk[num-1] = true;
                    }
                }
            }
        }

        return true;
    }
};
