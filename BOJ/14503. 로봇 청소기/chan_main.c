#include <stdio.h>
#pragma warning(disable:4996)

int map[55][55];
int N, M;
int r, c, d;
int Visited[55][55];
int Count;

int Dir_R[4] = { -1,0,1,0 };
int Dir_C[4] = { 0,1,0,-1 };

int Check_Valid(int R, int C) {

    return (R >= 0) && (R < N) && (C >= 0) && (C < M);
}

int Check_space(int R, int C) {

    int nextR = 0;
    int nextC = 0;

    for (int i = 0; i < 4; i++) {

        nextR = R + Dir_R[i];
        nextC = C + Dir_C[i];

        if (!Visited[nextR][nextC] && !map[nextR][nextC] && Check_Valid(nextR, nextC)) { // 벽이 아닌것 중, 하나라도 방문 안한게 있다면

            return 1; //아직 청소안된 칸이 있음
        }
    }
    return 0; // 모든 칸이 청소 완료
}

int Turn_CCW(int D) { // 반시계 방향 회전

    if (D == 0) return 3;
    else return (D - 1);
}

void Clean(int startR, int startC, int startD) {

    if (!Visited[startR][startC]) {

        Count++;
        Visited[startR][startC] = 1;
    }

    int currD = startD;
    int nextR = 0;
    int nextC = 0;

    if (Check_space(startR, startC)) {

        for (int i = 0; i < 4; i++)
        {
            currD = Turn_CCW(currD);
            nextR = startR + Dir_R[currD];
            nextC = startC + Dir_C[currD];

            if (!Visited[nextR][nextC] && !map[nextR][nextC] && Check_Valid(nextR, nextC)) {

                Clean(nextR, nextC, currD);
                return;
            }
        }
    }
    else {

        nextR = startR - Dir_R[currD];
        nextC = startC - Dir_C[currD];

        if (!map[nextR][nextC] && Check_Valid(nextR, nextC))
            Clean(nextR, nextC, currD);

    }
}

int main(void) {

    scanf("%d %d", &N, &M);
    scanf("%d %d %d", &r, &c, &d);

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            scanf("%d", &map[i][j]);
        }
    }
    Clean(r, c, d);
    printf("%d", Count);
}