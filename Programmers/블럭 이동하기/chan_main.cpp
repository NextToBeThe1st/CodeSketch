#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <set>

using namespace std;

bool is_valid(int i, int j, vector<vector<int>> board) {
    return i >= 0 && i < board.size() && j >= 0 && j < board[0].size() && board[i][j] == 0;
}

int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };

int solution(vector<vector<int>> board) {

    int N = board.size();

    queue< pair<int, int> > queue1;
    queue< pair<int, int> > queue2;
    queue< int > time_queue;

    set< pair< pair<int, int>, pair<int, int> > > Visited;

    queue1.push(make_pair(0, 0));
    queue2.push(make_pair(0, 1));
    time_queue.push(0);

    Visited.insert(make_pair(make_pair(0, 0), make_pair(0, 1)));

    while (!queue1.empty()) {

        pair<int, int> Curr_1 = queue1.front();
        pair<int, int> Curr_2 = queue2.front();
        int time = time_queue.front();

        queue1.pop();
        queue2.pop();
        time_queue.pop();

        int x1 = Curr_1.first;
        int y1 = Curr_1.second;
        int x2 = Curr_2.first;
        int y2 = Curr_2.second;

        if ((x1 == N - 1 && y1 == N - 1) || (x2 == N - 1 && y2 == N - 1)) {
            return time;
        }

        for (int i = 0; i < 4; ++i) {

            int nx1 = x1 + dx[i];
            int ny1 = y1 + dy[i];
            int nx2 = x2 + dx[i];
            int ny2 = y2 + dy[i];

            if (is_valid(nx1, ny1, board) && is_valid(nx2, ny2, board)) {
                pair<int, int> next1 = make_pair(nx1, ny1);
                pair<int, int> next2 = make_pair(nx2, ny2);

                if (Visited.find(make_pair(next1, next2)) == Visited.end()) {
                    Visited.insert(make_pair(next1, next2));
                    queue1.push(next1);
                    queue2.push(next2);
                    time_queue.push(time + 1);
                }
            }
        }

        if (x1 == x2) {
            for (int d = -1; d <= 1; d += 2) {

                if (is_valid(x1 + d, y1, board) && is_valid(x2 + d, y2, board)) {

                    pair<int, int> r1 = make_pair(x1, y1);
                    pair<int, int> r2 = make_pair(x1 + d, y1);

                    if (Visited.find(make_pair(r1, r2)) == Visited.end()) {
                        Visited.insert(make_pair(r1, r2));
                        queue1.push(r1);
                        queue2.push(r2);
                        time_queue.push(time + 1);
                    }

                    r1 = make_pair(x2, y2);
                    r2 = make_pair(x2 + d, y2);

                    if (Visited.find(make_pair(r1, r2)) == Visited.end()) {
                        Visited.insert(make_pair(r1, r2));
                        queue1.push(r1);
                        queue2.push(r2);
                        time_queue.push(time + 1);
                    }
                }
            }
        }

        if (y1 == y2) {
            for (int d = -1; d <= 1; d += 2) {

                if (is_valid(x1, y1 + d, board) && is_valid(x2, y2 + d, board)) {

                    pair<int, int> r1 = make_pair(x1, y1);
                    pair<int, int> r2 = make_pair(x1, y1 + d);

                    if (Visited.find(make_pair(r1, r2)) == Visited.end()) {
                        Visited.insert(make_pair(r1, r2));
                        queue1.push(r1);
                        queue2.push(r2);
                        time_queue.push(time + 1);
                    }

                    r1 = make_pair(x2, y2);
                    r2 = make_pair(x2, y2 + d);

                    if (Visited.find(make_pair(r1, r2)) == Visited.end()) {
                        Visited.insert(make_pair(r1, r2));
                        queue1.push(r1);
                        queue2.push(r2);
                        time_queue.push(time + 1);
                    }
                }
            }
        }
    }
    return -1;
}
