#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int ft, ed;
pair<int, int> wan;

bool comp(vector<int> a, vector<int> b) {
    if ((a[0] + a[1]) == (b[0] + b[1])) return a[0] > b[0];
    else return (a[0] + a[1]) > (b[0] + b[1]);
}

int solution(vector<vector<int>> scores) {
    int answer = 0;

    wan = { scores[0][0], scores[0][1] };

    sort(scores.begin(), scores.end(), comp);
    int cnt = 0;
    for (int i = 0; i < scores.size(); i++) {
        if (wan.first == scores[i][0] && wan.second == scores[i][1]) {
            cnt = i;
            break;
        }
    }
    for (int i = 0; i < cnt; i++) { // ��ȣ �� ��ȣ�� Ȯ���ص� ��.
        for (int j = 0; j < scores.size(); j++) {
            if (scores[i][0] < scores[j][0] && scores[i][1] < scores[j][1]) {
                scores[i][0] = -1;
                scores[i][1] = -1;
                break;
            }
        }
    }

    for (int i = 0; i < scores.size(); i++) { // ��ȣ�� ������ ���� �� �ִ���
        if (scores[i][0] > wan.first && scores[i][1] > wan.second) return -1;
    }
    sort(scores.begin(), scores.end(), comp);

    // for(int i = 0;i < scores.size();i++){
    //     cout<<scores[i][0] <<", " << scores[i][1]<<'\n';
    // }
    int prev = scores[0][0] + scores[0][1];
    if (prev == wan.first + wan.second) return 1; // ��ȣ�� 1���� ���
    answer = 1;
    for (int i = 1; i < scores.size(); i++) {
        if (scores[i][0] + scores[i][1] < prev) { // ���� ������ ������ ��� ++
            answer = i + 1;
        }
        prev = scores[i][0] + scores[i][1];
        if (wan.first + wan.second == scores[i][0] + scores[i][1]) break;
    }

    return answer;
}