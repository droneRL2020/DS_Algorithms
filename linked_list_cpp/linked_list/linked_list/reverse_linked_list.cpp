#include <iostream>
using namespace std;

/*
Input: 1->2->3->4->5->NULL
Output: 5->4->3->2->1->NULL
*/

class Node {
public:
	Node* next;
	int val;
	Node(int val_in)
		: val(val_in), next(NULL)
	{}
};

void print(Node* n) {
	while (n != NULL) {
		cout << n->val << " ";
		n = n->next;
	}
}

int main() {
	Node* first = new Node(1);
	Node* second = new Node(2);
	Node* third = new Node(3);
	Node* fourth = new Node(4);
	Node* fifth = new Node(5);
	first->next = second;
	second->next = third;
	third->next = fourth;
	fourth->next = fifth;
	
	print(first);

	return 0;
}
