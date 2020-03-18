#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> map;
        int sub_len;
        int max_len = 0;
        int start = 0;
        if (s.length()==1) {
            max_len = 1;
        }

        for (int i = 0; i < s.length(); ++i) {
            // if s[i] is in the hash map
            if ((map.find(s[i]) != map.end()) and (start <= map[s[i]])) {
                 // Need to move start
                // ex. pww 
                if (s[i] == s[i - 1]) {
                    start = i;
                }
                // ex. pwekw
                else {
                    start = map[s[i]]+1;
                }
            }
            // After moving start pointer
            sub_len = i - start + 1;
            // compare to store max_len
            if (sub_len > max_len) {
                max_len = sub_len;
            }
            // add on hash map
            map[s[i]] = i;
        }

        return max_len;
    }
};


int main() {
    /*  "pwwkew"
        " "
        "c"
        "au"
        "dvdf"
        "anviaj"
        "tmmzuxt"
     */
    string s{ "tmmzuxt" };

    Solution solution;
    cout << solution.lengthOfLongestSubstring(s);

  


    return 0;
}
