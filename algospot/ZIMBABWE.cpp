#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int MOD = 1000000007;
// 현재가격, digits: e의 자릿수들을 정렬한 것
string curPrice, digits;
//n : 현재 가격의 자릿수길이 m : 마지막 계란 가격의 배수
int n, m;
int cache[1 << 14][20][2];
// index : 이번에 채울 자리의 index, taken : 지금까지 사용한 자릿수들의 집합
// mod : 지금까지 만든 가격의 m에 대한 나머지, less : 지금까지 만든 가격이 이미 e보다 작으면 1 아니면 0
int price(int index, int taken, int mod, int less) {
	//기저
	if (index == n) {
		return (less && mod == 0) ? 1 : 0;
	}
	//메모이제이션
	int& ret = cache[taken][mod][less];
	if (ret != -1) return ret;
	ret = 0;
	for (int next = 0; next < n; ++next) {
		if ((taken & (1 << next)) == 0) {
			// 과거 가격은 새 가격보다 항상 작다
			if (!less && curPrice[index] < digits[next]) {
				continue;
			}
			// 같은 숫자는 한번만 선택한다.
			if (next > 0 && digits[next - 1] == digits[next] &&
				(taken & (1 << (next - 1))) == 0) {
				continue;
			}
			int nextTaken = taken | (1 << next);
			int nextMod = (mod * 10 + digits[next] - '0') % m;
			int nextLess = less || curPrice[index] > digits[next];
			ret += price(index + 1, nextTaken, nextMod, nextLess);
			ret %= MOD;
		}
	}
	return ret;
}

int ZIM_main() {
	int C;
	cin >> C;
	while (C--) {
		cin >> curPrice >> m;
		n = curPrice.size();
		digits = curPrice;
		sort(digits.begin(), digits.end());
		memset(cache, -1, sizeof(cache));
		cout << price(0, 0, 0, 0) << "\n";
	}
	return 0;
}