#include <string>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<bool>> ADJ;
vector<bool> Visited;
vector<int> Distance;

void Resize(int n) {

    Visited.resize(n + 1);
    Distance.resize(n + 1);
    ADJ.resize(n + 1);
    for (int i = 0; i < n + 1; ++i) {
        ADJ[i].resize(n + 1);
    }
}

void BFS(int start) {

    queue<int> Q;
    Q.push(start);
    Visited[start] = true;
    Distance[start] = 0;

    while (!Q.empty()) {

        int Curr = Q.front();
        Q.pop();

        for (int Next = 1; Next < ADJ.size(); ++Next) {

            if ((ADJ[Next][Curr] || ADJ[Curr][Next]) && !Visited[Next]) {

                Q.push(Next);
                Visited[Next] = true;
                Distance[Next] = Distance[Curr] + 1;
            }
        }
    }
}

vector<int> solution(int n, vector<vector<int>> roads, vector<int> sources, int destination) {

    vector<int> answer;
    Resize(n);

    for (int i = 0; i < roads.size(); ++i) {

        ADJ[roads[i][0]][roads[i][1]] = true;
        ADJ[roads[i][1]][roads[i][0]] = true;
    }
    BFS(destination);

    for (int i = 0; i < sources.size(); ++i) {

        if (Visited[sources[i]]) {
            answer.push_back(Distance[sources[i]]);
        }
        else {
            answer.push_back(-1);
        }
    }
    return answer;
}