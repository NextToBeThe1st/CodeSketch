#if 0
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
vector<vector<string>> applicant;
vector<vector<string>> condition;

vector<string> split(string str) {
    vector<string> v;

    int idx = 0;
    int curr = 0;

    while ((idx = str.find(" ", curr)) != string::npos) { // ' '를 idx 이후에서 찾음
        auto len = idx - curr;
        string tmp = str.substr(curr, len);
        if (tmp == "and") {
            curr = idx + 1;
            continue;
        }
        v.push_back(tmp);
        curr = idx + 1;
    }
    v.push_back(str.substr(curr));
    return v;
}

bool comp(vector<string> a, vector<string> b) {
    return stoi(a[4]) < stoi(b[4]); // 오름차순
}

int findby(int idx, int size) { // 조건 번호, 지원자 수
    int cnt = 0;
    int i = 0;
    if (condition[idx][4] != "-") {
        int l = 0, r = size - 1;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (stoi(applicant[mid][4]) < stoi(condition[idx][4])) {
                l = mid + 1;
            }
            else {
                r = mid - 1; // 지원자 성적이 큰 경우는 i 값도 갱신 필요
                i = mid;
            }
        }
    }
    for (; i < size; i++) {
        bool flag = false;
        // 언어
        if (condition[idx][0] == "-" || (applicant[i][0] == condition[idx][0])) flag = true;
        else continue;
        // 직군
        if (condition[idx][1] == "-" || (applicant[i][1] == condition[idx][1])) flag = true;
        else continue;
        // 경력
        if (condition[idx][2] == "-" || (applicant[i][2] == condition[idx][2])) flag = true;
        else continue;
        // 음식
        if (condition[idx][3] == "-" || (applicant[i][3] == condition[idx][3])) flag = true;
        else continue;

        if (condition[idx][4] == "-") flag = true; // 점수
        else if (stoi(applicant[i][4]) >= stoi(condition[idx][4])) flag = true;
        else continue;

        if (flag) {
            //cout<<i<<',';
            cnt++;
        }
    }
    return cnt;
}

vector<int> solution(vector<string> info, vector<string> query) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    vector<int> answer;

    for (int i = 0; i < info.size(); i++) {
        applicant.push_back(split(info[i]));
    }
    for (int i = 0; i < query.size(); i++) {
        condition.push_back(split(query[i]));
    }
    //----

    // 언어, 직군, 경력, 음식, 점수
    sort(applicant.begin(), applicant.end(), comp);
    // for(int i = 0;i < query.size();i++){
    //     for(int j = 0;j < condition[i].size();j++){
    //         cout<<condition[i][j]<<' ';
    //     }cout<<'\n';
    // }
    for (int i = 0; i < query.size(); i++) {
        answer.push_back(findby(i, info.size()));
        cout << '\n';
    }

    return answer;
}
#endif // 효율성 0...
