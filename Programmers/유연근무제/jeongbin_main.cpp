#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(vector<int> schedules, vector<vector<int>> timelogs, int startday) {
    int answer = 0;

    // ����ð� + 10�б��� ���
    // ��, ���� ���� X
    // �簢 x 100 �ؼ� ������ ǥ�� -> 9��58�� = 958 
    // ����ð�, ��� �ð�, ���� ���� (�� ~ ��)

    for (int k = 0; k < timelogs.size(); k++) { // ����� ��� ����Ʈ
        bool isAward = true;
        int day = startday;
        int deadline = schedules[k];
        if (deadline % 100 >= 50) {
            deadline = ((deadline / 100) * 100 + 100) + (deadline % 10);
        }
        else deadline += 10;
        cout << deadline << '\n';
        for (int i = 0; i < timelogs[k].size(); i++) { // ���Ϻ� ��� �ð�
            if (day % 7 == 0 || day % 7 == 6) {
                day++;
                continue; // ��, �� ����
            }
            if (timelogs[k][i] > deadline) {
                isAward = false;
                cout << "day : " << day << ", time" << timelogs[k][i] << " ? " << deadline << '\n';
                break;
            }
            day++;
        }
        if (isAward) answer++;
    }

    return answer;
}