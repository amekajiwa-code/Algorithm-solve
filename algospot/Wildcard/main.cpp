#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

//캐시를 저장할 배열
int cache[101][101];

string W, S;

//와일드카드 패턴에 대응되는 문자열인지 확인
int matchMemoized(int w, int s) {
	int& ret = cache[w][s];
	//기저 : 캐시에 데이터가 저장되있으면 return
	if (ret != -1) return ret;

	while (s < S.size() && w < W.size() &&
		(W[w] == '?' || W[w] == S[s])) {
		return ret = matchMemoized(w + 1, s + 1);
	}

	if (w == W.size()) return ret = (s == S.size());

	if (W[w] == '*') {
		if (matchMemoized(w + 1, s) ||
			(s < S.size() && matchMemoized(w, s + 1))) {
			ret = 1;
			return ret;
		}
	}

	ret = 0;
	return ret;
}

int main() {
	int C;
	cin >> C;
	while (C--) {
		cin >> W;
		int n;
		cin >> n;
		vector<string> results;
		for (int i = 0; i < n; ++i) {
			cin >> S;
			memset(cache, -1, sizeof(cache));
			if (matchMemoized(0, 0)) {
				results.push_back(S);
			}
		}

		sort(results.begin(), results.end());
		for (int i = 0; i < results.size(); ++i) {
			cout << results[i] << "\n";
		}
	}
	return 0;
}