#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(int n, vector<vector<int>> q, vector<int> ans) {
    int answer = 0;
    vector<int> numbers;

    for (int i = 1; i <= n; i++) {
        numbers.push_back(i);
    }

    vector<int> select;
    for (int i = 0; i < n - 5; i++) select.push_back(0);
    for (int i = 0; i < 5; i++) select.push_back(1);


    do {
        vector<int> candidate;

        for (int i = 0; i < n; i++) {
            if (select[i] == 1) {
                candidate.push_back(numbers[i]);
            }
        }

        bool ok = true;

        for (int i = 0; i < q.size(); i++) {
            int count = 0;

            for (int j = 0; j < 5; j++) {
                for (int k = 0; k < 5; k++) {
                    if (candidate[j] == q[i][k]) {
                        count++;
                    }
                }
            }
            if (count != ans[i]) {
                ok = false;
                break;
            }
        }
        if (ok) {
            answer++;
        }

    } while (next_permutation(select.begin(), select.end()));

    return answer;
}
