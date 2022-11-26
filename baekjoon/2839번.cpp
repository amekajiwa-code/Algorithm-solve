#include <iostream>

using namespace std;

namespace solution2839 {
	void MyCode() {
		const int SMALLBAG = 3;
		const int BIGBAG = 5;
		int result = 0;
		bool isSolved = false;
		int n;
		cin >> n;
		while (n >= 0) {
			if (n % BIGBAG == 0) {
				result += n / BIGBAG;
				cout << result;
				isSolved = true;
				break;
			}
			n -= 3;
			result++;
		}
		if (isSolved == false) {
			cout << -1;
		}
	}
}