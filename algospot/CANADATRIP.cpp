#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n, k;
int l[5000], m[5000], g[5000];

bool decision(int dist) {
	int ret = 0;
	for (int i = 0; i < n; ++i) {
		if (dist >= l[i] - m[i]) {
			ret += (min(dist, l[i]) - (l[i] - m[i])) / g[i] + 1;
		}
	}
	return ret >= k;
}

int optimize() {
	int lo = -1, hi = 8030001;
	while (lo + 1 < hi) {
		int mid = (lo + hi) / 2;
		if (decision(mid)) {
			hi = mid;
		}
		else {
			lo = mid;
		}
	}
	return hi;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int c;
	cin >> c;
	while (c--) {
		cin >> n >> k;
		for (int i = 0; i < n; ++i) {
			cin >> l[i] >> m[i] >> g[i];
		}
		int result = optimize();
		cout << result << "\n";
	}
	return 0;
}