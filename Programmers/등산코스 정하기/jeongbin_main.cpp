#if 0
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
typedef long long ll;
using namespace std;
vector<pair<int, int>> v[50004]; // 목적지, 가중치
vector<int> g;
int intensity[50004];
bool summitList[50004];
int ret_node;
int ret_weight;

void dijkstra() {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<pair<int, int>> weightList;
    fill(intensity, intensity + 50004, -1);

    for (auto gate : g) {
        pq.push({ 0,gate }); // 시작
        intensity[gate] = 0; // 자기 자신은 0
    }

    while (pq.size()) {
        int start_point = pq.top().second; // 시작지점
        int weight = pq.top().first; // 가중치
        pq.pop();

        if (intensity[start_point] < weight) continue; // 이미 간 곳의 w가 더 작다면 갈 필요 없음.
        if (summitList[start_point]) { // 봉우리라면
            weightList.push_back({ weight, start_point });
            continue;
        }

        for (auto there : v[start_point]) { // 연결된 경로 탐색
            int next_node = there.first;
            int next_weight = there.second;

            // 처음이거나 최대값이 더 작으면
            if ((intensity[next_node] == -1) || (intensity[next_node] > max(next_weight, weight))) {
                intensity[next_node] = max(next_weight, weight);
                pq.push({ intensity[next_node], next_node });
            }
        }
    }
    sort(weightList.begin(), weightList.end()); // 각 가중치 중 최소 + 최소 봉우리
    ret_weight = weightList[0].first;
    ret_node = weightList[0].second;
}

vector<int> solution(int n, vector<vector<int>> paths, vector<int> gates, vector<int> summits) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int i, j, w; // start, end, time
    for (auto iter : paths) {
        i = iter[0];
        j = iter[1];
        w = iter[2];

        v[i].push_back({ j,w }); // 경로 형태 변경
        v[j].push_back({ i,w }); // 양방향 간선
    }
    g = gates;
    for (int summit : summits) {
        summitList[summit] = true;
    }
    vector<int> answer;
    dijkstra();

    answer.push_back(ret_node);
    answer.push_back(ret_weight);

    return answer;
}
#endif // 0
