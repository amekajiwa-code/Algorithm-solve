//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//bool mates[10][10];
//// 친구인 애들끼리만 앉을 경우의 수
//int match(int n, bool studentsNumber[10]) {
//	//남은 학생중 가장 빠른 번호 찾기
//	int firstFree = -1;
//	for (int i = 0; i < n; ++i) {
//		if (!studentsNumber[i]) {
//			firstFree = i;
//			break;
//		}
//	}
//	//기저
//	if (firstFree == -1) {
//		return 1;
//	}
//	int ret = 0;
//	//짝꿍 한명씩 친구인지 아닌지 판별
//	for (int pairWith = firstFree + 1; pairWith < n; ++pairWith) {
//		// 짝꿍이 짝이 없으면서 둘이 친구인지 확인
//		if (!studentsNumber[pairWith] && mates[firstFree][pairWith]) {
//			//짝이 있음을 표시
//			studentsNumber[firstFree] = studentsNumber[pairWith] = true;
//			//재귀함수 : 남은 사람끼리 짝이 있는지 확인하고 돌아옴
//			ret += match(n, studentsNumber);
//			//초기화
//			studentsNumber[firstFree] = studentsNumber[pairWith] = false;
//		}
//	}
//}
//
//int picnic_main() {
//	int C;
//	cin >> C;
//	for (int i = 0; i < C; ++i) {
//		int n, m;
//		cin >> n >> m;
//		bool studentsNumber[10];
//		for (int j = 0; j < m; ++j) {
//			int mateA, mateB;
//			cin >> mateA >> mateB;
//			mates[mateA][mateB] = true;
//		}
//		cout << "입력완료\n";
//		//함수시작
//		cout << match(n, studentsNumber);
//	}
//	return 0;
//}