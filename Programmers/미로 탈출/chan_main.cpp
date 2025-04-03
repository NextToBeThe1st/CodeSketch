#include <string>
#include <vector>
#include <iostream>
#include <queue>

#define i_pos 0
#define j_pos 1

int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };

using namespace std;

vector<int> Start;
vector<int> Exit;
vector<int> Lever;

void Find_Pos(vector<string> maps) {

    for (int i = 0; i < maps.size(); ++i) {

        for (int j = 0; j < maps[i].size(); ++j) {

            if (maps[i][j] == 'S') {

                Start.push_back(i);
                Start.push_back(j);
            }
            if (maps[i][j] == 'L') {

                Lever.push_back(i);
                Lever.push_back(j);
            }
            if (maps[i][j] == 'E') {

                Exit.push_back(i);
                Exit.push_back(j);
            }
        }
    }
}

bool Check_Valid(vector<string> maps, int i, int j) {

    return i >= 0 && j >= 0 && i < maps.size() && j < maps[0].size() && maps[i][j] != 'X';
}

int Find_Shortest(vector<string> maps, vector<int> start, vector<int> end) {

    bool visited[100][100] = { 0 };
    int dist[100][100] = { 0 };

    queue<vector<int>> Q;
    Q.push(start);

    visited[start[i_pos]][start[j_pos]] = true;
    dist[start[i_pos]][start[j_pos]] = 0;

    while (!Q.empty()) {

        vector<int> Curr = Q.front();

        int Curr_i = Curr[i_pos];
        int Curr_j = Curr[j_pos];

        Q.pop();

        for (int i = 0; i < 4; ++i) {

            int Next_i = Curr_i + dx[i];
            int Next_j = Curr_j + dy[i];

            // cout <<i <<" -> " << Curr_i << Curr_j <<" to "<< Next_i << Next_j  << endl;

            if (!visited[Next_i][Next_j] && Check_Valid(maps, Next_i, Next_j)) {


                vector<int> Next = { Next_i,Next_j };

                dist[Next_i][Next_j] = dist[Curr_i][Curr_j] + 1;
                visited[Next_i][Next_j] = true;

                Q.push(Next);
            }
        }
    }
    return dist[end[i_pos]][end[j_pos]];
}

int solution(vector<string> maps) {

    int answer = 0;
    Find_Pos(maps);

    int StoL = Find_Shortest(maps, Start, Lever);
    int LtoE = Find_Shortest(maps, Lever, Exit);
    
    if (StoL == 0 || LtoE == 0) {
        return -1;
    }
    return  StoL + LtoE;
}
