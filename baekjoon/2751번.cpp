#include "2751��.h"
#include <iostream>
#include <algorithm>

using namespace std;

namespace solution2751 {
	void MyCode() {
		int n;
		cin >> n;
		int *array = new int[n]; // ���� �迭 �Ҵ�

		for (int i = 0; i < n; i++) {
			int temp;
			cin >> temp;
			array[i] = temp;
		}

		sort(array, array + n);
		for (int i = 0; i < n; i++) {
			cout << array[i] << " ";
		}

		delete[] array; // �迭 �Ҵ� ����
	}
}