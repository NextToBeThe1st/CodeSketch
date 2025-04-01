#include <iostream>
#include <vector>

using namespace std;

#define Start 0
#define End 1
#define Time 2
#define INF 1e9

int solution(int N, vector<vector<int> > road, int K) {

    int answer = 0;

    vector<vector<int>> ADJ(N + 1, vector<int>(N + 1, 0));
    vector<int> Min_Dis(N + 1, INF);
    vector<int> Visited(N + 1, 0);

    Min_Dis[1] = 0;

    for (int i = 0; i < road.size(); ++i) {

        int start = road[i][Start];
        int end = road[i][End];
        int time = road[i][Time];

        if (ADJ[start][end] == 0)
        {
            ADJ[start][end] = time;
            ADJ[end][start] = time;
        }
        else if (ADJ[start][end] > time)
        {
            ADJ[start][end] = time;
            ADJ[end][start] = time;
        }
    }

    for (int i = 1; i <= N; ++i) {

        int min_dist = INF;
        int curr_pos = -1;

        for (int j = 1; j <= N; ++j) {

            if (!Visited[j] && Min_Dis[j] < min_dist) {

                min_dist = Min_Dis[j];
                curr_pos = j;
            }
        }
        if (curr_pos == -1) break;

        Visited[curr_pos] = 1;

        for (int next_pos = 1; next_pos <= N; ++next_pos) {

            if (ADJ[curr_pos][next_pos] && !Visited[next_pos]) {

                Min_Dis[next_pos] = min(Min_Dis[next_pos], Min_Dis[curr_pos] + ADJ[curr_pos][next_pos]);
            }
        }
    }

    for (int i = 1; i <= N; ++i) {

        if (Min_Dis[i] <= K) answer++;
    }
    return answer;
}