#include <string>
#include <vector>
#include <queue>

using namespace std;

typedef struct Node {
    int ly, lx, ry, rx;
} node;

int n, mn = INT32_MAX;
int map[104][104];
bool visited[104][104][104][104];

int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, 1, 0, -1 };

int offset[] = { -1, 1 };

bool isValid(int y, int x) {
    return (y >= 0 && x >= 0 && y < n && x < n && map[y][x] == 0);
}

bool isInRange(node p) {
    return isValid(p.ly, p.lx) && isValid(p.ry, p.rx);
}

void bfs() {
    queue<pair<node, int>> q;
    q.push({ {0, 0, 0, 1}, 0 });
    visited[0][0][0][1] = true;

    while (!q.empty()) {
        node p = q.front().first;
        int sec = q.front().second;
        q.pop();

        if ((p.ly == n - 1 && p.lx == n - 1) || (p.ry == n - 1 && p.rx == n - 1)) {
            mn = min(mn, sec);
            return;
        }

        for (int i = 0; i < 4; i++) {
            int nly = p.ly + dy[i];
            int nlx = p.lx + dx[i];
            int nry = p.ry + dy[i];
            int nrx = p.rx + dx[i];
            node nextP = { nly, nlx, nry, nrx };
            if (isValid(nextP.ly, nextP.lx) && isValid(nextP.ry, nextP.rx) && !visited[nly][nlx][nry][nrx]) {
                visited[nly][nlx][nry][nrx] = true;
                q.push({ nextP, sec + 1 });
            }
        }

        // 가로 → 세로 회전
        if (p.ly == p.ry) {
            for (int i = 0; i < 2; i++) {
                int ny = p.ly + offset[i];
                if (!isValid(ny, p.lx) || !isValid(ny, p.rx)) continue;

                node roll1 = { p.ly, p.lx, ny, p.lx };
                if (!visited[roll1.ly][roll1.lx][roll1.ry][roll1.rx]) {
                    visited[roll1.ly][roll1.lx][roll1.ry][roll1.rx] = true;
                    q.push({ roll1, sec + 1 });
                }

                node roll2 = { p.ry, p.rx, ny, p.rx };
                if (!visited[roll2.ly][roll2.lx][roll2.ry][roll2.rx]) {
                    visited[roll2.ly][roll2.lx][roll2.ry][roll2.rx] = true;
                    q.push({ roll2, sec + 1 });
                }
            }
        }

        // 세로 → 가로 회전
        else if (p.lx == p.rx) {
            for (int i = 0; i < 2; i++) {
                int nx = p.lx + offset[i];
                if (!isValid(p.ly, nx) || !isValid(p.ry, nx)) continue;

                node roll1 = { p.ly, p.lx, p.ly, nx };
                if (!visited[roll1.ly][roll1.lx][roll1.ry][roll1.rx]) {
                    visited[roll1.ly][roll1.lx][roll1.ry][roll1.rx] = true;
                    q.push({ roll1, sec + 1 });
                }

                node roll2 = { p.ry, p.rx, p.ry, nx };
                if (!visited[roll2.ly][roll2.lx][roll2.ry][roll2.rx]) {
                    visited[roll2.ly][roll2.lx][roll2.ry][roll2.rx] = true;
                    q.push({ roll2, sec + 1 });
                }
            }
        }
    }
}

int solution(vector<vector<int>> board) {
    n = board.size();
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            map[i][j] = board[i][j];

    bfs();
    return mn;
}