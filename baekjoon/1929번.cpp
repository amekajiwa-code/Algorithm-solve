#include <iostream>

using namespace std;

namespace solution1929 {
	void MyCode() {
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);
		int m, n;
		cin >> m >> n;
		int* primeNumbers = new int[n + 1];

		//배열 초기화
		for (int i = 0; i <= n; ++i) {
			primeNumbers[i] = i;
		}
		primeNumbers[0] = 0;
		primeNumbers[1] = 0;

		//소수 판별
		for (int i = 2; i <= n; i++)
		{
			for (int j = 2 * i; j <= n; j += i) { // 2와 3의 배수 걸러내기
				primeNumbers[j] = 0;
			}
		}

		//소수 출력
		for (int i = m; i <= n; i++)
		{
			if (primeNumbers[i] != 0)
				cout << primeNumbers[i] << "\n";
		}
		delete[] primeNumbers;
	}
}