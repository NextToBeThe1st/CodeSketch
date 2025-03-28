#if 0
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

bool visited[20][20][20];
vector<int> tree[20]; // 연결 상태
vector<int> state; // 해당 노드의 상태
int mx = 0; // 최대 양의 수

void dfs(int here, int sheep, int wolf);
int solution(vector<int> info, vector<vector<int>> edges) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    for (int i = 0; i < edges.size(); i++) {
        tree[edges[i][0]].push_back(edges[i][1]);
        tree[edges[i][1]].push_back(edges[i][0]);
    }
    for (int i = 0; i < info.size(); i++) state.push_back(info[i]);

    state[0] = -1; // 루트는 양 -> 비움
    visited[0][1][0] = true; // 루트 노드 방문 처리
    dfs(0, 1, 0); // 루트 : 양 ++
    return mx;
}

void dfs(int here, int sheep, int wolf) {
    mx = max(mx, sheep); // 최대 양의 수를 답으로 선택

    // 연결되어 있는 부모,자식 노드 모두 확인
    for (auto there : tree[here]) {
        if (state[there] == 0 && !visited[there][sheep + 1][wolf]) { // 양, 방문 x
            visited[there][sheep + 1][wolf] = true;
            state[there] = -1;
            dfs(there, sheep + 1, wolf);
            state[there] = 0;
            visited[there][sheep + 1][wolf] = false;
        }
        else if (state[there] == 1) { // 늑대
            if (sheep > wolf + 1 && !visited[there][sheep][wolf + 1]) { // 늑대 +1보다 양이 많아야함, 방문 x
                visited[there][sheep][wolf + 1] = true;
                state[there] = -1;
                dfs(there, sheep, wolf + 1);
                state[there] = 1;
                visited[there][sheep][wolf + 1] = false;
            }
        }
        else { // 다음이 빈 노드
            if (!visited[there][sheep][wolf]) {
                visited[there][sheep][wolf] = true;
                dfs(there, sheep, wolf); // 이동
                visited[there][sheep][wolf] = false;
            }
        }
    }

}
#endif