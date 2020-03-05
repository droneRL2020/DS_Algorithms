#include <iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) 
        : val(x), next(NULL) 
    {}
};

class Solution {
public:
    int n;
    int m;
public:       
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        m = rec(head, n);
        if (m == 0)
            head = head->next;
        //while (head != NULL) {
        //    cout << head->val;
        //    head = head->next;
        //}
        return head;
    }
    int rec(ListNode* node, int n) {
        if (node->next != NULL) {
            m = rec(node->next, n);
            if (m == 0)
                node->next = node->next->next;
        }
        else {
            m = n;
        }
        return m - 1;
    }

};

int main() {
    ListNode* head = new ListNode(1);
    ListNode* second = new ListNode(2);
    ListNode* third = new ListNode(3);
    ListNode* fourth = new ListNode(4);
    ListNode* fifth = new ListNode(5);
    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    //test case 1
    Solution solution;
    cout << solution.removeNthFromEnd(head, 2);


    return 0;
}
