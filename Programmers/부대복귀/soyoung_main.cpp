#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(int n, vector<vector<int>> roads, vector<int> sources, int destination) {
    vector<int> answer;
    answer.resize(sources.size());

    vector<vector<int>> paths;

    vector<int> totalDist(100001, -1);

    paths.resize(100001);
    for (auto road : roads)
    {
        paths[road[0]].push_back(road[1]);
        paths[road[1]].push_back(road[0]);
    }

    queue<pair<int, int>> q;
    q.push({ destination, 0 });
    totalDist[destination] = 0;
    while (!q.empty())
    {
        pair<int, int> cur = q.front();
        q.pop();

        for (auto p : paths[cur.first])
        {
            int nextPosition = p;
            if (totalDist[nextPosition] == -1 || totalDist[nextPosition] > cur.second + 1)
            {
                q.push({ nextPosition, cur.second + 1 });
                totalDist[nextPosition] = cur.second + 1;
            }
        }
    }

    for (int i = 0; i < sources.size(); ++i)
    {
        answer[i] = totalDist[sources[i]];
    }

    return answer;
}