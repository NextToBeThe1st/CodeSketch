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
        graph[b].push_back(a);  // 왕복 가능
    }

    vector<int> dist(n + 1, -1);  // 초기값 -1: 도달 불가능
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


// sources 배열에 따라 각 부대원이 목적지까지 가는 최단 시간 계산

vector<int> solution(int n, vector<vector<int>> roads, vector<int> sources, int destination) {
    vector<int> dist = bfs(n, roads, destination);
    vector<int> answer;
    for (int src : sources) {
        answer.push_back(dist[src]);
    }
    return answer;
}