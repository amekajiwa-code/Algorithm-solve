#include <iostream>
#include <cstring>

using namespace std;

//N : 마을의 수
//D : 탈옥경과일
//P : 교도소가 있는 마을의 번호
//T : 확률을 계산할 마을의 수
//Q : 확률을 계산할 마을의 번호
int N, D, P, T, Q;
//connected : i번 마을과 j번 마을이 서로 인접해 있으면 1, 아니면 0
// deg : i번 마을과 인접한 마을의 개수
int connected[51][51], deg[51];
double cache[51][101];

double search(int here, int days) {
	// 기저 : 0일째일때
	if (days == 0) {
		return (here == P ? 1.0 : 0.0);
	}
	//메모이제이션
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