#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector < vector<int>> A;
    vector<vector<int>> permute(vector<int>& nums) {
        for (int& i : nums) {
            vector<int> placed;
            rec(nums, i, placed);
        }
        return A;
    }

    void rec(vector<int> nums, int place, vector<int> placed) {
        placed.push_back(place);
        if (placed.size() == nums.size()) {
            A.push_back(placed);
        }
        else {
            for (int& i : nums) {
                if (find(placed.begin(), placed.end(), i) == placed.end()) {
                    rec(nums, i, placed);
                }
            }
        }
    }
};



int main() {
    Solution solution;
    vector<int> nums{ 1,2,3 };
    vector<vector<int>> result;
    result = solution.permute(nums);
    
    for (vector<int>& i : result) {
        for (int& j : i) {
            cout << j << " ";
        }
        cout << endl;
    }
    

    return 0;
}