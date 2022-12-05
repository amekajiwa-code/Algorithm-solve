/*#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <cstdlib>

using namespace std;

const int INF = 987654321;
string N;

//조각 문제의 난이도를 판별
int classify(int a, int b) {
	//인덱스a부터 b - a + 1까지의 문자열 가져오기
	string M = N.substr(a, b - a + 1);
	//문자열이 모두 같을때 난이도 1
	if (M == string(M.size(), M[0])) return 1;
	//숫자가 등차수열인지 확인
	bool progressive = true;
	for (int i = 0; i < M.size() - 1; ++i) {
		if (M[i + 1] - M[i] != M[1] - M[0]) {
			progressive = false;
		}
	}
	//등차수열이면서 1씩 증감하면 난이도 2
	if (progressive && abs(M[1] - M[0]) == 1) {
		return 2;
	}
	//두수가 1212처럼 번갈아나오는지 확인
	bool alternating = true;
	for (int i = 0; i < M.size(); ++i) {
		if (M[i] != M[i % 2]) {
			alternating = false;
		}
	}
	//두수가 번갈아 나올때 난이도 4
	if (alternating) {
		return 4;
	}
	//1보다 크게 증감하는 등차수열일때 난이도 5
	if (progressive) {
		return 5;
	}
	//아무것도 해당되지 않을때 난이도 10
	return 10;
}

int cache[10002];
//3,5씩 끊어서 읽는 방법중 최소 난이도합 구하기
int memorize(int begin) {
	//기저 : 끝까지 읽었을때
	if (begin == N.size()) return 0;
	//메모이제이션 : 캐시에 데이터가 있을때
	int& ret = cache[begin];
	if (ret != -1) return ret;
	//조각문제
	ret = INF;
	//길이가 3, 4, 5일때로 조각
	for (int L = 3; L <= 5; ++L) {
		if (begin + L <= N.size()) {
			ret = min(ret, memorize(begin + L) + classify(begin, begin + L - 1));
		}
	}
	return ret;
}



int PI_main() {
	int C;
	cin >> C;
	while (C--) {
		cin >> N;
		memset(cache, -1, sizeof(cache));
		cout << memorize(0) << "\n";
	}
	return 0;
}*/