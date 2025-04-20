#if 0
#include <iostream>
#include <queue>
#include <tuple>
using namespace std;

typedef struct Point {
	int y;
	int x;
}point;

int n,m,arr[504][504], visited[504][504], ret = 0;

int dy[] = { -1,0,1,0 };
int dx[] = { 0,1,0,-1 };

void bfs(int y,int x) {
	priority_queue<pair<int, pair<int,int>>> pq;
	pq.push({ arr[y][x],{y,x}});
	visited[y][x] = 1;
	while (pq.size()) {
		tie(y,x) = pq.top().second;
		int h = pq.top().first;
		pq.pop();
		if (y == m - 1 && x == n - 1) {
			continue;
		}
		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			
			if (ny < 0 || nx < 0 || ny >= m || nx >= n) continue; 
			if (h <= arr[ny][nx]) continue;
			if (visited[ny][nx] == 0) {
				pq.push({ arr[ny][nx],{ny,nx}});
			}
			visited[ny][nx] += visited[y][x];
		}
	}
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> m >> n;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}
	bfs(0, 0);
	cout << visited[m-1][n-1];

	return 0;
}
#endif