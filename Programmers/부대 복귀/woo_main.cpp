#include <iostream>      
#include <vector>       
#include <queue>         
#include <limits>        

using namespace std;


vector<int> bfs(int n, const vector<vector<int>>& roads, int destination) {
    vector<vector<int>> graph(n + 1);
    for (const auto& road : roads) {
        int a = road[0];
        int b = road[1];
        graph[a].push_back(b);
        graph[b].push_back(a);  // �պ� ����
    }

    vector<int> dist(n + 1, -1);  // �ʱⰪ -1: ���� �Ұ���
    queue<int> q;
    q.push(destination);
    dist[destination] = 0;

    while (!q.empty()) {
        int now = q.front(); q.pop();
        for (int next : graph[now]) {
            if (dist[next] == -1) {
                dist[next] = dist[now] + 1;
                q.push(next);
            }
        }
    }
    return dist;
}


// sources �迭�� ���� �� �δ���� ���������� ���� �ִ� �ð� ���

vector<int> solution(int n, vector<vector<int>> roads, vector<int> sources, int destination) {
    vector<int> dist = bfs(n, roads, destination);
    vector<int> answer;
    for (int src : sources) {
        answer.push_back(dist[src]);
    }
    return answer;
}