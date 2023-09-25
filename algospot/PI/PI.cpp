#include <iostream>
#include <algorithm>
#include <cmath>
#include<memory.h>

using namespace std;

const int INF = 987654321;
string inputText;
int cache[10001];

int LevelCheck(int a, int b)
{
	string piece = inputText.substr(a, b - a + 1);
	//모두 같을때
	if (piece == string(piece.size(), piece[0])) return 1;
	//1씩 증가할때
	bool progressive = true;
	for (int i = 0; i < piece.size() - 1; ++i)
	{
		if (piece[i + 1] - piece[i] != piece[1] - piece[0])
		{
			progressive = false;
		}
	}
	if (progressive && abs(piece[1] - piece[0]) == 1)
	{
		return 2;
	}
	//숫자가 번갈아 가면서 나올때
	bool inturn = true;
	for (int i = 0; i < piece.size(); ++i)
	{
		if (piece[i] != piece[i % 2])
		{
			inturn = false;
		}
	}
	if (inturn) return 4;
	//등차수열일때
	if (progressive) return 5;
	//그외일때
	return 10;
}

int PI(int begin)
{
	//기저
	if (begin == inputText.size()) return 0;
	//메모이제이션
	int& ret = cache[begin];
	if (ret != -1) return ret;
	ret = INF;

	for (int i = 3; i < 6; ++i)
	{
		if (begin + i <= inputText.size())
		{
			ret = min(ret, PI(begin + i) + LevelCheck(begin, begin + i - 1));
		}
	}

	return ret;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int C;
	cin >> C;
	while (C--)
	{
		memset(cache, -1, sizeof(cache));
		cin >> inputText;
		cout << PI(0) << endl;
	}
}

//모든 경우를 순회하여 난이도를 구한다
//그 중 난이도가 작은놈만 배출
//이미 계산된 경우 메모이제이션으로 리턴