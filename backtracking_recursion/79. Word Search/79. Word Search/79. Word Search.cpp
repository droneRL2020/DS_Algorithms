//5:30pm start
//
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        bool res;
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                res = rec(board, word, i, j);
                if (res == true) {
                    return res;
                }
            }
        }return res;
    }

    bool rec(vector<vector<char>>& board, const string& word, int i = 0, int j = 0, int flag = 0) {
        char temp;
        bool res;
        if (flag == word.size()) {
            return true;
        }
        else {
            if (((i > -1) and (j > -1) and (i < board.size()) and (j < board[0].size())) == false) {
                return false;
            }
            else {
                if ((board[i][j] != word[flag])) {
                    return false;
                }
                else {
                    flag += 1;
                    temp = board[i][j];  // why not string temp
                    board[i][j] = '-';
                    res = rec(board, word, i, j + 1, flag) or rec(board, word, i + 1, j, flag) or rec(board, word, i, j - 1, flag) or rec(board, word, i - 1, j, flag);
                    board[i][j] = temp;
                    return res;
                }
            }
        }
    }
};

int main() {
    Solution solution;
    vector<vector<char>> board{ {'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'} };
    string word = "ABCB";
    cout<< solution.exist(board, word);
    return 0;
}