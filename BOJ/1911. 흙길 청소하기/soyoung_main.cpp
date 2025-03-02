#include <bits/stdc++.h>
using namespace std;
int result;
int N, L;
int st, en;
priority_queue<pair<int, int>> ponds;
int lastBoard = INT32_MAX;

void inputData();
void solution();

int main() {
	inputData();
	solution();
	cout << result << endl;
}

void inputData() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N >> L;
	for (int i = 0; i < N; ++i) {
		cin >> st >> en;
		ponds.push({ en, st });
	}
	

}

void solution() {
	while (!ponds.empty()) {
		pair<int, int> currentPond = ponds.top();
		ponds.pop();
		lastBoard = lastBoard > currentPond.first ? currentPond.first : lastBoard;
		int cnt = ceil((double)(lastBoard - currentPond.second) / (double)L);
		result += cnt;
		lastBoard -= cnt * L;
	}
}