#include <iostream>
#include <vector>
using namespace std;

int M, N;
vector<vector<int>> board;
int answer = 0;

int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };

void dfs(int y, int x) {
    if (y == M - 1 && x == N - 1) {
        answer++;
        return;
    }

    for (int i = 0; i < 4; ++i) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny < 0 || ny >= M || nx < 0 || nx >= N) continue;
        if (board[ny][nx] < board[y][x]) {  // 내리막이면 이동
            dfs(ny, nx);
        }
    }
}

int main() {
    cin >> M >> N;
    board.assign(M, vector<int>(N));
    for (int i = 0; i < M; ++i)
        for (int j = 0; j < N; ++j)
            cin >> board[i][j];

    dfs(0, 0);
    cout << answer << "\n";
    return 0;
}