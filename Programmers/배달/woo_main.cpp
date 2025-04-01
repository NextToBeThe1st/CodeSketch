#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int INF = 2147483647;

int solution(int N, vector<vector<int>> road, int K) {
    // 인접 리스트 생성
    vector<vector<pair<int, int>>> adj(N + 1);

    for (auto& r : road) {
        int a = r[0], b = r[1], c = r[2];
        adj[a].push_back({ b, c });
        adj[b].push_back({ a, c });
    }

    
    vector<int> dist(N + 1, INF);
    dist[1] = 0; // 1번 마을에서 출발!

    // 최소 힙을 사용한 우선순위 큐 (거리, 노드번호)
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({ 0, 1 });

    while (!pq.empty()) {
        int cost = pq.top().first;
        int here = pq.top().second;
        pq.pop();

        // 이미 더 짧은 경로를 찾은 경우 무시
        if (cost > dist[here]) continue;

        // 연결된 인접 마을 탐색
        for (auto& edge : adj[here]) {
            int there = edge.first;
            int nextCost = cost + edge.second;

            if (dist[there] > nextCost) {
                dist[there] = nextCost;
                pq.push({ nextCost, there });
            }
        }
    }

    // K 이하의 거리에 있는 마을의 개수 세기
    int answer = 0;
    for (int i = 1; i <= N; i++) {
        if (dist[i] <= K) answer++;
    }

    return answer;
}

/* TEST CODE
int main() {
    cout << solution(5, { {1,2,1},{2,3,3},{5,2,2},{1,4,2},{5,3,1},{5,4,2} }, 3) << endl;
    cout << solution(6, { {1,2,1},{1,3,2},{2,3,2},{3,4,3},{3,5,2},{3,5,3},{5,6,1} }, 4) << endl;
}*/