#if 0
#include <iostream>
using namespace std;

int n, m, r, c, d, cnt;
int arr[54][54], clean[54][54];
// 0�� ��� ����, 1�� ��� ����, 2�� ��� ����, 3�� ��� ����
int dy[] = { -1,0,1,0 };
int dx[] = { 0,1,0,-1 };

void input_data();
bool checkDirection(); // �ֺ� û�� ���� Ȯ��
void solution();

int main() {

	input_data(); // ������ �Է�
	solution(); // Ǯ��
	cout << cnt;

	return 0;
}
void input_data() {  // ������ �Է�
	cin >> n >> m;
	cin >> r >> c >> d;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}
}
bool checkDirection() { // �ֺ� û�� ���� Ȯ��
	bool flag = true;
	for (int i = 0; i < 4; i++) { 
		int nr = r + dy[i];
		int nc = c + dx[i];
		if (nr < 0 || nc < 0 || nr >= n || nc >= m) continue;
		if (clean[nr][nc] == 1 || arr[nr][nc] == 1) continue;
		flag = false;
	}
	return flag;
}
void solution() { // Ǯ��
	while (true) {
		if (clean[r][c] == 0) { // û�� �ȵǾ��ִٸ�
			clean[r][c] = 1; // ���� ĭ û��
			cnt++;
		}
		int nd = d;
		int nr = r;
		int nc = c;
		if (checkDirection()) { // û���� ������ ���ٸ�
			nd = (d + 2) % 4; // ���� ���� ���� ����
			nr = r + dy[nd];
			nc = c + dx[nd];
			if (nr < 0 || nc < 0 || nr >= n || nc >= m) break; // ���� �Ұ��� -> ����
			if (arr[nr][nc] == 1) break;
		}
		else { // �ݽð� ����
			d = (d + 3) % 4;
			nr = r + dy[d];
			nc = c + dx[d];
			if (nr < 0 || nc < 0 || nr >= n || nc >= m) continue;
			if (clean[nr][nc] == 1 || arr[nr][nc] == 1) continue;
			//cout << 1 << ' ';
		}
		r = nr;
		c = nc; // ���� �Ǵ� ����
	}
}
#endif