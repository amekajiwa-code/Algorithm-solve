#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int n, m, price[20], pref[20];
int cache[201];
// 최대 만족도의 합을 반환한다.
int sushi()
{
	int ret = 0;
	cache[0] = 0;
	for (int budget = 1; budget <= m; ++budget) {
		int cand = 0;
		for (int dish = 0; dish < n; ++dish)
			if (budget >= price[dish])
				cand = max(cand, cache[(budget - price[dish]) % 201] + pref[dish]);
		cache[budget % 201] = cand;
		ret = max(ret, cand);
	}
	return ret;
}
int sushi_main()
{
	int C;
	cin >> C;
	while (C--) {
		cin >> n >> m;
		for (int i = 0; i < n; i++) {
			cin >> price[i] >> pref[i];
			price[i] /= 100;
		}
		m /= 100;
		cout << sushi() << "\n";
	}
}