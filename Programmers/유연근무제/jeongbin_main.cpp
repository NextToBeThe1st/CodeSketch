#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(vector<int> schedules, vector<vector<int>> timelogs, int startday) {
    int answer = 0;

    // 희망시간 + 10분까지 출근
    // 토, 일은 영향 X
    // 사각 x 100 해서 정수로 표현 -> 9시58분 = 958 
    // 희망시각, 출근 시각, 시작 요일 (월 ~ 일)

    for (int k = 0; k < timelogs.size(); k++) { // 사람별 출근 리스트
        bool isAward = true;
        int day = startday;
        int deadline = schedules[k];
        if (deadline % 100 >= 50) {
            deadline = ((deadline / 100) * 100 + 100) + (deadline % 10);
        }
        else deadline += 10;
        cout << deadline << '\n';
        for (int i = 0; i < timelogs[k].size(); i++) { // 요일별 출근 시간
            if (day % 7 == 0 || day % 7 == 6) {
                day++;
                continue; // 토, 일 제외
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