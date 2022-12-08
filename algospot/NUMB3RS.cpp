#include <iostream>
#include <cstring>

using namespace std;

//N : ������ ��
//D : Ż�������
//P : �����Ұ� �ִ� ������ ��ȣ
//T : Ȯ���� ����� ������ ��
//Q : Ȯ���� ����� ������ ��ȣ
int N, D, P, T, Q;
//connected : i�� ������ j�� ������ ���� ������ ������ 1, �ƴϸ� 0
// deg : i�� ������ ������ ������ ����
int connected[51][51], deg[51];
double cache[51][101];

double search(int here, int days) {
	// ���� : 0��°�϶�
	if (days == 0) {
		return (here == P ? 1.0 : 0.0);
	}
	//�޸������̼�
	double& ret = cache[here][days];
	if (ret > -0.5) return ret;
	ret = 0.0;
	for (int there = 0; there < N; ++there) {
		if (connected[here][there]) {
			ret += search(there, days - 1) / (double)deg[there];
		}
	}
	return ret;
}

int Numb3rs_main() {
	int C;
	cin >> C;
	cout << fixed;
	cout.precision(8);
	while (C--) {
		memset(cache, -1, sizeof(cache));
		cin >> N >> D >> P;
		for (int i = 0; i < N; ++i) {
			deg[i] = 0;
			for (int j = 0; j < N; ++j) {
				cin >> connected[i][j];
				if (connected[i][j] == 1) {
					deg[i]++;
				}
			}
		}
		cin >> T;
		for (int i = 0; i < T; ++i) {
			cin >> Q;
			cout << search(Q, D) << " ";
		}
		cout << "\n";
	}
	return 0;
}