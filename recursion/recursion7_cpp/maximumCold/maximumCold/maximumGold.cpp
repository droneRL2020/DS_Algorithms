#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:

	vector<vector<int>> grid;
	int i;
	int j;
	int subMax;
	int rows;
	int cols;
	int* rptr = &rows;
	int* cptr = &cols;

    int getMaximumGold(vector<vector<int>>& grid) {
		if(grid.empty()) 
			return 0;
		rows = grid.size();
		cols = grid[1].size();
		
		int maxGold = 0;
		for (int i = 0; i < rows; ++i) {
			for (int j = 0; j < cols; ++j) {
				maxGold = max(maxGold, rec(i, j, grid));
			}
		}return maxGold;	
    }

	int rec(int i, int j, vector<vector<int>> & grid) {
		if ((i >= 0) and (i < *rptr) and (j >= 0) and (j < *cptr) and (grid[i][j] != 0)) {
			int gold = grid[i][j];
			grid[i][j] = 0;
			subMax = gold + max({ rec(i + 1, j, grid),
								rec(i - 1, j, grid),
								rec(i, j + 1, grid),
								rec(i, j - 1, grid) });
			grid[i][j] = gold;
		}
		else
			subMax = 0;
		return subMax;
	}

	
};

int main() {
	Solution solution;
	vector<vector<int>> grid_in{ {0,6,0},{5,8,7},{0,9,0} };
	cout << solution.getMaximumGold(grid_in);
	return 0;
}