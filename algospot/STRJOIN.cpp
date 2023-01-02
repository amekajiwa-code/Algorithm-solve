#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int n;

int concat(const vector<int>& lengths) {
	//�켱���� ť ����
	priority_queue<int, vector<int>, greater<int>> pq;
	for (int i = 0; i < lengths.size(); ++i) {
		pq.push(lengths[i]);
	}
	int ret = 0;
	//���� ª�� ���ڿ����� ���� ��ġ��
	while (pq.size() > 1) {
		int min1 = pq.top();
		pq.pop();
		int min2 = pq.top();
		pq.pop();
		pq.push(min1 + min2);
		ret += min1 + min2;
	}
	return ret;
}

int main() {
	int c;
	cin >> c;
	while (c--) {
		cin >> n;
		vector<int> lengths;
		for (int i = 0; i < n; ++i) {
			int input;
			cin >> input;
			lengths.push_back(input);
		}
		cout << concat(lengths) << "\n";
	}
	return 0;
}