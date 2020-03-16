// leetcode.com/problems/same-tree/
#include <iostream>
using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
//class Solution {
//public:
//    bool flag = false;
//    bool isSameTree(TreeNode* p, TreeNode* q) {
//        traverse(p, q);
//        return flag;
//    }
//
//    void traverse(TreeNode* node1, TreeNode* node2) {
//        if ((node1 and node2) == NULL) {
//            if ((node1 or node2) == NULL)
//            {
//                flag = true;
//            }
//            else {
//                flag = false;
//            }
//            return;
//        }
//        else {
//            if (node1->val != node2->val) {
//                flag = false;
//                return;
//            }
//            else {
//                flag = true;
//                traverse(node1->left, node2->left);
//                traverse(node1->right, node2->right);
//            }
//        }
//    }
//};


class Solution {
public:
    bool flag = true;
    bool isSameTree(TreeNode* p, TreeNode* q) {
        traverse(p, q);
        return flag;
    }

    void traverse(TreeNode* node1, TreeNode* node2) {
        if (flag == false)
            return;
        if ((node1 or node2) == NULL) {
            return;
        }
        else if ((node1 and node2) == NULL) {
            flag = false;
            return;
        }
        else {
            if (node1->val != node2->val) {
                flag = false;
                return;
            }
            else {
                flag = true;
                traverse(node1->left, node2->left);
                traverse(node1->right, node2->right);
            }
        }
    }
};


int main() {
    TreeNode node1_1{ 2 };
    TreeNode node1_2{ 4 };

    node1_1.right = &node1_2;

    TreeNode node2_1{ 2 };
    TreeNode node2_2{3 };
    TreeNode node2_3{ 4 };

    node2_1.left = &node2_2;
    node2_1.right = &node2_3;

    Solution solution;
    
    cout << solution.isSameTree(&node1_1, &node2_1);
   
    return 0;
}