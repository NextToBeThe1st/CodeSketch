#include <bits/stdc++.h>
using namespace std;

const int MAX = 51;
const int NOTCLEANED = 0;
const int WALL = 1;
const int CLEANED = -1;
int N, M;
// 로봇청소기의 방향
int r, c, d;
// 로봇 청소기의 현재 위치
pair<int, int> vacuum;
// 북, 동, 남, 서
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };
int nx, ny;
int result;
int room[MAX][MAX];

void inputData();
bool isAroundDirty();
bool check(int x, int y, int state);
void solution();


int main() {
	inputData();
	solution();
	cout << result << endl;
}

void inputData() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N >> M;
	cin >> vacuum.first >> vacuum.second >> d;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			cin >> room[i][j];
		}
	}
}
// 주변 4칸 깨끗한지 체크
bool isAroundDirty() {
	for (int i = 0; i < 4; ++i){
		nx = vacuum.first + dx[i];
		ny = vacuum.second + dy[i];
		if (check(nx, ny, NOTCLEANED)) {
			return true;
		}
	}
	return false;
}

bool check(int x, int y, int state) {
	return (room[x][y] == state);
}

void solution() {
	while (1) {
		//현재 칸이 아직 청소되지 않은 경우, 현재 칸을 청소한다.
		if (room[vacuum.first][vacuum.second] == NOTCLEANED) {
			//cout << "clean the room" << endl;
			result += 1;
			room[vacuum.first][vacuum.second] = CLEANED;
		}

		// 현재 칸의 주변 4칸 중 청소되지 않은 빈 칸이 있는 경우
		if (isAroundDirty()) {
			//cout << "Not clean" << endl;
			while (1) {
				d = (d + 3) % 4;
				nx = vacuum.first + dx[d];
				ny = vacuum.second + dy[d];
				if (room[nx][ny] == NOTCLEANED){
					vacuum = make_pair(nx, ny);
					break;
				}
			}
		}
		// 현재 칸의 주변 4칸 중 청소되지 않은 빈 칸이 없는 경우
		else {
			//cout << "is clean" << endl;
			nx = vacuum.first - dx[d];
			ny = vacuum.second - dy[d];
			// 바라보는 방향의 뒤쪽 칸이 벽이라 후진할 수 없다면 작동을 멈춘다.
			if (check(nx, ny, WALL)) {
				return;
			}
			// 바라보는 방향을 유지한 채로 한 칸 후진할 수 있다면 한 칸 후진하고 1번으로 돌아간다.
			vacuum = make_pair(nx, ny);
		}

		

	}
}