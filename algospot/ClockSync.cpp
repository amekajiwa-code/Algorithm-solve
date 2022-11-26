#include <iostream>
#include <vector>

using namespace std;

//ū����, ����ġ, �ð� ����
const int INF = 9999, SWITCHES = 10, CLOCKS = 16;

// �� ����ġ���� ����� �ð� ǥ��
// x�� ���� .�̸� ����ȵ�
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

// ��� �ð谡 12�ÿ� ������ �ִ��� Ȯ��
bool areAligned(vector<int>& clocks) {
	for (int i = 0; i < clocks.size(); ++i) {
		if (clocks[i] != 12) {
			return false;
		}
	}
	return true;
}

void push(vector<int>& clocks, int mySwitch) {
	//�������� ����ġ�� ���ð躰�� ������ִ��� Ȯ���ϰ� ������ִٸ� �ð踦 +3 ����
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
	//��� ����ġ�� �� �������� �ð��� ���ĵ� ������ 0 �ƴϸ� INF 
	if (mySwitch == SWITCHES) {
		return areAligned(clocks) ? 0 : INF;
	}
	int ret = INF;
	// ����ġ�� �ƿ� �ȴ����������� 3�������� ���������� for��
	for (int i = 0; i < 4; ++i) {
		//��� ����ġ�� �� ���������� ���
		//���� �ּҰ� ��ȯ
		ret = min(ret, i + solve(clocks, mySwitch + 1));
		push(clocks, mySwitch);
	}
	// ����ġ�� �׹� ������ ���󺹱�
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

