#include <bits/stdc++.h>
using namespace std;

const int MAX = 501;
const int dx[4] = { -1, 1, 0, 0 };
const int dy[4] = { 0, 0, -1, 1 };

int M, N;
int result = 0;
int board[MAX][MAX] = { 0 };
int visited[MAX][MAX] = { 0 };
bool visits[MAX][MAX] = { false };


void inputData();
bool isInRange(int x, int y);
int dfs(int x, int y);
void saveRoute(bool curVisit[MAX][MAX]);
void solution();

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	inputData();
	solution();
	cout << result << endl;
	return 0;
}

void inputData() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> M >> N;
	for (int i = 0; i < M; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			cin >> board[i][j];
		}

	}
	return;
}

bool isInRange(int x, int y)
{
	return (0 <= x && x < M && 0 <= y && y < N);
}

void saveRoute(bool curVisit[MAX][MAX])
{
	for (int i = 0; i < M; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			if (curVisit[i][j] == true)
			{
				visited[i][j]++;
			}
		}
	}
	return;
}

int dfs(int x, int y)
{
	if (x == M - 1 && y == N - 1)
		return 1;

	if (visited[x][y] != -1)
		return visited[x][y];

	visited[x][y] = 0;

	for (int i = 0; i < 4; ++i)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (isInRange(nx, ny) && board[nx][ny] < board[x][y])
		{
			visited[x][y] += dfs(nx, ny);
		}
	}
	return visited[x][y];
}

void solution()
{
	memset(visited, -1, sizeof(visited)); // 초기값 설정
	result = dfs(0, 0);
}