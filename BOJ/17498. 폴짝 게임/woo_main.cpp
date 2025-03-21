#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int N, M, D;
vector<vector<long long>> grid;
vector<vector<long long>> dp;

void input() {
    cin >> N >> M >> D;
    grid.resize(N, vector<long long>(M));
    dp.resize(N, vector<long long>(M, LLONG_MIN)); // ���� ���ϴ� ��� ����

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cin >> grid[i][j];
        }
    }
}

long long getMax(int i, int j) { //DP ������ ���� �ִ밪 Ž��
    long long maxVal = LLONG_MIN;

    for (int k = max(0, i - D); k < i; ++k) {
        int l_min = max(0, j - D);
        int l_max = min(M - 1, j + D);

        for (int l = l_min; l <= l_max; ++l) {
            if (abs(i - k) + abs(j - l) <= D) {
                if (dp[k][l] != LLONG_MIN) { // �ʱ�ȭ ������ ���� �ƴ��� ����
                    maxVal = max(maxVal, dp[k][l] + grid[k][l] * grid[i][j]);
                }
            }
        }
    }
    return maxVal;
}

void solution() {
    for (int j = 0; j < M; ++j) {
        dp[0][j] = 0; // ù ��° ���� �׻� 0���� �ʱ�ȭ
    }

    for (int i = 1; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            dp[i][j] = getMax(i, j); //(i, j)�� �̵��� �� �ִ� ��� (k, l) Ž��
        }
    }

    long long maxScore = LLONG_MIN;
    for (int j = 0; j < M; ++j) {
        maxScore = max(maxScore, dp[N - 1][j]);
    }

    cout << maxScore << "\n";
}

int main() {
    ios::sync_with_stdio(false); //����
    cin.tie(nullptr);

    input();
    solution();

    return 0;
}