//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//bool mates[10][10];
//// ģ���� �ֵ鳢���� ���� ����� ��
//int match(int n, bool studentsNumber[10]) {
//	//���� �л��� ���� ���� ��ȣ ã��
//	int firstFree = -1;
//	for (int i = 0; i < n; ++i) {
//		if (!studentsNumber[i]) {
//			firstFree = i;
//			break;
//		}
//	}
//	//����
//	if (firstFree == -1) {
//		return 1;
//	}
//	int ret = 0;
//	//¦�� �Ѹ� ģ������ �ƴ��� �Ǻ�
//	for (int pairWith = firstFree + 1; pairWith < n; ++pairWith) {
//		// ¦���� ¦�� �����鼭 ���� ģ������ Ȯ��
//		if (!studentsNumber[pairWith] && mates[firstFree][pairWith]) {
//			//¦�� ������ ǥ��
//			studentsNumber[firstFree] = studentsNumber[pairWith] = true;
//			//����Լ� : ���� ������� ¦�� �ִ��� Ȯ���ϰ� ���ƿ�
//			ret += match(n, studentsNumber);
//			//�ʱ�ȭ
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
//		cout << "�Է¿Ϸ�\n";
//		//�Լ�����
//		cout << match(n, studentsNumber);
//	}
//	return 0;
//}