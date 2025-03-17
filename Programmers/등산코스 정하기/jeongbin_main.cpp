#if 0
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
typedef long long ll;
using namespace std;
vector<pair<int, int>> v[50004]; // ������, ����ġ
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
        pq.push({ 0,gate }); // ����
        intensity[gate] = 0; // �ڱ� �ڽ��� 0
    }

    while (pq.size()) {
        int start_point = pq.top().second; // ��������
        int weight = pq.top().first; // ����ġ
        pq.pop();

        if (intensity[start_point] < weight) continue; // �̹� �� ���� w�� �� �۴ٸ� �� �ʿ� ����.
        if (summitList[start_point]) { // ���츮���
            weightList.push_back({ weight, start_point });
            continue;
        }

        for (auto there : v[start_point]) { // ����� ��� Ž��
            int next_node = there.first;
            int next_weight = there.second;

            // ó���̰ų� �ִ밪�� �� ������
            if ((intensity[next_node] == -1) || (intensity[next_node] > max(next_weight, weight))) {
                intensity[next_node] = max(next_weight, weight);
                pq.push({ intensity[next_node], next_node });
            }
        }
    }
    sort(weightList.begin(), weightList.end()); // �� ����ġ �� �ּ� + �ּ� ���츮
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

        v[i].push_back({ j,w }); // ��� ���� ����
        v[j].push_back({ i,w }); // ����� ����
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
