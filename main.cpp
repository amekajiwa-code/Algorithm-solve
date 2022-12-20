#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

int n;
// time, pay
vector<pair <int, int>> table;
int cache[51][1001];
bool schedule[1500001];

bool check(int today, int useTime) {
	for (int i = today; i <= today + useTime; ++i) {
		if (schedule[i] == true) return true;
	}
	return false;
}

//today�� 1�Ϻ��� ����
int benefit(int today) {
	//���� : ������ ���� �ҿ�ð��� 1�� �϶� �ϴ��� ��ȯ
	//if (today == n && table[today].first == 1) return table[today].second;
	//���� : ������ ������ ���Ѹ�ŭ ����ϰ� ��ȯ
	if (today == n + 1) return 0;
	//����
	if (today > n) return -54321;
	int time = table[today].first;
	int pay = table[today].second;
	//�޸������̼�
	int& ret = cache[time][pay];
	if (ret != -1) return ret;
	//���� ������ ��ŵ
	ret = benefit(today + 1);
	//���� ������ ó��
	//���� �������̶� ��ġ�� �������� �ִ��� Ȯ��
	int pre = benefit(today + time);
	if (pre == -54321) {
		table[today].second = 0;
	}
	else {
		schedule[today] = true;
		pre += pay;
	}
	ret = max(ret, pre);
	return ret;
}

int main(void) {
	cin >> n;
	table.push_back(make_pair(0, 0)); // 0���� �����ϱ� ���ؼ� ���� ����
	for (int i = 0; i < n; ++i) {
		int time, pay;
		cin >> time >> pay;
		table.push_back(make_pair(time, pay));
	}
	memset(cache, -1, sizeof(cache));
	cout << benefit(1) << "\n";
}