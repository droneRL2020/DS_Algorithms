#include <iostream>
using namespace std;

class Solution {
public:
    int mySqrt(int x) {
        // less than 4
        long long sqrt;
        if (x == 0) {
            return sqrt = 0;
        }
        else if (x < 4) {
            return sqrt = 1;
        }
        // larer than 4
        sqrt = 2;
        while (sqrt*sqrt< x) {
            if (sqrt*sqrt*sqrt*sqrt <= x) {
                sqrt = sqrt *sqrt;
            }
            else if((sqrt+1)*(sqrt+1) <= x) {
                sqrt += 1;
            }
            else {
                return sqrt;
            }
        }
        return sqrt;
    }
};

int main() {
    Solution solution;
    cout << solution.mySqrt(4);
    return 0;
}