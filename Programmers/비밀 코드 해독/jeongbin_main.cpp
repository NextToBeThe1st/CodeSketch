#include <string>
#include <vector>

using namespace std;
vector<int> ret;
vector<vector<int>> num;
int answer = 0, cnt;

void combi(int start, vector<int> b) {
    if (b.size() == 5) {
        for (int k = 0; k < num.size(); k++) { // q ���鼭 Ȯ��
            int code_contain_cnt = 0;
            for (int code : b) {
                for (int i = 0; i < num[k].size(); i++) {
                    if (num[k][i] == code) {
                        code_contain_cnt++;
                        break;
                    }
                }
                //if(code_contain_cnt == ret[k]) break; // ���丸ŭ ���ԵǾ� ������ �Ѿ X -> �ʰ��ص� �ȵ�.
            }
            if (code_contain_cnt != ret[k]) return; // ���丸ŭ ���ԵǾ� ���� ������ return
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