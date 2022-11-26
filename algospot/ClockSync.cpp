#include <iostream>
#include <vector>

using namespace std;

//큰정수, 스위치, 시계 갯수
const int INF = 9999, SWITCHES = 10, CLOCKS = 16;

// 각 스위치별로 연결된 시계 표현
// x면 연결 .이면 연결안됨
const char linked[SWITCHES][CLOCKS + 1] = {
	"xxx.............",
	"...x...x.x.x....",
	"....x.....x...xx",
	"x...xxxx........",
	"......xxx.x.x...",
	"x.x...........xx",
	"...x..........xx",
	"....xx.x......xx",
	".xxxxx..........",
	"...xxx...x...x..",
};

// 모든 시계가 12시에 맞춰져 있는지 확인
bool areAligned(vector<int>& clocks) {
	for (int i = 0; i < clocks.size(); ++i) {
		if (clocks[i] != 12) {
			return false;
		}
	}
	return true;
}

void push(vector<int>& clocks, int mySwitch) {
	//누르려는 스위치와 모든시계별로 연결되있는지 확인하고 연결되있다면 시계를 +3 돌림
	for (int clock = 0; clock < CLOCKS; ++clock) {
		if (linked[mySwitch][clock] == 'x') {
			clocks[clock] += 3;
			if (clocks[clock] == 15) {
				clocks[clock] = 3;
			}
		}
	}
}

int solve(vector<int>& clocks, int mySwitch) {
	//모든 스위치를 다 눌렀을때 시간이 정렬되 있으면 0 아니면 INF 
	if (mySwitch == SWITCHES) {
		return areAligned(clocks) ? 0 : INF;
	}
	int ret = INF;
	// 스위치를 아예 안눌렀을때부터 3번까지만 누를때까지 for문
	for (int i = 0; i < 4; ++i) {
		//모든 스위치를 다 누를때까지 재귀
		//가장 최소값 반환
		ret = min(ret, i + solve(clocks, mySwitch + 1));
		push(clocks, mySwitch);
	}
	// 스위치를 네번 누르면 원상복귀
	return ret;
}

int ClockSync_main() {
	int C;
	cin >> C;
	while (C--) {
		vector<int> clocks;
		for (int i = 0; i < 16; ++i) {
			int time;
			cin >> time;
			clocks.push_back(time);
		}
		int result = solve(clocks, 0);
		if (result >= 9999) {
			cout << -1 << "\n";
		}
		else {
			cout << result << "\n";
		}
	}

	return 0;
}

