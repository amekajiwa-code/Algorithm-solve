#include <iostream>
#include <algorithm>
#include <limits>
#include <cstring>

using namespace std;

//32비트 정수 전체보다 작은 정수를 표현하기 위해 64비트 최소치 사용
const long long NEGINF = numeric_limits<long long>::min();
int n, m, A[100], B[100];
int cache[101][101];

int JLIS(int indexA, int indexB) {
	//캐시에 데이터가 있으면 return
	int& ret = cache[indexA + 1][indexB + 1];
	if (ret != -1) return ret;
	ret = 2;
	long long a = (indexA == -1 ? NEGINF : A[indexA]);
	long long b = (indexB == -1 ? NEGINF : B[indexB]);
	long long maxElement = max(a, b);
	//다음 원소 찾기
	for (int nextA = indexA + 1; nextA < n; ++nextA) {
		if (maxElement < A[nextA]) {
			ret = max(ret, JLIS(nextA, indexB) + 1);
		}
	}
	for (int nextB = indexB + 1; nextB < m; ++nextB) {
		if (maxElement < B[nextB]) {
			ret = max(ret, JLIS(indexA, nextB) + 1);
		}
	}
	return ret;
}


int JLIS_main() {
	int C;
	cin >> C;
	while (C--) {
		cin >> n >> m;
		memset(cache, -1, sizeof(cache));
		for (int i = 0; i < n; ++i) {
			cin >> A[i];
		}
		for (int i = 0; i < m; ++i) {
			cin >> B[i];
		}
		cout << JLIS(-1, -1) - 2 << "\n";
	}
	return 0;
}