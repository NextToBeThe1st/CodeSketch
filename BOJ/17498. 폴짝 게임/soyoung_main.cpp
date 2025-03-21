#include <bits/stdc++.h>
using namespace std;

int N, M, D;  // 행의 개수, 열의 개수, 최대 점프 거리 정수
vector<vector<long long>> inputLine; // DP 테이블
vector<vector<long long>> a; // 입력값

void solution();
void inputData();
long long getMax(int i, int j);

int main() {
    inputData();
    solution();
    long long maxVal = *max_element(inputLine[N - 1].begin(), inputLine[N - 1].begin() + M);
    cout << maxVal << endl;
    return 0;
}

long long getMax(int i, int j) {
    long long maxVal = LLONG_MIN;
    for (int k = max(0, i - D); k < i; ++k) {
        int l_min = max(0, j - D);
        int l_max = min(M - 1, j + D);
        for (int l = l_min; l <= l_max; ++l) {
            if (abs(i - k) + abs(j - l) <= D) {
                if (inputLine[k][l] != LLONG_MIN) {
                    maxVal = max(maxVal, inputLine[k][l] + (long long)a[k][l] * a[i][j]);
                }
            }
        }
    }
    return maxVal;
}

void solution() {
    for (int j = 0; j < M; ++j) {
        inputLine[0][j] = 0;
    }
    for (int i = 1; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            inputLine[i][j] = getMax(i, j);
        }
    }
}

void inputData() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M >> D;
    inputLine = vector<vector<long long>>(N, vector<long long>(M, LLONG_MIN));
    a = vector<vector<long long>>(N, vector<long long>(M));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cin >> a[i][j];
        }
    }
}