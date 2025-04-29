#include <string>
#include <vector>

using namespace std;

// 백트래킹
void backtrack(int idx, int n, vector<vector<int>>& q, vector<int>& ans, vector<int> current, int& answer)
{
    if (current.size() == 5)
    {
        bool isValid = true;
        int qs = q.size();
        for (int i = 0; i < qs; ++i)
        {
            int cnt = 0;
            for (auto a : current)
            {
                for (auto b : q[i]) {
                    if (a == b) cnt++;
                }
            }
            if (cnt != ans[i])
            {
                isValid = false;
                break;
            }

        }
        if (isValid) answer++;
        return;
    }
    if (idx > n) return;
    current.push_back(idx);
    backtrack(idx + 1, n, q, ans, current, answer);
    current.pop_back();
    backtrack(idx + 1, n, q, ans, current, answer);
}

int solution(int n, vector<vector<int>> q, vector<int> ans) {
    int answer = 0;
    vector<int> current;
    backtrack(1, n, q, ans, current, answer);
    return answer;
}