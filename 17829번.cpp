//#include <iostream>
//#include <vector>
//#include <algorithm>
//
//using namespace std;
//
//int secondMax(vector<int> vector) {
//	int max = -10001;
//	int second = -10001;
//	for (int i = 0; i < vector.size(); ++i) {
//		if (max < vector[i]) {
//			second = max;
//			max = vector[i];
//		}
//		else if (second < vector[i]) {
//			second = vector[i];
//		}
//	}
//	return second;
//}
//
////4분할된 정사각형에서 2번째로 큰 수 받기 재귀
////분할된 정사각형에서 분할안될때까지 계속 쪼개다 답 배출함
//int pooling(vector<vector <int>>& board, int startY, int startX, int size) {
//	if (startY >= board.size() || startX >= board.size()) {
//		return -10001;
//	}
//	if (size == 2) {
//		vector<int> poolVec;
//		for (int i = 0; i < 2; ++i) {
//			for (int j = 0; j < 2; ++j) {
//				poolVec.push_back(board[startY + i][startX + j]);
//			}
//		}
//		return secondMax(poolVec);
//	}
//
//	int nSize = size / 2;
//	int ret = 0;
//	vector<int> retVec;
//	//왼쪽위
//	ret = pooling(board, startY, startX, nSize);
//	retVec.push_back(ret);
//	//오른쪽위
//	ret = pooling(board, startY, startX + nSize, nSize);
//	retVec.push_back(ret);
//	//왼쪽아래
//	ret = pooling(board, startY + nSize, startX, nSize);
//	retVec.push_back(ret);
//	//오른쪽아래
//	ret = pooling(board, startY + nSize, startX + nSize, nSize);
//	retVec.push_back(ret);
//
//	ret = secondMax(retVec);
//	return ret;
//}
//
//int main17829() {
//	int N;
//	cin >> N;
//	vector <vector <int>> board(N, vector <int>(N));
//	for (int i = 0; i < N; ++i) {
//		for (int j = 0; j < N; ++j) {
//			cin >> board[i][j];
//		}
//	}
//	cout << pooling(board, 0, 0, N) << "\n";
//	return 0;
//}