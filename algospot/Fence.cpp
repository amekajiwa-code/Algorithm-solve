#include <iostream>
#include <vector>

using namespace std;

vector<int> h;

int solve(int left, int right) {
	//기저 : 판자가 하나일때
	if (left == right) {
		return h[left];
	}
	//가운데 기준으로 2분할
	int mid = (left + right) / 2;
	//분할한 두곳에서 가장큰 직사각형 찾기
	int ret = max(solve(left, mid), solve(mid + 1, right));
	// 두공간 모두 걸치는 판자중 가장큰 직사각형 찾기;
	int lo = mid, hi = mid + 1;
	int height = min(h[lo], h[hi]);
	// mid와 mid+1의 직사각형 고려
	ret = max(ret, height * 2);
	// 사각형이 입력 전체르 덮을 때까지 확장
	while (left < lo || hi < right) {
		//양쪽중 높이가 높은쪽으로 직사각형 확장
		if (hi < right && (lo == left || h[lo - 1] < h[hi + 1])) {
			++hi;
			height = min(height, h[hi]);
		}
		else {
			--lo;
			height = min(height, h[lo]);
		}
		// 확장한 사각형과 비교
		ret = max(ret, height * (hi - lo + 1));
	}
	return ret;
}

int Fence_main() {
	int C;
	cin >> C;
	while (C--) {
		int n;
		cin >> n;
		for (int i = 0; i < n; ++i) {
			int boardH;
			cin >> boardH;
			h.push_back(boardH);
		}
		int result = solve(0, n - 1);
		cout << result << "\n";
		h.clear();
	}
	return 0;
}