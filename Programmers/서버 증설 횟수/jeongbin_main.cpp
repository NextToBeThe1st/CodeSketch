#include <string>
#include <vector>
#include <iostream>
using namespace std;

int server[25];

int solution(vector<int> players, int m, int k) {
    int answer = 0;

    for (int i = 0; i < players.size(); i++) {
        if (players[i] < m) continue; // m 미만 -> 증설안함.
        int n = (players[i] - (server[i] * m)) / m;
        if (n <= 0) continue;
        answer += n;
        //cout<<n<<' ';
        for (int j = i; j < i + k; j++) {
            if (j >= players.size()) break; // 범위초과 해결
            server[j] += n;
        }
    }
    // cout<<'\n';
    // for(int i = 0;i < players.size();i++){
    //     cout<<server[i]<<' ';    
    // }
    return answer;
}