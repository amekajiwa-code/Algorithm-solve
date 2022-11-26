#include "10814¹ø.h"
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

namespace solution10814 {
	bool compare(pair<int, string> a, pair<int, string> b)
	{
		return a.first < b.first;
	}

	void MyCode() {
		int n;
		cin >> n;
		vector<pair<int, string>> member;

		for (int i = 0; i < n; i++) {
			int temp;
			string temp2;
			cin >> temp >> temp2;
			member.push_back(make_pair(temp, temp2));
		}

		stable_sort(member.begin(), member.end(), compare);

		for (int i = 0; i < n; i++) {
			cout << member[i].first << " " << member[i].second << "\n";
		}
	}
}