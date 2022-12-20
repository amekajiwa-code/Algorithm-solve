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

//today는 1일부터 시작
int benefit(int today) {
	//기저 : 마지막 날의 소요시간이 1일 일때 일당을 반환
	//if (today == n && table[today].first == 1) return table[today].second;
	//기저 : 마지막 날까지 일한몫만큼 계산하고 반환
	if (today == n + 1) return 0;
	//예외
	if (today > n) return -54321;
	int time = table[today].first;
	int pay = table[today].second;
	//메모이제이션
	int& ret = cache[time][pay];
	if (ret != -1) return ret;
	//오늘 스케줄 스킵
	ret = benefit(today + 1);
	//오늘 스케줄 처리
	//오늘 스케줄이랑 겹치는 스케줄이 있는지 확인
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
	table.push_back(make_pair(0, 0)); // 0일을 제외하기 위해서 더미 삽입
	for (int i = 0; i < n; ++i) {
		int time, pay;
		cin >> time >> pay;
		table.push_back(make_pair(time, pay));
	}
	memset(cache, -1, sizeof(cache));
	cout << benefit(1) << "\n";
}