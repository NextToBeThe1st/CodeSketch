#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;
// 같은 시간대에 게임을 이용하는 사람이 m명
// m명 미만이라면 서버 증설 필요X
// 하나의 서버는 k시간 동안 운영하고, 그 이후에는 반납
// players의 길이는 24
int solution(vector<int> players, int m, int k) {
    int answer = 0;
    queue<pair<int, int>> q;
    for (int i = 0; i < 24; ++i)
    {
        while (q.size() > 0)
        {
            if (i - q.front().second >= k)
            {
                q.pop();
            }
            else {
                break;
            }
        }
        while (true)
        {
            if (players[i] >= m * (q.size() + 1))
            {
                q.push({ k, i });
                answer++;
            }
            else break;
        }
    }
    return answer;
}