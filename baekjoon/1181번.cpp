#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

bool MyCompare(const string& a, const string& b) {
	if (a.length() == b.length()) {
		for (int i = 0; i < a.length(); ++i) {
			if (!(a[i] == b[i])) {
				return a.at(i) < b.at(i);
			}
		}
	}
	return a.length() < b.length();
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	vector<string> vector;
	int N;
	cin >> N;
	for (int i = 0; i < N; ++i) {
		string text;
		cin >> text;
		vector.push_back(text);
	}
	//
	sort(vector.begin(), vector.end(), MyCompare);
	vector.erase(unique(vector.begin(), vector.end()), vector.end());
	for (int i = 0; i < vector.size(); ++i) {
		cout << vector[i] << endl;
	}
}
