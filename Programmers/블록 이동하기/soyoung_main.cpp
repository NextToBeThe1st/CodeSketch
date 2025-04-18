#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <set>

using namespace std;

const int dx[4] = { -1, 1, 0, 0 };
const int dy[4] = { 0, 0, -1, 1 };
const int nx[2] = { 1, -1 };
int N = 0;

struct Robot {
    pair<int, int> a;
    pair<int, int> b;
    Robot(pair<int, int> a, pair<int, int> b) {
        if (a < b) {
            this->a = a;
            this->b = b;
        }
        else {
            this->a = b;
            this->b = a;
        }
    }
    bool operator<(const Robot& other) const {
        if (a != other.a) return a < other.a;
        return b < other.b;
    }
};

bool isInRange(int x, int y) {
    return 0 <= x && x < N && 0 <= y && y < N;
}

int solution(vector<vector<int>> board) {
    int answer = INT32_MAX;
    Robot robot = Robot({ 0, 0 }, { 0, 1 });
    set<Robot> visited;
    N = board.size();
    pair<int, int> target = { N - 1, N - 1 };
    queue<pair<Robot, int>> q;
    q.push({ robot, 0 });
    while (!q.empty()) {
        pair<Robot, int> cur = q.front();
        Robot r = cur.first;
        q.pop();
        // 만약 로봇이 지나간 시간이 answer보다 크다면 pass
        if (cur.first.a == target || cur.first.b == target) {
            answer = cur.second;
        }
        if (cur.second > answer) continue;
        // 로봇이 지나갈 수 있는 모든 경우의 수를 구한다.
        for (int i = 0; i < 4; ++i) {
            pair<int, int> a = { r.a.first + dx[i], r.a.second + dy[i] };
            pair<int, int> b = { r.b.first + dx[i], r.b.second + dy[i] };
            if (isInRange(a.first, a.second) && isInRange(b.first, b.second) && board[a.first][a.second] == 0 && board[b.first][b.second] == 0 && visited.count(Robot(a, b)) == 0) {
                visited.insert(Robot(a, b));
                q.push({ Robot(a, b), cur.second + 1 });
            }
        }
        if (r.a.first == r.b.first) { // 수평 상태
            for (int d : {-1, 1}) { // 위 또는 아래로 회전
                int x = r.a.first;
                int y1 = r.a.second;
                int y2 = r.b.second;
                int nx = x + d;
                if (isInRange(nx, y1) && isInRange(nx, y2) &&
                    board[nx][y1] == 0 && board[nx][y2] == 0) {

                    // r.a를 축으로 회전
                    Robot next1(r.a, { r.a.first + d, r.a.second });
                    if (!visited.count(next1)) {
                        visited.insert(next1);
                        q.push({ next1, cur.second + 1 });
                    }

                    // r.b를 축으로 회전
                    Robot next2(r.b, { r.b.first + d, r.b.second });
                    if (!visited.count(next2)) {
                        visited.insert(next2);
                        q.push({ next2, cur.second + 1 });
                    }
                }
            }
        }
        else { // 수직 상태
            for (int d : {-1, 1}) {
                int y = r.a.second;
                int x1 = r.a.first;
                int x2 = r.b.first;
                int ny = y + d;
                if (isInRange(x1, ny) && isInRange(x2, ny) &&
                    board[x1][ny] == 0 && board[x2][ny] == 0) {

                    Robot next1(r.a, { r.a.first, r.a.second + d });
                    if (!visited.count(next1)) {
                        visited.insert(next1);
                        q.push({ next1, cur.second + 1 });
                    }

                    Robot next2(r.b, { r.b.first, r.b.second + d });
                    if (!visited.count(next2)) {
                        visited.insert(next2);
                        q.push({ next2, cur.second + 1 });
                    }
                }
            }
        }

    }

    return answer;
}
int main() {
    vector<vector<int>> board; //= { {0,0,0,1,1},{0,0,0,1,0},{0,1,0,1,1},{1,1,0,0,1},{0,0,0,0,0} };
    board.resize(5);
    for (int i = 0; i < 5; ++i) {
        board[i].resize(5);
        for (int j = 0; j < 5; ++j) {
            cin >> board[i][j];
        }
    }
    cout << solution(board) << endl;
}