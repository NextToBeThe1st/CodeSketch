#include <string>
#include <vector>
#include <iostream>

using namespace std;

int to_minute(int time) {

    int minute = (time % 100);
    int hour = ((time - minute) / 100) % 100;
    return (hour * 60) + minute;
}

int solution(vector<int> schedules, vector<vector<int>> timelogs, int startday) {

    int answer = schedules.size();

    for (int p = 0; p < schedules.size(); ++p) {

        for (int d = 0; d < 7; ++d) {

            int day = ((startday + d - 1) % 7) + 1;

            if (day == 6 || day == 7) {
                continue;
            }
            else if (to_minute(schedules[p]) + 10 < to_minute(timelogs[p][d])) {
                answer--;
                break;
            }

        }
    }
    return answer;
}
