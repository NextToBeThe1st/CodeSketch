#include <iostream>
#include <vector>
using namespace std;

int solution(vector<int> schedules, vector<vector<int>> timelogs, int startday) {
    int n = schedules.size();
    int result = 0;

    for (int i = 0; i < n; ++i) {
        int hope = schedules[i];
        int hope_hour = hope / 100;
        int hope_min = hope % 100;
        int hope_total = hope_hour * 60 + hope_min + 10; // 인정 범위 (희망 + 10분)

        bool ok = true;
        for (int j = 0; j < 7; ++j) {
            int day = (startday + j - 1) % 7 + 1; // 1~7 (월~일)

            if (day >= 1 && day <= 5) { // 평일만
                int actual = timelogs[i][j];
                int act_hour = actual / 100;
                int act_min = actual % 100;
                int act_total = act_hour * 60 + act_min; // 실제 출근 시간

                if (act_total > hope_total) {
                    ok = false; // 지각
                    break;
                }
            }
        }
        if (ok) result++;
    }
    return result;
}
