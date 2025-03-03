#if 01
#include <iostream>
#include <queue>
using namespace std;

int n, l, st, ed, ret, curr = 2e9;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // �����ּ�, ����

void input_data();

void solution();

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);

	input_data();
	solution();
	cout << ret;

	return 0;
}

void input_data() {
	cin >> n >> l;
	for (int i = 0; i < n; i++) {
		cin >> st >> ed;
		pq.push({ st,ed - st });
		curr = min(curr, st); // ù ���� �ּ� ����
	}
}

void solution() {
	while (pq.size()) { // �� ������ ������ŭ ����
		int start = pq.top().first; // ������ ���� �ּ�
		int len = pq.top().second; // ������ ����
		int bridge_num = 0;
		int nstart = start;
		int nlen = len;
		pq.pop();

		if (curr > start) { // curr�� ���� �ּҺ��� ũ�ٸ� -> �κ����� �� ��� �ִ� ��.
			nstart = curr; // ���� �ּ� ����
			nlen = start + len - nstart; // ������ ���� ����
			if (nlen <= 0)continue;
		}
		else {
			curr = start;
		}
		if (nlen % l != 0) {
			bridge_num = nlen / l + 1;
		}
		else {
			bridge_num = nlen / l;
		}
		ret += bridge_num;
		curr = curr + bridge_num * l;
		//cout << nstart << ", " << nlen << ", " << bridge_num <<", "<<curr << "\n";

	}
}
#endif