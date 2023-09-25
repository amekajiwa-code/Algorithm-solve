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
	//��� ������
	if (piece == string(piece.size(), piece[0])) return 1;
	//1�� �����Ҷ�
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
	//���ڰ� ������ ���鼭 ���ö�
	bool inturn = true;
	for (int i = 0; i < piece.size(); ++i)
	{
		if (piece[i] != piece[i % 2])
		{
			inturn = false;
		}
	}
	if (inturn) return 4;
	//���������϶�
	if (progressive) return 5;
	//�׿��϶�
	return 10;
}

int PI(int begin)
{
	//����
	if (begin == inputText.size()) return 0;
	//�޸������̼�
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

//��� ��츦 ��ȸ�Ͽ� ���̵��� ���Ѵ�
//�� �� ���̵��� ������ ����
//�̹� ���� ��� �޸������̼����� ����