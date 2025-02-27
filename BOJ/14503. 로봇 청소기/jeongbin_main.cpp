#if 0
#include <iostream>
using namespace std;

int n, m, r, c, d, cnt;
int arr[54][54], clean[54][54];
// 0인 경우 북쪽, 1인 경우 동쪽, 2인 경우 남쪽, 3인 경우 서쪽
int dy[] = { -1,0,1,0 };
int dx[] = { 0,1,0,-1 };

void input_data();
bool checkDirection(); // 주변 청소 상태 확인
void solution();

int main() {

	input_data(); // 데이터 입력
	solution(); // 풀이
	cout << cnt;

	return 0;
}
void input_data() {  // 데이터 입력
	cin >> n >> m;
	cin >> r >> c >> d;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}
}
bool checkDirection() { // 주변 청소 상태 확인
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
void solution() { // 풀이
	while (true) {
		if (clean[r][c] == 0) { // 청소 안되어있다면
			clean[r][c] = 1; // 현재 칸 청소
			cnt++;
		}
		int nd = d;
		int nr = r;
		int nc = c;
		if (checkDirection()) { // 청소할 구역이 없다면
			nd = (d + 2) % 4; // 후진 방향 따로 설정
			nr = r + dy[nd];
			nc = c + dx[nd];
			if (nr < 0 || nc < 0 || nr >= n || nc >= m) break; // 후진 불가능 -> 종료
			if (arr[nr][nc] == 1) break;
		}
		else { // 반시계 돌기
			d = (d + 3) % 4;
			nr = r + dy[d];
			nc = c + dx[d];
			if (nr < 0 || nc < 0 || nr >= n || nc >= m) continue;
			if (clean[nr][nc] == 1 || arr[nr][nc] == 1) continue;
			//cout << 1 << ' ';
		}
		r = nr;
		c = nc; // 전진 또는 후진
	}
}
#endif