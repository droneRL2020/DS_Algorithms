#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        if (matrix.size() == 0) {
            return res;
        }
        int i = 0;
        int j = 0;
        int rounds;
        if (matrix[0].size() >= matrix.size()) {
            if (matrix.size() % 2 == 0) {
                rounds = matrix.size() / 2;
            }
            else {
                rounds = int(matrix.size() / 2) + 1;
            }
        }
        else {
            if (matrix.size() % 2 == 0) {
                rounds = matrix.size() / 2;
            }
            else {
                rounds = int(matrix.size() / 2) + 1;
            }
        }
        for (int k = 0; k < rounds; ++k) {
            while ((j < matrix[0].size()) and (matrix[i][j] != -999)) {
                res.push_back(matrix[i][j]);
                matrix[i][j] = -999;

                j += 1;
            }
            j -= 1;
            i += 1;
            while ((i < matrix.size()) and (matrix[i][j] != -999)) {
                res.push_back(matrix[i][j]);
                matrix[i][j] = -999;

                i += 1;
            }
            i -= 1;
            j -= 1;
            while ((j > -1) and (matrix[i][j] != -999)) {
                res.push_back(matrix[i][j]);
                matrix[i][j] = -999;

                j -= 1;
            }
            j += 1;
            i -= 1;
            while ((i > -1) and (matrix[i][j] != -999)) {
                res.push_back(matrix[i][j]);
                matrix[i][j] = -999;

                i -= 1;
            }
            i += 1;
            j += 1;
        }
        return res;
    }
};

int main() {
    Solution solution;
    vector<vector<int>> A{ {1,2,3,4,5,6,7,8,9,10},
    {11,12,13,14,15,16,17,18,19,20},
    {21,22,23,24,25,26,27,28,29,30},
    {31,32,33,34,35,36,37,38,39,40},
    {41,42,43,44,45,46,47,48,49,50},
    {51,52,53,54,55,56,57,58,59,60},
    {61,62,63,64,65,66,67,68,69,70},
    {71,72,73,74,75,76,77,78,79,80},
    {81,82,83,84,85,86,87,88,89,90},
    {91,92,93,94,95,96,97,98,99,100 }
};
    solution.spiralOrder(A);
    return 0;
}