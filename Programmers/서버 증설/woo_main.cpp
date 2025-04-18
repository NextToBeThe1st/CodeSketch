#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int solution(vector<int> players, int m, int k) {
    unordered_map<int, int> expiryMap; // 종료 시각 → 만료될 서버 수
    int total_capacity = 0;            // 현재 운영 중인 서버가 감당 가능한 총 인원
    int answer = 0;

    for (int time = 0; time < 24; ++time) {
        // 1. 만료된 서버 처리
        if (expiryMap.count(time)) {
            total_capacity -= expiryMap[time] * m;
            expiryMap.erase(time);
        }

        // 2. 현재 시간에 필요한 사용자 처리
        int required = players[time];
        if (total_capacity < required) {
            int shortage = required - total_capacity;
            int toAdd = (shortage + m - 1) / m; // ceil(shortage / m)

            total_capacity += toAdd * m;
            expiryMap[time + k] += toAdd;

            cout << "[" << time << "~" << time + 1 << "시] 사용자: " << required
                << "명 → 서버 추가: " << toAdd << "대" << endl;

            answer += toAdd;
        }
    }

    return answer;
}

int main() {
    vector<int> players = { 0, 2, 3, 3, 1, 2, 0, 0, 0, 0, 4, 2, 0, 6, 0, 4, 2, 13, 3, 5, 10, 0, 1, 5 };
    int m = 3, k = 5;

    int result = solution(players, m, k);
    cout << "총 증설 횟수: " << result << endl;  // expected: 7

    return 0;
}
