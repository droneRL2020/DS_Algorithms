#include <iostream>
#include <cmath>
using namespace std;

class Solution {
public:
    int countPrimes(int n) {
        int count_prime = 0;
        for (int i = 2; i < n; ++i) {
            if ((i == 2) or (i == 3) or (i == 5)) {
                count_prime += 1;
            }
            else if (((i % 2) != 0) and ((i % 3) != 0) and ((i % 5) != 0)) {
                int flag = 0;
                for (int j = 3; j<int(sqrt(i)) + 1; j+=2) {
                    if ((j != i) and (i % j == 0)) {
                        flag += 1;
                        break;
                    }
                }
                if (flag == 0) {
                    count_prime += 1;
                }
            }
        }
        return count_prime;
    }
};


int main() {
    Solution solution;
    cout << solution.countPrimes(999);
    
    return 0;
}