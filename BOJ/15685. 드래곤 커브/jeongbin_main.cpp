#if 0
#include <iostream>
#include <stack>
#define LIMIT 100
using namespace std;

int n;
bool arr[104][104];
int dx[] = { 1, 0, -1, 0 }; // �ݽð�
int dy[] = { 0, -1, 0, 1 };
int cwx[] = { 0,-1,1,1 }; // 0 -> 1, 1 -> 2, 2 -> 3, 3 -> 4 ������ �ð���� ȸ��
int cwy[] = { 1,-1,-1,1 };
stack<pair<pair<int, int>,int>> st; // ��ǥ, ����

void make_dragon_curv(int y, int x, int d, int g) {
	arr[y][x] = true;
	st.push({{ y,x }, d }); // ���� ��ġ �Է�
	int ny = y + dy[d];
	int nx = x + dx[d];
	st.push({ { ny,nx }, -1 });
	arr[ny][nx] = true; // 0���� ó��

	for (int i = 0; i < g; i++) {
		stack<pair<pair<int, int>, int>> tmp;
		int cy = st.top().first.first;
		int cx = st.top().first.second; // �߽��� �� x, y�� ����
		int cd = st.top().second; // ���� 
		tmp.push({ { cy,cx }, cd });
		st.pop();
		while (st.size()) {
			int py = st.top().first.first;
			int px = st.top().first.second; // ���� x, y �� ����
			int pd = st.top().second;  // ����
			tmp.push({ { py,px }, pd});
			st.pop();

			// ���� ������ ���� ��ǥ�� �ʱ� ������ -1�� ����
			// ���� ��ǥ ����
			int ny = py + cwy[pd];
			int nx = px + cwx[pd];
			int nd = (pd + 1) % 4;

			if (ny < 0 || nx < 0 || ny >= LIMIT || nx >= LIMIT) continue;
			arr[ny][nx] = true;
			


			cy = py;
			cx = px; // �߽� x, y �� ����
		}
		while (tmp.size()) {
			st.push(tmp.top());
			tmp.pop();
		}
	}

}

void solution() {
	int x, y, d, g;
	cin >> n;
	for (int i = 0; i < n; i++) {
		st = stack<pair<pair<int, int>, int>>(); // ���� �ʱ�ȭ

		cin >> x >> y >> d >> g;
		make_dragon_curv(y, x, d, g); // �巡�� Ŀ�� ����

	}
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);

	solution();

	return 0;
}
#endif // ����... 

#if 0
#include <iostream>
#include <vector>
#define LIMIT 100
using namespace std;

int n, ret;
bool arr[104][104];
vector<int> v;
int dx[] = { 1, 0, -1, 0 }; // ���� ����
int dy[] = { 0, -1, 0, 1 };

void check_box();
void draw_dragon_curv(int y, int x);
void make_dragon_curv(int d, int g);
void solution();

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	solution();

	return 0;
}

void solution() {
	int x, y, d, g;
	cin >> n;
	for (int i = 0; i < n; i++) {

		cin >> x >> y >> d >> g;
		make_dragon_curv(d, g); // �巡�� Ŀ�� ����
		draw_dragon_curv(y, x);
	}
	check_box();
}
void make_dragon_curv(int d, int g) {
	v.clear(); // Ŀ�� �ʱ�ȭ
	v.push_back(d); // 0����� �⺻������ ����
	for (int i = 0; i < g; i++) {
		vector<int> curv; // ������ �巡�� Ŀ��
		for (int j = v.size() - 1; j >= 0; j--) {
			curv.push_back((v[j] + 1) % 4); // (���� + 1) % 4
		}
		// ���� Ŀ�꿡 �߰�
		for (int j = 0; j < curv.size(); j++) {
			v.push_back(curv[j]);
		}
	}
}
void draw_dragon_curv(int y, int x) {
	int ny, nx;
	arr[y][x] = true;
	for (int i : v) {
		ny = y + dy[i];
		nx = x + dx[i];

		arr[ny][nx] = true;
		// x,y ��ǥ ����
		y = ny;
		x = nx;
	}
}
void check_box() {
	for (int i = 0; i <= LIMIT; i++) {
		for (int j = 0; j <= LIMIT; j++) {
			if (arr[i][j] && arr[i][j + 1] && arr[i + 1][j] && arr[i + 1][j + 1]) ret++;
			//cout << arr[i][j] << ' ';
		}
		//cout << '\n';
	}
	cout << ret;
}
#endif // ����