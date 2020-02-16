#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int s_len = s.size();
        int max_len = 0;
        int i = 0;
        if (s == "")
            return 0;
        else if (s.size() == 1)
            return 1;
        while (i < (s_len - max_len)) {
            int j = i;
            int temp_len = 0;
            string curr = "";
            while (curr.find(s[j]) == string::npos and j < s_len) {
                curr += s[j];
                temp_len += 1;
                j += 1;
            }
            if (max_len < temp_len)
                max_len = temp_len;
            i++;
        }
        return max_len;
    }
};