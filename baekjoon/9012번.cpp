#include <iostream>
#include <stack>

using namespace std;

namespace solution9012 {
	void MyCode() {
		//¿©´Â°ýÈ£¿Í ´Ý´Â°ýÈ£°¡ ¸¸³µÀ»¶§ »Ñ¿ä»Ñ¿ä
		int n;
		cin >> n;
		stack<int> stack;

		for (int i = 0; i < n; i++) {
			string text;
			cin >> text;
			int openCount = 0;
			bool isFailed = false;
			for (char c : text) {
				if (c == '(') {
					stack.push(c);
					++openCount;
				}
				else if ((c == ')')) {
					if (openCount == 0) {
						isFailed = true;
						break;
					}
					else {
						stack.pop();
						--openCount;
					}
				}
			}
			if (openCount > 0 || isFailed) {
				cout << "NO\n";
			}
			else {
				cout << "YES\n";
			}
		}
	}
}