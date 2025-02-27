#include <vector>
#include <iostream>
using namespace std;

int mapInput();
void navigate(int& r, int& c, int& d);
bool checkRear(int r, int c, int d);
bool surroundcheck(int r, int c, int d);
void moveRear(int& r, int& c, int d);
bool checkFrontAndMove(int& r, int& c, int& d);

int N, M;
int r, c, d;
int cleanCount;
vector<vector<int>> room;  //크기는 mapInput()에서 재설정)

int main() {
    cleanCount = 0;
    mapInput();  // 맵 입력
    navigate(r, c, d);  // 로봇 작동 시작
    cout << cleanCount << endl;  // 최종 청소된 칸 개수 출력
    return 0;
}

int mapInput() {
    cin >> N >> M;
    cout << "크기 입력 완료" << endl;

    cin >> r >> c >> d;
    cout << "위치 입력 완료" << endl;

    room.resize(N, vector<int>(M));  // 벡터 크기 재설정

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> room[i][j];
        }
    }

    return 0;
}

void navigate(int& r, int& c, int& d) {
    while (true) {
        if (room[r][c] == 0) {  //현재 위치 청소
            room[r][c] = 2;
            cleanCount++;
        }

        if (surroundcheck(r, c, d) == false) {  // 주변에 청소할 곳이 없는 경우
            if (checkRear(r, c, d) == false) {  // 후진 가능 여부 확인
                return;  // 후진 불가능하면 종료
            }
            else {
                moveRear(r, c, d);  // 후진 수행
            }
        }
        else {  // 주변에 청소할 곳이 있는 경우
            checkFrontAndMove(r, c, d); //회전, 전방 이동
        }
    }
}

bool surroundcheck(int r, int c, int d) {
    int dx[4] = { -1, 0, 1, 0 };  // 북, 동, 남, 서
    int dy[4] = { 0, 1, 0, -1 };

    for (int i = 0; i < 4; i++) {
        int nx = r + dx[i];
        int ny = c + dy[i];

        if (nx >= 0 && nx < N && ny >= 0 && ny < M && room[nx][ny] == 0) {  // 벡터 범위 초과 방지
            return true;
        }
    }
    return false;
}

bool checkRear(int r, int c, int d) {
    int dx[4] = { 1, 0, -1, 0 };  // 후진 방향 (북 → 남, 동 → 서, 남 → 북, 서 → 동)
    int dy[4] = { 0, -1, 0, 1 };

    int nx = r + dx[d];
    int ny = c + dy[d];

    return (nx >= 0 && nx < N && ny >= 0 && ny < M && room[nx][ny] != 1);  
}

void moveRear(int& r, int& c, int d) {
    int dx[4] = { 1, 0, -1, 0 };  // 후진 방향
    int dy[4] = { 0, -1, 0, 1 };

    int nx = r + dx[d];
    int ny = c + dy[d];

    if (nx >= 0 && nx < N && ny >= 0 && ny < M) { 
        r = nx;
        c = ny;
    }
}

bool checkFrontAndMove(int& r, int& c, int& d) {
    // 반시계 방향으로 90도 회전
    d = (d + 3) % 4;  // 북(0) → 서(3) → 남(2) → 동(1)

    int dx[4] = { -1, 0, 1, 0 };  // 북, 동, 남, 서
    int dy[4] = { 0, 1, 0, -1 };

    int nx = r + dx[d];
    int ny = c + dy[d];

    if (nx >= 0 && nx < N && ny >= 0 && ny < M && room[nx][ny] == 0) {  
        r = nx;
        c = ny;
        return true;
    }
    return false;
}

/*if (map[cur] != cleaned) :
    map[cur] = cleaned
elif(surroundingCheck == 0):
    if(backwardAvailable == 1):
        moveBack(cur, direction)eo
    else: break
else:
    direction = direction--
    if(forwardCheck):
        moveForward(cur, direction)*/


/*
    1. 현재 칸이 아직 청소되지 않은 경우, 현재 칸을 청소한다.
   
    2. 현재 칸의 주변 4칸 중 청소되지 않은 빈 칸이 없는 경우,
        바라보는 방향을 유지한 채로 한 칸 후진할 수 있다면 한 칸 후진하고 1번으로 돌아간다.
        바라보는 방향의 뒤쪽 칸이 벽이라 후진할 수 없다면 작동을 멈춘다.

    3.현재 칸의 주변 4칸 중 청소되지 않은 빈 칸이 있는 경우,
        반시계 방향으로 90도 회전한다.
        바라보는 방향을 기준으로 앞쪽 칸이 청소되지 않은 빈 칸인 경우 한 칸 전진한다.
        1번으로 돌아간다.
*/
