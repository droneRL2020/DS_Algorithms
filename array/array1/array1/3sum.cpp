#include <iostream>
#include <vector>
#include <algorithm>    
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int start = 0;
        vector<vector<int>> result;
        if (nums.size() < 3) {
            return result;
        }
        sort(nums.begin(), nums.end());
        while (start < nums.size() - 2) {
            int left = start + 1;
            int right = nums.size() - 1;
            while (left < right) {
                //total comparison
                int total = nums[start] + nums[left] + nums[right];
                if (total < 0) {
                    while ((nums[left + 1] == nums[left]) and (left < nums.size()-1)) {
                        left += 1;
                    }left += 1;
                }
                else if (total > 0) {
                    while ((nums[right - 1] == nums[right]) and (right>1)) {
                        right -= 1;
                    }right -= 1;
                }
                else {
                    result.push_back({ nums[start],nums[left],nums[right] });
                    while ((nums[left + 1] == nums[left]) and (left < nums.size() - 2)) {
                        left += 1;
                    }left += 1;
                    while ((nums[right - 1] == nums[right]) and (right > 1)) {
                        right -= 1;
                    }right -= 1;
                }
            }
            //move until new start
            while ((nums[start] == nums[start + 1]) and (start < nums.size() - 2))
                start += 1;
            start += 1;
        }
        return result;
    }
};

int main() {
    //vector<int> a{ -4,-2,1,-5,-4,-4,4,-2,0,4,0,-2,3,1,-5,0 }; //-4,-1,-1,0,1,2
    //vector<int>a{0,0,0,0 }; //-4,-1,-1,0,1,2
    vector<int>a{ -3,-2,-2,0,0, };
    Solution solution;
    solution.threeSum(a);
    return 0;
}