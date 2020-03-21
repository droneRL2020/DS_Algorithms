#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int twoSumLessThanK(vector<int>& A, int K) {
        sort(A.begin(), A.end());
        int l = 0;
        int r = A.size() - 1;
        int max_out = -1;
        while (l < r) {
            if (A[l] + A[r] - K >= 0) {
                r -= 1;
            }
            else {
                if (A[l] + A[r] > max_out) {
                    max_out = A[l] + A[r];
                }
                l += 1;
            }
        }
        return max_out;
    }
};

int main() {
    Solution solution;
    vector<int> vec_in{254, 914, 110, 900, 147, 441, 209, 122, 571, 942, 136, 350, 160, 127, 178, 839, 201, 386, 462, 45, 735, 467, 153, 415, 875, 282, 204, 534, 639, 994, 284, 320, 865, 468, 1, 838, 275, 370, 295, 574, 309, 268, 415, 385, 786, 62, 359, 78, 854, 944};
    cout << solution.twoSumLessThanK(vec_in, 200);
    return 0;
}