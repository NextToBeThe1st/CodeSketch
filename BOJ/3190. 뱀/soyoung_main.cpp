#include<bits/stdc++.h>
using namespace std;
const int MAX = 101;	// 보드 및 사과 개수 최대값
const int APPLE = 1;
int N, K, L, X;			// 보드의 크기, 사과의 개수, 뱀의 방향 변환 횟수, 방향 전환 시간
char C;					// 뱀의 방향
int x, y;				// 사과의 위치 입력
deque<pair<int, int>> snake;	// 뱀의 위치
deque<pair<int, char>> snakeVec;// 뱀의 방향 정보
int currentSnakeVec = 0;
int board[MAX][MAX];
int result = 0;
// 오->밑->왼->위
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

void inputData();
void solution();
bool canMove(pair<int, int> head);

int main() {
	inputData();
	solution();
	cout << result << endl;
}

void inputData() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> K;
	for (int i = 0; i < K; ++i) {
		cin >> x >> y;
		board[x-1][y-1] = APPLE;
	}
	cin >> L;
	for (int i = 0; i < L; ++i) {
		cin >> X >> C;
		snakeVec.push_back({X, C});
	}
	snake.push_front({ 0, 0 });
}
// 뱀의 머리가 벽이나 자기 자신의 몸과 부딪히는 지 확인
bool canMove(pair<int, int> head) {
	if (head.first >= 0 && head.first < N && head.second >= 0 && head.second < N){
		for (auto body : snake) {
			if (head == body) {
				return false; 
			}
		}
		return true;
	}
	return false;
}

void solution() {
	while (true) {
		// 시간이 1초 증가한다.
		++result;
		// 먼저 뱀은 몸길이를 늘려 머리를 다음칸에 위치시킨다.
		pair<int, int> nextHead = snake.front();
		nextHead.first += dx[currentSnakeVec];
		nextHead.second += dy[currentSnakeVec];
		// 만약 벽이나 자기자신의 몸과 부딪히면 게임이 끝난다.
		if (!canMove(nextHead)) {
			break; 
		}
		snake.push_front(nextHead);
		// 만약 이동한 칸에 사과가 있다면, 
		if (board[snake.front().first][snake.front().second] == 1) {
			// 그 칸에 있던 사과가 없어지고
			board[snake.front().first][snake.front().second] = 0;
			// 꼬리는 움직이지 않는다.
		}
		else {
			// 만약 이동한 칸에 사과가 없다면, 몸길이를 줄여서 꼬리가 위치한 칸을 비워준다. 즉, 몸길이는 변하지 않는다.
			snake.pop_back();
		}

		// 뱀의 방향을 바꿔야 하는지 확인한다.
		if (!snakeVec.empty() && snakeVec.front().first == result) {
			if (snakeVec.front().second == 'D') {
				currentSnakeVec = (currentSnakeVec + 1) % 4;
			}
			else {
				currentSnakeVec = (currentSnakeVec + 3) % 4;
			}
			snakeVec.pop_front();
		}
		
	}
}