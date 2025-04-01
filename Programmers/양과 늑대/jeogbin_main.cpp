#if 0
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

bool visited[20][20][20];
vector<int> tree[20]; // ���� ����
vector<int> state; // �ش� ����� ����
int mx = 0; // �ִ� ���� ��

void dfs(int here, int sheep, int wolf);
int solution(vector<int> info, vector<vector<int>> edges) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    for (int i = 0; i < edges.size(); i++) {
        tree[edges[i][0]].push_back(edges[i][1]);
        tree[edges[i][1]].push_back(edges[i][0]);
    }
    for (int i = 0; i < info.size(); i++) state.push_back(info[i]);

    state[0] = -1; // ��Ʈ�� �� -> ���
    visited[0][1][0] = true; // ��Ʈ ��� �湮 ó��
    dfs(0, 1, 0); // ��Ʈ : �� ++
    return mx;
}

void dfs(int here, int sheep, int wolf) {
    mx = max(mx, sheep); // �ִ� ���� ���� ������ ����

    // ����Ǿ� �ִ� �θ�,�ڽ� ��� ��� Ȯ��
    for (auto there : tree[here]) {
        if (state[there] == 0 && !visited[there][sheep + 1][wolf]) { // ��, �湮 x
            visited[there][sheep + 1][wolf] = true;
            state[there] = -1;
            dfs(there, sheep + 1, wolf);
            state[there] = 0;
            visited[there][sheep + 1][wolf] = false;
        }
        else if (state[there] == 1) { // ����
            if (sheep > wolf + 1 && !visited[there][sheep][wolf + 1]) { // ���� +1���� ���� ���ƾ���, �湮 x
                visited[there][sheep][wolf + 1] = true;
                state[there] = -1;
                dfs(there, sheep, wolf + 1);
                state[there] = 1;
                visited[there][sheep][wolf + 1] = false;
            }
        }
        else { // ������ �� ���
            if (!visited[there][sheep][wolf]) {
                visited[there][sheep][wolf] = true;
                dfs(there, sheep, wolf); // �̵�
                visited[there][sheep][wolf] = false;
            }
        }
    }

}
#endif