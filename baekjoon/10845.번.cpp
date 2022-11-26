#include <iostream>
#include <queue>
#include <string>

using namespace std;

namespace solution10845 {
	void MyCode() {
		int n;
		cin >> n;
		queue<int> queue;
		for (int i = 0; i < n; i++) {
			string text;
			cin >> text;
			if (text == "push") {
				int num;
				cin >> num;
				queue.push(num);
			}
			else if (text == "pop") {
				if (queue.empty()) {
					cout << "-1" << "\n";
				}
				else {
					cout << queue.front() << "\n";
					queue.pop();
				}
			}
			else if (text == "size") {
				cout << queue.size() << "\n";
			}
			else if (text == "empty") {
				if (queue.empty()) {
					cout << "1" << "\n";
				}
				else {
					cout << "0" << "\n";
				}
			}
			else if (text == "front") {
				if (queue.empty()) {
					cout << "-1" << "\n";
				}
				else {
					cout << queue.front() << "\n";
				}
			}
			else if (text == "back") {
				if (queue.empty()) {
					cout << "-1" << "\n";
				}
				else {
					cout << queue.back() << "\n";
				}
			}
		}
	}
}
