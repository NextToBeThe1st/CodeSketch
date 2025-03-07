#if 0
#include <iostream>
#include <queue>
#include <tuple>
using namespace std;

int N, K, L;
char C;
int arr[104][104]; // 1 : ���, 2 : ��
int dx[] = { 1,0,-1,0 }; // ��, ��, ��, ��
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
	int x, y, s; // x,y ��ǥ, s : ��
	for (int i = 0; i < K; i++) {
		cin >> y >> x;
		arr[y - 1][x - 1] = 1; // ��� �Է�
	}
	cin >> L;

	for (int i = 0; i < L; i++) {
		cin >> s >> C;
		moves.push({ s,C }); // �� ���� ��ȯ ����
	}
}


void solution() {
	int x = 0, y = 0, s, curr_sec = 0, curr_dir = 0;
	char d;
	arr[y][x] = 2; // �� ó�� ��ġ
	snake.push_back({ y,x });
	tie(s, d) = moves.front(); // �� �ʱⰪ ����
	moves.pop();

	while (true) {
		if (curr_sec >= s) { // ���� ��ȯ
			if (d == 'L') curr_dir = (curr_dir + 3) % 4; // ����
			else curr_dir = (curr_dir + 1) % 4; // ������
			if (moves.empty()) { 
				s = 2e9; // ���̻� ���� ��ȯ�� ���ٸ� ������ ����
			}
			else {
				tie(s, d) = moves.front(); // ���� ���� ��ȯ ����
				moves.pop();
			}
		}
		curr_sec++; // ���� �� ����
		tie(y, x) = snake.front();
		int ny = y + dy[curr_dir]; // ����
		int nx = x + dx[curr_dir];
		if (ny < 0 || nx < 0 || ny >= N || nx >= N) break; // ���� �����
		if (arr[ny][nx] == 2) break; // �ڱ� ���� ������

		if (arr[ny][nx] != 1) {// ��� ������
			auto tail = snake.back();
			arr[tail.first][tail.second] = 0;
			snake.pop_back(); // ���� �����
		}
		arr[ny][nx] = 2; // �Ӹ� �̵�
		snake.push_front({ ny,nx });

	}

	cout << curr_sec;
}
#endif