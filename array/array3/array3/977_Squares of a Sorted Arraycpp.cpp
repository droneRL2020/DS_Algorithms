#include <iostream>	
#include <vector>
#include <cmath>
using namespace std;
class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        int l = 0;
        int r = A.size() - 1;
        vector<int> result(A.size());
        int init = A.size() - 1;
        while (l <= r) {
            if (pow(A[l], 2) <= pow(A[r], 2)) {
                result[init] = pow(A[r], 2);
                r -= 1;
                init -= 1;
            }
            else {
                result[init] = pow(A[l], 2);
                l += 1;
                init -= 1;
            }
        }
        return result;
    }
};

int main() {
    Solution solution;
    //solution.sortedSquares(vec_in);
    return 0;
}