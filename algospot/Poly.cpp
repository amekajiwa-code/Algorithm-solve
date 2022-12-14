#include <iostream>
#include <cstring>

using namespace std;

const int MOD = 10000000;
int cache[101][101];

int poly(int n, int first) {
	//기저 : 모든 정사각형을 포함했을때
	if (n == first) return 1;
	//메모이제이션
	int& ret = cache[n][first];
	if (ret != -1) return ret;
	ret = 0;
	for (int second = 1; second <= n - first; ++second) {
		int add = second + first - 1;
		add *= poly(n - first, second);
		add %= MOD;
		ret += add;
		ret %= MOD;
	}
	return ret;
}

int Poly_main() {
	int C;
	cin >> C;
	while (C--) {
		int n;
		cin >> n;
		memset(cache, -1, sizeof(cache));
		int result = 0;
		for (int i = 1; i <= n; ++i)
		{
			result += poly(n, i);
			result %= MOD;
		}
		cout << result << "\n";
	}
	return 0;
}