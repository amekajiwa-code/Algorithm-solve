#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int MAX_N = 15;
// k : 부분문자열의 수
int k;
string word[MAX_N];
int cache[MAX_N][1 << MAX_N], overlap[MAX_N][MAX_N];

//단어 a뒤에 b가 등장할때 최대 겹칠수 있는 길이 계산
void overlaping(int a, int b) {
	int len = min(word[a].size(), word[b].size());
	for (int i = len; len > 0; --i) {
		if (word[a].substr(word[a].size() - i) == word[b].substr(0, i)) {
			overlap[a][b] = i;
			return;
		}
	}
	overlap[a][b] = 0;
}

//last : 마지막에 출현한 조각
//used : 지금까지 출현한 조각
int restore(int last, int used) {
	//기저
	if (used == (1 << k) - 1) return 0;
	//메모이제이션
	int& ret = cache[last][used];
	if (ret != -1) return ret;
	ret = 0;
	for (int next = 0; next < k; ++next) {
		if ((used & (1 << next)) == 0) {
			int cand = overlap[last][next] +
				restore(next, used | (1 << next));
			ret = max(ret, cand);
		}
	}
	return ret;
}

// 처음 호출 시 last는 restore()가 최댓값을 반환한 시작 단어로,
// used는 1<<last
string reconstruct(int last, int used) {
	// 기저 : 모든 조각을 사용했을때
	if (used == (1 << k) - 1) return "";
	//다음에 올 문자열 조각찾기
	for (int next = 0; next < k; ++next) {
		//next가 이미 사용된 조각이면 스킵
		if ((used & (1 << next)) != 0) continue;
		//next를 사용했을 경우의 답이 최적해와 같다면 next를 사용한다.
		int cand = overlap[last][next] +
			restore(next, used | (1 << next));
		if (restore(last, used) == cand) {
			return (word[next].substr(overlap[last][next]) +
				reconstruct(next, used | (1 << next)));
		}
	}
	return "@#(#@$";
}

int Restore_main() {
	int C;
	cin >> C;
	while (C--) {
		cin >> k;
		for (int i = 0; i < k; ++i) {
			cin >> word[i];
		}
		memset(cache, -1, sizeof(cache));
		memset(overlap, -1, sizeof(overlap));
		while (true) {
			bool removed = false;
			for (int i = 0; i < k && !removed; ++i) {
				for (int j = 0; j < k; ++j) {
					if (i != j && word[i].find(word[j]) != -1) {
						word[j] = word[k - 1];
						k--;
						removed = true;
					}
				}
			}
			if (!removed) break;
		}
		word[k] = "";
		for (int a = 0; a <= k; ++a) {
			for (int b = 0; b <= k; ++b) {
				if (a != b) {
					overlaping(a, b);
				}
			}
		}
		cout << reconstruct(k, 0) << "\n";
	}
	return 0;
}