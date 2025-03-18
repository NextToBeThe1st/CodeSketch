#include <bits/stdc++.h>
using namespace std;
#define MAX 50001

vector<vector<pair<int, int>>> node(MAX);
vector<int> course(MAX);
const int SUMMIT = 2;
const int GATE = 1;
const int NODE = 0;

void setNode(vector<vector<int>> paths) {
    for (auto path : paths) {
        node[path[0]].push_back({ path[2], path[1] });
        node[path[1]].push_back({ path[2], path[0] });
    }
}

int getIntensity(int summit, vector<int> gates) {
    vector<int> intensities(MAX, INT32_MAX);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    intensities[summit] = 0;
    pq.push({ 0, summit });

    while (!pq.empty()) {
        int intense = pq.top().first;
        int curPoint = pq.top().second;
        pq.pop();
        if (course[curPoint] == GATE) return intense;
        if (intense > intensities[curPoint]) continue;
        for (auto i : node[curPoint]) {
            int cost = i.first;
            int nextNode = i.second;
            int newIntense = max(intense, cost); // 경로 상 최대 비용

            if (newIntense < intensities[nextNode] && course[nextNode] == NODE) {
                intensities[nextNode] = newIntense;
                pq.push({ newIntense, nextNode });
            }
        }
    }

    int minIntensity = INT32_MAX;
    for (auto gate : gates) {
        if (intensities[gate] != INT32_MAX) {
            minIntensity = min(minIntensity, intensities[gate]);
        }
    }
    return minIntensity;
}

vector<int> solution(int n, vector<vector<int>> paths, vector<int> gates, vector<int> summits) {
    vector<int> answer = { INT32_MAX, INT32_MAX };
    setNode(paths);
    for (auto summit : summits) {
        course[summit] = SUMMIT;
    }
    sort(summits.begin(), summits.end());
    for (auto summit : summits) {
        //cout << summit << endl;
        int intensity = getIntensity(summit, gates);
        //cout << "summit " << summit << " intensity is " << intensity << endl;
        if (intensity < answer[1]) {
            answer[0] = summit;
            answer[1] = intensity;
        }
    }
    return answer;
}