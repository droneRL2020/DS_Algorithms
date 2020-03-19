#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool validPalindrome(string s) {
        int l = 0;
        int r = s.length() - 1;
        int flag = 1;
        bool result = true;
        string s_1, s_2;
        while ((flag > 0) and l <= r) {
            if (s[l] != s[r]) {
                flag -= 1;
                s_1 = s;
                s_2 = s;
                s_1.erase(s_1.begin() + l);
                s_2.erase(s_2.end() - (s.length()-r));
            }
            else {
                l += 1;
                r -= 1;
            }
        }
        if (flag == 1) {
            return true;

        }
        l = 0;
        r = s_1.length() - 1;
        while (l <= r) {
            if (s_1[l] == s_1[r]) {
                l += 1;
                r -= 1;
                result = true;
            }
            else {
                result = false;
                break;
            }
        }
        if (result == true) {
            return result;
        }
        l = 0;
        r = s_2.length() - 1;
        while (l <= r) {
            if (s_2[l] == s_2[r]) {
                l += 1;
                r -= 1;
                result = true;
            }
            else {
                return false;
            }
        }
        return result;
    }
};

int main() {
    Solution solution;
    solution.validPalindrome("abcda");
    return 0; 
}