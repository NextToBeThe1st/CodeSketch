#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <climits>
#include <algorithm>

using namespace std;

struct Edge {
    int node, weight;
};

vector<int> solution(int n, vector<vector<int>> paths, vector<int> gates, vector<int> summits) {
    // �׷��� ����
    vector<vector<Edge>> graph(n + 1);
    for (auto& path : paths) {
        int u = path[0], v = path[1], w = path[2];
        graph[u].push_back({ v, w });
        graph[v].push_back({ u, w });
    }

    // ���Ա� �� ����츮 ����
    set<int> gates_set(gates.begin(), gates.end());
    set<int> summits_set(summits.begin(), summits.end());

    // ���ͽ�Ʈ�� ����: �ּ� ����ġ X, �ּ� intensity ã�� O
    vector<int> intensity(n + 1, INT_MAX);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq; // (intensity, node)

    for (int gate : gates) {
        pq.push({ 0, gate });
        intensity[gate] = 0;
    }

    while (!pq.empty()) {
        auto [cur_intensity, cur_node] = pq.top();
        pq.pop();

        // ����츮�� �����ϸ� ���� 
        if (summits_set.find(cur_node) != summits_set.end()) continue;

        for (auto& edge : graph[cur_node]) {
            int next_node = edge.node;
            int max_intensity = max(cur_intensity, edge.weight);

            // �� ���� intensity�� ���ŵǴ� ��츸 ����
            if (max_intensity < intensity[next_node]) {
                intensity[next_node] = max_intensity;
                pq.push({ max_intensity, next_node });
            }
        }
    }

    // ������ ����츮 ã��
    int min_intensity = INT_MAX;
    int best_summit = -1;

    sort(summits.begin(), summits.end()); // �ּ� ����츮 ��ȣ
    for (int summit : summits) {
        if (intensity[summit] < min_intensity) {
            min_intensity = intensity[summit];
            best_summit = summit;
        }
    }

    return { best_summit, min_intensity };
}




// �׽�Ʈ��
int main() {
    vector<vector<int>> paths1 = { {1, 2, 3}, {2, 3, 5}, {2, 4, 2}, {2, 5, 4}, {3, 4, 4}, {4, 5, 3}, {4, 6, 1}, {5, 6, 1} };
    vector<int> gates1 = { 1, 3 };
    vector<int> summits1 = { 5 };
    vector<int> result1 = solution(6, paths1, gates1, summits1);
    cout << "[" << result1[0] << ", " << result1[1] << "]\n";  // [5, 3]

    vector<vector<int>> paths2 = { {1, 4, 4}, {1, 6, 1}, {1, 7, 3}, {2, 5, 2}, {3, 7, 4}, {5, 6, 6} };
    vector<int> gates2 = { 1 };
    vector<int> summits2 = { 2, 3, 4 };
    vector<int> result2 = solution(7, paths2, gates2, summits2);
    cout << "[" << result2[0] << ", " << result2[1] << "]\n";  // [3, 4]

    return 0;
}