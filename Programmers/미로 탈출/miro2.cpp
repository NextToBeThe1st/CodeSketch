#include <string>
#include <vector>
#include <queue>
#include <tuple>
#include <iostream>

using namespace std;
char arr[104][104];
int visited[104][104];
int dy[] = { -1,0,1,0 };
int dx[] = { 0,1,0,-1 };

pair<int, int> st, ex, la;
int size_y, size_x;
int bfs(int y, int x, char c) {
    queue<pair<int, int>> q;
    q.push({ y,x });
    visited[y][x] = 1;
    while (q.size()) {
        tie(y, x) = q.front();
        q.pop();
        if (arr[y][x] == c) return visited[y][x] - 1;
        for (int i = 0;i < 4;i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (ny < 0 || nx < 0 || ny >= size_y || nx >= size_x) continue;
            if (visited[ny][nx] != 0 || arr[ny][nx] == 'X') continue;
            visited[ny][nx] = visited[y][x] + 1;
            q.push({ ny,nx });
        }
    }
    return -1;
}

void showInfo() {
    for (int i = 0;i < size_y;i++) {
        for (int j = 0;j < size_x;j++) {
            cout << visited[i][j] << ' ';
        }cout << '\n';
    }
}

int solution(vector<string> maps) {
    int answer = 0;

    for (int j = 0;j < maps.size();j++) {
        for (int i = 0;i < maps[0].length();i++) {
            arr[j][i] = maps[j][i];
            if (arr[j][i] == 'S') st = { j,i };
            else if (arr[j][i] == 'E') ex = { j,i };
            else if (arr[j][i] == 'L') la = { j,i };
        }
    }

    size_y = maps.size();
    size_x = maps[0].length();
    int l = bfs(st.first, st.second, 'L');
    int e = 0;
    if (l == -1) return -1;
    else {
        answer += l;
        showInfo();
        cout << "==============\n";
        fill(&visited[0][0], &visited[0][0] + 104 * 104, 0);
        e = bfs(la.first, la.second, 'E');
        if (e == -1) {
            return -1;
        }
        else {
            showInfo();
            answer += visited[ex.first][ex.second];
        }
    }
    // cout<<"st : "<<st.first << ", "<< st.second<<'\n';
    // cout<<"la : "<<la.first << ", "<< la.second<<'\n';
    // cout<<"ex : "<<ex.first << ", "<< ex.second<<'\n';

    return l + e;
}