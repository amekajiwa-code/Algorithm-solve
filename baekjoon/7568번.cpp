#include <iostream>
#include <vector>

using namespace std;

namespace solution7568 {
	void MyCode() {
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);
		int n;
		vector<pair<int, int>> bodySize;
		cin >> n;

		for (int i = 0; i < n; ++i) {
			int kg, cm;
			cin >> kg >> cm;
			bodySize.push_back(make_pair(kg, cm));
		}

		for (int i = 0; i < n; ++i) {
			int grade = 1;
			for (int j = 0; j < n; ++j) {
				if (j == i) {
					continue;
				}
				if (bodySize[i].first < bodySize[j].first &&
					bodySize[i].second < bodySize[j].second) {
					++grade;
				}
			}
			cout << grade << " ";
		}
	}
}
