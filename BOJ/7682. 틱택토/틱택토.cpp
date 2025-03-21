#include <iostream>
#include <string>
using namespace std;
//�̱�� �迭
int win[8][3] = {
    {0,1,2}, {3,4,5}, {6,7,8},
    {0,3,6}, {1,4,7}, {2,5,8},
    {0,4,8}, {2,4,6}
};

//�̰��?? ����� ����?
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

    // �⺻ ���� ����
    if (oCount > xCount || xCount - oCount > 1) return false;

    // �� �� �¸�? �Ұ���
    if (xWin && oWin) return false;

    // X�� �̰�ٸ� X�� �� �� �� ���ƾ� ��
    if (xWin && xCount != oCount + 1) return false;

    // O�� �̰�ٸ� X, O �� ���ƾ� ��
    if (oWin && xCount != oCount) return false;

    // �¸� ����, 9ĭ �� �� ���� ���º�
    if (!xWin && !oWin && xCount + oCount == 9) return true;

    // �¸� ���ǿ� �´� ���
    if (xWin || oWin) return true;

    // ������ ���� �� �����µ� �Էµ� ���
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