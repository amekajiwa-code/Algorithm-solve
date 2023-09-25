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
	ret = 0;
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

//메모이제이션으로 이미 계산된 값 리턴
//이번 인덱스의 값이 최대값인지 확인
//재귀함수를 돌려 이번값보다 큰값이 있는지 확인
//더 크면 길이를 +1 늘림
//재귀가 끝나면 JLIS 리턴


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
		cout << JLIS(-1, -1) << "\n";
	}
	return 0;
}