#include <bits/stdc++.h>
#include <vector>
#include <iostream>
#include <list>
using namespace std;

int mapInput(); 
int navigate();
int N, M; 
int r, c, d;
vector<vector<int>> room(N, vector<int>(M));
int main() {
    mapInput();  // 함수 실행
    return 0;
}

int mapInput() {  // 매개변수 제거
    cin >> N >> M;  // 방의 크기 입력
    cout << "크기 입력 완료" << endl;
    
    
    cin >> r >> c >> d;  // 로봇의 초기 위치 (r, c) 및 방향 d
    cout << "위치 입력 완료" << endl;

      

    // 방의 상태 입력받기
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> room[i][j];
        }
    }

    // 입력된 맵 출력 
    cout << "Room Map:" << endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cout << room[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}

int navigate(int r, int c, int d) {
    
    if (room[r][c] == 0) {
        room[r][c] = 2;
    }
    else if(surroundcheck(r, c, d)== false) {
        if(moveRearAvailable){m}

    };
}

bool surroundcheck(int r, int c, int d) {
    int x_axis[4] = {1, 0, -1, 0};
    int y_axis[4] = {0, 1, 0, -1};
    for (int i = 0; i <= 3; i++) {
        if (room[r + x_axis[i]][c + y_axis[i]] == 0) {
            return true;
            break;
        }
    }
    return false;
}

bool moveRearAvailable(int r, int c, int d) {
    if (d == 0) {
        if (room[r + 1][c] != 1) {
            r = r + 1;
        };
    }
    else if (d == 1) {
        {
            if (room[r][c - 1] != 1) return true;
            c = c - 1;
        }
        }
    }
    else if (d == 2) {
        if (room[r - 1][c] != 1) return true;
    }
    else if (d == 3) {
        if (room[r][c + 1] != 1) return true;
    }
    else {
        return false;
    }
    
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
