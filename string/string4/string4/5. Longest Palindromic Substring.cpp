#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        string max_str;
        if (s.length() == 0) {
            max_str = "";
        }
        else {
            max_str = s[0];
            for (int i = 0; i < s.length(); ++i) {
                string sub_str = "";
                sub_str = s[i];
                int r = 1;
                int l = 1;
                while (s[i] == s[i + 1]) {
                    sub_str += s[i + 1];
                    i += 1;
                    l += 1;
                }
                int j = i;
                while ((j - l > -1) and (j + r < s.length())) {
                    if (s[j - l] == s[j + r]) {
                        sub_str = s[j - l] + sub_str + s[j + r];
                        r += 1;
                        l += 1;
                    }
                    else {
                        break;
                    }
                }if (sub_str.length() > max_str.length()) {
                    max_str = sub_str;
                }
            }
        }
        return max_str;
    }
};

int main() {
    Solution solution;
    //string s{ "ibvjkmpyzsifuxcabqqpahjdeuzaybqsrsmbfplxycsafogotliyvhxjtkrbzqxlyfwujzhkdafhebvsdhkkdbhlhmaoxmbkqiwiusngkbdhlvxdyvnjrzvxmukvdfobzlmvnbnilnsyrgoygfdzjlymhprcpxsnxpcafctikxxybcusgjwmfklkffehbvlhvxfiddznwumxosomfbgxoruoqrhezgsgidgcfzbtdftjxeahriirqgxbhicoxavquhbkaomrroghdnfkknyigsluqebaqrtcwgmlnvmxoagisdmsokeznjsnwpxygjjptvyjjkbmkxvlivinmpnpxgmmorkasebngirckqcawgevljplkkgextudqaodwqmfljljhrujoerycoojwwgtklypicgkyaboqjfivbeqdlonxeidgxsyzugkntoevwfuxovazcyayvwbcqswzhytlmtmrtwpikgacnpkbwgfmpavzyjoxughwhvlsxsgttbcyrlkaarngeoaldsdtjncivhcfsaohmdhgbwkuemcembmlwbwquxfaiukoqvzmgoeppieztdacvwngbkcxknbytvztodbfnjhbtwpjlzuajnlzfmmujhcggpdcwdquutdiubgcvnxvgspmfumeqrofewynizvynavjzkbpkuxxvkjujectdyfwygnfsukvzflcuxxzvxzravzznpxttduajhbsyiywpqunnarabcroljwcbdydagachbobkcvudkoddldaucwruobfylfhyvjuynjrosxczgjwudpxaqwnboxgxybnngxxhibesiaxkicinikzzmonftqkcudlzfzutplbycejmkpxcygsafzkgudy" };
    string s{ "tattarrattat" };
    cout << solution.longestPalindrome(s);
    return 0;
}