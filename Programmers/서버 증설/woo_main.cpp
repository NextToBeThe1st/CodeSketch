#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int solution(vector<int> players, int m, int k) {
    unordered_map<int, int> expiryMap; // ���� �ð� �� ����� ���� ��
    int total_capacity = 0;            // ���� � ���� ������ ���� ������ �� �ο�
    int answer = 0;

    for (int time = 0; time < 24; ++time) {
        // 1. ����� ���� ó��
        if (expiryMap.count(time)) {
            total_capacity -= expiryMap[time] * m;
            expiryMap.erase(time);
        }

        // 2. ���� �ð��� �ʿ��� ����� ó��
        int required = players[time];
        if (total_capacity < required) {
            int shortage = required - total_capacity;
            int toAdd = (shortage + m - 1) / m; // ceil(shortage / m)

            total_capacity += toAdd * m;
            expiryMap[time + k] += toAdd;

            cout << "[" << time << "~" << time + 1 << "��] �����: " << required
                << "�� �� ���� �߰�: " << toAdd << "��" << endl;

            answer += toAdd;
        }
    }

    return answer;
}

int main() {
    vector<int> players = { 0, 2, 3, 3, 1, 2, 0, 0, 0, 0, 4, 2, 0, 6, 0, 4, 2, 13, 3, 5, 10, 0, 1, 5 };
    int m = 3, k = 5;

    int result = solution(players, m, k);
    cout << "�� ���� Ƚ��: " << result << endl;  // expected: 7

    return 0;
}
