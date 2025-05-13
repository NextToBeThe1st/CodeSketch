#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>

using namespace std;

int N;
vector<int> A;
int ops[4]; // +, -, *, /
int min_result = INT_MAX;
int max_result = INT_MIN;

// 연산 처리 함수
int calc(int a, int b, int op) {
    switch (op) {
    case 0: return a + b;
    case 1: return a - b;
    case 2: return a * b;
    case 3:
        if (a < 0) return -(-a / b);  // C++14식 음수 나눗셈 처리
        else return a / b;
    }
    return 0;
}

void dfs(int depth, int value) {
    if (depth == N) {
        min_result = min(min_result, value);
        max_result = max(max_result, value);
        return;
    }

    for (int i = 0; i < 4; ++i) {
        if (ops[i] > 0) {
            ops[i]--;
            dfs(depth + 1, calc(value, A[depth], i));
            ops[i]++;
        }
    }
}

int main() {
    cin >> N;
    A.resize(N);
    for (int i = 0; i < N; ++i) cin >> A[i];
    for (int i = 0; i < 4; ++i) cin >> ops[i];

    dfs(1, A[0]);

    cout << max_result << "\n" << min_result << "\n";
    return 0;
}