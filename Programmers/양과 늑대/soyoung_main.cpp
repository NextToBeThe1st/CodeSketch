#include <bits/stdc++.h>
using namespace std;

int answer = 0;

void dfs(int curr, vector<vector<int>>& graph, vector<int>& info, vector<bool>& visited, int sheep, int wolf) {
    if (info[curr] == 0) sheep++;
    else wolf++;

    if (wolf >= sheep) {
        return;
    }

    answer = max(answer, sheep);

    visited[curr] = true;

    for (int i = 0; i < graph.size(); i++) {
        if (!visited[i]) continue;
        for (int next : graph[i]) {
            if (!visited[next]) {
                dfs(next, graph, info, visited, sheep, wolf);
            }
        }
    }
    visited[curr] = false;
}

int solution(vector<int> info, vector<vector<int>> edges) {
    vector<vector<int>> graph(info.size());

    for (auto& edge : edges) {
        graph[edge[0]].push_back(edge[1]);
        graph[edge[1]].push_back(edge[0]);
    }

    vector<bool> visited(info.size(), false);
    dfs(0, graph, info, visited, 0, 0);

    return answer;
}