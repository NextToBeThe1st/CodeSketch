#include <iostream>

#define Max 105
#define Snake -1 //���� �ִ� ĭ (��ó�� ���)
#define Apple 1

using namespace std;

int Size, NumofApple, NumofTurn;

int Map[Max][Max];

int TurnSec[Max]; //���� ���ƾ� �ϴ��� Ȯ��
char TurnDir[Max];

int Snake_Pos_X[Max * Max]; //���� �Ӹ��� ���� ��ǥ ��Ͽ� �迭
int Snake_Pos_Y[Max * Max]; 

int head,tail,Second, Direction;

int dx[4] = { 0,1,0,-1 }; //������ [][+1] �Ʒ��� [+1][0] ���� [0][-1] ���� [-1][0]
int dy[4] = { 1,0,-1,0 };

int Turn(int dir, char Instruction) {

    if (Instruction == 'L') return (dir + 3) % 4;
    else if (Instruction == 'D') return (dir + 1) % 4;
}

int Check_Valid(int x, int y) {

    return x >= 1 && x <= Size && y >= 1 && y <= Size && Map[x][y] != Snake; 
}

void Init_Snake() {

    Snake_Pos_X[head] = 1;
    Snake_Pos_Y[head] = 1;  //�Ӹ��� ���� ��ġ�� 1,1

    Map[1][1] = Snake;
}

void Start_Game() {

    Init_Snake();

    int temp = 0;

    while (1) {

        Second++;

        int NextX = Snake_Pos_X[head] + dx[Direction];
        int NextY = Snake_Pos_Y[head] + dy[Direction];

        if (!Check_Valid(NextX, NextY)) {
            cout << Second << endl;
            break;
        }

        if (Map[NextX][NextY] != Apple) {
            Map[Snake_Pos_X[tail]][Snake_Pos_Y[tail]] = 0;
            tail++;
        }

        head++;
        Snake_Pos_X[head] = NextX;
        Snake_Pos_Y[head] = NextY;
        Map[NextX][NextY] = Snake;

        if ( Second == TurnSec[temp]) {
            Direction = Turn(Direction, TurnDir[temp]);
            temp++;
        }
    }
    return;
}

int main(void) {

    int Tempi, Tempj;

    cin >> Size;
    cin >> NumofApple;

    for (int i = 0; i < NumofApple; ++i) {

        cin >> Tempi >> Tempj;
        Map[Tempi][Tempj] = Apple;
    }
    cin >> NumofTurn;

    for (int i = 0; i < NumofTurn; ++i) {

        cin >> TurnSec[i] >> TurnDir[i];
    }
    Start_Game();
    return 0;
}