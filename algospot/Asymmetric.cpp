//#include <iostream>
//#include <cstring>
//#include <algorithm>
//
//using namespace std;
//
//const int BigNum = 1000000007;
//
//int cache[101];
//int tiling(int width) {
//	//기저 : 너비가 1일때
//	if (width <= 1) return 1;
//	//메모이제이션
//	int& ret = cache[width];
//	if (ret != -1) return ret;
//	return ret = (tiling(width - 2) + tiling(width - 1)) % BigNum;
//}
//
//// 2 * n 사각형을 비대칭으로 채우는 경우의 수
//int asymmetric(int width) {
//	//너비가 홀수일 때
//	if (width % 2 == 1) {
//		return (tiling(width) - tiling(width / 2) + BigNum) % BigNum;
//	}
//	// 사각형을 채우는 모든 경우의 수에서 대칭인만큼 빼기
//	int ret = tiling(width);
//	ret = (ret - tiling(width / 2) + BigNum) % BigNum;
//	ret = (ret - tiling(width / 2 - 1) + BigNum) % BigNum;
//	return ret;
//}
//
//int Asym_main() {
//	int C;
//	cin >> C;
//	while (C--) {
//		int width;
//		cin >> width;
//		memset(cache, -1, sizeof(cache));
//		int result = asymmetric(width);
//		cout << result << "\n";
//	}
//	return 0;
//}