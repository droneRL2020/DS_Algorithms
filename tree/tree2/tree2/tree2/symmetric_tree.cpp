#include <iostream>
#include <vector>
using namespace std;
struct TreeNode {
   int val;
   TreeNode *left;
   TreeNode *right;
   TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 


class Solution {
public:
    vector<int> l;
    vector<int> r;
    bool isSymmetric(TreeNode* root) {
        if (root == NULL)
            return true;
        else {
            l_traverse(root->left);
            r_traverse(root->right);
            if (l == r)
                return true;
            else
                return false;

        }
    }
    void l_traverse(TreeNode* node) {
        if (node == NULL) {
            l.push_back(0);
            return;
        }
        else {
            l.push_back(node->val);
            l_traverse(node->left);
            l_traverse(node->right);
        }
    }

    void r_traverse(TreeNode* node) {
        if (node == NULL) {
            r.push_back(0);
            return;
        }

        else {
            r.push_back(node->val);
            r_traverse(node->right);
            r_traverse(node->left);
        }
    }
};

int main() {
    TreeNode node1{ 1 };
    TreeNode node2{ 2 };
    TreeNode node3{ 2 };
    TreeNode node5{ 3 };
    TreeNode node7{ 3 };
    node1.left = &node2;
    node1.right = &node3;
    node2.right = &node5;
    node3.right = &node7;
    Solution solution;
    cout << solution.isSymmetric(&node1);
    return 0;
}