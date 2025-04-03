#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

const int dx[4] = { 1, -1, 0, 0 };
const int dy[4] = { 0, 0, -1, 1 };
int col, row;

void findPoint(vector<string> maps, pair<int, int>& lever, pair<int, int>& startPoint, pair<int, int>& endPoint) {
    for (int i = 0; i < maps.size(); ++i) {
        for (int j = 0; j < maps[i].size(); ++j) {
            if (maps[i][j] == 'L') { lever = { i, j }; }
            if (maps[i][j] == 'S') { startPoint = { i, j }; }
            if (maps[i][j] == 'E') { endPoint = { i, j }; }
        }
    }
}

bool inRange(int x, int y) {
    return (0 <= x && x < col && 0 <= y && y < row);
}

int bfs(pair<int, int> stPos, pair<int, int>destPos, vector<string> maps) {
    int dist = INT32_MAX;
    bool visited[101][101] = { false };
    queue<pair<pair<int, int>, int>> q;
    q.push({ stPos, 0 });
    while (!q.empty()) {
        pair<pair<int, int>, int> cur = q.front();
        q.pop();
        if (cur.first == destPos) {
            return cur.second;
        }
        for (int i = 0; i < 4; ++i) {
            int nx = cur.first.first + dx[i];
            int ny = cur.first.second + dy[i];
            if (inRange(nx, ny) && maps[nx][ny] != 'X' && !visited[nx][ny]) {
                visited[nx][ny] = true;
                q.push({ {nx, ny}, cur.second + 1 });
            }
        }

    }
    return -1;
}

int solution(vector<string> maps) {
    pair<int, int> lever;
    pair<int, int> startPoint;
    pair<int, int> endPoint;
    int answer = 0;
    col = maps.size();
    row = maps[0].size();
    findPoint(maps, lever, startPoint, endPoint);
    int stol = bfs(startPoint, lever, maps);
    int ltoe = bfs(lever, endPoint, maps);
    if (stol < 0 || ltoe < 0) {
        return -1;
    }
    return stol + ltoe;
}