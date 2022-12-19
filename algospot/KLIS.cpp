#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

const int MAX = 2000000000 + 1;
int n;
int cacheLen[501], cacheCnt[501], S[500];

// S[start]에서 시작하는 증가 부분 수열 중 최대 길이를 반환한다.
int LIS(int start) {
	//메모이제이션
	int& ret = cacheLen[start + 1];
	if (ret != -1) return ret;
	ret = 1;
	for (int next = start + 1; next < n; ++next) {
		if (start == -1 || S[start] < S[next]) {
			ret = max(ret, LIS(next) + 1);
		}
	}
	return ret;
}

// S[start]에서 시작하는 최대 증가 부분 수열의 수를 반환한다.
int count(int start) {
	//기저 : LIS 길이가 1일때
	if (LIS(start) == 1) return 1;
	//메모이제이션
	int& ret = cacheCnt[start + 1];
	if (ret != -1) return ret;
	ret = 0;
	for (int next = start + 1; next < n; ++next) {
		if ((start == -1 || S[start] < S[next]) &&
			LIS(start) == LIS(next) + 1)
			ret = min<long long>(MAX, (long long)ret + count(next));
	}
	return ret;
}

void reconstruct(int start, int skip, vector<int>& lis) {
	// 1. S[start]는 항상 LIS에 포함된다.
	if (start != -1) lis.push_back(S[start]);
	// 2. 뒤에 올수있는 숫자들과 위치의 목록을 만든다.
	// (숫자, 숫자의 위치)의 목록이 된다.
	vector<pair <int, int>> followers;
	for (int next = start + 1; next < n; ++next) {
		if ((start == -1 || S[start] < S[next]) &&
			LIS(start) == LIS(next) + 1) {
			followers.push_back(make_pair(S[next], next));
		}
		sort(followers.begin(), followers.end());
	}
	// 3. k번째 LIS의 다음 숫자를 찾는다.
	for (int i = 0; i < followers.size(); ++i) {
		//이 숫자를 뒤에 이어서 만들 수 있는 LIS의 개수를 본다.
		int idx = followers[i].second;
		int cnt = count(idx);
		if (cnt <= skip) {
			skip -= cnt;
		}
		else {
			reconstruct(idx, skip, lis);
			break;
		}
	}
}

int KLIS_main() {
	int C;
	cin >> C;
	while (C--) {
		int k;
		cin >> n >> k;
		for (int i = 0; i < n; ++i) {
			cin >> S[i];
		}
		memset(cacheLen, -1, sizeof(cacheLen));
		memset(cacheCnt, -1, sizeof(cacheCnt));
		int lisRet = LIS(-1) - 1;
		vector<int> myLis;
		reconstruct(-1, k - 1, myLis);
		cout << lisRet << "\n";
		for (int i = 0; i < myLis.size(); ++i) {
			cout << myLis[i] << " ";
		}
		cout << "\n";
	}
	return 0;
}