#include <string>
#include <vector>

using namespace std;

int solution(vector<int> schedules, vector<vector<int>> timelogs, int startday) {
    int answer = 0;
    for (int i = 0; i < schedules.size(); ++i)
    {
        int hour = schedules[i] / 100;
        int minute = schedules[i] % 100 + 10;
        if (minute >= 60) {
            hour += 1;
            minute -= 60;
        }
        int limitTime = hour * 100 + minute;
        bool late = false;
        for (int j = 0; j < 7; ++j) {
            int today = (startday - 1 + j) % 7 + 1;

            if (today >= 6) continue;

            if (timelogs[i][j] > limitTime) {
                late = true;
                break;
            }
        }

        if (!late) answer++;

    }


    return answer;
}