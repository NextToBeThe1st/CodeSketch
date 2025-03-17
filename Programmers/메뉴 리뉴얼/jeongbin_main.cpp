#if 0

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;
int arr[24][27];
vector<string> tmp_courseList[14]; // 각 course 수의 현재 최대값.
int courseMax[14];
map<string, int> mp;

void combi(int start, string tmp, string order) { // 조합
    if (tmp.length() > order.length()) { // 개수가 order보다 많으면 return
        return;
    }
    mp[tmp]++;
    for (int i = start + 1;i < order.length();i++) {
        tmp += order[i]; // 코스 추가
        combi(i, tmp, order); // 조합
        tmp.pop_back(); // 코스 제외
    }
}

vector<string> solution(vector<string> orders, vector<int> course) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    vector<string> answer;

    for (auto iter : orders) {
        sort(iter.begin(), iter.end()); // 코스정렬
        combi(-1, "", iter);
    }
    // for(auto iter : mp){
    //     cout<<s.first << " : "<< s.second<<'\n';
    // }

    for (auto s : mp) {
        int len = s.first.length(); // 길이저장 
        // course 수에 길이가 포함되지 않는다면 다음으로 넘어감
        if (find(course.begin(), course.end(), len) == course.end()) continue;
        if (s.second < 2) continue;
        if (courseMax[len] < s.second) { // 더 크면 배열 비우고 추가
            tmp_courseList[len].clear();
            tmp_courseList[len].push_back(s.first);
            courseMax[len] = s.second;
        }
        else if (courseMax[len] == s.second) { // 같으면 그냥 추가
            tmp_courseList[len].push_back(s.first);
        }
    }

    for (auto courseNum : course) {
        for (auto courseList : tmp_courseList[courseNum]) { // 코스 answer에 넣기
            answer.push_back(courseList);
        }
    }
    sort(answer.begin(), answer.end()); // 순서대로 정렬
    return answer;
}

#endif // 0
