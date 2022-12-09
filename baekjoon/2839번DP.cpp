#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int cache[5001];

int delivery(int kg) {
	//기저 : 5kg가방과 3kg가방이 알맞게 들어가면 반환, 초과하면 매우큰수 반환
	if (kg < 0) return 1e9;
	if (kg == 0) return 0;
	//메모이제이션
	int& ret = cache[kg];
	if (ret != -1) return ret;
	//가방이 알맞게 들어갈때 마다 +1해서 가방개수를 늘림
	return ret = min(delivery(kg - 5) + 1, delivery(kg - 3) + 1);
}

int main() {
	int n;
	cin >> n;
	memset(cache, -1, sizeof(cache));
	int result = delivery(n);
	if (result >= 1e9) cout << "-1";
	else cout << result;
	return 0;
}