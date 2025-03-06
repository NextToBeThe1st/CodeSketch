#include <iostream>
#include <vector>
#include <queue>
#include <map>

using namespace std;

struct SnakeGame {
    int N, K, L;  // ���� ũ��, ��� ����, ���� ��ȯ Ƚ��
    vector<vector<int>> board;  // ���� ����
    vector<pair<int, char>> route;  // ���� ��ȯ ����
    queue<pair<int, int>> snake;  // ���� ��ġ ����
    int direction = 1;  // �⺻ �̵� ���� == ����

    
    int dx[4] = { -1, 0, 1, 0 };
    int dy[4] = { 0, 1, 0, -1 }; //��, ��, ��, ��

   
    void input() {
        cin >> N;
        board.resize(N, vector<int>(N, 0));  // 0 = �� ����, 1 = ��, 2 = ���

        cin >> K;
        for (int i = 0; i < K; i++) {
            int x, y;
            cin >> x >> y;
            board[x - 1][y - 1] = 2;  // ��� ��ġ
        }

        cin >> L;
        for (int i = 0; i < L; i++) {
            int X;
            char C;
            cin >> X >> C;
            route.push_back({ X, C }); // ���� ��ȯ ����
        }

        // �� �ʱ� ��ġ
        snake.push({ 0, 0 });
        board[0][0] = 1;  // �� ��ġ ǥ��
    }

    // �浹 Ȯ��
    bool crashCheck(int x, int y) {
        return (x < 0 || x >= N || y < 0 || y >= N || board[x][y] == 1);
        // ��밡�� ��ġ�� �� �� Ȥ�� ����� ��ĥ ����
    }

    // �� �̵� �� ���� ����
    int move() {
        int time = 0;
        int routeIndex = 0;  // ���� ��ȯ �ε���
        int headX = 0, headY = 0;  // �� �Ӹ� ��ġ

        while (true) {
            time++; 
            int newX = headX + dx[direction];
            int newY = headY + dy[direction]; //�밡�� ����

            
            if (crashCheck(newX, newY)) return time;

            
            if (board[newX][newY] == 2) {
                board[newX][newY] = 1;  // ����� ������ �� ���� ���� (���� ���� X)
            }
            else {  
                auto tail = snake.front();
                snake.pop(); 
                board[tail.first][tail.second] = 0;  // ����� ������ ���� ����
            }

            // �Ӹ� ��ġ ����
            snake.push({ newX, newY });
            board[newX][newY] = 1;
            headX = newX;
            headY = newY;

            // ���� ��ȯ üũ
            if (routeIndex < L && route[routeIndex].first == time) {
                if (route[routeIndex].second == 'L') {  // ���� ȸ��
                    direction = (direction + 3) % 4;
                }
                else if (route[routeIndex].second == 'D') {  // ������ ȸ��
                    direction = (direction + 1) % 4;
                }
                routeIndex++;  // ���� ���� ��ȯ Ȯ��
            }
        }
    }
};

int main() {
    SnakeGame game;
    game.input();
    cout << game.move() << endl;
    return 0;
}