#if 0

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;
int arr[24][27];
vector<string> tmp_courseList[14]; // �� course ���� ���� �ִ밪.
int courseMax[14];
map<string, int> mp;

void combi(int start, string tmp, string order) { // ����
    if (tmp.length() > order.length()) { // ������ order���� ������ return
        return;
    }
    mp[tmp]++;
    for (int i = start + 1;i < order.length();i++) {
        tmp += order[i]; // �ڽ� �߰�
        combi(i, tmp, order); // ����
        tmp.pop_back(); // �ڽ� ����
    }
}

vector<string> solution(vector<string> orders, vector<int> course) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    vector<string> answer;

    for (auto iter : orders) {
        sort(iter.begin(), iter.end()); // �ڽ�����
        combi(-1, "", iter);
    }
    // for(auto iter : mp){
    //     cout<<s.first << " : "<< s.second<<'\n';
    // }

    for (auto s : mp) {
        int len = s.first.length(); // �������� 
        // course ���� ���̰� ���Ե��� �ʴ´ٸ� �������� �Ѿ
        if (find(course.begin(), course.end(), len) == course.end()) continue;
        if (s.second < 2) continue;
        if (courseMax[len] < s.second) { // �� ũ�� �迭 ���� �߰�
            tmp_courseList[len].clear();
            tmp_courseList[len].push_back(s.first);
            courseMax[len] = s.second;
        }
        else if (courseMax[len] == s.second) { // ������ �׳� �߰�
            tmp_courseList[len].push_back(s.first);
        }
    }

    for (auto courseNum : course) {
        for (auto courseList : tmp_courseList[courseNum]) { // �ڽ� answer�� �ֱ�
            answer.push_back(courseList);
        }
    }
    sort(answer.begin(), answer.end()); // ������� ����
    return answer;
}

#endif // 0
