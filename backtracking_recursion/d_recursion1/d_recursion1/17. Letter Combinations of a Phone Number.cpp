#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    unordered_map<char, string> mp;
    vector<string> v;
    vector<string> letterCombinations(string digits) {  // digits = "239"
        mp['2'] = "abc";
        mp['3'] = "def";
        mp['4'] = "ghi";
        mp['5'] = "jkl";
        mp['6'] = "mno";
        mp['7'] = "pqrs";
        mp['8'] = "tuv";
        mp['9'] = "wxyz";
        v = rec(digits,0);
        return v;
    }
    vector<string> rec(string digits, int key_idx, string ele="") {// "239", 0->"239", 1 
        //string ele="";  // "a" --> "ad" --> ""adw"
        if (key_idx > digits.length() - 1) {
            v.push_back(ele);
        }
        else {
            for (int i = 0; i < mp[char(digits[key_idx])].length(); ++i) {
                //string* ele = new string;
                //*ele += mp[char(digits[key_idx])][i];
                string temp = ele;
                ele += mp[char(digits[key_idx])][i];
                cout << &ele << "---" << ele << endl;
                rec(digits, key_idx + 1, ele);
                ele = temp;
            }
        }return v;
    }

};

    

int main() {
    Solution solution;
    solution.letterCombinations("239");
    //string a = "";
    //string s = "a";
    //cout << a + s;
    
    return 0;
}