#include <iostream>
using namespace std;

int fib(int N) {
	int sum = 0;
	if (N == 0)
		return 0;
	else if (N == 1)
		return 1;
	else {
		sum += fib(N - 1) + fib(N - 2);
		return sum;
	}
}

int main() {
	// test1
	cout << fib(4);
	return 0;
}