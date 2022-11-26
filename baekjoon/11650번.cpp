#include "11650¹ø.h"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

namespace solution11650 {
	void MyCode() {
		int n;
		cin >> n;
		vector<pair<int, int>> vector;

		for (int i = 0; i < n; i++) {
			int x;
			int y;
			cin >> x >> y;
			vector.push_back({ x, y });
		}

		sort(vector.begin(), vector.end());

		for (int i = 0; i < n; i++) {
			cout << vector[i].first << " " << vector[i].second << "\n";
		}
	}
}