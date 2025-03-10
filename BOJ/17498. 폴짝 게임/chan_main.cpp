#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M, D;
vector<vector<int>> Map;
vector<vector<int>> dp;

class Point {
public:

    int x, y;
    Point(int x, int y) : x(x), y(y) {}
};

void input() {

    cin >> N >> M >> D;
    Map.resize(N, vector<int>(M));
    dp.resize(N, vector<int>(M, -1e12));

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cin >> Map[i][j];
        }
    }
}

int get_distance(Point p1, Point p2) {

    return abs(p1.x - p2.x) + abs(p1.y - p2.y);
}

void solution() {

    for (int j = 0; j < M; ++j) {

        dp[0][j] = 0;
    }

    for (int curr_i = 1; curr_i < N; ++curr_i) {

        for (int curr_j = 0; curr_j < M; ++curr_j) {

            for (int prev_i = max(0, curr_i - D); prev_i < curr_i; ++prev_i) {

                for (int prev_j = max(0, curr_j - D); prev_j < min(M, curr_j + D + 1); ++prev_j) {

                    Point curr_p(curr_i, curr_j);
                    Point prev_p(prev_i, prev_j);

                    if (get_distance(curr_p, prev_p) <= D) {

                        dp[curr_i][curr_j] = max(dp[curr_i][curr_j], dp[prev_i][prev_j] + Map[curr_i][curr_j] * Map[prev_i][prev_j]);
                    }
                }
            }
        }
    }

    int max_score = -1e12;

    for (int j = 0; j < M; ++j) {

        max_score = max(max_score, dp[N - 1][j]);
    }
    cout << max_score << endl;
}

int main() {

    input();
    solution();
    return 0;
}
