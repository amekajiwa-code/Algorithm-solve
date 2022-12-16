//#include <iostream>
//#include <algorithm>
//#include <cstring>
//
//using namespace std;
//
//const int EMPTY = -987654321;
//int n, board[50];
//int cache[50][50];
//int play(int left, int right) {
//	//기저
//	if (left > right) return 0;
//	int& ret = cache[left][right];
//	if (ret != EMPTY) return ret;
//	// 수를 가져가는 경우
//	ret = max(board[left] - play(left + 1, right),
//		board[right] - play(left, right - 1));
//	// 수를 없애는 경우
//	if (right - left + 1 >= 2) {
//		ret = max(ret, -play(left + 2, right));
//		ret = max(ret, -play(left, right - 2));
//	}
//	return ret;
//}
//
//int numbergame_main() {
//	int C;
//	cin >> C;
//	while (C--) {
//		cin >> n;
//		for (int i = 0; i < n; ++i) {
//			for (int j = 0; j < n; ++j) {
//				cache[i][j] = EMPTY;
//			}
//		}
//		for (int i = 0; i < n; ++i) {
//			cin >> board[i];
//		}
//		int result = play(0, n - 1);
//		cout << result << "\n";
//	}
//	return 0;
//}