#if 0
#include <iostream>
#include <queue>
#include <tuple>
using namespace std;

int N, K, L;
char C;
int arr[104][104]; // 1 : 사과, 2 : 뱀
int dx[] = { 1,0,-1,0 }; // 오, 밑, 왼, 위
int dy[] = { 0,1,0,-1 };
queue<pair<int, char>> moves;
deque<pair<int, int>> snake;

void input_data();
void solution();

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	input_data();
	solution();

	return 0;
}

void input_data() {
	cin >> N >> K;
	int x, y, s; // x,y 좌표, s : 초
	for (int i = 0; i < K; i++) {
		cin >> y >> x;
		arr[y - 1][x - 1] = 1; // 사과 입력
	}
	cin >> L;

	for (int i = 0; i < L; i++) {
		cin >> s >> C;
		moves.push({ s,C }); // 뱀 방향 전환 저장
	}
}


void solution() {
	int x = 0, y = 0, s, curr_sec = 0, curr_dir = 0;
	char d;
	arr[y][x] = 2; // 뱀 처음 위치
	snake.push_back({ y,x });
	tie(s, d) = moves.front(); // 뱀 초기값 설정
	moves.pop();

	while (true) {
		if (curr_sec >= s) { // 방향 전환
			if (d == 'L') curr_dir = (curr_dir + 3) % 4; // 왼쪽
			else curr_dir = (curr_dir + 1) % 4; // 오른쪽
			if (moves.empty()) { 
				s = 2e9; // 더이상 방향 전환이 없다면 끝까지 전진
			}
			else {
				tie(s, d) = moves.front(); // 다음 방향 전환 갱신
				moves.pop();
			}
		}
		curr_sec++; // 현재 초 증가
		tie(y, x) = snake.front();
		int ny = y + dy[curr_dir]; // 전진
		int nx = x + dx[curr_dir];
		if (ny < 0 || nx < 0 || ny >= N || nx >= N) break; // 범위 벗어나면
		if (arr[ny][nx] == 2) break; // 자기 몸에 박으면

		if (arr[ny][nx] != 1) {// 사과 없으면
			auto tail = snake.back();
			arr[tail.first][tail.second] = 0;
			snake.pop_back(); // 꼬리 지우기
		}
		arr[ny][nx] = 2; // 머리 이동
		snake.push_front({ ny,nx });

	}

	cout << curr_sec;
}
#endif