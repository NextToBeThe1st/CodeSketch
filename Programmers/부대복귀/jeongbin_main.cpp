#if 0
#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;

int visited[100004];
vector<int> map[100004];
vector<int> ret;

void bfs(vector<int> sources, int dest) {
    queue<pair<int, int>> q; // �켱����  ť ��� �� �ð��ʰ� ��.
    q.push({ 0, dest });
    visited[dest] = 0;
    while (q.size()) {
        int here = q.front().second;
        int sec = q.front().first;
        q.pop();
        //cout<<here<<": "<<sec<<'\n';
        // auto pos = find(sources.begin(), sources.end(), here);
        // if( pos != sources.end()){
        //     visited[here] = sec;
        //     sources.erase(pos);
        //     continue;
        // }
        if (visited[here] < sec) continue;
        for (int there : map[here]) {
            int next_sec = sec + 1;
            //cout<<there<<": "<<next_sec<<'\n';
            if (next_sec > visited[there]) continue;
            //cout<<there<<": "<<next_sec<<'\n';
            visited[there] = next_sec;
            q.push({ next_sec, there });
        }
    }
}

// �� ������, �� ����(�պ�), ��ġ�� ���� �ٸ� ����(�����), �δ��� ����(������)
vector<int> solution(int n, vector<vector<int>> roads, vector<int> sources, int destination) {
    vector<int> answer;

    for (int i = 0; i < roads.size(); i++) {
        map[roads[i][0]].push_back(roads[i][1]);
        map[roads[i][1]].push_back(roads[i][0]);
    }
    fill(visited, visited + 100004, INT32_MAX);
    bfs(sources, destination);
    for (int i = 0; i < sources.size(); i++) {
        if (visited[sources[i]] == INT32_MAX) answer.push_back(-1);
        else answer.push_back(visited[sources[i]]);
    }

    return answer;
}
#endif // 0
