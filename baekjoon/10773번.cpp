#include <iostream>
#include <stack>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	stack<int> stack;
	int k;
	cin >> k;

	for (int i = 0; i < k; ++i) {
		int n;
		cin >> n;
		if (n == 0) {
			stack.pop();
		}
		else {
			stack.push(n);
		}
	}

	int sum = 0;
	while (!stack.empty()) {
		int temp = stack.top();
		sum += temp;
		stack.pop();
	}
	cout << sum;
}
