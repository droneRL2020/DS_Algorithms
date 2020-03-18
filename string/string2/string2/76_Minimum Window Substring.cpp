#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
#include <algorithm>


using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        string sub_str;
        int sub_len;
        int min_len = 9999;
        int start = 0;
        int end;
        int min_end = 0;
        
        // get unique key of t
        string unique_t = t;
        sort(unique_t.begin(), unique_t.end());
        auto last = unique(unique_t.begin(), unique_t.end());
        unique_t.erase(last, unique_t.end());

        // get frequency
        unordered_map <char, int> t_map;
        for (char& ele : t) {
            t_map[ele] += 1;
        }

        unordered_map<char, int> map;

        for (int i = 0; i < s.length(); ++i) {
            map[s[i]] = i;
            // 1. map has all unique string of t
            int flag = 0;
            for (char& ele : unique_t) {
                if (map.find(ele) != map.end()){
                    flag += 1;
                }
            }
            // 2. each string's frequency is same
            if (t_map.find(s[i]) != t_map.end()) {
                t_map[s[i]] -= 1;
            }
            // check all t_map values are <= 0
            int formed = 0;
            for (int k = 0; k < t_map.size(); ++k) {
                if (t_map[unique_t[k]] <= 0) {
                    formed += 1;
                }
            }
            
            // 1 and 2. all t_map value is less or equal to 0
            if ((flag==unique_t.size())and(formed == unique_t.size())){
                sub_len = i - start + 1;
                if (sub_len < min_len) {
                    sub_str = s.substr(start, sub_len);
                    min_len = sub_len;
                }
            }

            // when i reached the end
            while ((i == s.length() - 1) and (formed == unique_t.size())) {
                if (t_map.find(s[start]) != t_map.end()) {
                    t_map[s[start]] += 1;
                }
                // find the last end pointer
                for (char& ele : unique_t) {
                    if (min_end < map[ele]) {
                        end = map[ele];
                        min_end = end;
                    }
                }

                sub_len = end - start + 1;
                if (sub_len < min_len) {
                    sub_str = s.substr(start, sub_len);
                    min_len = sub_len;
                }
                start += 1;

                // check all t_map values are <= 0
                formed = 0;
                for (int k = 0; k < t_map.size(); ++k) {
                    if (t_map[unique_t[k]] <= 0) {
                        formed += 1;
                    }
                }
            }

        }
        return sub_str;
    }
};

int main() {
    /*
    Input: S = "ADOBECODEBANC", T = "ABC"
    Output: "BANC"
    S:"a"  when doesn't exist outputs ""
    T:"aa"
    */
    Solution solution;
    string s ="abbcaab";
    string t = "aab";
    cout << solution.minWindow(s, t);
    

    return 0;
}