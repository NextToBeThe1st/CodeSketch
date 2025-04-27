#include <string>
#include <vector>

using namespace std;
vector<int> ret;
vector<vector<int>> num;
int answer = 0, cnt;

void combi(int start, vector<int> b) {
    if (b.size() == 5) {
        for (int k = 0; k < num.size(); k++) { // q 돌면서 확인
            int code_contain_cnt = 0;
            for (int code : b) {
                for (int i = 0; i < num[k].size(); i++) {
                    if (num[k][i] == code) {
                        code_contain_cnt++;
                        break;
                    }
                }
                //if(code_contain_cnt == ret[k]) break; // 정답만큼 포함되어 있으면 넘어감 X -> 초과해도 안됨.
            }
            if (code_contain_cnt != ret[k]) return; // 정답만큼 포함되어 있지 않으면 return
        }

        answer++;
        return;
    }
    for (int i = start; i <= cnt; i++) {
        b.push_back(i);
        combi(i + 1, b);
        b.pop_back();
    }
}

int solution(int n, vector<vector<int>> q, vector<int> ans) {
    cnt = n;
    ret = ans;
    num = q;
    vector<int> b;
    combi(1, b);

    return answer;
}