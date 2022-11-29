#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

vector<int> multiply(const vector<int>& a, const vector<int>& b) {
    vector<int> c(a.size() + b.size() + 1, 0);
    for (int i = 0; i < a.size(); i++)
        for (int j = 0; j < b.size(); j++)
            c[i + j] += (a[i] * b[j]);
    return c;
}

void addTo(vector<int>& a, const vector<int>& b, int k) {
    a.resize(max(a.size(), b.size() + k));
    for (int i = 0; i < b.size(); i++)
        a[i + k] += b[i];
}

void subFrom(vector<int>& a, const vector<int>& b) {
    a.resize(max(a.size(), b.size()) + 1);
    for (int i = 0; i < b.size(); i++)
        a[i] -= b[i];
}

vector<int> karatsuba(const vector<int>& a, const vector<int>& b) {
    int an = a.size(), bn = b.size();
    if (an < bn)
        return karatsuba(b, a);
    if (an == 0 || bn == 0)
        return vector<int>();
    //크기가 작은경우 카라츠바 알고리즘을 사용하지 않고 구한다.
    if (an <= 50)
        return multiply(a, b);

    //a와 b를 절반으로 나눈다.
    int half = an / 2;
    vector<int> a0(a.begin(), a.begin() + half);
    vector<int> a1(a.begin() + half, a.end());
    vector<int> b0(b.begin(), b.begin() + min<int>(bn, half));
    vector<int> b1(b.begin() + min<int>(bn, half), b.end());

    vector<int> z2 = karatsuba(a1, b1);
    vector<int> z0 = karatsuba(a0, b0);

    addTo(a0, a1, 0);
    addTo(b0, b1, 0);

    vector<int> z1 = karatsuba(a0, b0);
    subFrom(z1, z0);
    subFrom(z1, z2);

    vector<int> res;
    addTo(res, z0, 0);
    addTo(res, z1, half);
    addTo(res, z2, half * 2);

    return res;
}

int hugs(const string& members, const string& fans) {
    int N = members.size(), M = fans.size();
    vector<int> A(N), B(M);
    //멤버나 팬이 남자일때 1 대입
    for (int i = 0; i < N; ++i) {
        A[i] = (members[i] == 'M');
    }
    for (int i = 0; i < M; ++i) {
        B[M - i - 1] = (fans[i] == 'M');
    }
    //카라츠바 알고리즘으로 곱셈연산
    vector<int> C = karatsuba(A, B);
    int allHugs = 0;
    //곱결과가 0일때 모두가 포옹을 함
    for (int i = N - 1; i < M; ++i) {
        if (C[i] == 0) {
            ++allHugs;
        }
    }
    return allHugs;
}

int FanMeeting_main() {
    int C;
    cin >> C;
    while (C--) {
        string memberText, fanText;
        cin >> memberText >> fanText;
        int result = hugs(memberText, fanText);
        cout << result << "\n";
    }
    return 0;
}