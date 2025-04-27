#include <string>
#include <vector>
#include <iostream>
using namespace std;

int server[25];

int solution(vector<int> players, int m, int k) {
    int answer = 0;

    for (int i = 0; i < players.size(); i++) {
        if (players[i] < m) continue; // m �̸� -> ��������.
        int n = (players[i] - (server[i] * m)) / m;
        if (n <= 0) continue;
        answer += n;
        //cout<<n<<' ';
        for (int j = i; j < i + k; j++) {
            if (j >= players.size()) break; // �����ʰ� �ذ�
            server[j] += n;
        }
    }
    // cout<<'\n';
    // for(int i = 0;i < players.size();i++){
    //     cout<<server[i]<<' ';    
    // }
    return answer;
}