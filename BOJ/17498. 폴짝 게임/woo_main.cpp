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
    dp.resize(N, vector<long long>(M, LLONG_MIN)); // 음수 곱하는 경우 감안

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cin >> grid[i][j];
        }
    }
}

long long getMax(int i, int j) { //DP 갱신을 위한 최대값 탐색
    long long maxVal = LLONG_MIN;

    for (int k = max(0, i - D); k < i; ++k) {
        int l_min = max(0, j - D);
        int l_max = min(M - 1, j + D);

        for (int l = l_min; l <= l_max; ++l) {
            if (abs(i - k) + abs(j - l) <= D) {
                if (dp[k][l] != LLONG_MIN) { // 초기화 상태의 값이 아닌지 검증
                    maxVal = max(maxVal, dp[k][l] + grid[k][l] * grid[i][j]);
                }
            }
        }
    }
    return maxVal;
}

void solution() {
    for (int j = 0; j < M; ++j) {
        dp[0][j] = 0; // 첫 번째 행은 항상 0으로 초기화
    }

    for (int i = 1; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            dp[i][j] = getMax(i, j); //(i, j)로 이동할 수 있는 모든 (k, l) 탐색
        }
    }

    long long maxScore = LLONG_MIN;
    for (int j = 0; j < M; ++j) {
        maxScore = max(maxScore, dp[N - 1][j]);
    }

    cout << maxScore << "\n";
}

int main() {
    ios::sync_with_stdio(false); //정빈
    cin.tie(nullptr);

    input();
    solution();

    return 0;
}