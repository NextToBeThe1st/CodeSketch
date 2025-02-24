// 양방향이라는 점에 주목해야 한다.
// 자신->자신이라는 조건이 추가되었다.
// 둘 다 경로를 갈 수 없을 때의 조건을 따로 추가해야 했다.
#include <bits/stdc++.h>
#define MAX 801
using namespace std;

int N, E;	// 정점의 개수, 간선의 개수
vector<pair<int, int>> node[MAX];
int v1, v2;	// 반드시 저쳐야 하는 정점 번호 
int a, b, c;
int result;

void input_data();
int djikstra(int start_point, int end_point);
int solution();

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	input_data();
	result = solution();
	cout << result << endl;
	return 0;
}

void input_data() {
	cin >> N >> E;
	for (int i = 0; i < E; ++i){
		cin >> a >> b >> c;
		node[a].push_back(make_pair(c, b));
		node[b].push_back(make_pair(c, a));
	}
	for (int i = 1; i <= N; ++i)	{
		node[i].push_back(make_pair(0, i));
	}
	cin >> v1 >> v2;
}

int djikstra(int start_point, int end_point) {
	int distance[MAX];
	fill(distance, distance + MAX, INT_MAX);
	priority_queue<pair<int, int>> q;
	q.push({ 0, start_point });
	while (!q.empty()) {
		int cost = -q.top().first;
		int curr_point = q.top().second;
		q.pop();
		if (distance[curr_point] < cost) continue;
		for (int i = 0; i < node[curr_point].size(); ++i) {
			int curr_cost = cost + node[curr_point][i].first;
			if (curr_cost < distance[node[curr_point][i].second]) {
				distance[node[curr_point][i].second] = curr_cost;
				q.push({ -curr_cost, node[curr_point][i].second });
			}
		}
	}
	//cout << distance[end_point] << endl;
	return distance[end_point] == INT_MAX ? -1 : distance[end_point];
}

int solution() {
	int track1[4] = {1, v1, v2, N};
	int track2[4] = { 1, v2, v1, N };
	int result1 = 0, result2 = 0, djik_result;
	for (int i = 0; i < 3; ++i){
		djik_result = djikstra(track1[i], track1[i + 1]);
		if (djik_result == -1) {
			result1 = INT_MAX;
			break;
		}
		result1 += djik_result;
	}
	//cout << "result1 : " << result1 << endl;
	for (int i = 0; i < 3; ++i) {
		djik_result = djikstra(track2[i], track2[i + 1]);
		if (djik_result == -1) {
			result2 = INT_MAX;
			break;
		}
		result2 += djik_result;
		
	}
	//cout << "result2 : " << result2 << endl;
	if (result1 == result2 && result1 == INT_MAX){
		return -1;
	}
	return result1 < result2 ? result1 : result2;
}