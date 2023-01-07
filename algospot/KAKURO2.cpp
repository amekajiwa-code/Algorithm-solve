#include <iostream>
#include <algorithm>
#include <bitset>
#include <cstring>

using namespace std;

const int MAX = 20;

int candidates[10][46][1024];

int N, color[MAX][MAX], value[MAX][MAX], hint[MAX][MAX][2];

int hintNum, sum[MAX * MAX], length[MAX * MAX], known[MAX * MAX];

void put(int y, int x, int val) {
    for (int i = 0; i < 2; i++) {
        known[hint[y][x][i]] += (1 << val);
    }
    value[y][x] = val;
}

void remove(int y, int x, int val) {
    for (int i = 0; i < 2; i++) {
        known[hint[y][x][i]] -= (1 << val);
    }
    value[y][x] = 0;
}

int getCandHint(int hint) {
    return candidates[length[hint]][sum[hint]][known[hint]];
}

int getCandCoord(int y, int x) {
    return getCandHint(hint[y][x][0]) & getCandHint(hint[y][x][1]);
}

int getSize(int mask)
{
    int num = 0, compare = 1;
    for (int i = 1; i <= 9; ++i) {
        compare = compare << 1;
        if (compare & mask) num++;
    }
    return num;
}

int getSum(int mask) {
    int sum = 0, compare = 1;
    for (int i = 1; i <= 9; ++i) {
        compare = compare << 1;
        if (compare & mask) sum += i;
    }
    return sum;
}

void generateCandidates() {
    memset(candidates, 0, sizeof(candidates));
    for (int set = 0; set < 1024; set += 2) {
        int length = getSize(set), sum = getSum(set);
        int subset = set;
        while (1) {
            candidates[length][sum][subset] |= (set & ~subset);
            if (subset == 0) break;
            subset = (subset - 1) & set;
        }
    }
}

void printSolution(void) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << value[i][j] << " ";
        }
        cout << endl;
    }
}

bool search(void) {
    int y = -1, x = -1, minCandidates = 1023;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (color[i][j] == 1 && value[i][j] == 0) {
                int candidate = getCandCoord(i, j);
                if (getSize(minCandidates) > getSize(candidate)) {
                    minCandidates = candidate;
                    y = i, x = j;
                }
            }
        }
    }

    if (minCandidates == 0) {
        return false;
    }

    if (y == -1) {
        printSolution();
        return true;
    }

    for (int val = 1; val <= 9; val++) {
        if (minCandidates & (1 << val)) {
            put(y, x, val);
            if (search()) {
                return true;
            }
            remove(y, x, val);
        }
    }
    return false;
}

int main(void) {
    int test_case;
    cin >> test_case;

    if (test_case < 1 || test_case>50) {
        exit(-1);
    }

    generateCandidates();

    for (int i = 0; i < test_case; i++) {
        memset(color, 0, sizeof(color));
        memset(value, 0, sizeof(value));
        memset(hint, 0, sizeof(hint));
        memset(sum, 0, sizeof(sum));
        memset(length, 0, sizeof(length));
        memset(known, 0, sizeof(known));

        cin >> N;

        if (N<1 || N>MAX) {
            exit(-1);
        }

        for (int j = 0; j < N; j++) {
            for (int k = 0; k < N; k++) {
                cin >> color[j][k];
            }
        }

        cin >> hintNum;

        for (int j = 0; j < hintNum; j++) {
            int y, x, dir, total;
            int moveY, moveX, nextY, nextX;
            int len = 0;
            cin >> y >> x >> dir >> total;
            hint[y - 1][x - 1][dir] = j;
            sum[hint[y - 1][x - 1][dir]] = total;

            if (dir) {
                moveY = 1;
                moveX = 0;
            }

            else {
                moveY = 0;
                moveX = 1;
            }

            nextY = y - 1 + moveY, nextX = x - 1 + moveX;

            while (1) {
                if (!color[nextY][nextX]) {
                    break;
                }
                hint[nextY][nextX][dir] = j;
                len++;
                nextY += moveY;
                nextX += moveX;
            }
            length[hint[y - 1][x - 1][dir]] = len;
        }
        search();
    }
    return 0;
}