#include <iostream>
#include <vector>
#include <queue>
#include <map>

using namespace std;

struct SnakeGame {
    int N, K, L;  // 보드 크기, 사과 개수, 방향 변환 횟수
    vector<vector<int>> board;  // 보드 상태
    vector<pair<int, char>> route;  // 방향 전환 정보
    queue<pair<int, int>> snake;  // 뱀의 위치 정보
    int direction = 1;  // 기본 이동 방향 == 동쪽

    
    int dx[4] = { -1, 0, 1, 0 };
    int dy[4] = { 0, 1, 0, -1 }; //북, 동, 남, 서

   
    void input() {
        cin >> N;
        board.resize(N, vector<int>(N, 0));  // 0 = 빈 공간, 1 = 뱀, 2 = 사과

        cin >> K;
        for (int i = 0; i < K; i++) {
            int x, y;
            cin >> x >> y;
            board[x - 1][y - 1] = 2;  // 사과 위치
        }

        cin >> L;
        for (int i = 0; i < L; i++) {
            int X;
            char C;
            cin >> X >> C;
            route.push_back({ X, C }); // 방향 전환 정보
        }

        // 뱀 초기 위치
        snake.push({ 0, 0 });
        board[0][0] = 1;  // 뱀 위치 표시
    }

    // 충돌 확인
    bool crashCheck(int x, int y) {
        return (x < 0 || x >= N || y < 0 || y >= N || board[x][y] == 1);
        // 뱀대가리 위치가 맵 밖 혹은 몸통과 겹칠 경후
    }

    // 뱀 이동 및 게임 실행
    int move() {
        int time = 0;
        int routeIndex = 0;  // 방향 전환 인덱스
        int headX = 0, headY = 0;  // 뱀 머리 위치

        while (true) {
            time++; 
            int newX = headX + dx[direction];
            int newY = headY + dy[direction]; //대가리 전진

            
            if (crashCheck(newX, newY)) return time;

            
            if (board[newX][newY] == 2) {
                board[newX][newY] = 1;  // 사과가 있으면 뱀 길이 증가 (꼬리 제거 X)
            }
            else {  
                auto tail = snake.front();
                snake.pop(); 
                board[tail.first][tail.second] = 0;  // 사과가 없으면 꼬리 제거
            }

            // 머리 위치 갱신
            snake.push({ newX, newY });
            board[newX][newY] = 1;
            headX = newX;
            headY = newY;

            // 방향 전환 체크
            if (routeIndex < L && route[routeIndex].first == time) {
                if (route[routeIndex].second == 'L') {  // 왼쪽 회전
                    direction = (direction + 3) % 4;
                }
                else if (route[routeIndex].second == 'D') {  // 오른쪽 회전
                    direction = (direction + 1) % 4;
                }
                routeIndex++;  // 다음 방향 전환 확인
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