#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <tuple>
using namespace std;

struct State {
    pair<int, int> p1, p2;
    int time;
};

// 해당 좌표가 유효한지
bool isValid(pair<int, int> p, const vector<vector<int>>& board) {
    int n = board.size();
    return p.first >= 0 && p.second >= 0 && p.first < n && p.second < n && board[p.first][p.second] == 0;
}

// 중복확인/큐에 push
void tryPush(set<tuple<int, int, int, int>>& visited, queue<State>& q, pair<int, int> np1, pair<int, int> np2, int time) {
    auto key = make_tuple(np1.first, np1.second, np2.first, np2.second);
    auto keyRev = make_tuple(np2.first, np2.second, np1.first, np1.second);
    // (np1, np2)와 (np2, np1)을 동일한 상태로 간주
    if (visited.count(key) == 0 && visited.count(keyRev) == 0) {
        visited.insert(key); // 큐에 넣기 전에 방문 처리
        q.push({ np1, np2, time });
    }
}

// 현재 상태에서 가능한 회전 동작 수행
void tryRotate(const pair<int, int>& p1, const pair<int, int>& p2, int time, set<tuple<int, int, int, int>>& visited, queue<State>& q, const vector<vector<int>>& board) {
    int n = board.size();
    // 가로 상태일 경우
    if (p1.first == p2.first) {
        for (int d : {-1, 1}) {
            int ny = p1.first + d;
            // 회전 시 대각선 2칸 모두 비어 있어야 함
            if (ny >= 0 && ny < n && board[ny][p1.second] == 0 && board[ny][p2.second] == 0) {
                // 왼쪽 축 기준 회전
                tryPush(visited, q, { p1.first, p1.second }, { ny, p1.second }, time + 1);
                // 오른쪽 축 기준 회전
                tryPush(visited, q, { p2.first, p2.second }, { ny, p2.second }, time + 1);
            }
        }
    }
    // 세로 상태일 경우
    else if (p1.second == p2.second) {
        for (int d : {-1, 1}) {
            int nx = p1.second + d;
            // 회전 시 대각선 2칸 모두 비어 있어야 함
            if (nx >= 0 && nx < n && board[p1.first][nx] == 0 && board[p2.first][nx] == 0) {
                // 위쪽 축 기준 회전
                tryPush(visited, q, { p1.first, p1.second }, { p1.first, nx }, time + 1);
                // 아래쪽 축 기준 회전
                tryPush(visited, q, { p2.first, p2.second }, { p2.first, nx }, time + 1);
            }
        }
    }
}

// 메인 로직: 최소 시간 계산
int solution(vector<vector<int>> board) {
    int n = board.size();
    set<tuple<int, int, int, int>> visited; // 방문한 상태 저장 (중복 제거용)
    queue<State> q; // BFS 탐색을 위한 큐

    // 초기 상태: 로봇은 (0,0)과 (0,1)에 가로로 위치
    pair<int, int> start1 = { 0, 0 };
    pair<int, int> start2 = { 0, 1 };

    q.push({ start1, start2, 0 });
    visited.insert({ 0, 0, 0, 1 }); // 시작 상태도 방문 처리

    int dy[] = { -1, 1, 0, 0 };
    int dx[] = { 0, 0, -1, 1 };

    while (!q.empty()) {
        auto [p1, p2, t] = q.front(); q.pop();

        // 종료 조건
        if (p1 == make_pair(n - 1, n - 1) || p2 == make_pair(n - 1, n - 1)) {
            return t;
        }

        // 1. 상하좌우 이동
        for (int i = 0; i < 4; ++i) {
            pair<int, int> np1 = { p1.first + dy[i], p1.second + dx[i] };
            pair<int, int> np2 = { p2.first + dy[i], p2.second + dx[i] };

            if (isValid(np1, board) && isValid(np2, board)) {
                tryPush(visited, q, np1, np2, t + 1);
            }
        }

        // 2. 회전
        tryRotate(p1, p2, t, visited, q, board);
    }

    return -1; // 도달 불가
}