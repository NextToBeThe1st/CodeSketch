#include <iostream>
#include <string>
using namespace std;
//이기는 배열
int win[8][3] = {
    {0,1,2}, {3,4,5}, {6,7,8},
    {0,3,6}, {1,4,7}, {2,5,8},
    {0,4,8}, {2,4,6}
};

//이겼냐?? 결과가 났냐?
bool isWin(const string& board, char player) {
    for (int i = 0; i < 8; i++) {
        if (board[win[i][0]] == player &&
            board[win[i][1]] == player &&
            board[win[i][2]] == player) {
            return true;
        }
    }
    return false;
}

bool isValid(const string& board) {
    int xCount = 0, oCount = 0;

    for (char c : board) {
        if (c == 'X') xCount++;
        else if (c == 'O') oCount++;
    }

    bool xWin = isWin(board, 'X');
    bool oWin = isWin(board, 'O');

    // 기본 조건 위반
    if (oCount > xCount || xCount - oCount > 1) return false;

    // 둘 다 승리? 불가능
    if (xWin && oWin) return false;

    // X가 이겼다면 X가 한 수 더 많아야 함
    if (xWin && xCount != oCount + 1) return false;

    // O가 이겼다면 X, O 수 같아야 함
    if (oWin && xCount != oCount) return false;

    // 승리 없고, 9칸 다 찬 경우는 무승부
    if (!xWin && !oWin && xCount + oCount == 9) return true;

    // 승리 조건에 맞는 경우
    if (xWin || oWin) return true;

    // 게임이 아직 안 끝났는데 입력된 경우
    return false;
}

int main() {
    string board;
    while (cin >> board && board != "end") {
        if (isValid(board)) cout << "valid\n";
        else cout << "invalid\n";
    }
    return 0;
}