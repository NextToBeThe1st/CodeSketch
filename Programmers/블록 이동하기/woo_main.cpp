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

// �ش� ��ǥ�� ��ȿ����
bool isValid(pair<int, int> p, const vector<vector<int>>& board) {
    int n = board.size();
    return p.first >= 0 && p.second >= 0 && p.first < n && p.second < n && board[p.first][p.second] == 0;
}

// �ߺ�Ȯ��/ť�� push
void tryPush(set<tuple<int, int, int, int>>& visited, queue<State>& q, pair<int, int> np1, pair<int, int> np2, int time) {
    auto key = make_tuple(np1.first, np1.second, np2.first, np2.second);
    auto keyRev = make_tuple(np2.first, np2.second, np1.first, np1.second);
    // (np1, np2)�� (np2, np1)�� ������ ���·� ����
    if (visited.count(key) == 0 && visited.count(keyRev) == 0) {
        visited.insert(key); // ť�� �ֱ� ���� �湮 ó��
        q.push({ np1, np2, time });
    }
}

// ���� ���¿��� ������ ȸ�� ���� ����
void tryRotate(const pair<int, int>& p1, const pair<int, int>& p2, int time, set<tuple<int, int, int, int>>& visited, queue<State>& q, const vector<vector<int>>& board) {
    int n = board.size();
    // ���� ������ ���
    if (p1.first == p2.first) {
        for (int d : {-1, 1}) {
            int ny = p1.first + d;
            // ȸ�� �� �밢�� 2ĭ ��� ��� �־�� ��
            if (ny >= 0 && ny < n && board[ny][p1.second] == 0 && board[ny][p2.second] == 0) {
                // ���� �� ���� ȸ��
                tryPush(visited, q, { p1.first, p1.second }, { ny, p1.second }, time + 1);
                // ������ �� ���� ȸ��
                tryPush(visited, q, { p2.first, p2.second }, { ny, p2.second }, time + 1);
            }
        }
    }
    // ���� ������ ���
    else if (p1.second == p2.second) {
        for (int d : {-1, 1}) {
            int nx = p1.second + d;
            // ȸ�� �� �밢�� 2ĭ ��� ��� �־�� ��
            if (nx >= 0 && nx < n && board[p1.first][nx] == 0 && board[p2.first][nx] == 0) {
                // ���� �� ���� ȸ��
                tryPush(visited, q, { p1.first, p1.second }, { p1.first, nx }, time + 1);
                // �Ʒ��� �� ���� ȸ��
                tryPush(visited, q, { p2.first, p2.second }, { p2.first, nx }, time + 1);
            }
        }
    }
}

// ���� ����: �ּ� �ð� ���
int solution(vector<vector<int>> board) {
    int n = board.size();
    set<tuple<int, int, int, int>> visited; // �湮�� ���� ���� (�ߺ� ���ſ�)
    queue<State> q; // BFS Ž���� ���� ť

    // �ʱ� ����: �κ��� (0,0)�� (0,1)�� ���η� ��ġ
    pair<int, int> start1 = { 0, 0 };
    pair<int, int> start2 = { 0, 1 };

    q.push({ start1, start2, 0 });
    visited.insert({ 0, 0, 0, 1 }); // ���� ���µ� �湮 ó��

    int dy[] = { -1, 1, 0, 0 };
    int dx[] = { 0, 0, -1, 1 };

    while (!q.empty()) {
        auto [p1, p2, t] = q.front(); q.pop();

        // ���� ����
        if (p1 == make_pair(n - 1, n - 1) || p2 == make_pair(n - 1, n - 1)) {
            return t;
        }

        // 1. �����¿� �̵�
        for (int i = 0; i < 4; ++i) {
            pair<int, int> np1 = { p1.first + dy[i], p1.second + dx[i] };
            pair<int, int> np2 = { p2.first + dy[i], p2.second + dx[i] };

            if (isValid(np1, board) && isValid(np2, board)) {
                tryPush(visited, q, np1, np2, t + 1);
            }
        }

        // 2. ȸ��
        tryRotate(p1, p2, t, visited, q, board);
    }

    return -1; // ���� �Ұ�
}