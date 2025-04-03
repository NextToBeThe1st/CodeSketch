#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<string> maps;
vector<pair<int, int>> directions = { {1,0},{-1,0},{0,1},{0,-1} };

int bfs(pair<int, int> start, pair<int, int> end) {
    queue<pair<int, int>> q;
    vector<vector<int>> visited(n, vector<int>(m, -1));

    q.push(start);
    visited[start.first][start.second] = 0;

    while (!q.empty()) {
        auto [x, y] = q.front(); q.pop();

        if (x == end.first && y == end.second)
            return visited[x][y];

        for (auto [dx, dy] : directions) {
            int nx = x + dx;
            int ny = y + dy;

            if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
            if (visited[nx][ny] != -1 || maps[nx][ny] == 'X') continue;

            visited[nx][ny] = visited[x][y] + 1;
            q.push({ nx,ny });
        }
    }
    return -1;
}

//도달 여부 선필터링
bool isReachable(pair<int, int> start, pair<int, int> end) {
    queue<pair<int, int>> q;
    vector<vector<bool>> visited(n, vector<bool>(m, false));

    q.push(start);
    visited[start.first][start.second] = true;

    while (!q.empty()) {
        auto [x, y] = q.front(); q.pop();
        if (make_pair(x, y) == end) return true;

        for (auto [dx, dy] : directions) {
            int nx = x + dx;
            int ny = y + dy;
            if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
            if (visited[nx][ny] || maps[nx][ny] == 'X') continue;
            visited[nx][ny] = true;
            q.push({ nx,ny });
        }
    }
    return false;
}

//도달 여부 선필터링2
bool isTrapped(pair<int, int> pos) {
    int x = pos.first;
    int y = pos.second;
    for (auto [dx, dy] : directions) {
        int nx = x + dx;
        int ny = y + dy;
        if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
        if (maps[nx][ny] != 'X') return false; // 이동 가능한 방향 있음
    }
    return true; // 4방향 다 벽 or 막힘
}

int solution(vector<string> input_maps) {
    maps = input_maps;
    n = maps.size();
    m = maps[0].size();

    pair<int, int> start, lever, exit;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (maps[i][j] == 'S') start = { i,j };
            else if (maps[i][j] == 'L') lever = { i,j };
            else if (maps[i][j] == 'E') exit = { i,j };
        }
    }
    //if(!isReachable(start, lever) || !isReachable(lever, exit)) return -1;
    if (isTrapped(lever) || isTrapped(exit)) return -1;


    int toLever = bfs(start, lever);   // -1
    int toExit = bfs(lever, exit);
    if (toLever != -1 && toExit != -1) return toLever + toExit;
    else return -1;
}

//Test code
/*int main(){
    vector<string> maps1 = {"SOOOL","XXXXO","OOOOO","OXXXX","OOOOE"};
    vector<string> maps2 = {"LOOXS","OOOOX","OOOOO","OOOOO","EOOOO"};

    cout << solution(maps1) << "\n";
    cout << solution(maps2) << "\n";
}*/