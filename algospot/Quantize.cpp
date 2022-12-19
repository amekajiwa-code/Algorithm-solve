#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int INF = 987654321;
int n;

// 양자화 한 수열(정렬됨), A의 부분합을 저장할곳, A제곱의 부분합을 저장할 곳
int A[101], pSum[101], pSqSum[101];

//사전계산 : A정렬하고 부분합 계산
void precalc() {
	sort(A, A + n);
	pSum[0] = A[0];
	pSqSum[0] = A[0] * A[0];
	for (int i = 1; i < n; ++i) {
		pSum[i] = pSum[i - 1] + A[i];
		pSqSum[i] = pSqSum[i - 1] + A[i] * A[i];
	}
}

// A수열의 구간을 숫자로 표현할때의 최소오차합 계산
int minError(int lo, int hi) {
	//부분합을 이용해 A수열 구간의 합 구하기
	//hi에서 ㅣo - 1 를 빼면 구간의 합이 된다.
	int sum = pSum[hi] - (lo == 0 ? 0 : pSum[lo - 1]);
	int sqSum = pSqSum[hi] - (lo == 0 ? 0 : pSqSum[lo - 1]);
	//평균을 반올림한 값으로 수들을 표현
	int m = int(0.5 + (double)sum / (hi - lo + 1));
	int ret = sqSum - 2 * m * sum + m * m * (hi - lo + 1);
	return ret;
}

int cache[101][11];
int quantize(int from, int parts) {
	//기저 : 모든 숫자를 다 양자화했을때
	if (from == n) return 0;
	//기저 : 숫자가 남았지만 양자화 할수 없을때 아주 큰 수 반환
	if (parts == 0) return INF;
	//메모이제이션
	int& ret = cache[from][parts];
	if (ret != -1) return ret;
	ret = INF;
	// 조각의 길이를 변화시켜 가며 최소치 찾기
	for (int partSize = 1; from + partSize <= n; ++partSize) {
		ret = min(ret, minError(from, from + partSize - 1)
			+ quantize(from + partSize, parts - 1));
	}
	return ret;
}

int main() {
	int C;
	cin >> C;
	while (C--) {
		int s;
		cin >> n >> s;
		memset(cache, -1, sizeof(cache));
		for (int i = 0; i < n; ++i) {
			cin >> A[i];
		}
		precalc();
		cout << quantize(0, s) << "\n";
	}
	return 0;
}