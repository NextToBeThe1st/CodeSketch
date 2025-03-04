#if 01
#include <iostream>
#include <queue>
using namespace std;

int n, l, st, ed, ret, curr = 2e9;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // 시작주소, 길이

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
		curr = min(curr, st); // 첫 시작 주소 저장
	}
}

void solution() {
	while (pq.size()) { // 물 웅덩이 개수만큼 수행
		int start = pq.top().first; // 웅덩이 시작 주소
		int len = pq.top().second; // 웅덩이 길이
		int bridge_num = 0;
		int nstart = start;
		int nlen = len;
		pq.pop();

		if (curr > start) { // curr이 시작 주소보다 크다면 -> 널빤지가 더 깔려 있는 것.
			nstart = curr; // 시작 주소 갱신
			nlen = start + len - nstart; // 웅덩이 길이 갱신
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