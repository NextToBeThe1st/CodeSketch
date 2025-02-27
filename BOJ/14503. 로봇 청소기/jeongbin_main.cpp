#if 01
#include <iostream>
using namespace std;

int n, m, r, c, d, cnt;
int arr[54][54], clean[54][54];
// 0�� ��� ����, 1�� ��� ����, 2�� ��� ����, 3�� ��� ����
int dy[] = { -1,0,1,0 };
int dx[] = { 0,-1,0,1 };

void input_data() {
	cin >> n >> m;
	cin >> r >> c >> d;
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < m;j++) {
			cin >> arr[i][j];
		}
	}
}
bool checkDirection() {
	bool flag = true;
	for (int i = 0;i < 4;i++) { // �ֺ� û�� ���� Ȯ��
		int nr = r + dy[i];
		int nc = c + dx[i];
		if (nr < 0 || nc < 0 || nr >= n || nc >= m) continue;
		if (clean[nr][nc] == 1|| arr[nr][nc] == 1) continue;
		flag = false;
	}
	return flag;
}
void solution() {
	while (true) {
		if (!clean[r][c]) {
			clean[r][c] = 1; // ���� ĭ û��
			cnt++;
		}
		int nd = d;
		int nr = r;
		int nc = c;
		if (checkDirection()) { // û���� ���� ����.
			nd = (d + 2) % 4; // ���� ����
			nr = r + dy[nd];
			nc = c + dx[nd];
			if (nr < 0 || nc < 0 || nr >= n || nc >= m) break; // ���� �Ұ��� -> ����
			if (arr[nr][nc] == 1) break;
		}
		else { // �ݽð� ����
			d = (d + 1) % 4;
			nr = r + dy[nd];
			nc = c + dx[nd];
			if (nr < 0 || nc < 0 || nr >= n || nc >= m) continue;
			if (clean[nr][nc] == 1|| arr[nr][nc] == 1) continue;
		}
		r = nr;
		c = nc; // ���� �Ǵ� ����
	}
}
int main() {

	input_data();
	solution();
	cout << cnt;

	return 0;
}

#endif