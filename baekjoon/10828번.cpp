#include <iostream>
#include <stack>
#include <string>

using namespace std;

namespace solution10828 {
	void MyCode() {
		int n;
		cin >> n;
		stack<int> stack;
		for (int i = 0; i < n; i++) {
			string text;
			cin >> text;
			if (text == "push") {
				int num;
				cin >> num;
				stack.push(num);
			}
			else if (text == "pop") {
				if (stack.empty()) {
					cout << "-1" << "\n";
				}
				else {
					cout << stack.top() << "\n";
					stack.pop();
				}
			}
			else if (text == "size") {
				cout << stack.size() << "\n";
			}
			else if (text == "empty") {
				if (stack.empty()) {
					cout << "1" << "\n";
				}
				else {
					cout << "0" << "\n";
				}
			}
			else if (text == "top") {
				if (stack.empty()) {
					cout << "-1" << "\n";
				}
				else {
					cout << stack.top() << "\n";
				}
			}
		}
	}
}
