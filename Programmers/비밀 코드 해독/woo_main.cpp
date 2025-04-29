#include <bits/stdc++.h>
using namespace std;

int solution(int n, vector<vector<int>> q, vector<int> ans) {
    vector<vector<int>> candidates;

    // 1 전체 조합 생성
    vector<int> nums;
    for (int i = 1; i <= n; ++i) nums.push_back(i);

    vector<int> comb(n, 0);
    fill(comb.end() - 5, comb.end(), 1);

    do {
        vector<int> temp;
        for (int i = 0; i < n; ++i) {
            if (comb[i]) temp.push_back(nums[i]);
        }
        candidates.push_back(temp);
    } while (next_permutation(comb.begin(), comb.end()));

    // 2 시도별 필터링
    for (int i = 0; i < q.size(); ++i) {
        vector<vector<int>> next_candidates;
        for (auto& code : candidates) {
            int match = 0;
            for (int a : code) {
                for (int b : q[i]) {
                    if (a == b) match++;
                }
            }
            if (match == ans[i]) {
                next_candidates.push_back(code);
            }
        }
        candidates = next_candidates;
    }

    //3 남은 후보 개수 반환
    return candidates.size();
}