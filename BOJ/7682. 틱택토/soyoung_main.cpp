#include <bits/stdc++.h>
#include <unordered_map>
#include <stdio.h>
using namespace std;

string inputStr;
char board[3][3];
int x = 0, o = 0, p = 0;
unordered_map<char, bool> winner;


bool inputData();
bool checkTicTacToe();

int main() {
    while (inputData()) {
        if (checkTicTacToe()) {
            cout << "valid" << endl;
        }
        else {
            cout << "invalid" << endl;
        }
    }
}

bool inputData() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    x = 0; o = 0; p = 0;
    if (!(cin >> inputStr) || inputStr == "end") {
        return false;
    }
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            board[i][j] = inputStr[(i*3)+j];
            if (inputStr[(i * 3) + j] == 'X') x++;
            else if (inputStr[(i * 3) + j] == 'O') o++;
            else p++;
        }
    }
    return true;
}

bool checkTicTacToe() {
    winner['O'] = false;
    winner['X'] = false;
    if (!(x - o == 0 || x - o == 1)) {
        return false;
    }
    for (int i = 0; i < 3; ++i) {
        if (board[i][0] != '.' && board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            winner[board[i][0]] = true;
        }
        if (board[0][i] != '.' && board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
            winner[board[0][i]] = true;
        }
    }
    if (board[1][1] != '.' && ((board[0][0] == board[1][1] && board[1][1] == board[2][2]) || (board[0][2] == board[1][1] && board[1][1] == board[2][0]))) {
        winner[board[1][1]] = true; 
    }
    if (winner['X']){
        if (x-o == 1 && !winner['O']) {
            return true;
        }
    }
    else {
        if (winner['O']) {
            if (x == o) return true;
        }
        else {
            if (p == 0) return true;
        }
    }
    return false;
}