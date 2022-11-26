#include <iostream>
#include <queue>

namespace solution11866 {

	using namespace std;

	// 제거된 원소의 다음이 1번
	void MyCode() {
		int n, k;
		cin >> n >> k;
		queue<int> que;
		queue<int> result;

		for (int i = 1; i <= n; i++) {
			que.push(i);
		}

		int count = 1;

		while (!que.empty()) {
			if (count == k) {
				result.push(que.front());
				count = 1;
			}
			else {
				que.push(que.front());
				++count;
			}
			que.pop();
		}

		cout << "<";
		while (!result.empty()) {
			if (result.size() == 1) {
				cout << result.front();
				break;
			}
			cout << result.front() << ", ";
			result.pop();
		}
		cout << ">";
	}
}