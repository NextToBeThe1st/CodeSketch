#if 01

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
vector<int> graph[1004];
int input_cnt[1004];
vector<int> ans;

int solution() {
	
	// ���� ������ 0�� ��带 tmp�� ����
	vector<int> tmp;
	for (int i = 1; i <= n; i++) {
		if (input_cnt[i] == 0) {
			tmp.push_back(i);
		}
	}

	while (!tmp.empty()) {
		int here = tmp.back();
		tmp.pop_back();
		ans.push_back(here);

		for (int there : graph[here]) {
			input_cnt[there]--;
			if (input_cnt[there] == 0) {
				tmp.push_back(there);
			}
		}
	}

	// ����Ŭ or ��� ��尡 ����� ���� ���
	if (ans.size() != n) return 0;

	return 1;
}

int main() {

	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int num, prev = 0;
		cin >> num;
		for (int j = 0; j < num; j++) { // ���� �ϴ� ���� Ȯ���� ���� graph ����
			int x;
			cin >> x;
			if (j > 0) {
				graph[prev].push_back(x);  // prev -> x ���� �߰�
				input_cnt[x]++;
			}
			prev = x;
		}
	}

	int ret = solution();
	if (ret == 0) cout << 0;
	else {
		for (int i : ans) {
			cout << i << '\n';
		}
	}

	return 0;
}

#endif

#if 0

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n, m;
vector<int> graph[1004];
int input_cnt[1004];

vector<int> ans;

int solution() {

	// ���� ������ 0�� ��带 tmp�� ����
	queue<int> tmp;
	for (int i = 1; i <= n; i++) {
		if (input_cnt[i] == 0) {
			tmp.push(i);
		}
	}

	while (tmp.size()) {
		int here = tmp.front();
		tmp.pop();
		ans.push_back(here);

		for (int there : graph[here]) {
			input_cnt[there]--;
			if (input_cnt[there] == 0) {
				tmp.push(there);
			}
		}
	}

	// ����Ŭ or ��� ��尡 ����� ���� ���
	if (ans.size() != n) return 0;

	return 1;
}

int main() {

	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int num, prev = 0;
		cin >> num;
		for (int j = 0; j < num; j++) { // ���� �ϴ� ���� Ȯ���� ���� graph ����
			int x;
			cin >> x;
			if (j > 0) {
				graph[prev].push_back(x);  // prev -> x ���� �߰�
				input_cnt[x]++;
			}
			prev = x;
		}
	}

	int ret = solution();
	if (ret == 0) cout << 0;
	else {
		for (int i : ans) {
			cout << i << '\n';
		}
	}

	return 0;
}

#endif