#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;


int solution(int N, vector<vector<int>> road, int K) {
    int answer = 0;
    vector<pair<int, int>> graph[51];
    vector<int> dist(N + 1, INT32_MAX);
    for (auto r : road) {
        int a = r[0], b = r[1], c = r[2];
        graph[a].push_back({ b, c });
        graph[b].push_back({ a, c });
    }
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    dist[1] = 0;
    pq.push({ 0, 1 });

    while (!pq.empty()) {
        auto [cur_dist, cur] = pq.top();
        pq.pop();

        if (cur_dist > dist[cur]) continue;

        for (auto [next, cost] : graph[cur]) {
            if (dist[next] > cur_dist + cost) {
                dist[next] = cur_dist + cost;
                pq.push({ dist[next], next });
            }
        }
    }
    for (int i = 1; i <= N; ++i) {
        if (dist[i] <= K) answer++;
    }

    return answer;
}