#include<iostream>
#include<vector>
#include<algorithm>
#include <stack>

using namespace std;

int N, M;
int map[501][501];
//bool visited[501][501];

int CNT;

int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };

bool check_valid(int i, int j) {

	return i >= 0 && i < N && j >= 0 && j < M;
}

void input() {

	cin >> N >> M;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j)
		{
			cin >> map[i][j];
		}
	}
}

void DFS_Count() {

	stack<pair<int, int>> Stack;

	Stack.push(make_pair(0, 0));
	//visited[0][0] = true;

	while (!Stack.empty()) {

		pair<int, int> Curr;
		Curr = Stack.top();
		Stack.pop();

		int Curr_i = Curr.first;
		int Curr_j = Curr.second;

		if (Curr_i == (N - 1) && Curr_j == (M - 1)) {

			CNT++;
			continue;

		}

		for (int i = 0; i < 4; ++i) {

			int Next_i = Curr_i + dx[i];
			int Next_j = Curr_j + dy[i];

			if (/*!visited[Next_i][Next_j] &&*/ check_valid(Next_i, Next_j) && map[Curr_i][Curr_j] > map[Next_i][Next_j]) {

				cout << map[Next_i][Next_j] << endl;
				Stack.push(make_pair(Next_i, Next_j));

				//visited[Next_i][Next_j] = true;
			}
		}
	}
}

int main(void) {

	input();
	DFS_Count();

	cout << CNT;
}