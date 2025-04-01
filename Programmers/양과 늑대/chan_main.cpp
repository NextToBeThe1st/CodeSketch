#include <string>
#include <vector>
#include <iostream>

#define Sheep 0
#define Wolf 1

using namespace std;

int ADJ[20][20];
int Node[20];

int visited[1 << 17];

int sheep_count;
int info_size;

void CountSheep(int state, int sheep, int wolf){
    
    if (sheep == wolf){
        return;
    }
    if (visited[state]){
        return;
    }
    visited[state] = true;

    if (sheep > sheep_count){
        sheep_count = sheep;
    }

    for (int i = 0; i < info_size; ++i){
        
        if (state & (1 << i)){
            
            for (int j = 0; j < info_size; ++j){
                
                if (ADJ[i][j] == 1 && !(state & (1 << j))){
                    
                    CountSheep(state | (1 << j), sheep + (Node[j] == Sheep), wolf + (Node[j] == Wolf));
                }
            }
        }
    }
}

int solution(vector<int> info, vector<vector<int>> edges){
    
    info_size = info.size();
    sheep_count = 0;

    for (int i = 0; i < info_size; ++i){
        Node[i] = info[i];
    }

    for (int i = 0; i < edges.size(); ++i){
        
        ADJ[edges[i][0]][edges[i][1]] = 1;
        ADJ[edges[i][1]][edges[i][0]] = 1;
    }

    CountSheep(1 << 0, 1, 0);

    return sheep_count;
}
