#include <iostream>
#include <vector>
#include <numeric>   

using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> sub_v_in;
        vector<vector<int>> res;
        return rec(res, target, candidates, sub_v_in);
    }

    vector<vector<int>> rec(vector<vector<int>>& res, const int& target, const vector<int>& candidates, vector<int>& sub_v, int sub_v_sum = 0, int x = 0) {
        int new_sub_v_sum;
        vector<int> new_sub_v;
        if (sub_v_sum == target) {
            res.push_back(sub_v);
        }
        else if (sub_v_sum < target) {
            for (int i = x; i < candidates.size(); ++i) {
                new_sub_v = sub_v;
                cout << &new_sub_v << "new_sub_v" << " " << &sub_v << "sub_v" << endl;
                new_sub_v.push_back(candidates[i]);
                new_sub_v_sum = sub_v_sum + candidates[i];
                rec(res, target, candidates, new_sub_v, new_sub_v_sum, i);
            }
        }

        return res;
    }
};

int main() {
    Solution solution;
    vector<int> candidates{ 2, 3, 6, 7 };
    int target = 7;
    solution.combinationSum(candidates, target);
    return 0;
}